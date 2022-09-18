#include "practice_2_3.h"
#include "link_list.h"

namespace practice_2_3
{

    namespace p_21
    {
        using namespace list;
        using std::cout;
        using std::endl;

        // O(n^2)
        template <typename E>
        LinkNode<E> const *judge_ring_1(LinkList<E> &l)
        {
            if (!l.next)
                return nullptr;

            auto q = l.next;
            auto p = l.next->next;
            while (q)
            {
                while (p)
                {
                    if (p == q)
                        return p;
                    p = p->next;
                }
                q = q->next;
            }

            return nullptr;
        }

        // O(n)
        template <typename E>
        LinkNode<E> const *judge_ring_2(LinkList<E> &l)
        {
            auto fast = &l;
            auto slow = &l;
            while (fast && fast->next)
            {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast)
                    break;
            }
            if (slow == nullptr || fast->next == nullptr)
                return nullptr;
            auto p = &l;
            while (p != slow)
            {
                p = p->next;
                slow = slow->next;
            }
            return p;
        }

    } // namespace p_01

    void practice_21()
    {
        using namespace p_21;
        auto head = LinkNode<int>();
        auto n4 = LinkNode<int>(4);
        auto n3 = LinkNode<int>(3, &n4);
        auto n2 = LinkNode<int>(2, &n3);
        auto n1 = LinkNode<int>(1, &n2);
        n4.next = &n2;
        head.next = &n1;

        cout << " is link having ring ? "
             << judge_ring_1(n1) << endl;

        cout << " is link having ring ? "
             << judge_ring_2(n1) << endl;
    }
} // namespace practice_2_3