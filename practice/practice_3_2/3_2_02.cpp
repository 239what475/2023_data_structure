#include "practice_3_2.h"
#include "sq_queue.h"
#include "sq_stack.h"

namespace practice_3_2
{
    namespace p_02
    {
        using namespace queue;
        using std::cout;
        using std::endl;

        template <typename E>
        void reverse(SqQueue<E> &q)
        {
            using namespace stack;
            auto s = SqStack<E>();
            E e;
            while (!q.empty())
            {
                q.dequeue(e);
                s.push(e);
            }
            while (!s.empty())
            {
                s.pop(e);
                q.enqueue(e);
            }
        }
    } // namespace p_02

    void practice_02()
    {
        using namespace p_02;
        auto q = SqQueue<int>();
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);

        cout << q << endl;
        reverse(q);
        cout << "reverse :" << endl
             << q << endl;
    }
} // namespace practice_3_2
