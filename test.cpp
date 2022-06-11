#include <iostream>
#include "CAutoSepOStream.hpp"
using namespace std;
int main()
{
    CAutoSepOStream o1(cout);
    CAutoSepOStream o2(cout, ", ");
    CAutoSepOStream o3(cout, "\n");
    o1 << 1 << 2 << "test1" << endl;
    o2 << "~~" << 123 << "test2" << endl;
    o3 << 1.1 << "test3" << endl;
    cout.setf(ios::fixed);
    cout.precision(6);
    o3 << 1.1 << "test4" << endl;
    return 0;
}
/* 
1 2 test1
~~, 123, test2
1.1
test3
1.100000
test4
*/
