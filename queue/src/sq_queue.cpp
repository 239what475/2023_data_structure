#include "data_structure_queue_test.h"
#include "sq_queue.h"

void sq_queue_test()
{
    using namespace queue;
    using std::cout;
    using std::endl;

    auto q = SqQueue<int>();
    cout << "enqueue 1:" << endl;
    q.enqueue(1);
    cout << q << endl;
    cout << "enqueue 2:" << endl;
    q.enqueue(2);
    cout << q << endl;
    cout << "dequeue:" << endl;
    int a;
    q.dequeue(a);
    cout << q << endl;
    cout << "is empty ? " << (q.empty() ? "yes" : "no") << endl
         << endl;
}