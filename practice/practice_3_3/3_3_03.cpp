#include "practice_3_3.h"
#include "sq_stack.h"

namespace practice_3_3
{
    namespace p_03
    {
        double p_1(int x, int n)
        {
            if (n == 0)
                return 1;
            else if (n == 1)
                return 2 * x;
            else
                return 2 * x * p_1(x, n - 1) - 2 * (n - 1) * p_1(x, n - 2);
        }

        double p_2(int x, int n)
        {
            using namespace stack;
            struct data
            {
                int n;
                double val;
            };
            auto s = SqStack<data>();
            double f1 = 1;
            double f2 = 2 * x;
            data top;
            for (int i = n; i >= 2; i--)
                s.push(data{i, 0});
            while (!s.empty())
            {
                s.pop(top);
                top.val = 2 * x * f2 - 2 * (top.n - 1) * f1;
                f1 = f2;
                f2 = top.val;
            }
            if (n == 0)
                return f1;
            return f2;
        }

        double p_3(int x, int n)
        {
            double f1 = 1;
            double f2 = 2 * x;
            double val;
            for (int i = 2; i <= n; i++)
            {
                val = 2 * x * f2 - 2 * (i - 1) * f1;
                if (i == n)
                    return val;
                f1 = f2;
                f2 = val;
            }
            if (n == 0)
                return f1;
            return f2;
        }
    } // namespace p_03

    void practice_03()
    {
        using namespace p_03;
        using std::cout;
        using std::endl;
        cout << p_1(3, 9) << endl;
        cout << p_2(3, 9) << endl;
        cout << p_3(3, 9) << endl;
    }
} // namespace practice_3_3
