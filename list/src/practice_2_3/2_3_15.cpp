#include "practice_2_3.h"
#include "link_list.h"

namespace practice_2_3
{

    namespace p_15
    {
        using namespace list;
        using std::cout;
        using std::endl;

        void get_intersection(LinkList<int> &l1, LinkList<int> &l2)
        {
            if (l1.empty() || l2.empty())
            {
                l1.destroyList();
                return;
            }
            auto p1 = l1.next;
            auto p2 = l2.next;
            l1.next = nullptr;
            auto temp = p1;
            while (p1 && p2)
            {
                if (p1->data == p2->data)
                {
                    temp = p1;
                    p1 = p1->next;
                    p2 = p2->next;
                    temp->next = l1.next;
                    l1.next = temp;
                }
                else if (p1->data < p2->data)
                {
                    temp = p1;
                    p1 = p1->next;
                    delete temp;
                }
                else
                {
                    p2 = p2->next;
                }
            }
            while (p1)
            {
                temp = p1->next;
                delete p1;
                p1 = temp;
            }
        }

    } // namespace p_01

    void practice_15()
    {
        using namespace p_15;
        auto l1 = LinkList<int>((const int[]){1, 2, 7, 11, 13}, 5);
        auto l2 = LinkList<int>((const int[]){2, 6, 7}, 3);

        cout << l1 << endl
             << l2 << endl;
        get_intersection(l1, l2);
        cout << "get intersection :" << endl
             << l1 << endl;
        l1.destroyList();
        l2.destroyList();
    }
} // namespace practice_2_3