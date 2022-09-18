//
//
//

#ifndef DATA_STRUCTURE_LIST_CIRCULAR_LINK_LIST_H
#define DATA_STRUCTURE_LIST_CIRCULAR_LINK_LIST_H

#include <iostream>
#include "link_list.h"

namespace list
{
    template <typename E>
    class CircularLinkNode : public LinkNode<E>
    {
    public:
        CircularLinkNode() : LinkNode<E>() {}

        CircularLinkNode(const E data) : LinkNode<E>(data) {}

        CircularLinkNode(const E data, CircularLinkNode<E> *next) : LinkNode<E>(data)
        {
            this->next = next;
        }

        CircularLinkNode(const E l[], int n, bool with_head_node = true);

        void destroyList() override;

        // override
        CircularLinkNode<E> const *locateElem(E e) const;

        CircularLinkNode<E> const *getElem(int i) const;

        bool add(E e) override;

        bool listInsert(int i, E e) override;

        bool listDelete(int i, E &e) override;

        // 只对带头结点的有效
        bool empty() const override { return this->next == this; }

        int length();

    public:
        // 覆盖 LinkList::next
        CircularLinkNode<E> *next = nullptr;
    };

    template <typename E>
    CircularLinkNode<E>::CircularLinkNode(const E l[], int n, bool with_head_node)
    {
        this->is_head_node = with_head_node;

        CircularLinkNode<E> *r;

        // 使用尾插法
        if (with_head_node)
        {
            // 带头结点
            r = this->next = new CircularLinkNode<E>(l[0]);
        }
        else
        {
            // 不带头结点
            this->data = l[0];
            r = this;
        }

        for (int i = 1; i < n - 1; i++)
            r = r->next = new CircularLinkNode<E>(l[i]);
        r->next = new CircularLinkNode<E>(l[n - 1], this);
    }

    template <typename E>
    void CircularLinkNode<E>::destroyList()
    {
        CircularLinkNode<E> *temp = nullptr;
        while (this->next != this)
        {
            temp = this->next;
            this->next = this->next->next;
            delete temp;
        }
        std::cout << "delete double link list success" << std::endl;
    }

    template <typename E>
    CircularLinkNode<E> const *CircularLinkNode<E>::locateElem(E e) const
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
    CircularLinkNode<E> const *CircularLinkNode<E>::getElem(int i) const
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
    bool CircularLinkNode<E>::add(E e)
    {
        auto p = this;
        while (p->next != this)
            p = p->next;
        p->next = new CircularLinkNode<E>(e, this);
        return true;
    }

    template <typename E>
    bool CircularLinkNode<E>::listInsert(int i, E e)
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
                p->next = new CircularLinkNode<E>(e, p->next);
                return true;
            }
            else
                return false;
        }
        else
        {
            if (i == 1)
            {
                this->next = new CircularLinkNode<E>(this->data, this->next);
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
                p->next = new CircularLinkNode<E>(e, p->next);
                return true;
            }
            else
                return false;
        }
    }

    template <typename E>
    bool CircularLinkNode<E>::listDelete(int i, E &e)
    {
        auto k = 1;
        auto p = this->is_head_node ? this->next : this;
        while (p->next != this && k < i - 1)
            k++;
        if (k == i - 1 && p->next != this)
        {
            auto node = p->next;
            p->next = p->next->next;
            e = node->data;
            delete node;
            return true;
        }
        else
            return false;
    }

    template <typename E>
    int CircularLinkNode<E>::length()
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
    std::ostream &operator<<(std::ostream &cout, CircularLinkNode<E> &l)
    {
        cout << "[";
        auto p = l.is_head_node ? l.next : &l;
        if (!l.empty())
        {
            while (p->next != &l)
            {
                cout << p->data << ",";
                p = p->next;
            }
            cout << p->data << ",";
        }
        cout << "]";

        return cout;
    }

    template <typename E>
    using CircularLinkList = CircularLinkNode<E>;
}

#endif // DATA_STRUCTURE_LIST_CIRCULAR_LINK_LIST_H