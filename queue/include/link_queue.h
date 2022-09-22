//
//
//

#ifndef DATA_STRUCTURE_QUEUE_LINK_QUEUE_H
#define DATA_STRUCTURE_QUEUE_LINK_QUEUE_H

#include <iostream>
#include "base_queue.h"

namespace queue
{
    template <typename E>
    struct QueueNode
    {
        E data;
        struct QueueNode *next;
    };

    template <typename E>
    class LinkQueue : public Queue<E>
    {
    public:
        LinkQueue()
        {
            front = rear = new QueueNode<E>();
        }

        ~LinkQueue() {}

        bool enqueue(E e) override;

        bool dequeue(E &e) override;

        bool getHead(E &e) override;

        bool empty() const override { return front == rear; }

    public:
        QueueNode<E> *front = nullptr;
        QueueNode<E> *rear = nullptr;
    };

    template <typename E>
    bool LinkQueue<E>::enqueue(E e)
    {
        rear = rear->next = new QueueNode<E>{e, nullptr};
        return true;
    }

    template <typename E>
    bool LinkQueue<E>::dequeue(E &e)
    {
        if (empty())
            return false;
        e = front->next->data;

        auto temp = front->next;
        front->next = front->next->next;
        if (rear == temp)
            rear = front;
        delete temp;
        return true;
    }

    template <typename E>
    bool LinkQueue<E>::getHead(E &e)
    {
        if (empty())
            return false;
        e = front->data;
        return true;
    }

    template <typename E>
    std::ostream &operator<<(std::ostream &cout, LinkQueue<E> &q)
    {
        cout << "[";
        auto p = q.front->next;
        while (p)
        {
            cout << p->data << ",";
            p = p->next;
        }
        cout << "]";
        return cout;
    }

} // namespace queue

#endif // DATA_STRUCTURE_QUEUE_LINK_QUEUE_H