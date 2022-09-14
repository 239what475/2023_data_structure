#include "sq_list.h"
#include "practice_2_2.h"

namespace practice_2_2
{
    using namespace list;

    namespace p_04
    {
        using std::cout;
        using std::endl;

        bool delete_between_s_t_order(SqList<int> &l, int s, int t)
        {
            if (s > t || l.empty())
                return false;

            int num = 0;
            int i = 0;

            for (; i < l.length && l.data[i] < s; i++)
                ;

            for (; i < l.length && l.data[i] <= t; i++)
                num++;

            for (; i < l.length; i++)
                l.data[i - num] = l.data[i];

            l.length -= num;
            return true;
        }
    } // namespace p_04

    void practice_04()
    {
        using namespace p_04;
        SqList<int> l;
        l.addAll((const int[]){1, 2, 3, 4, 5}, 5);
        l.print();
        if (delete_between_s_t_order(l, 2, 3))
        {
            cout << "delete num between 2 and 3" << endl;
            l.print();
        }
    }

} // namespace practice_2_2