#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
string solution(string parentheses) {
    // Type your solution here
    stack<char> s; 
    char tmp; 
    int left = 0;
    int len = parentheses.length();
    
    for (int i = 0; i < len; ++i) { 
        if (parentheses[i] == '(') { 
            s.push(parentheses[i]); 
        } 
        else {
            if (!s.empty()) {
                tmp = s.top();
                s.pop();
            } else {
                left++;
            }
        }
    } 
    int right = static_cast<int> (s.size());
    parentheses = string(left, '(') + parentheses + string(right, ')');
    return parentheses; 
}

int main(){
    std::string ret = ")(()(";
    std::cout << solution(ret);
}