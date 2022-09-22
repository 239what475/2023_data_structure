#include "practice_2_3.h"
#include "link_list.h"

namespace practice_2_3
{

    namespace p_24
    {
        using namespace list;
        using std::cout;
        using std::endl;

        int absulate_value(int x)
        {
            return x > 0 ? x : -x;
        }

        void delete_absolute_value(LinkList<int> &l, int max)
        {
            int data[max + 1] = {0};
            auto p = &l;
            auto temp = &l;
            while (p->next)
            {
                if (data[absulate_value(p->next->data)] == 0)
                {
                    data[absulate_value(p->next->data)] = 1;
                    p = p->next;
                }
                else
                {
                    temp = p->next;
                    p->next = p->next->next;
                    delete temp;
                }
            }
        }

    } // namespace p_24

    void practice_24()
    {
        using namespace p_24;
        auto l = LinkList<int>((const int[]){1, 2, -2, 4, 0, 5, -1, -5}, 8);
        cout << l << endl;
        delete_absolute_value(l, 5);
        cout << "delete absolute value :" << endl
             << l << endl;
        l.destroyList();
    }
} // namespace practice_2_3