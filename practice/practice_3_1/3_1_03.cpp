#include "practice_3_1.h"
#include <iostream>

namespace practice_3_1
{
    namespace p_03
    {
        using std::cout;
        using std::endl;

        bool judge(const char l[])
        {
            auto action = 0;
            auto p = l;
            while (*p != '\0')
            {
                if (*p == 'I')
                {
                    action++;
                }
                else
                {
                    action--;
                    if (action < 0)
                        return false;
                }
                p++;
            }

            return action == 0;
        }
    } // namespace p_03

    void practice_03()
    {
        using namespace p_03;

        auto l1 = "IOIIOIOO";
        auto l2 = "IOOIOIIO";
        auto l3 = "IIIOIOIO";
        auto l4 = "IIIOOIOO";

        cout << "l1 : " << (judge(l1) ? "legal" : "illegal") << endl;
        cout << "l2 : " << (judge(l2) ? "legal" : "illegal") << endl;
        cout << "l3 : " << (judge(l3) ? "legal" : "illegal") << endl;
        cout << "l4 : " << (judge(l4) ? "legal" : "illegal") << endl;
    }
} // namespace practice_3_1
