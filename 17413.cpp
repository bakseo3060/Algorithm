#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void){
    string s;
    stack<char> word;
    getline(cin, s);
    // '<' '>'로 닫혀있는지 확인
    int s_size = s.size();
    // 1. '<' 시작할 경우 '>' 닫힐때까지 그대로 출력
    // 2. 그 외의 경우 공백이 나올 때까지 stack에 push후
    // 공백이 나올 경우 stack all pop
    int i=0;
    while(i < s_size) {
        if(s[i]=='<') {
            while(s[i] != '>' && i<s_size) {
                cout << s[i];
                i++;
            }
            if(s[i] == '>') {
                cout << s[i];
                i++;
            }
        } else {
            while(s[i] != '<' && s[i] != ' ' && i <s_size) {
                word.push(s[i]);
                i++;
            }
            while(word.empty() != true) {
                cout << word.top();
                word.pop();
            }
            if(s[i] == ' ') {
                cout << s[i];
                i++;
            }
        }
    }
    cout << '\n';
}