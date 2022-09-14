#include "sq_list.h"
#include "practice_2_2.h"

namespace practice_2_2
{
    using namespace list;

    namespace p_12
    {
        using std::cout;
        using std::endl;

        int find_main(SqList<int> &l)
        {
            int main_elem = l.data[0];
            int repeat = 1;
            for (int i = 1; i < l.length; i++)
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
                for (int i = repeat = 0; i < l.length; i++)
                    if (l.data[i] == main_elem)
                        repeat++;
                        
            if (repeat > l.length / 2)
                return main_elem;
            else
                return -1;
        }
    } // namespace p_04

    void practice_12()
    {
        using namespace p_12;
        SqList<int> l;
        l.addAll((const int[]){0, 5, 5, 3, 5, 1, 5, 7}, 8);
        l.print();
        cout << "find main:" << find_main(l) << endl;
    }

} // namespace practice_2_2