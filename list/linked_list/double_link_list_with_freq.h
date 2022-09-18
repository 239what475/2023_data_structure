//
//
//

#ifndef DATA_STRUCTURE_LIST_DOUBLE_LINK_LIST_WITH_FREQ_H
#define DATA_STRUCTURE_LIST_DOUBLE_LINK_LIST_WITH_FREQ_H

#include <iostream>
#include "double_link_list.h"

namespace list
{
    template <typename E>
    class DoubleLinkNodeWithFreq : public DoubleLinkNode<E>
    {
    public:
        DoubleLinkNodeWithFreq() : DoubleLinkNode<E>() {}

        DoubleLinkNodeWithFreq(const E data) : DoubleLinkNode<E>(data) {}
        DoubleLinkNodeWithFreq(const E data, DoubleLinkNodeWithFreq<E> *prior, DoubleLinkNodeWithFreq<E> *next = nullptr)
            : DoubleLinkNode<E>(data)
        {
            this->next = next;
            this->prior = prior;
        }

        DoubleLinkNodeWithFreq(const E l[], int n, bool with_head_node = true);

        void destroyList() { DoubleLinkList<E>::destroyList(); }

    public:
        int freq = 0;
        DoubleLinkNodeWithFreq<E> *next = nullptr;
        DoubleLinkNodeWithFreq<E> *prior = nullptr;
    };

    template <typename E>
    DoubleLinkNodeWithFreq<E>::DoubleLinkNodeWithFreq(const E l[], int n, bool with_head_node)
    {
        this->is_head_node = with_head_node;

        DoubleLinkNodeWithFreq<E> *r;
        // 使用尾插法
        if (with_head_node)
        {
            // 带头结点
            r = this->next = new DoubleLinkNodeWithFreq<E>(l[0], this);
        }
        else
        {
            // 不带头结点
            r = this;
            this->data = l[0];
        }

        for (int i = 1; i < n; i++)
            r = r->next = new DoubleLinkNodeWithFreq<E>(l[i], r);
    }

    template <typename E>
    std::ostream &operator<<(std::ostream &cout, DoubleLinkNodeWithFreq<E> &l)
    {
        cout << "[";
        auto p = l.is_head_node ? l.next : &l;
        while (p)
        {
            cout << p->data << ",";
            p = p->next;
        }
        cout << "]";
        return cout;
    }

    template <typename E>
    using DoubleLinkListWithFreq = DoubleLinkNodeWithFreq<E>;
}

#endif // DATA_STRUCTURE_LIST_DOUBLE_LINK_LIST_WITH_FREQ_H