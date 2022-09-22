#include "practice_2_3.h"
#include "double_link_list_with_freq.h"

namespace practice_2_3
{

    namespace p_20
    {
        using namespace list;
        using std::cout;
        using std::endl;

        template <typename E>
        DoubleLinkListWithFreq<E> const *Locate(DoubleLinkListWithFreq<E> &l, E x)
        {
            auto p = l.is_head_node ? l.next : &l;
            while (p && p->data != x)
                p = p->next;
            if (!p)
                return nullptr;

            p->freq++;
            if (p->prior == &l || p->prior->freq > p->freq)
                return p;

            if (p->next)
                p->next->prior = p->prior;
            p->prior->next = p->next;

            auto q = p->prior;
            while (q != &l && q->freq < p->freq)
                q = q->prior;

            if (q->next)
                q->next->prior = p;
            p->next = q->next;
            q->next = p;
            p->prior = q;

            return p;
        }

    } // namespace p_20

    void practice_20()
    {
        using namespace p_20;
        auto l = DoubleLinkListWithFreq<int>((const int[]){1, 2, 3, 4}, 4);

        cout << l << endl;
        cout << "locate element 3 at address :" << Locate(l, 3) << endl
             << l << endl
             << "locate element 2 at address :" << Locate(l, 2) << endl
             << l << endl
             << "locate element 3 at address :" << Locate(l, 3) << endl
             << l << endl
             << "locate element 4 at address :" << Locate(l, 4) << endl
             << l << endl
             << "locate element 1 at address :" << Locate(l, 1) << endl
             << l << endl
             << "locate element 1 at address :" << Locate(l, 1) << endl
             << l << endl;
        l.destroyList();
    }
} // namespace practice_2_3