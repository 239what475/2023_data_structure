#include "sq_list.h"
#include "practice_2_2.h"

namespace practice_2_2
{
    namespace p_03
    {
        using namespace list;
        using std::cout;
        using std::endl;

        void delete_x(SqList<int> &l, int x)
        {
            int num = 0;
            for (int i = 0; i < l.length(); i++)
            {
                if (l.data[i] == x)
                    num++;
                else
                    l.data[i - num] = l.data[i];
            }
            l.length() -= num;

            // for (int i = 0; i < l.length; i++)
            // {
            //     if (l.data[i] = !x)
            //     {
            //         l.data[num] = l.data[i];
            //         num++;
            //     }
            // }
            // l.length = num;
        }
    } // namespace p_03

    void practice_03()
    {
        using namespace p_03;
        auto l = SqList<int>((const int[]){1, 2, 3, 1, 4}, 5);
        cout << l << endl;
        delete_x(l, 1);
        cout << l << endl;
    }

} // namespace practice_2_2
