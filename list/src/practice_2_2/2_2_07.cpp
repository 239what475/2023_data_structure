#include "sq_list.h"
#include "practice_2_2.h"

namespace practice_2_2
{
    using namespace list;

    namespace p_07
    {
        using std::cout;
        using std::endl;

        bool combine(SqList<int> &l1, SqList<int> &l2, SqList<int> &l3)
        {
            int i, j, k;
            for (i = j = k = 0; i < l1.length && j < l2.length; k++)
            {
                if (l1.data[i] < l2.data[j])
                {
                    l3.data[k] = l1.data[i++];
                }
                else
                {
                    l3.data[k] = l2.data[j++];
                }
            }
            for (; i < l1.length; i++, k++)
                l3.data[k] = l1.data[i];
            for (; j < l2.length; j++, k++)
                l3.data[k] = l2.data[j];

            l3.length = k;
            return true;
        }
    } // namespace p_04

    void practice_07()
    {
        using namespace p_07;
        SqList<int> l1;
        l1.addAll((const int[]){1, 3, 5}, 3);
        l1.print();

        SqList<int> l2;
        l2.addAll((const int[]){2, 4, 6}, 3);
        l2.print();
        SqList<int> l3;
        if (combine(l1, l2, l3))
        {
            cout << "combine two list" << endl;
            l3.print();
        }
    }

} // namespace practice_2_2