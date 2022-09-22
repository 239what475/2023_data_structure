#include "practice_2_3.h"
#include "link_list.h"

namespace practice_2_3
{

    namespace p_02
    {
        using namespace list;
        using std::cout;
        using std::endl;

        template <typename E>
        void delete_all_x_1(LinkList<E> &l, E x)
        {
            auto pre = &l;
            auto p = l.next;
            while (p)
            {
                if (p->data == x)
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

        template <typename E>
        void delete_all_x_2(LinkList<E> &l, E x)
        {
            auto r = &l;
            auto q = l.next;
            auto p = l.next;
            while (p)
            {
                if (p->data == x)
                {
                    q = p;
                    p = p->next;
                    delete q;
                }
                else
                {
                    r->next = p;
                    r = r->next;
                    p = p->next;
                }
            }
            r->next = nullptr;
        }

    } // namespace p_02

    void practice_02()
    {
        using namespace p_02;
        {
            auto l = LinkList<int>((const int[]){1, 2, 2, 2, 3, 4, 2}, 7);
            cout << l << endl
                 << "delete all 2" << endl;
            delete_all_x_1(l, 2);
            cout << l << endl;
            l.destroyList();
        }
        cout << endl;
        {
            auto l = LinkList<int>((const int[]){1, 2, 2, 2, 3, 4, 2}, 7);
            cout << l << endl
                 << "delete all 2" << endl;
            delete_all_x_2(l, 2);
            cout << l << endl;
            l.destroyList();
        }
    }
} // namespace practice_2_3
