//
//
//

#ifndef DATA_STRUCTURE_STACK_SQ_STACK_H
#define DATA_STRUCTURE_STACK_SQ_STACK_H

#include <iostream>
#include "base_stack.h"

namespace stack
{
    const int MaxSize = 50;

    template <typename E>
    class SqStack : public Stack<E>
    {
    public:
        SqStack()
        {
            this->data = new E[MaxSize];
            top = -1;
        }

        ~SqStack() { delete[] data; }

        void destroyStack() override { top = -1; }

        bool push(E e) override;

        bool pop(E &e) override;

        bool getTop(E &e) override;

        bool empty() const override { return top == -1; }

        bool overflow() const override { return top == MaxSize - 1; }

    public:
        E *data;
        int top;
    };

    template <typename E>
    bool SqStack<E>::push(E e)
    {
        if (overflow())
            return false;

        data[++top] = e;
        return true;
    }

    template <typename E>
    bool SqStack<E>::pop(E &e)
    {
        if (empty())
            return false;
        e = data[top--];

        return true;
    }
    template <typename E>
    bool SqStack<E>::getTop(E &e)
    {
        if (empty())
            return false;
        e = data[top];
        return true;
    }

    template <typename E>
    std::ostream &operator<<(std::ostream &cout, SqStack<E> &s)
    {
        cout << "[";
        for (int i = 0; i <= s.top; i++)
            cout << s.data[i] << ",";
        cout << "]";
        return cout;
    }

} // namespace stack

#endif // DATA_STRUCTURE_STACK_SQ_STACK_H