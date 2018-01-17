#include <iostream>
#include <string>
using namespace std;


long long pow(long long,unsigned long long);
int main(){
    long long T;unsigned long long n;
    while(cin >> T){
        if(T==0) break;
        for(long long i = 0;i < T;++ i){
            cin >> n;
            cout << "Case "<<i+1<<": ";
            long long sum = 0;
            sum = (pow(4,n-1)+pow(2,n-1));
            cout << sum % 100 <<endl;
        }
        cout << endl;
    }
    return 0;
}


long long pow(long long x,unsigned long long y)
{
    int re=1;
    while(y)
    {
        if(y&1) (re*=x)%=100;
        (x*=x)%=100; y>>=1;
    }
    return re;
}