#include "practice_2_3.h"
#include "circular_double_link_list.h"

namespace practice_2_3
{

    namespace p_17
    {
        using namespace list;
        using std::cout;
        using std::endl;

        bool judge_symmetry(CircularDoubleLinkList<int> &l)
        {
            auto head = l.next;
            auto tail = l.prior;
            while (tail != head && head->next != tail)
            {
                if (tail->data == head->data)
                {
                    head = head->next;
                    tail = tail->prior;
                }
                else
                    return false;
            }
            return true;
        }

    } // namespace p_01

    void practice_17()
    {
        using namespace p_17;
        auto l = CircularDoubleLinkList<int>((const int[]){1, 2, 2, 1}, 4);

        cout << l << endl;
        cout << "judge symmetry :"
             << (judge_symmetry(l) ? "true" : "false")
             << endl;
        l.destroyList();
    }
} // namespace practice_2_3