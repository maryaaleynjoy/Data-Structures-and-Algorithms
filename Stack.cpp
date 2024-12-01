#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}


string infixToPostfix(const string& expression) {
    stack<char> stack;
    string output;

    for (char ch : expression) {
        if (isspace(ch)) {
            continue; 
        }
        if (isdigit(ch)) { 
            output += ch;
        } else if (ch == '(') { 
            stack.push(ch);
        } else if (ch == ')') { 
            while (!stack.empty() && stack.top() != '(') {
                output += stack.top();
                stack.pop();
            }
            stack.pop(); 
        } else { 
            while (!stack.empty() && precedence(stack.top()) >= precedence(ch)) {
                output += stack.top();
                stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.empty()) {
        output += stack.top();
        stack.pop();
    }

    return output;
}


int evaluatePostfix(const string& postfix) {
    stack<int> stack;

    for (char ch : postfix) {
        if (isdigit(ch)) { 
            stack.push(ch - '0'); 
        } else { 
            int right = stack.top(); stack.pop();
            int left = stack.top(); stack.pop();
            switch (ch) {
                case '+': stack.push(left + right); break;
                case '-': stack.push(left - right); break;
                case '*': stack.push(left * right); break;
                case '/': stack.push(left / right); break;
            }
        }
    }

    return stack.top(); 
}


int calculate(const string& expression) {

    string postfix = infixToPostfix(expression);
    cout << "Postfix Expression: " << postfix << endl;


    return evaluatePostfix(postfix);
}

int main() {
    string infixExpression;

    cout << "Enter an infix expression : ";
    getline(cin, infixExpression); 

    int result = calculate(infixExpression);
    cout << "Result: " << result << endl;

    return 0;
