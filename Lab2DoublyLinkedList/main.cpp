#include <iostream>
#include "IntList.h"
using namespace std;

int main()
{
    IntList tester;

    cout << "tester.push_front(1)" << endl;    
    cout << "tester.push_front(2)" << endl;
    cout << "tester.push_front(3)" << endl;    
    cout << "tester.push_front(4)" << endl;
    tester.push_front(1);
    tester.push_front(2);
    tester.push_front(3);
    tester.push_front(4);
    cout << tester << endl;
    cout << "tester.printReverse()" << endl;
    tester.printReverse();
    cout << endl;
    cout << "tester.pop_front()" << endl;
    cout << "tester.pop_front()" << endl;
    tester.pop_front();
    tester.pop_front();
    cout << tester << endl;
    cout << "tester.printReverse()" << endl;
    tester.printReverse();
    cout << endl;
    cout << "tester.push_back(1)" << endl;    
    cout << "tester.push_back(2)" << endl;
    cout << "tester.push_back(3)" << endl;    
    cout << "tester.push_back(4)" << endl;
    tester.push_back(1);
    tester.push_back(2);
    tester.push_back(3);
    tester.push_back(4);
    cout << tester << endl;
    cout << "tester.printReverse()" << endl;
    tester.printReverse();
    cout << endl;
    cout << "tester.pop_back()" << endl;    
    cout << "tester.pop_back()" << endl;
    tester.pop_back();
    tester.pop_back();
    cout << tester << endl;
    cout << "tester.printReverse()" << endl;
    tester.printReverse();
    cout << endl;

    return 0;
}