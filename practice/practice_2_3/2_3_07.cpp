#include "practice_2_3.h"
#include "link_list.h"

namespace practice_2_3
{

    namespace p_07
    {
        using namespace list;
        using std::cout;
        using std::endl;

        void delete_between_s_t(LinkList<int> &l, int s, int t)
        {
            if (l.empty())
                return;
            auto pre = &l;
            auto p = l.next;
            while (p)
            {
                if (p->data >= s && p->data <= t)
                {
                    pre->next = p->next;
                    delete p;
                    p = pre->next;
                }
                else
                {
                    pre = p;
                    p = p->next;
                }
            }
        }

    } // namespace p_07

    void practice_07()
    {
        using namespace p_07;
        auto l = LinkList<int>((const int[]){1, 2, 5, 7, 3, 4, 2}, 7);
        cout << l << endl
             << "delete between 3 and 6" << endl;
        delete_between_s_t(l, 3, 6);
        cout << l << endl;
        l.destroyList();
    }
} // namespace practice_2_3
