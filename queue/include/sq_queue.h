//
//
//

#ifndef DATA_STRUCTURE_QUEUE_SQ_QUEUE_H
#define DATA_STRUCTURE_QUEUE_SQ_QUEUE_H

#include <iostream>
#include "base_queue.h"

namespace queue
{
    const int MaxSize = 50;

    template <typename E>
    class SqQueue : public Queue<E>
    {
    public:
        SqQueue()
        {
            this->data = new E[MaxSize];
        }

        ~SqQueue() { delete[] data; }

        bool enqueue(E e) override;

        bool dequeue(E &e) override;

        bool getHead(E &e) override;

        bool empty() const override { return front == rear; }

    public:
        E *data;
        int front = 0;
        int rear = 0;
    };

    template <typename E>
    bool SqQueue<E>::enqueue(E e)
    {
        if (front == (rear + 1) % MaxSize)
            return false;
        data[rear] = e;
        rear = (rear + 1) % MaxSize;
        return true;
    }

    template <typename E>
    bool SqQueue<E>::dequeue(E &e)
    {
        if (empty())
            return false;
        e = data[front];
        front = (front + 1) % MaxSize;
        return true;
    }
    
    template <typename E>
    bool SqQueue<E>::getHead(E &e)
    {
        if (empty())
            return false;
        e = data[front];
        return true;
    }

    template <typename E>
    std::ostream &operator<<(std::ostream &cout, SqQueue<E> &q)
    {
        int length = q.rear - q.front;
        length = length < 0 ? length + MaxSize : length;
        cout << "[";
        for (int i = 0; i < length; i++)
            cout << q.data[(i + q.front) % MaxSize] << ",";
        cout << "]";
        return cout;
    }

} // namespace stack

#endif // DATA_STRUCTURE_QUEUE_SQ_QUEUE_H