#include "practice_2_3.h"
#include "link_list.h"

namespace practice_2_3
{

    namespace p_22
    {
        using namespace list;
        using std::cout;
        using std::endl;

        template <typename E>
        bool find_k_position_from_bottom(LinkList<E> &l, int k)
        {
            auto k_p = l.next;
            auto p = l.next;
            int between = 0;
            while (p)
            {
                p = p->next;
                if (between < k)
                    between++;
                else
                    k_p = k_p->next;
            }

            if (between == k)
            {
                cout << k_p->data << endl;
                return true;
            }
            else
                return false;
        }

    } // namespace p_22

    void practice_22()
    {
        using namespace p_22;
        auto l = LinkList<int>((const int[]){1, 2, 3, 4, 5, 6, 7}, 7);
        cout << l << endl;
        find_k_position_from_bottom(l, 3);
        l.destroyList();
    }
} // namespace practice_2_3