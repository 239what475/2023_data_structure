#include "practice_2_3.h"
#include "link_list.h"

namespace practice_2_3
{

    namespace p_06
    {
        using namespace list;
        using std::cout;
        using std::endl;

        // 不动结点，只移动结点的值
        void sort_increase_1(LinkList<int> &l)
        {
            if (l.empty())
                return;
            auto min = l.next->data;
            auto min_p = l.next;
            auto p = l.next;
            auto current = p;
            while (p->next)
            {
                current = p->next;
                while (current)
                {
                    if (min > current->data)
                    {
                        min = current->data;
                        min_p = current;
                    }
                    current = current->next;
                }
                min_p->data = p->data;
                p->data = min;
                p = p->next;
                min = p->data;
                min_p = p;
            }
        }

        // best
        void sort_increase_2(LinkList<int> &l)
        {
            auto p = l.next;
            auto pre = &l;
            auto temp = p->next;
            p->next = nullptr;
            p = temp;
            while (p)
            {
                temp = p->next;
                pre = &l;
                // 在 L 中找位置插入 p
                while (pre->next && pre->next->data < p->data)
                    pre = pre->next;
                p->next = pre->next;
                pre->next = p;
                p = temp;
            }
        }

        void sort_increase_3(LinkList<int> &l)
        {
            auto p = l.next;
            auto pre = &l;
            auto temp = &l;
            l.next = nullptr;

            while (p)
            {
                pre = nullptr;
                temp = p;
                auto max = p->data;
                auto max_pre = pre;
                // 找 p中最大的结点
                while (p)
                {
                    if (p->data > max)
                    {
                        max_pre = pre;
                        max = p->data;
                    }
                    pre = p;
                    p = p->next;
                }
                p = temp;
                // 头插法插入到 l 中
                if (max_pre)
                {
                    temp = max_pre->next;
                    max_pre->next = max_pre->next->next;
                    temp->next = l.next;
                    l.next = temp;
                }
                else
                {
                    temp->next = l.next;
                    l.next = temp;
                    break;
                }
            }
        }

    } // namespace p_01

    void practice_06()
    {
        using namespace p_06;
        {
            auto l = LinkList<int>((const int[]){1, 2, 5, 7, 3, 4, 2}, 7);
            cout << l << endl
                 << "sort increase" << endl;
            sort_increase_1(l);
            cout << l << endl;
            l.destroyList();
        }
        cout << endl;
        {
            auto l = LinkList<int>((const int[]){1, 2, 5, 7, 3, 4, 2}, 7);
            cout << l << endl
                 << "sort increase" << endl;
            sort_increase_2(l);
            cout << l << endl;
            l.destroyList();
        }
        cout << endl;
        {
            auto l = LinkList<int>((const int[]){1, 2, 5, 7, 3, 4, 2}, 7);
            cout << l << endl
                 << "sort increase" << endl;
            sort_increase_3(l);
            cout << l << endl;
            l.destroyList();
        }
    }
} // namespace practice_2_3
