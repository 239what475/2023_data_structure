#include "practice_2_3.h"
#include "link_list.h"

namespace practice_2_3
{

    namespace p_12
    {
        using namespace list;
        using std::cout;
        using std::endl;

        void delete_repeat(LinkList<int> &l)
        {
            if (l.empty())
                return;

            auto p = l.next;
            auto temp = p;
            while (p->next)
            {
                if (p->next->data == p->data)
                {
                    temp = p->next;
                    p->next = p->next->next;
                    delete temp;
                }
                else
                    p = p->next;
            }
        }

    } // namespace p_12

    void practice_12()
    {
        using namespace p_12;
        auto l = LinkList<int>((const int[]){7, 10, 10, 21, 30, 42, 42, 42, 51, 70}, 10);
        cout << l << endl;
        delete_repeat(l);
        cout << "delete repeat :" << endl
             << l << endl;
        l.destroyList();
    }
} // namespace practice_2_3