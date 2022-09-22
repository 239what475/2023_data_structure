#include "sq_list.h"
#include "practice_2_2.h"
#include <string>

namespace practice_2_2
{
    namespace p_10
    {
        using namespace list;
        using std::cout;
        using std::endl;
        using std::string;

        void reverse(SqList<string> &l, int from, int to)
        {
            string temp;
            for (int i = 0; i < (to - from + 1) / 2; i++)
            {
                temp = l.data[from + i];
                l.data[from + i] = l.data[to - i];
                l.data[to - i] = temp;
            }
        }

        void reorder(SqList<string> &l, int p)
        {
            string temp;
            reverse(l, 0, l.length() - 1);
            reverse(l, 0, p - 1);
            reverse(l, p, l.length() - 1);
        }
    } // namespace p_10

    void practice_10()
    {
        using namespace p_10;
        const string li[] = {"a1", "a2", "a3", "a4", "a5", "a6", "a7"};
        auto l = SqList<string>(li, 7);
        cout << l << endl;

        reorder(l, 4);
        cout << "reorder list" << endl
             << l << endl;
    }

} // namespace practice_2_2