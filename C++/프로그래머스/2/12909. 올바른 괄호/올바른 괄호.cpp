#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> paren;
    
    for(char a : s) {
        if(a == '(') {
            paren.push('(');
        }
        else if(a == ')') {
            if(paren.empty()) {
                return false;
            } else {
                paren.pop();
            }
        }
    }

    if(paren.empty()) {
        return true;
    } else {
        return false;
    }
}