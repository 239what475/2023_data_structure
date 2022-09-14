//
//
//

#if !defined(DATA_STRUCTURE_LIST_BASE_LIST_H)
#define DATA_STRUCTURE_LIST_BASE_LIST_H

namespace list
{
    const int MaxSize = 50;

    template <typename E>
    class List
    {
    public:
        virtual ~List() = default;

        virtual int locateElem(E e) const = 0;

        virtual E getElem(int i) const = 0;

        virtual bool add(E e) = 0;

        virtual bool listInsert(int i, E e) = 0;

        virtual bool listDelete(int i, E &e) = 0;

        virtual void print() const = 0;

        virtual bool empty() const = 0;
    };
} // namespace list

#endif // DATA_STRUCTURE_LIST_BASE_LIST_H
