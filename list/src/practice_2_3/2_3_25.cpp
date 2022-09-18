#include "practice_2_3.h"
#include "link_list.h"
#include <string>

namespace practice_2_3
{

    namespace p_25
    {
        using namespace list;
        using std::cout;
        using std::endl;

        void reorder(LinkList<std::string> &l)
        {
            if (!l.next)
                return;

            auto start = l.next;
            auto end = &l;
            auto mid = &l;
            auto last = &l;
            auto temp = &l;
            // 找到中点
            while (end->next)
            {
                end = end->next;
                mid = mid->next;
                if (end->next)
                    end = end->next;
            }
            // 颠倒后半段
            while (mid->next != end)
            {
                temp = mid->next->next;
                mid->next->next = end->next;
                end->next = mid->next;
                mid->next = temp;
            }
            // 把后半段插进前半段
            while (start != mid)
            {
                temp = start->next;
                start->next = mid->next;
                mid->next = mid->next->next;
                start = start->next;
                start->next = temp;
                start = start->next;
            }
        }

    } // namespace p_01

    void practice_25()
    {
        using namespace p_25;
        std::string s[] = {"a1", "a2", "a3", "a4", "a5", "a6", "a7", "a8"};
        auto l = LinkList<std::string>(s, 8);
        cout << l << endl;
        reorder(l);
        cout << "reorder :" << endl
             << l << endl;
        l.destroyList();
    }
} // namespace practice_2_3