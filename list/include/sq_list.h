//
//
//

#ifndef DATA_STRUCTURE_LIST_SQ_LIST_H
#define DATA_STRUCTURE_LIST_SQ_LIST_H

#include <iostream>
#include "base_list.h"

namespace list
{
    const int MaxSize = 50;

    template <typename E>
    class SqList : public List<E>
    {
    public:
        SqList() { data = new E[MaxSize]; }

        SqList(const E l[], int n);

        ~SqList() { delete[] data; }

        void destroyList() override{};

        // override
        int locateElem(E e) const;

        E getElem(int i) const { return data[i - 1]; }

        bool add(E e) override;

        bool listInsert(int i, E e) override;

        bool listDelete(int i, E &e) override;

        bool empty() const override { return m_length == 0; }

        int &length() { return m_length; }

    public:
        E *data;

    private:
        int m_length = 0;
    };

    template <typename E>
    SqList<E>::SqList(const E l[], int n)
    {
        data = new E[MaxSize];
        int i = 0;
        for (; i < n && i < MaxSize; i++)
        {
            data[i + m_length] = l[i];
        }
        m_length += i;
    }

    template <typename E>
    int SqList<E>::locateElem(E e) const
    {
        for (int i = 0; i < m_length; i++)
            if (data[i] == e)
                return i;
        return 0;
    }

    template <typename E>
    bool SqList<E>::add(E e)
    {
        if (m_length >= MaxSize)
            return false;
        data[m_length] = e;
        m_length++;
        return true;
    }

    template <typename E>
    bool SqList<E>::listInsert(int i, E e)
    {
        if (i < 1 || i > m_length + 1)
            return false;
        if (m_length >= MaxSize)
            return false;
        for (int j = m_length; j >= i; j--)
            data[j] = data[j - 1];
        data[i - 1] = e;
        m_length++;
        return true;
    }

    template <typename E>
    bool SqList<E>::listDelete(int i, E &e)
    {
        if (i < 1 || i > m_length)
            return false;
        e = data[i - 1];
        for (int j = i; j < m_length; j++)
            data[j - 1] = data[j];
        m_length--;
        return true;
    }

    template <typename E>
    std::ostream &operator<<(std::ostream &cout, SqList<E> &l)
    {
        cout << "[";
        for (int i = 0; i < l.length(); i++)
            cout << l.data[i] << ",";
        cout << "]";
        return cout;
    }
} // namespace list

#endif // DATA_STRUCTURE_LIST_SQ_LIST
