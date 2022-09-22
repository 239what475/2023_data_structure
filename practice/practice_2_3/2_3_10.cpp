#include "practice_2_3.h"
#include "link_list.h"

namespace practice_2_3
{

    namespace p_10
    {
        using namespace list;
        using std::cout;
        using std::endl;

        template <typename E>
        LinkList<E> *split_with_index(LinkList<E> &l1)
        {
            if (l1.empty())
                return nullptr;
            auto index = 0;
            auto p = l1.next;
            l1.next = nullptr;
            auto l2 = new LinkList<E>();
            auto p1 = &l1;
            auto p2 = l2;

            while (p)
            {
                switch ((index++ + 1) % 2)
                {
                case 1:
                    // 奇数项
                    p1->next = p;
                    p1 = p1->next;
                    break;
                default:
                    // 偶数项
                    p2->next = p;
                    p2 = p2->next;
                    break;
                }
                p = p->next;
            }
            p1->next = p2->next = nullptr;
            return l2;
        }

    } // namespace p_10

    void practice_10()
    {
        using namespace p_10;
        auto l1 = LinkList<int>((const int[]){1, 5, 8, 2, 3, 4, 2, 6}, 8);
        cout << l1 << endl;
        auto l2 = split_with_index(l1);
        cout << "split l1 with index :" << endl
             << "l1 : " << l1 << endl
             << "l2 : " << *l2 << endl;
        l1.destroyList();
        l2->destroyList();
    }
} // namespace practice_2_3