#include "data_structure_stack_test.h"
#include "link_stack.h"

void link_stack_test()
{
    using namespace stack;
    using std::cout;
    using std::endl;

    auto s = LinkStack<int>();
    cout << "push 1:" << endl;
    s.push(1);
    cout << s << endl;
    cout << "push 2:" << endl;
    s.push(2);
    cout << s << endl;
    cout << "pop:" << endl;
    int a;
    s.pop(a);
    cout << s << endl;
    cout << "is empty ? " << (s.empty() ? "yes" : "no") << endl
         << endl;
}