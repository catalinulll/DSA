#include "ExtendedTest.h"
#include "ShortTest.h"
#include "TestMethod.h"
#include <stack>
#include <iostream>
using namespace std;

int main() {

    testAll();
    testAllExtended();
    cout << "Test previous" << endl;
    testPrevious();
    cout << "That's all!" << endl;
    system("pause");

}



