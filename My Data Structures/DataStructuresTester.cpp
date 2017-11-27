#include "myQueue.h"
#include <iostream>
using namespace std;

int main(){
    myQueue testHeap;
    testHeap.Insert(2);
    testHeap.Insert(16);
    testHeap.Insert(19);
    testHeap.Insert(4);
    testHeap.Insert(14);
    testHeap.PrintQueue();
    cout << testHeap.DeleteTop() << endl;
    testHeap.PrintQueue();
    cout << testHeap.DeleteTop() << endl;
    testHeap.PrintQueue();
    cout << testHeap.DeleteTop() << endl;
    testHeap.PrintQueue();
     cout << testHeap.DeleteTop() << endl;
    cout << "END"<<endl;
    cin.get();
    return 0;
}