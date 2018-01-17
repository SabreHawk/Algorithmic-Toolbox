#include <iostream>
using namespace std;

int main(){
    int dir[4][2] = {1,0,0,1,-1,0,0,-1};
    int a,b = 0;
    a = dir[2][0];
    b = dir[2][1];
    cout << a <<" " << b<<endl;
}