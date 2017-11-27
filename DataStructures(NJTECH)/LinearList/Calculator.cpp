#include <iostream>
#include <stack>
#include <list>
#include <string>
#include <string.h>
using namespace std;

list<char> aftStack;
stack<char> charStack;

string formulaString = "1+2*3+(4*5-6)*7";
int main() {
    list<char>::iterator itor;
    for (int i = 0; i< formulaString.length(); ++i) {
        //cout<<i<<endl;
        if (formulaString[i] >= '1' && formulaString[i] <= '9') {
            aftStack.push_back(formulaString[i]);
        }
        else if (formulaString[i] == '(') {
            charStack.push('(');
        }
        else if (formulaString[i] == ')') {
            char temp = charStack.top();
            while (temp != '(') {
                charStack.pop();
                aftStack.push_back(temp);
                temp = charStack.top();
            }
            charStack.pop();
        }
        else if (formulaString[i] == '+' || formulaString[i] == '-' || formulaString[i] == '*' || formulaString[i] == '/') {
            if (charStack.empty()) {
                charStack.push(formulaString[i]);
            }
            else {
                if (formulaString[i] == '+' || formulaString[i] == '-') {
                    char temp = charStack.top();
                    while (!charStack.empty() && temp != '(') {
                        aftStack.push_back(temp);
                        charStack.pop();
                        if (charStack.empty())break;
                        temp = charStack.top();
                    }
                }
                else {
                    char temp = charStack.top();
                    while (charStack.top() == '*' || charStack.top() == '/') {
                        aftStack.push_back(temp);
                        charStack.pop();
                        temp = charStack.top();
                    }
                }
                charStack.push(formulaString[i]);
            }

        }

    }

    char temp = charStack.top();
    while (!charStack.empty()) {
        aftStack.push_back(temp);
        charStack.pop();
        if (charStack.empty()) break;
        temp = charStack.top();
    }
    string aftString;
    for (itor = aftStack.begin(); itor != aftStack.end(); itor++) {
        aftString += *itor;
    }cout << endl;
    cout << aftString << endl;

    int num1 = 0;
    int num2 = 0;
    stack<int> calStack;
    for (itor = aftStack.begin(); itor != aftStack.end(); itor++) {
        if (*itor > '0'&&*itor <= '9') {
            calStack.push(*itor-'0');
        }
        else {
        //  cout<<*itor<<endl;
            num1 = calStack.top();
            calStack.pop();
            if(calStack.empty()){
                cout<<"ITOR " <<*itor<<endl;
                cout<<"TEST "<< num1<<endl;
                cout<<"ERROR"<<endl;
            }
            num2 = calStack.top();
            calStack.pop();
            
            switch (*itor)
            {
            case '+':
                calStack.push(num1 + num2);
                cout<<num2 <<" + "<<num1<<" = "<<calStack.top()<<endl;
                break;
            case '-':
                calStack.push(num2 - num1);
            cout<<num2 <<" - "<<num1<<" = "<<calStack.top()<<endl;
                break;
            case '*':
                calStack.push(num1 * num2);
                cout<<num2 <<" * "<<num1<<" = "<<calStack.top()<<endl;
                break;
            case '/':
                calStack.push(num2 / num1);
                break;
            default:
                cout<<"ERROR"<<endl;
                break;
            }
        }

    }
    cout << calStack.top() << endl;

    return 0;
}
