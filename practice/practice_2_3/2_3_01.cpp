#include "practice_2_3.h"
#include "link_list.h"

namespace practice_2_3
{

    namespace p_01
    {
        using namespace list;
        using std::cout;
        using std::endl;

        template <typename E>
        // 注： 这里 l 为引用，不会产生断链
        void delete_all_x(LinkList<E> *&l, E x)
        {
            if (l)
            {
                if (l->data == x)
                {
                    auto p = l;
                    l = l->next;
                    delete p;
                    delete_all_x(l, x);
                }
                else
                {
                    delete_all_x(l->next, x);
                }
            }
        }

    } // namespace p_01

    void practice_01()
    {
        using namespace p_01;
        auto l = new LinkList<int>((const int[]){1, 2, 2, 2, 3, 4, 2}, 7, false);
        cout << *l << endl
             << "delete all 2" << endl;
        delete_all_x(l, 2);
        cout << *l << endl;
        l->destroyList();
        delete l;
    }
} // namespace practice_2_3
