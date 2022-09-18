#include "sq_list.h"
#include "practice_2_2.h"

namespace practice_2_2
{
    namespace p_14
    {
        using namespace list;
        using std::cout;
        using std::endl;

        int abs(int a)
        {
            if (a < 0)
                return -a;
            return a;
        }

        int is_min_first(int a, int b, int c)
        {
            if (a < b && a < c)
            {
                return true;
            }
            else
                return false;
        }

        int find_min_distance(SqList<int> &l1, SqList<int> &l2, SqList<int> &l3)
        {
            int i, j, k, min_d, d;
            min_d = 0x7fffffff;
            i = j = k = 0;
            while (i < l1.length() && j < l2.length() && k < l3.length())
            {
                d = abs(l1.data[i] - l2.data[j]) + abs(l2.data[j] - l3.data[k]) + abs(l3.data[k] - l1.data[i]);
                if (d < min_d)
                    min_d = d;

                if (is_min_first(l1.data[i], l2.data[j], l3.data[k]))
                    i++;
                else if (is_min_first(l2.data[j], l1.data[i], l3.data[k]))
                    j++;
                else
                    k++;
            }
            return min_d;
        }
    } // namespace p_04

    void practice_14()
    {
        using namespace p_14;
        auto l1 = SqList<int>((const int[]){-1, 0, 9}, 3);
        cout << l1 << endl;

        auto l2 = SqList<int>((const int[]){-25, -10, 10, 11}, 4);
        cout << l2 << endl;

        auto l3 = SqList<int>((const int[]){2, 9, 17, 30, 41}, 5);
        cout << l3 << endl;

        cout << "find min distance:" << find_min_distance(l1, l2, l3) << endl;
    }

} // namespace practice_2_2