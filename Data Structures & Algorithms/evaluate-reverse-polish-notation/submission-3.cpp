#include<string>
class Solution {
public:
    int to_int(string str){
        int result = 0, i = 0;
        if(str[0] == '-') {
            i++;
        }
        for( ; i < str.size(); i++) {
            result = result * 10 + (str[i] - 48);
        }
        if(str[0] == '-') {
            result *= -1;
        }
        cout << result << endl;
        return result;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> number;
        int i, a, b; char o;
        for(i = 0 ; i < tokens.size(); i++) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                o = tokens[i][0];
                b = number.top();
                number.pop();
                a = number.top();
                number.pop();
                int result = 0 ;
                
                switch(o) {
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
                number.push(to_int(tokens[i]));
            }
        }
        return(number.top());

    }
};
