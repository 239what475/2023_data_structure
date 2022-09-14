#include "sq_list.h"
#include "practice_2_2.h"

namespace practice_2_2
{
    using namespace list;

    namespace p_13
    {
        using std::cout;
        using std::endl;

        int find_min_distance(SqList<int> &l)
        {
            int positive_nums[l.length] = {0};
            for (int i = 0; i < l.length; i++)
                if (l.data[i] > 0 && l.data[i] <= l.length)
                    positive_nums[l.data[i] - 1] = 1;

            for (int i = 0; i < l.length; i++)
                if (positive_nums[i] == 0)
                    return i + 1;

            return l.length + 1;
        }
    } // namespace p_04

    void practice_13()
    {
        using namespace p_13;
        SqList<int> l1;
        l1.addAll((const int[]){-5, 3, 2, 3}, 4);
        l1.print();
        cout << "find min postitive num:" << find_min_distance(l1) << endl;

        SqList<int> l2;
        l2.addAll((const int[]){1, 2, 3, 4}, 4);
        l2.print();
        cout << "find min postitive num:" << find_min_distance(l2) << endl;
    }

} // namespace practice_2_2