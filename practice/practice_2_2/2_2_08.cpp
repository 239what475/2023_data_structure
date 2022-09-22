#include "sq_list.h"
#include "practice_2_2.h"

namespace practice_2_2
{
    namespace p_08
    {
        using namespace list;
        using std::cout;
        using std::endl;

        void reorder(SqList<int> &l, int m, int n)
        {
            int temp;
            for (int i = 0; i < l.length() / 2; i++)
            {
                temp = l.data[i];
                l.data[i] = l.data[l.length() - i - 1];
                l.data[l.length() - 1 - i] = temp;
            }
            for (int i = 0; i < n / 2; i++)
            {
                temp = l.data[i];
                l.data[i] = l.data[n - i - 1];
                l.data[n - 1 - i] = temp;
            }
            for (int i = 0; i < m / 2; i++)
            {
                temp = l.data[n + i];
                l.data[n + i] = l.data[l.length() - i - 1];
                l.data[l.length() - 1 - i] = temp;
            }
        }
    } // namespace p_08

    void practice_08()
    {
        using namespace p_08;
        auto l = SqList<int>((const int[]){1, 2, 3, 4, 7, 8, 9}, 7);
        cout << l << endl;

        reorder(l, 4, 3);
        cout << "reorder list" << endl
             << l << endl;
    }

} // namespace practice_2_2