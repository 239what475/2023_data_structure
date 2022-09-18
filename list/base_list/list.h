//
//
//

#ifndef DATA_STRUCTURE_LIST_BASE_LIST_H
#define DATA_STRUCTURE_LIST_BASE_LIST_H

namespace list
{
    const int MaxSize = 50;

    template <typename E>
    class List
    {
    public:
        virtual ~List() = default;

        virtual void destroyList() = 0;

        int locateElem(E e) const;

        E getElem(int i) const;

        virtual bool add(E e) = 0;

        virtual bool listInsert(int i, E e) = 0;

        virtual bool listDelete(int i, E &e) = 0;

        virtual bool empty() const = 0;

        int length();
    };
} // namespace list

#endif // DATA_STRUCTURE_LIST_BASE_LIST_H
