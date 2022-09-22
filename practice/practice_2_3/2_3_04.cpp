#include "practice_2_3.h"
#include "link_list.h"

namespace practice_2_3
{

    namespace p_04
    {
        using namespace list;
        using std::cout;
        using std::endl;

        void delete_min(LinkList<int> &l)
        {
            if (l.empty())
                return;

            auto p = l.next;
            auto p_pre = &l;
            auto min = l.next->data;
            auto min_p_pre = &l;

            while (p)
            {
                if (p->data < min)
                {
                    min = p->data;
                    min_p_pre = p_pre;
                }
                p_pre = p;
                p = p->next;
            }

            auto min_p = min_p_pre->next;
            min_p_pre->next = min_p_pre->next->next;
            delete min_p;
        }

    } // namespace p_04

    void practice_04()
    {
        using namespace p_04;
        auto l = LinkList<int>((const int[]){2, 1, 0, 3, 4}, 5);
        cout << l << endl
             << "delete minnium data" << endl;
        delete_min(l);
        cout << l << endl
             << "delete minnium data" << endl;
        delete_min(l);
        cout << l << endl;;
        l.destroyList();
    }
} // namespace practice_2_3