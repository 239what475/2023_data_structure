#include "sq_list.h"
#include "practice_2_2.h"
#include <string>

namespace practice_2_2
{
    using namespace list;

    namespace p_10
    {
        using std::cout;
        using std::endl;
        using std::string;

        void reverse(SqList<string> &l, int from, int to)
        {
            string temp;
            for (int i = 0; i < (to - from + 1) / 2; i++)
            {
                temp = l.data[from + i];
                l.data[from + i] = l.data[to - i];
                l.data[to - i] = temp;
            }
        }

        void reorder(SqList<string> &l, int p)
        {
            string temp;
            reverse(l, 0, l.length - 1);
            reverse(l,0,p-1);
            reverse(l,p,l.length-1);
        }
    } // namespace p_04

    void practice_10()
    {
        using namespace p_10;
        SqList<string> l;
        const string li[] = {"a1", "a2", "a3", "a4", "a5", "a6", "a7"};
        l.addAll(li, 7);
        l.print();
        reorder(l, 4);
        cout << "reorder list" << endl;
        l.print();
    }

} // namespace practice_2_2