#include "practice_2_3.h"
#include "link_list.h"

namespace practice_2_3
{

    namespace p_13
    {
        using namespace list;
        using std::cout;
        using std::endl;

        void combine(LinkList<int> &l1, LinkList<int> &l2, LinkList<int> &l3)
        {
            if (l1.empty() || l2.empty())
            {
                l3.next = l1.next ? l1.next : l2.next;
                return;
            }
            auto p1 = l1.next;
            auto p2 = l2.next;
            LinkNode<int> *temp = nullptr;
            while (p1 && p2)
            {
                if (p1->data < p2->data)
                {
                    temp = p1->next;
                    p1->next = l3.next;
                    l3.next = p1;
                    p1 = temp;
                }
                else
                {
                    temp = p2->next;
                    p2->next = l3.next;
                    l3.next = p2;
                    p2 = temp;
                }
            }
            if (p1)
                p2 = p2;
            while (p2)
            {
                temp = p2->next;
                p2->next = l3.next;
                l3.next = p2;
                p2 = temp;
            }

            l1.next = nullptr;
            l2.next = nullptr;
        }

    } // namespace p_13

    void practice_13()
    {
        using namespace p_13;
        auto l1 = LinkList<int>((const int[]){1, 5, 7}, 3);
        auto l2 = LinkList<int>((const int[]){2, 6, 10, 11}, 4);
        auto l3 = LinkList<int>();

        cout << l1 << endl
             << l2 << endl;
        combine(l1, l2, l3);
        cout << "combine :" << endl
             << l3 << endl;
        l3.destroyList();
    }
} // namespace practice_2_3