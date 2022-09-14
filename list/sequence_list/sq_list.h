//
//
//

#if !defined(DATA_STRUCTURE_LIST_SQ_LIST)
#define DATA_STRUCTURE_LIST_SQ_LIST

#include <iostream>
#include "list.h"

namespace list
{
    template <typename E>
    class SqList : public List<E>
    {
    public:
        SqList() { data = new E[MaxSize]; }

        ~SqList() { delete[] data; }

        // override
        int locateElem(E e) const;

        E getElem(int i) const { return data[i - 1]; }

        bool add(E e);

        bool listInsert(int i, E e);

        bool listDelete(int i, E &e);

        void print() const;

        bool empty() const { return length == 0; }
        //

        bool addAll(const E l[], int n);

    public:
        E *data;
        int length = 0;
    };

    template <typename E>
    int SqList<E>::locateElem(E e) const
    {
        for (int i = 0; i < length; i++)
            if (data[i] == e)
                return i;
        return 0;
    }

    template <typename E>
    bool SqList<E>::add(E e)
    {
        if (length >= MaxSize)
            return false;
        data[length] = e;
        length++;
        return true;
    }

    template <typename E>
    bool SqList<E>::listInsert(int i, E e)
    {
        if (i < 1 || i > length + 1)
            return false;
        if (length >= MaxSize)
            return false;
        for (int j = length; j >= i; j--)
            data[j] = data[j - 1];
        data[i - 1] = e;
        length++;
        return true;
    }

    template <typename E>
    bool SqList<E>::listDelete(int i, E &e)
    {
        if (i < 1 || i > length)
            return false;
        e = data[i - 1];
        for (int j = i; j < length; j++)
            data[j - 1] = data[j];
        length--;
        return true;
    }

    template <typename E>
    void SqList<E>::print() const
    {
        using std::cout;
        using std::endl;
        cout << "[";
        for (int i = 0; i < length; i++)
            cout << data[i] << ",";
        cout << "]" << endl;
    }

    template <typename E>
    bool SqList<E>::addAll(const E l[], int n)
    {
        if (n + length > MaxSize)
            return false;
        for (int i = 0; i < n; i++)
        {
            data[i + length] = l[i];
        }
        length += n;
        return true;
    }
} // namespace list

#endif // DATA_STRUCTURE_LIST_SQ_LIST
