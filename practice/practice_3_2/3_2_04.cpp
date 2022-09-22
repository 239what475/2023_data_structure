#include "practice_3_2.h"
#include "link_queue.h"

namespace queue
{
    template <typename E>
    class LinkQueueNoDelete : public LinkQueue<E>
    {
    public:
        bool enqueue(E e) override;

        bool dequeue(E &e) override;
    };

    template <typename E>
    bool LinkQueueNoDelete<E>::enqueue(E e)
    {
        if (this->rear->next)
            this->rear->next->data = e;
        else
            this->rear->next = new QueueNode<E>{e, nullptr};
        this->rear = this->rear->next;
        return true;
    }

    template <typename E>
    bool LinkQueueNoDelete<E>::dequeue(E &e)
    {
        if (this->front == this->rear)
            return false;
        e = this->front->next->data;
        auto temp = this->front->next;
        this->front->next = this->front->next->next;
        if (this->rear == temp)
            this->rear = this->front;
        temp->next = this->rear->next;
        this->rear->next = temp;
        return true;
    }

    template <typename E>
    std::ostream &operator<<(std::ostream &cout, LinkQueueNoDelete<E> &q)
    {
        cout << "[";
        if (!q.empty())
        {
            auto p = q.front->next;
            while (p != q.rear)
            {
                cout << p->data << ",";
                p = p->next;
            }
            cout << p->data << ",";
        }
        cout << "]";
        return cout;
    }

} // namespace queue

namespace practice_3_2
{
    void practice_04()
    {
        using namespace queue;
        using std::cout;
        using std::endl;

        auto q = LinkQueueNoDelete<int>();
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