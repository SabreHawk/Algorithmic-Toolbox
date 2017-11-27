#include <iostream>
using namespace std;
#define MAX 100
struct Node{
    int value;
    Node * next;
    Node(int _value):value(_value),next(NULL){
    }
};

Node * head = new Node(0);
Node * tailPtr = head;
void my_push_back(int _value){
    Node * tempPtr = new Node(_value);
    tailPtr->next = tempPtr;
    tailPtr = tempPtr;
    head->value++;
}
void my_pop_back(){
    if(head->value>=MAX){
        return;
    }
    Node * tempPtr = head;
    while(tempPtr->next!=tailPtr){
        tempPtr = tempPtr->next;
    }
    delete tailPtr;
    tailPtr =tempPtr;
    head->value--;
}

void my_pop_front(){
    Node * tempPtr = head->next;
    head->next = tempPtr->next;
    head->value--;  
    delete tempPtr;
}

void my_insert(int _value,int _index){
    if(_index>=MAX){
        return;
    }
    int currentIndex = 0;
    Node * tempPtr = head->next;
    while(currentIndex != _index){
        tempPtr= tempPtr->next;
        ++ currentIndex;
    }
    Node* newPtr = new Node(_value);
    newPtr->next = tempPtr->next;
    tempPtr->next = newPtr;
    head->value ++;
}

void my_delete(int _index){
    if(_index>=head->value||_index>=MAX||_index<0){
        return;
    }
    int currentIndex = 0;
    Node * tempForePtr = head;
    Node * tempPtr = head->next;
    while(currentIndex!=_index){
        tempForePtr = tempPtr;
        tempPtr = tempPtr->next;
        currentIndex++;
    }
    tempForePtr->next = tempPtr->next;
    delete tempPtr;
    head->value --;
}

void show(){
    Node * tempPtr =head->next;
    cout<< "LENGTH : " <<head->value<<endl;
    while(tempPtr != NULL){
        cout<< tempPtr->value<<" ";
        tempPtr = tempPtr ->next;
    }
    cout<<endl;
}
int main(){
    for(int i = 0;i<10;++ i){
        my_push_back(i);
    }
    show();
    my_delete(8);
    show();
    my_insert(100,3);
    show();
    return 0;
}

