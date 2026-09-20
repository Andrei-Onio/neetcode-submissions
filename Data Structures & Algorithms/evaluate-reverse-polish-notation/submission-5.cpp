#include<string>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> number;
        int i, a, b; char o;
        for(i = 0 ; i < tokens.size(); i++) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                b = number.top();
                number.pop();
                a = number.top();
                number.pop();
                int result = 0 ;
                
                switch(tokens[i][0]) {
                case '+' : result = a + b;
                    break;
                case '-' : result = a - b;
                    break;
                case '*' : result = a * b;
                    break;
                case '/' : result = a / b;
                    break;
                }
                number.push(result);

            }
            else {
                number.push(stoi(tokens[i]));
            }
        }
        return(number.top());

    }
};
