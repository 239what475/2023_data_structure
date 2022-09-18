#include "practice_2_3.h"
#include "link_list.h"

namespace practice_2_3
{

    namespace p_14
    {
        using namespace list;
        using std::cout;
        using std::endl;

        void get_public(LinkList<int> &l1, LinkList<int> &l2, LinkList<int> &l3)
        {
            if (l1.empty() || l2.empty())
                return;
            auto p1 = l1.next;
            auto p2 = l2.next;
            auto p3 = &l3;
            while (p1 && p2)
            {
                if (p1->data < p2->data)
                    p1 = p1->next;
                else if (p1->data > p2->data)
                    p2 = p2->next;
                else
                {
                    p3 = p3->next = new LinkNode<int>(p1->data);
                    p1 = p1->next;
                    p2 = p2->next;
                }
            }
        }

    } // namespace p_01

    void practice_14()
    {
        using namespace p_14;
        auto l1 = LinkList<int>((const int[]){1, 2, 7}, 3);
        auto l2 = LinkList<int>((const int[]){2, 6, 7, 11}, 4);
        auto l3 = LinkList<int>();

        cout << l1 << endl
             << l2 << endl;
        get_public(l1, l2, l3);
        cout << "get public :" << endl
             << l3 << endl;
        l1.destroyList();
        l2.destroyList();
        l3.destroyList();
    }
} // namespace practice_2_3