#include "practice_2_3.h"
#include "link_list.h"

namespace practice_2_3
{

    namespace p_03
    {
        using namespace list;
        using std::cout;
        using std::endl;

        template <typename E>
        void r_output(LinkList<E> *l)
        {
            if (l->next)
            {
                r_output(l->next);
            }
            cout << l->data << ",";
        }

        template <typename E>
        void reverse_output(LinkList<E> &l)
        {
            if (l.next)
                r_output(l.next);
        }

    } // namespace p_01

    void practice_03()
    {
        using namespace p_03;
        auto l = LinkList<int>((const int[]){1, 2, 2, 2, 3, 4, 2}, 7);
        cout << l << endl
             << "reverse output:";
        reverse_output(l);
        cout << endl;
        l.destroyList();
    }
} // namespace practice_2_3
