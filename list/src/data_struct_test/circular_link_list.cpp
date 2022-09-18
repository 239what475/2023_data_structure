#include "data_struct_list_test.h"
#include "circular_link_list.h"

void circular_link_list_test()
{
    using namespace list;
    using std::cout;
    using std::endl;

    cout << "with head node : " << endl;
    auto l = CircularLinkList<int>((const int[]){1, 2, 3}, 3);
    cout << l << endl;
    cout << "3 at address : " << l.locateElem(3) << endl
         << l.getElem(2)->data << " is on address " << l.getElem(2) << endl
         << "add 5 to list" << endl;
    l.add(5);

    cout << l << endl
         << "insert 10 at index 1" << endl;
    l.listInsert(1, 10);
    cout << l << endl;

    int a;
    l.listDelete(2, a);
    cout << "delete " << a << " at index 2" << endl
         << "is list empty ? " << (l.empty() ? "true" : "false") << endl
         << l << endl;
    l.destroyList();

    cout << endl
         << "without head node :" << endl;
    auto l1 = CircularLinkList<int>((const int[]){1, 2, 3}, 3, false);
    cout << l1 << endl;

    cout << "3 at address : " << l1.locateElem(3) << endl
         << l1.getElem(2)->data << " is on address " << l1.getElem(2) << endl
         << "add 5 to list" << endl;
    l1.add(5);

    cout << l1 << endl
         << "insert 8 at index 3" << endl;
    l1.listInsert(3, 8);
    cout << l1 << endl;

    int b;
    l1.listDelete(2, b);
    cout << "delete " << b << " at index 2" << endl
         << "is list empty ? " << (l1.empty() ? "true" : "false") << endl
         << "the length of list is :" << l1.length() << endl
         << l1 << endl;
    l1.destroyList();
}