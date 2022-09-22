#include "practice_2_3.h"
#include "circular_link_list.h"

namespace practice_2_3
{

    namespace p_19
    {
        using namespace list;
        using std::cout;
        using std::endl;

        void output_increase(CircularLinkList<int> &l)
        {
            if (l.empty())
                return;

            auto min = l.next->data;
            auto min_prior_p = &l;
            auto p = &l;
            auto temp = p;
            while (l.next != &l)
            {
                while (p->next != &l)
                {
                    if (p->next->data <= min)
                    {
                        min = p->next->data;
                        min_prior_p = p;
                    }
                    p = p->next;
                }
                std::cout << min << "," << std::endl;
                temp = min_prior_p->next;
                min_prior_p->next = min_prior_p->next->next;
                delete temp;
                p = &l;
                min = l.next->data;
            }
        }

    } // namespace p_19

    void practice_19()
    {
        using namespace p_19;
        auto l = CircularLinkList<int>((const int[]){1, 2, 2, 1}, 4);

        cout << l << endl;
        cout << "output increase :" << endl;
        output_increase(l);
        l.destroyList();
    }
} // namespace practice_2_3