#include "practice_2_3.h"
#include "circular_link_list.h"

namespace practice_2_3
{

    namespace p_18
    {
        using namespace list;
        using std::cout;
        using std::endl;

        void combine(CircularLinkList<int> &l1, CircularLinkList<int> &l2)
        {
            if (l2.empty())
                return;

            auto p1 = &l1;
            while (p1->next != &l1)
            {
                p1 = p1->next;
            }
            auto p2 = &l2;
            while (p2->next != &l2)
            {
                p2 = p2->next;
            }
            p1->next = l2.next;
            p2->next = &l1;
            l2.next = &l2;
        }

    } // namespace p_18

    void practice_18()
    {
        using namespace p_18;
        auto l1 = CircularLinkList<int>((const int[]){1, 2, 7, 11, 15}, 5);
        auto l2 = CircularLinkList<int>((const int[]){2, 7, 11, 15}, 4);

        cout << l1 << endl
             << l2 << endl;
        combine(l1, l2);
        cout << "combine :" << endl
             << l1 << endl
             << l2 << endl;
        l1.destroyList();
    }
} // namespace practice_2_3