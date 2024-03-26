#include "Bag.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
#include "TestMethod.h"
#include <iostream>

using namespace std;

int main() {

    testAll();
    cout << "Short tests over" << endl;
    testAllExtended();
    cout << "Extended tests over" << endl;
    testMethod();
    cout << "New method tests over" << endl;
    cout << "All test over" << endl;
    return 0;
}
