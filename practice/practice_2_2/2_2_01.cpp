#include "practice_2_2.h"
#include "sq_list.h"

namespace practice_2_2
{

    namespace p_01
    {
        using namespace list;
        using std::cout;
        using std::endl;

        bool delete_min(SqList<int> &l, int &e)
        {
            if (l.empty())
                return false;

            int min = l.data[0];
            int index = 0;

            // find index and value of minnium element by comparison
            for (int i = 1; i < l.length(); i++)
            {
                if (min > l.data[i])
                {
                    min = l.data[i];
                    index = i;
                }
            }

            e = min;
            l.data[index] = l.data[l.length() - 1];
            l.length()--;

            return true;
        }
    } // namespace practice_01

    void practice_01()
    {
        using namespace p_01;
        auto l = SqList<int>((const int[]){3, 2, 1, 4}, 4);
        cout << l << endl;

        int e;
        if (delete_min(l, e))
        {
            cout << "min element : " << e << endl
                 << l << endl;
        }
        else
        {
            cout << "empty list" << endl;
        }
    }
} // namespace practice_2_2
