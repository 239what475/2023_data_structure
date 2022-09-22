#include "practice_3_1.h"
#include "link_list.h"
#include "sq_stack.h"

namespace practice_3_1
{
    namespace p_04
    {
        using namespace list;
        using std::cout;
        using std::endl;

        template <typename E>
        bool judge(LinkList<E> &l)
        {
            using namespace stack;
            auto p = l.next;
            auto s = SqStack<E>();
            auto len = l.length();

            for (int i = 0; i < len / 2; i++)
            {
                s.push(p->data);
                p = p->next;
            }

            if (len % 2 == 1)
                p = p->next;

            auto e = '\0';
            while (p)
            {
                s.pop(e);
                if (p->data != e)
                    return false;
                p = p->next;
            }

            return true;
        }
    } // namespace p_04

    void practice_04()
    {
        using namespace p_04;
        auto l1 = LinkList<char>((const char[]){"xyx"}, 3);
        auto l2 = LinkList<char>((const char[]){"xyyx"}, 4);
        auto l3 = LinkList<char>((const char[]){"xxyyx"}, 5);

        cout << "is l1 symmetry ? " << (judge(l1) ? "yes" : "no") << endl
             << l1 << endl;
        cout << "is l2 symmetry ? " << (judge(l2) ? "yes" : "no") << endl
             << l2 << endl;
        cout << "is l3 symmetry ? " << (judge(l3) ? "yes" : "no") << endl
             << l3 << endl;
    }
} // namespace practice_3_1
