#include "practice_3_3.h"
#include "sq_queue.h"

namespace practice_3_3
{
    namespace p_04
    {
        using namespace queue;
        using std::cout;
        using std::endl;

        SqQueue<char> q;
        SqQueue<char> q1;
        SqQueue<char> q2;

        void embark()
        {
            int j = 0;
            int i = 0;
            char x;
            while (j < 10)
            {
                if (i < 4 && !q1.empty())
                {
                    q1.dequeue(x);
                    q.enqueue(x);
                    j++;
                    i++;
                }
                else if (i == 4 && !q2.empty())
                {
                    q2.dequeue(x);
                    q.enqueue(x);
                    j++;
                    i = 0;
                }
                else if (i < 4 && !q2.empty())
                {
                    q2.dequeue(x);
                    q.enqueue(x);
                    j++;
                    i = 0;
                }
                if (q1.empty() && q2.empty())
                    break;
            }
        }

        void outputAndClearEmbarkQueue()
        {
            char x;
            cout << "[";
            while (!q.empty())
            {
                q.dequeue(x);
                cout << x << ",";
            }
            cout << "]" << endl;
        }
    } // namespace p_04

    void practice_04()
    {
        using namespace p_04;
        char str[] = "1110101100111011111";
        cout << str << endl;
        auto p = str;
        while (*p != '\0')
        {
            if (*p == '1')
                q1.enqueue(*(p++));
            else
                q2.enqueue(*(p++));
        }
        embark();
        outputAndClearEmbarkQueue();
        embark();
        outputAndClearEmbarkQueue();
        cout << "q1: " << q1 << endl
             << "q2" << q2 << endl;
    }
} // namespace practice_3_3
