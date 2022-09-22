#include "practice_2_3.h"
#include "link_list.h"

namespace practice_2_3
{

    namespace p_08
    {
        using namespace list;
        using std::cout;
        using std::endl;

        // O(len1×len2)
        template <typename E>
        LinkNode<E> const *delete_public_nodes_1(LinkList<E> &l1, LinkList<E> &l2)
        {
            if (l1.empty() || l2.empty())
                return nullptr;
            auto p1 = l1.next;
            auto p2 = l2.next;

            while (p1)
            {
                while (p2)
                {
                    if (p1 == p2 && p1)
                    {
                        return p1;
                    }
                    p2 = p2->next;
                }
                p2 = l2.next;
                p1 = p1->next;
            }

            return nullptr;
        }

        // O(len1 + len2)
        template <typename E>
        LinkNode<E> const *find_public_nodes_2(LinkList<E> &l1, LinkList<E> &l2)
        {
            if (l1.empty() || l2.empty())
                return nullptr;
            auto len1 = l1.length();
            auto len2 = l2.length();
            LinkList<E> *longList, *shortList;
            longList = len1 > len2 ? &l1 : &l2;
            shortList = len1 > len2 ? &l2 : &l1;
            auto dist = len1 > len2 ? len1 - len2 : len2 - len1;
            while (dist--)
                longList = longList->next;
            while (longList)
            {
                if (longList == shortList)
                {
                    return longList;
                }
                else
                {
                    longList = longList->next;
                    shortList = shortList->next;
                }
            }
            return nullptr;
        }

    } // namespace p_08

    void practice_08()
    {
        using namespace p_08;
        {
            auto l1 = LinkList<int>((const int[]){3}, 1);
            auto l2 = LinkList<int>((const int[]){4, 6, 9}, 3);
            auto l3 = LinkList<int>((const int[]){2, 1}, 2, false);

            l1.next->next = &l3;
            l2.next->next->next->next = &l3;

            LinkNode<int> *pub;

            cout << l1 << endl
                 << l2 << endl
                 << "find public node : " << delete_public_nodes_1(l1, l2) << endl
                 << &l3 << endl;
        }
        cout << endl;
        {
            auto l1 = LinkList<int>((const int[]){3}, 1);
            auto l2 = LinkList<int>((const int[]){4, 6, 9}, 3);
            auto l3 = LinkList<int>((const int[]){2, 1}, 2, false);

            l1.next->next = &l3;
            l2.next->next->next->next = &l3;

            LinkNode<int> *pub;

            cout << l1 << endl
                 << l2 << endl
                 << "find public node : " << find_public_nodes_2(l1, l2) << endl
                 << &l3 << endl;
        }
    }
} // namespace practice_2_3