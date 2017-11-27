#include <iostream>
#include <stdio.h>
#include "stdlib.h"
using namespace std;

int numOne = 0;
int numTwo = 0;
int GCD(int _num1,int _num2){
    if(_num2 == 0) return _num1;
    int nextNumTwo = _num1%_num2;
    return  GCD(_num2,nextNumTwo);
}
int main(){
    scanf("%d%d",&numOne,&numTwo);
    if(numOne < numTwo){
        int temp = numOne;
        numOne = numTwo;
        numTwo = temp;
    }
    int answer = GCD(numOne,numTwo);
    printf("%d\n",answer);
    system("Pause");
    return 0;
}