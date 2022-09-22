#include "data_structure_stack_test.h"
#include "share_stack.h"

void share_stack_test()
{
    using namespace stack;
    using std::cout;
    using std::endl;

    auto s = ShareStack<int>();
    cout << "push 1 in stack 1:" << endl;
    s.push(1, 1);
    cout << s << endl;

    cout << "push 2 in stack 1:" << endl;
    s.push(2, 1);
    cout << s << endl;

    cout << "push 3 in stack 2:" << endl;
    s.push(3, 2);
    cout << s << endl;

    cout << "stack 1 pop:" << endl;
    int a;
    s.pop(a, 1);
    cout << s << endl;
    cout << "stack 1 empty ? " << (s.empty(1) ? "yes" : "no") << endl
         << endl;
}