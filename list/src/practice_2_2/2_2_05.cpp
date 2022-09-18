#include "sq_list.h"
#include "practice_2_2.h"

namespace practice_2_2
{
    namespace p_05
    {
        using namespace list;
        using std::cout;
        using std::endl;

        bool delete_between_s_t(SqList<int> &l, int s, int t)
        {
            if (s > t || l.empty())
                return false;

            int num = 0;
            for (int i = 0; i < l.length(); i++)
            {
                if (l.data[i] >= s && l.data[i] <= t)
                {
                    num++;
                }
                else
                {
                    l.data[i - num] = l.data[i];
                }
            }
            l.length() -= num;
            return true;
        }
    } // namespace p_04

    void practice_05()
    {
        using namespace p_05;
        auto l = SqList<int>((const int[]){1, 2, 3, 1, 4}, 5);
        cout << l << endl;
        delete_between_s_t(l, 1, 3);
        cout << l << endl;
    }

} // namespace practice_2_2