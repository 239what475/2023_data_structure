#include "sq_list.h"
#include "practice_2_2.h"

namespace practice_2_2
{
    namespace p_12
    {
        using namespace list;
        using std::cout;
        using std::endl;

        int find_main(SqList<int> &l)
        {
            int main_elem = l.data[0];
            int repeat = 1;
            for (int i = 1; i < l.length(); i++)
            {
                if (l.data[i] != main_elem)
                {
                    repeat--;
                    if (repeat == 0)
                    {
                        main_elem = l.data[i];
                        repeat++;
                    }
                }
                else
                    repeat++;
            }

            if (repeat > 0)
                for (int i = repeat = 0; i < l.length(); i++)
                    if (l.data[i] == main_elem)
                        repeat++;

            if (repeat > l.length() / 2)
                return main_elem;
            else
                return -1;
        }
    } // namespace p_12

    void practice_12()
    {
        using namespace p_12;
        auto l = SqList<int>((const int[]){0, 5, 5, 3, 5, 1, 5, 7}, 8);
        cout << l << endl;

        cout << "find main:" << find_main(l) << endl;
    }

} // namespace practice_2_2