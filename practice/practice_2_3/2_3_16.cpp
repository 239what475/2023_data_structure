#include "practice_2_3.h"
#include "link_list.h"

namespace practice_2_3
{

    namespace p_16
    {
        using namespace list;
        using std::cout;
        using std::endl;

        bool judge_consecutive(LinkList<int> &l1, LinkList<int> &l2)
        {
            if (l1.empty() || l2.empty())
                return false;

            auto p1 = l1.next;
            auto pre = p1;
            auto p2 = l2.next;
            while (p1 && p2)
                if (p1->data != p2->data)
                {
                    p1 = pre->next;
                    pre = pre->next;
                    p2 = l2.next;
                }
                else
                {
                    p1 = p1->next;
                    p2 = p2->next;
                }

            if (p2)
                return false;
            else
                return true;
        }

    } // namespace p_16

    void practice_16()
    {
        using namespace p_16;
        auto l1 = LinkList<int>((const int[]){1, 2, 7, 11, 15}, 5);
        auto l2 = LinkList<int>((const int[]){2, 7, 11, 15}, 4);

        cout << l1 << endl
             << l2 << endl;
        cout << "judge consecutive :"
             << (judge_consecutive(l1, l2) ? "true" : "false")
             << endl;
        l1.destroyList();
        l2.destroyList();
    }
} // namespace practice_2_3