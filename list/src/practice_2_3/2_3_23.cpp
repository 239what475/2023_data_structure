#include "practice_2_3.h"
#include "link_list.h"

namespace practice_2_3
{

    namespace p_23
    {
        using namespace list;
        using std::cout;
        using std::endl;

        template <typename E>
        LinkNode<E> const *find_public_nodes(LinkList<E> &l1, LinkList<E> &l2)
        {
            if (l1.empty() || l2.empty())
                return nullptr;
            auto len1 = l1.length();
            auto len2 = l2.length();
            auto p1 = &l1;
            auto p2 = &l2;
            for (; len1 > len2; len1--)
                p1 = p1->next;
            for (; len2 > len1; len2--)
                p2 = p2->next;

            while (p1->next && p1->next != p2->next)
            {
                p1 = p1->next;
                p2 = p2->next;
            }

            return p1->next;
        }

    } // namespace p_01

    void practice_23()
    {
        using namespace p_23;
        auto l1 = LinkList<char>((const char[]){"load"}, 4);
        auto l2 = LinkList<char>((const char[]){"be"}, 2);
        auto l3 = LinkList<char>((const char[]){"ing"}, 3, false);

        l1.next->next->next->next->next = &l3;
        l2.next->next->next = &l3;

        cout << l1 << endl
             << l2 << endl
             << "find public node : " << find_public_nodes(l1, l2) << endl
             << &l3 << endl;
        // l1.destroyList();
        // l2.destroyList();
    }
} // namespace practice_2_3