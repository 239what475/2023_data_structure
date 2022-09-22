#include "practice_3_3.h"
#include "sq_stack.h"

namespace practice_3_3
{
    namespace p_02
    {
        using namespace stack;

        void sort(char *str)
        {
            auto s = SqStack<char>();
            auto p = str;
            char top;
            int n;
            while (*str != '\0')
            {
                if (*str == '1')
                    *(p++) = *str;
                else
                    s.push(*str);
                str++;
            }
            while (*p != '\0')
            {
                s.pop(top);
                *(p++) = top;
            }
        }
    } // namespace p_02

    void practice_02()
    {
        using namespace p_02;
        using std::cout;
        using std::endl;
        char str[] = "1010101";
        cout << "sort " << str << " -> " << endl;
        sort(str);
        cout << str << endl;
    }
} // namespace practice_3_3
