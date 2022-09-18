#include "practice_2_3.h"
#include "link_list.h"

namespace practice_2_3
{

    namespace p_05
    {
        using namespace list;
        using std::cout;
        using std::endl;

        template <typename E>
        void reverse_1(LinkList<E> &l)
        {
            if (l.next && l.next->next)
            {
                auto insert = l.next;
                auto p = l.next->next;
                insert->next = nullptr;
                auto pre = p;
                while (p)
                {
                    pre = p;
                    p = p->next;
                    pre->next = insert;
                    insert = pre;
                }
                l.next = insert;
            }
        }

        template <typename E>
        void reverse_2(LinkList<E> &l)
        {
            if (l.next && l.next->next)
            {
                auto prior = l.next;
                LinkList<E> *temp = nullptr;
                auto p = l.next->next;
                while (p)
                {
                    prior->next = temp;
                    temp = prior;
                    prior = p;
                    p = p->next;
                }
                prior->next = temp;
                l.next = prior;
            }
        }

    } // namespace p_01

    void practice_05()
    {
        using namespace p_05;
        {
            auto l = LinkList<int>((const int[]){2, 1, 0, 3, 4, 2}, 6);
            cout << l << endl
                 << "reverse list" << endl;
            reverse_1(l);
            cout << l << endl;
            l.destroyList();
        }
        cout << endl;
        {
            auto l = LinkList<int>((const int[]){2, 1, 0, 3, 4, 2}, 6);
            cout << l << endl
                 << "reverse list" << endl;
            reverse_2(l);
            cout << l << endl;
            l.destroyList();
        }
    }
} // namespace practice_2_3