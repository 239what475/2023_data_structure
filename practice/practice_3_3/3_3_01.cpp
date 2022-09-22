#include "practice_3_3.h"
#include "sq_stack.h"

namespace practice_3_3
{
    namespace p_01
    {
        using namespace stack;

        bool judge(const char *str)
        {
            auto s = SqStack<char>();
            char top;
            while (*str != '\0')
            {
                switch (*str)
                {
                case '(':
                case '[':
                case '{':
                    s.push(*str);
                    break;
                case ')':
                    s.pop(top);
                    if (top != '(')
                        return false;
                    break;
                case ']':
                    s.pop(top);
                    if (top != '[')
                        return false;
                    break;
                case '}':
                    s.pop(top);
                    if (top != '{')
                        return false;
                    break;
                default:
                    return false;
                }
                str++;
            }
            return s.empty();
        }
    } // namespace p_01

    void practice_01()
    {
        using namespace p_01;
        auto str = "([]{[})";
        std::cout << str << " is symmetry ? " << (judge(str) ? "yes" : "no") << std::endl;
    }
} // namespace practice_3_3
