#include "practice_2_3.h"
#include "link_list.h"

namespace practice_2_3
{

    namespace p_09
    {
        using namespace list;
        using std::cout;
        using std::endl;

        void output_increase(LinkList<int> *&l)
        {
            auto min = l->next->data;
            auto min_p_pre = l;
            auto p = l;
            while (l->next)
            {
                while (p->next)
                {
                    if (p->next->data < min)
                    {
                        min = p->next->data;
                        min_p_pre = p;
                    }
                    p = p->next;
                }
                cout << min << ", " << endl;
                p = min_p_pre->next;
                min_p_pre->next = p->next;
                delete p;
                p = l;
            }
            delete l;
        }

    } // namespace p_01

    void practice_09()
    {
        using namespace p_09;
        auto l = new LinkList<int>((const int[]){1, 5, 8, 2, 3, 4, 2}, 7);
        cout << "output increase:" << endl;
        output_increase(l);
    }
} // namespace practice_2_3
