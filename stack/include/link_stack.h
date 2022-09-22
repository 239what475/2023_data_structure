//
//
//

#ifndef DATA_STRUCTURE_STACK_LINK_STACK_H
#define DATA_STRUCTURE_STACK_LINK_STACK_H

#include <iostream>
#include "base_stack.h"

namespace stack
{
    template <typename E>
    struct StackNode
    {
        E data;
        struct StackNode *next;
    };

    template <typename E>
    class LinkStack : public Stack<E>
    {
    public:
        void destroyStack() override;

        bool push(E e) override;

        bool pop(E &e) override;

        bool getTop(E &e) override;

        bool empty() const override { return list == nullptr; }

        // 正常情况不会满
        bool overflow() const override { return false; }

    public:
        StackNode<E> *list = nullptr;
    };

    template <typename E>
    void LinkStack<E>::destroyStack()
    {
        while (list)
        {
            auto temp = list->next;
            delete list;
            list = temp;
        }
    }

    template <typename E>
    bool LinkStack<E>::push(E e)
    {
        list = new StackNode<E>{e, list};
        return true;
    }

    template <typename E>
    bool LinkStack<E>::pop(E &e)
    {
        if (!list)
            return false;
        e = list->data;
        auto temp = list->next;
        delete list;
        list = temp;
        return true;
    }

    template <typename E>
    bool LinkStack<E>::getTop(E &e)
    {
        if (!list)
            return false;
        e = list->data;
        return true;
    }

    template <typename E>
    std::ostream &operator<<(std::ostream &cout, LinkStack<E> &s)
    {
        cout << "[";
        auto p = s.list;
        while (p)
        {
            cout << p->data << ",";
            p = p->next;
        }
        cout << "]";
        return cout;
    }

} // namespace stack

#endif // DATA_STRUCTURE_STACK_LINK_STACK_H