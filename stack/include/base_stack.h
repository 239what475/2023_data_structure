//
//
//

#ifndef DATA_STRUCTURE_STACK_BASE_STACK_H
#define DATA_STRUCTURE_STACK_BASE_STACK_H

namespace stack
{
    template <typename E>
    class Stack
    {
    public:
        virtual ~Stack() = default;

        virtual void destroyStack() = 0;

        virtual bool push(E e) = 0;

        virtual bool pop(E &e) = 0;

        virtual bool getTop(E &e) = 0;

        virtual bool empty() const = 0;

        virtual bool overflow() const = 0;
    };
} // namespace stack

#endif // DATA_STRUCTURE_STACK_BASE_STACK_H
