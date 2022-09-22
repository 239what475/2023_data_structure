#include "data_struct_list_test.h"
#include "sq_list.h"

void sq_list_test()
{
     using namespace list;
     using std::cout;
     using std::endl;
     auto l = SqList<int>((const int[]){1, 2, 3}, 3);
     cout << "3 at index : " << l.locateElem(3) << endl
          << l.getElem(2) << " is on index 2" << endl
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
          << endl;
}