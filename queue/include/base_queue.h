//
//
//

#ifndef DATA_STRUCTURE_QUEUE_BASE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_BASE_QUEUE_H

namespace queue
{
    template <typename E>
    class Queue
    {
    public:
        virtual ~Queue() = default;

        virtual bool enqueue(E e) = 0;

        virtual bool dequeue(E &e) = 0;

        virtual bool getHead(E &e) = 0;

        virtual bool empty() const = 0;
    };
} // namespace queue

#endif // DATA_STRUCTURE_QUEUE_BASE_QUEUE_H
