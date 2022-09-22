//
//
//

#ifndef DATA_STRUCTURE_STACK_SHARE_STACK_H
#define DATA_STRUCTURE_STACK_SHARE_STACK_H

#include <iostream>

namespace stack
{
    const int MaxSize = 50;

    template <typename E>
    class ShareStack
    {
    public:
        ShareStack()
        {
            this->data = new E[MaxSize];
            top1 = -1;
            top2 = MaxSize;
        }

        ~ShareStack() { delete[] data; }

        void destroyStack()
        {
            top1 = -1;
            top2 = MaxSize;
        }

        bool push(E e, int stack);

        bool pop(E &e, int stack);

        bool getTop(E &e, int stack);

        bool empty(int stack) const;

        bool overflow() const { return top2 - top1 == 1; }

    public:
        E *data;
        int top1;
        int top2;
    };

    template <typename E>
    bool ShareStack<E>::push(E e, int stack)
    {
        if (overflow())
            return false;
        if (stack == 1)
        {
            data[++top1] = e;
        }
        else
        {
            data[--top2] = e;
        }
        return true;
    }

    template <typename E>
    bool ShareStack<E>::pop(E &e, int stack)
    {
        if (stack == 1)
        {
            if (top1 == -1)
                return false;
            e = data[top1--];
        }
        else
        {
            if (top2 == MaxSize)
                return false;
            e = data[top2++];
        }
        return true;
    }
    template <typename E>
    bool ShareStack<E>::getTop(E &e, int stack)
    {
        if (stack == 1)
        {
            if (top1 == -1)
                return false;
            e = data[top1];
        }
        else
        {
            if (top2 == MaxSize)
                return false;
            e = data[top2];
        }
        return true;
    }

    template <typename E>
    bool ShareStack<E>::empty(int stack) const
    {
        return stack == 1 ? top1 == -1 : top2 == MaxSize;
    }

    template <typename E>
    std::ostream &operator<<(std::ostream &cout, ShareStack<E> &s)
    {
        cout << "stack 1: [";
        for (int i = 0; i <= s.top1; i++)
            cout << s.data[i] << ",";
        cout << "]" << std::endl;
        cout << "stack 2: [";
        for (int i = MaxSize - 1; i >= s.top2; i--)
            cout << s.data[i] << ",";
        cout << "]";
        return cout;
    }

} // namespace stack

#endif // DATA_STRUCTURE_STACK_SHARE_STACK_H