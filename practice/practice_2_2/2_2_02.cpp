#include "sq_list.h"
#include "practice_2_2.h"

namespace practice_2_2
{
    namespace p_02
    {
        using namespace list;
        using std::cout;
        using std::endl;

        void reverse(SqList<int> &l)
        {
            int temp;
            for (int i = 0; i < l.length() / 2; i++)
            {
                temp = l.data[i];
                l.data[i] = l.data[l.length() - 1 - i];
                l.data[l.length() - 1 - i] = temp;
            }
        }
    } // namespace practice_02

    void practice_02()
    {
        using namespace p_02;
        auto l = SqList<int>((const int[]){1, 2, 3, 4}, 4);
        cout << l << endl;
        reverse(l);
        cout << l << endl;
    }
} // namespace practice_2_2
