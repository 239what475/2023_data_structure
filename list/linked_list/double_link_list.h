//
//
//

#ifndef DATA_STRUCTURE_LIST_DOUBLE_LINK_LIST_H
#define DATA_STRUCTURE_LIST_DOUBLE_LINK_LIST_H

#include <iostream>
#include "list.h"

namespace list
{
    template <typename E>
    class DoubleLinkNode : public List<E>
    {
    public:
        DoubleLinkNode()
        {
            is_head_node = true;
        }

        DoubleLinkNode(const E data)
        {
            this->data = data;
        }
        DoubleLinkNode(const E data, DoubleLinkNode<E> *prior, DoubleLinkNode<E> *next = nullptr)
        {
            this->data = data;
            this->next = next;
            this->prior = prior;
        }

        DoubleLinkNode(const E l[], int n, bool with_head_node = true);

        ~DoubleLinkNode()
        {
            if (is_head_node)
                std::cout << "delete head node " << std::endl;
            else
                std::cout << "delete node with data : " << data << std::endl;
        }

        void destroyList() override;

        // override
        DoubleLinkNode<E> const *locateElem(E e) const;

        DoubleLinkNode<E> const *getElem(int i) const;

        bool add(E e) override;

        bool listInsert(int i, E e) override;

        bool listDelete(int i, E &e) override;

        bool empty() const override { return next == nullptr; }

        int length();

    public:
        E data;
        DoubleLinkNode<E> *next = nullptr;
        DoubleLinkNode<E> *prior = nullptr;
        bool is_head_node = false;
    };

    template <typename E>
    DoubleLinkNode<E>::DoubleLinkNode(const E l[], int n, bool with_head_node)
    {
        this->is_head_node = with_head_node;

        DoubleLinkNode<E> *r;
        // 使用尾插法
        if (with_head_node)
        {
            // 带头结点
            r = next = new DoubleLinkNode<E>(l[0], this);
        }
        else
        {
            // 不带头结点
            r = this;
            data = l[0];
        }

        for (int i = 1; i < n; i++)
            r = r->next = new DoubleLinkNode<E>(l[i], r);
    }

    template <typename E>
    void DoubleLinkNode<E>::destroyList()
    {
        auto p = this->next;
        DoubleLinkNode *next = nullptr;
        while (p)
        {
            next = p->next ? p->next : nullptr;
            delete p;
            p = next;
        }
        this->next = nullptr;
        std::cout << "delete double link list success" << std::endl;
    }

    template <typename E>
    DoubleLinkNode<E> const *DoubleLinkNode<E>::locateElem(E e) const
    {
        auto p = is_head_node ? next : this;
        while (p && p->data != e)
        {
            p = p->next;
        }
        return p;
    }

    template <typename E>
    DoubleLinkNode<E> const *DoubleLinkNode<E>::getElem(int i) const
    {
        int j = 1;
        auto p = is_head_node ? next : this;
        while (p && j < i)
        {
            p = p->next;
            j++;
        }
        return p;
    }

    template <typename E>
    bool DoubleLinkNode<E>::add(E e)
    {
        auto p = is_head_node ? next : this;
        while (p->next)
            p = p->next;
        p->next = new DoubleLinkNode<E>(e, p, this);
        return true;
    }

    template <typename E>
    bool DoubleLinkNode<E>::listInsert(int i, E e)
    {
        if (is_head_node)
        {
            if (i == 1)
            {
                next = new DoubleLinkNode<E>(e, this, next);
                next->next->prior = next;
                return true;
            }

            auto k = 1;
            auto p = next;
            while (p->next && k < i - 1)
            {
                k++;
                p = p->next;
            }
            if (k == i - 1)
            {
                p->next = new DoubleLinkNode<E>(e, p, p->next);
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
                next = new DoubleLinkNode<E>(data, this, next);
                data = e;
                next->next->prior = next;
                return true;
            }

            auto k = 1;
            auto p = this;
            while (p->next && k < i - 1)
            {
                k++;
                p = p->next;
            }
            if (k == i - 1)
            {
                p->next = new DoubleLinkNode<E>(e, p, p->next);
                p->next->next->prior = p->next;
                return true;
            }
            else
                return false;
        }
    }

    template <typename E>
    bool DoubleLinkNode<E>::listDelete(int i, E &e)
    {
        auto k = 1;
        auto p = is_head_node ? next : this;
        while (p->next && k < i - 1)
            k++;
        if (k == i - 1 && p->next)
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
    int DoubleLinkNode<E>::length()
    {
        auto p = is_head_node ? next : this;
        int l = 0;
        while (p)
        {
            l++;
            p = p->next;
        }

        return l;
    }

    template <typename E>
    std::ostream &operator<<(std::ostream &cout, DoubleLinkNode<E> &l)
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
    using DoubleLinkList = DoubleLinkNode<E>;
} // namespace list

#endif // DATA_STRUCTURE_LIST_DOUBLE_LINK_LIST_H