//
//
//

#ifndef DATA_STRUCTURE_QUEUE_SQ_QUEUE_WITH_TAG_H
#define DATA_STRUCTURE_QUEUE_SQ_QUEUE_WITH_TAG_H

#include <iostream>
#include "sq_queue.h"

namespace queue
{
    template <typename E>
    class SqQueueWithTag : public SqQueue<E>
    {
    public:
        SqQueueWithTag() : SqQueue<E>() {}

        bool enqueue(E e) override;

        bool dequeue(E &e) override;

        bool empty() const override
        {
            return tag == 0 && this->front == this->rear;
        }

    public:
        // 0 = empty
        int tag = 0;
    };

    template <typename E>
    bool SqQueueWithTag<E>::enqueue(E e)
    {
        if (tag && this->front == this->rear)
            return false;
        this->data[this->rear] = e;
        this->rear = (this->rear + 1) % MaxSize;
        tag = 1;
        return true;
    }

    template <typename E>
    bool SqQueueWithTag<E>::dequeue(E &e)
    {
        if (empty())
            return false;
        e = this->data[this->front];
        this->front = (this->front + 1) % MaxSize;
        if (this->front == this->rear)
            tag = 0;
        return true;
    }

    template <typename E>
    std::ostream &operator<<(std::ostream &cout, SqQueueWithTag<E> &q)
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

#endif // DATA_STRUCTURE_QUEUE_SQ_QUEUE_WITH_TAG_H