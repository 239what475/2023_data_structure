//
//
//

#ifndef DATA_STRUCTURE_LIST_LINK_LIST_H
#define DATA_STRUCTURE_LIST_LINK_LIST_H

#include <iostream>
#include "base_list.h"

namespace list
{
    template <typename E>
    class LinkNode : public List<E>
    {
    public:
        LinkNode()
        {
            this->next = nullptr;
            this->is_head_node = true;
        }

        LinkNode(const E data)
        {
            this->data = data;
            this->next = nullptr;
        }
        LinkNode(const E data, LinkNode<E> *next)
        {
            this->data = data;
            this->next = next;
        }

        LinkNode(const E l[], int n, bool with_head_node = true);

        ~LinkNode()
        {
            if (is_head_node)
            {
                std::cout << "delete head node" << std::endl;
                // 如果存在公共结点，则会出现错误
                // if (next)
                // {
                //     this->destroyList();
                // }
            }
            else
                std::cout << "delete node with data : " << data << std::endl;
        }

        void destroyList() override;

        // override
        LinkNode<E> const *locateElem(E e) const;

        virtual LinkNode<E> const *getElem(int i) const;

        bool add(E e) override;

        bool listInsert(int i, E e) override;

        bool listDelete(int i, E &e) override;

        bool empty() const override { return next == nullptr; }

        int length();

    public:
        E data;
        LinkNode<E> *next;
        // 结点是否为头结点
        bool is_head_node = false;
    };

    template <typename E>
    LinkNode<E>::LinkNode(const E l[], int n, bool with_head_node)
    {
        this->is_head_node = with_head_node;
        // 使用尾插法
        LinkNode<E> *r;

        if (with_head_node)
        {
            // 带头结点
            r = next = new LinkNode<E>(l[0]);
        }
        else
        {
            // 不带头结点
            r = this;
            data = l[0];
        }

        for (int i = 1; i < n; i++)
            r = r->next = new LinkNode<E>(l[i]);
    }

    template <typename E>
    void LinkNode<E>::destroyList()
    {
        auto p = this->next;
        LinkNode *next = nullptr;
        while (p)
        {
            next = p->next ? p->next : nullptr;
            delete p;
            p = next;
        }
        this->next = nullptr;
        std::cout << "delete link list success" << std::endl;
    }

    template <typename E>
    LinkNode<E> const *LinkNode<E>::locateElem(E e) const
    {
        auto p = is_head_node ? next : this;
        while (p && p->data != e)
            p = p->next;
        return p;
    }

    template <typename E>
    LinkNode<E> const *LinkNode<E>::getElem(int i) const
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
    bool LinkNode<E>::add(E e)
    {
        auto p = this;
        while (p->next)
            p = p->next;
        p->next = new LinkNode<E>(e);
        return true;
    }

    template <typename E>
    bool LinkNode<E>::listInsert(int i, E e)
    {
        if (is_head_node)
        {
            if (i == 1)
            {
                next = new LinkNode<E>(e, next);
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
                p->next = new LinkNode<E>(e, p->next);
                return true;
            }
            else
                return false;
        }
        else
        {
            if (i == 1)
            {
                next = new LinkNode<E>(data, next);
                data = e;
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
                p->next = new LinkNode<E>(e, p->next);
                return true;
            }
            else
                return false;
        }
    }

    template <typename E>
    bool LinkNode<E>::listDelete(int i, E &e)
    {
        auto k = 1;
        auto p = is_head_node ? next : this;
        while (p->next && k < i - 1)
            k++;
        if (k == i - 1 && p->next)
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
    int LinkNode<E>::length()
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
    std::ostream &operator<<(std::ostream &cout, LinkNode<E> &l)
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
    using LinkList = LinkNode<E>;

} // namespace list

#endif // DATA_STRUCTURE_LIST_LINK_LIST