//
//
//

#ifndef DATA_STRUCTURE_LIST_CIRCULAR_LINK_LIST_H
#define DATA_STRUCTURE_LIST_CIRCULAR_LINK_LIST_H

#include <iostream>
#include "double_link_list.h"

namespace list
{
    template <typename E>
    class CircularDoubleLinkNode : public DoubleLinkNode<E>
    {
    public:
        CircularDoubleLinkNode() : DoubleLinkNode<E>() {}

        CircularDoubleLinkNode(const E data) : DoubleLinkNode<E>(data) {}

        CircularDoubleLinkNode(const E data, CircularDoubleLinkNode<E> *prior, CircularDoubleLinkNode<E> *next = nullptr)
            : DoubleLinkNode<E>(data)
        {
            this->next = next;
            this->prior = prior;
        }

        CircularDoubleLinkNode(const E l[], int n, bool with_head_node = true);

        void destroyList() override;

        // override
        CircularDoubleLinkNode<E> const *locateElem(E e) const;

        CircularDoubleLinkNode<E> const *getElem(int i) const;

        bool add(E e) override;

        bool listInsert(int i, E e) override;

        bool listDelete(int i, E &e) override;

        // 只对带头结点的有效
        bool empty() const override { return this->next == this; }

        int length();

    public:
        CircularDoubleLinkNode<E> *next = nullptr;
        CircularDoubleLinkNode<E> *prior = nullptr;
    };

    template <typename E>
    CircularDoubleLinkNode<E>::CircularDoubleLinkNode(const E l[], int n, bool with_head_node)
    {
        this->is_head_node = with_head_node;

        CircularDoubleLinkNode<E> *r;

        // 使用尾插法
        if (with_head_node)
        {
            // 带头结点
            r = this->next = new CircularDoubleLinkNode<E>(l[0], this);
        }
        else
        {
            // 不带头结点
            this->data = l[0];
            r = this;
        }

        for (int i = 1; i < n - 1; i++)
            r = r->next = new CircularDoubleLinkNode<E>(l[i], r);
        r->next = new CircularDoubleLinkNode<E>(l[n - 1], r, this);
        this->prior = r->next;
    }

    template <typename E>
    void CircularDoubleLinkNode<E>::destroyList()
    {
        CircularDoubleLinkNode<E> *temp = nullptr;
        while (this->next != this)
        {
            temp = this->next;
            this->next = this->next->next;
            delete temp;
        }
        this->prior = this;
        std::cout << "delete double link list success" << std::endl;
    }

    template <typename E>
    CircularDoubleLinkNode<E> const *CircularDoubleLinkNode<E>::locateElem(E e) const
    {
        if (!this->is_head_node && this->data == e)
            return this;

        auto p = this->next;
        while (p != this && p->data != e)
        {
            p = p->next;
        }
        return p == this ? nullptr : p;
    }

    template <typename E>
    CircularDoubleLinkNode<E> const *CircularDoubleLinkNode<E>::getElem(int i) const
    {
        if (!this->is_head_node && i == 1)
            return this;

        int j = 1;
        auto p = this->is_head_node ? this->next : this;
        while (p->next != this && j < i)
        {
            p = p->next;
            j++;
        }
        if (p->next == this && i > j)
            return nullptr;

        return p;
    }

    template <typename E>
    bool CircularDoubleLinkNode<E>::add(E e)
    {
        auto p = this;
        while (p->next != this)
            p = p->next;
        p->next = new CircularDoubleLinkNode<E>(e, p, this);
        this->prior = p->next;
        return true;
    }

    template <typename E>
    bool CircularDoubleLinkNode<E>::listInsert(int i, E e)
    {
        if (this->is_head_node)
        {
            auto k = 0;
            auto p = this;
            while (p->next != this && k < i - 1)
            {
                k++;
                p = p->next;
            }
            if (k == i - 1)
            {
                p->next = new CircularDoubleLinkNode<E>(e, p, p->next);
                p->next->next->prior = p->next;
                return true;
            }
            else
                return false;
        }
        else
        {
            if (i == 1)
            {
                this->next = new CircularDoubleLinkNode<E>(this->data, this, this->next);
                this->next->next->prior = this->next;
                this->data = e;
                return true;
            }

            auto k = 1;
            auto p = this;
            while (p->next != this && k < i - 1)
            {
                k++;
                p = p->next;
            }
            if (k == i - 1)
            {
                p->next = new CircularDoubleLinkNode<E>(e, p, p->next);
                p->next->next->prior = p->next;
                return true;
            }
            else
                return false;
        }
    }

    template <typename E>
    bool CircularDoubleLinkNode<E>::listDelete(int i, E &e)
    {
        auto k = 1;
        auto p = this->is_head_node ? this->next : this;
        while (p->next != this && k < i - 1)
            k++;
        if (k == i - 1 && p->next != this)
        {
            auto node = p->next;
            p->next = p->next->next;
            p->next->prior = p;
            e = node->data;
            delete node;
            return true;
        }
        else
            return false;
    }

    template <typename E>
    int CircularDoubleLinkNode<E>::length()
    {
        auto p = this->is_head_node ? this->next : this;
        int l = 1;
        while (p->next != this)
        {
            l++;
            p = p->next;
        }

        return l;
    }

    template <typename E>
    std::ostream &operator<<(std::ostream &cout, CircularDoubleLinkNode<E> &l)
    {
        cout << "[";
        auto p = l.is_head_node ? l.next : &l;
        while (p->next != &l)
        {
            cout << p->data << ",";
            p = p->next;
        }
        cout << p->data << ",";
        cout << "]";
        return cout;
    }

    template <typename E>
    using CircularDoubleLinkList = CircularDoubleLinkNode<E>;
} // namespace list

#endif // DATA_STRUCTURE_LIST_CIRCULAR_LINK_LIST_H