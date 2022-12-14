#include "sq_list.h"
#include "practice_2_2.h"

namespace practice_2_2
{
    namespace p_06
    {
        using namespace list;
        using std::cout;
        using std::endl;

        bool delete_repeat(SqList<int> &l)
        {
            if (l.empty())
                return false;

            int pre = l.data[0];
            int repeat = 0;

            for (int i = 1; i < l.length(); i++)
            {
                if (l.data[i] == pre)
                    repeat++;
                else
                    pre = l.data[i];

                l.data[i - repeat] = l.data[i];
            }
            l.length() -= repeat;

            // int i, j;
            // for (i = 0, j = 1; j < l.length; j++)
            //     if (l.data[i] != l.data[j])
            //         l.data[++i] = l.data[j];
            // l.length = i + 1;

            return true;
        }
    } // namespace p_06

    void practice_06()
    {
        using namespace p_06;
        auto l = SqList<int>((const int[]){1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 5}, 11);
        cout << l << endl;

        if (delete_repeat(l))
        {
            cout << "delete repeat num" << endl
                 << l << endl;
        }
    }

} // namespace practice_2_2