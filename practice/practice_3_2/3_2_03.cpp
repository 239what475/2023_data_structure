#include "practice_3_2.h"
#include "base_queue.h"
#include "sq_stack.h"

namespace queue
{
    const int MaxSize = 50;

    template <typename E>
    class QueueByStack : public Queue<E>
    {
    public:
        ~QueueByStack() {}

        bool enqueue(E e) override;

        bool dequeue(E &e) override { return out.pop(e); }

        bool getHead(E &e) override { return out.getTop(e); }

        bool empty() const override { return out.empty(); }

    public:
        stack::SqStack<E> in;
        stack::SqStack<E> out;
    };

    template <typename E>
    bool QueueByStack<E>::enqueue(E e)
    {
        if (out.overflow())
            return false;
        E t;
        while (!out.empty())
        {
            out.pop(t);
            in.push(t);
        }
        in.push(e);
        while (!in.empty())
        {
            in.pop(t);
            out.push(t);
        }
        return true;
    }

    template <typename E>
    std::ostream &operator<<(std::ostream &cout, QueueByStack<E> &q)
    {
        return cout << q.out;
    }

} // namespace stack

namespace practice_3_2
{
    void practice_03()
    {
        using namespace queue;
        using std::cout;
        using std::endl;

        auto q = QueueByStack<int>();
        cout << "enqueue 1:" << endl;
        q.enqueue(1);
        cout << q << endl;
        cout << "enqueue 2:" << endl;
        q.enqueue(2);
        cout << q << endl;
        cout << "dequeue:" << endl;
        int a;
        q.dequeue(a);
        cout << q << endl;
        cout << "is empty ? " << (q.empty() ? "yes" : "no") << endl
             << endl;
    }
} // namespace practice_3_2