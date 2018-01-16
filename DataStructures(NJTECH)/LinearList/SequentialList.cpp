#include <iostream>
using namespace std;

class SequentialList{
    private:
        int MAXLENGTH = 100;
        int sList[MAXLENGTH] = {0};
        int length = 0;
    public:
        SquentialList(){
        }
        void initList(){
            length = 0;
        }
        void length(){
            return length;
        }
        void insertValue(int _x,int _index){
            if(length>=MXlength){
                cout<<"List is Full"<<endl;
                return;
            }
            if(_index<0||_index>length){
                cout<<"illegal Index"<<endl;
                return 0;
            }
            for(int i = length,i>_index;-- i){
                sList[i] = slist[i-1];
            }
            sList[_index] = _x;
            length++;
        }
        void push(int _x){
            if(length>=MXlength){
                cout<<"List is Full"<<endl;
                return;
            }
            sList[length++] = _x;
        }
        void deleteValue(int _x,int _index){
            if(_index<0||index>=length){
                cout<<"List is Full"<<endl;
                return;
            }
            for(int i = _index,i<length-1++ i){
                sLsit[i] = sList[i+1];
            }
            length--;
        }
        void find(int _index){
            return sList[_index];
        }
        void show(){
            for(int i = 0;i<legth;++ i){
                cout<<i<<" ";
            }cout<<endl;
        }
}

int main(){
    sList myList;
    myList.push(1);
}