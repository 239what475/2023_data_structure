#include "practice_2_3.h"
#include "link_list.h"
#include <string>

namespace practice_2_3
{

    namespace p_11
    {
        using namespace list;
        using std::cout;
        using std::endl;

        // 和 2_3_10 一样
        template <typename E>
        void split_with_index(LinkList<E> &l1, LinkList<E> &l2, LinkList<E> &l3)
        {
            if (l1.empty())
                return;
            auto index = 0;
            auto p2 = &l2;
            auto temp = &l3;
            auto p = l1.next;
            while (p)
            {
                switch ((index++ + 1) % 2)
                {
                case 1:
                    p2->next = p;
                    p2 = p2->next;
                    p = p->next;
                    break;
                default:
                    temp = p->next;
                    p->next = l3.next;
                    l3.next = p;
                    p = temp;
                    break;
                }
            }
            p2->next = nullptr;
        }

    } // namespace p_11

    void practice_11()
    {
        using std::string;
        using namespace p_11;
        string strs[] = {"a1", "b1", "a2", "b2", "a3", "b3", "a4", "b4"};
        auto l1 = LinkList<string>(strs, 8);
        auto l2 = LinkList<string>();
        auto l3 = LinkList<string>();
        cout << "l1 : " << l1 << endl;
        split_with_index(l1, l2, l3);
        cout << "split l1 with index :" << endl
             << "l2 : " << l2 << endl
             << "l3 : " << l3 << endl;
        l2.destroyList();
        l3.destroyList();
    }
} // namespace practice_2_3