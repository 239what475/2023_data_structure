#include "sq_list.h"
#include "practice_2_2.h"

namespace practice_2_2
{

    namespace p_09
    {
        using namespace list;
        using std::cout;
        using std::endl;

        bool find(SqList<int> &l, int x)
        {
            int start = 0, end = l.length() - 1, mid;
            while (start < end && end - start != 1)
            {
                mid = (start + end) / 2;
                if (l.data[mid] < x)
                    start = mid;
                else
                    end = mid;
            }
            if (l.data[start] == x)
            {
                l.data[start] = l.data[start + 1];
                l.data[start + 1] = x;
            }
            else if (l.data[end] == x)
            {
                l.data[end] = l.data[end + 1];
                l.data[end + 1] = x;
            }
            else
            {
                for (int i = l.length(); i > end; i--)
                {
                    l.data[i] = l.data[i - 1];
                }
                l.data[end] = x;
                l.length()++;
            }

            // better:
            //
            // while (start <= end)
            // {
            //     mid = (start + end) / 2;
            //     if (l.data[mid] == x)
            //         break;
            //     else if (l.data[mid] < x)
            //         start = mid + 1;
            //     else
            //         end = mid - 1;
            // }
            // if (l.data[mid] == x && mid != l.length() - 1)
            // {
            //     l.data[mid] = l.data[mid + 1];
            //     l.data[mid + 1] = x;
            // }
            // else if (start > end)
            // {
            //     for (int i = l.length(); i > end; i--)
            //     {
            //         l.data[i] = l.data[i - 1];
            //     }
            //     l.data[end] = x;
            //     l.length()++;
            // }

            return true;
        }
    } // namespace p_04

    void practice_09()
    {
        using namespace p_09;
        auto l = SqList<int>((const int[]){1, 2, 3, 4, 7, 8, 9}, 7);
        cout << l << endl;
        if (find(l, 5))
        {
            cout << "find 5" << endl
                 << l << endl;
        }
        else
        {
            cout << "not find x" << endl;
        }
    }

} // namespace practice_2_2