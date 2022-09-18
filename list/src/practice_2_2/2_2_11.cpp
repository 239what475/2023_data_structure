#include "sq_list.h"
#include "practice_2_2.h"

namespace practice_2_2
{
    namespace p_11
    {
        using namespace list;
        using std::cout;
        using std::endl;

        int median(SqList<int> &l1, SqList<int> &l2)
        {
            int i, j;
            int mid;

            i = j = 0;
            while (i + j < l1.length())
            {
                if (l1.data[i] < l2.data[j])
                {
                    mid = l1.data[i];

                    if (i < l1.length() - 1)
                        i++;
                    else
                        j++;
                }
                else
                {
                    mid = l2.data[j];

                    if (j < l2.length() - 1)
                        j++;
                    else
                        i++;
                }
            }
            cout << mid << endl;
            return mid;
        }
    } // namespace p_04

    void practice_11()
    {
        using namespace p_11;
        auto l1 = SqList<int>((const int[]){11, 13, 15, 17, 19}, 5);
        cout << l1 << endl;

        auto l2 = SqList<int>((const int[]){2, 4, 6, 8, 20}, 5);
        cout << l2 << endl;

        cout << "median of two list : " << median(l1, l2) << endl;
    }

} // namespace practice_2_2