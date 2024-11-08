#ifndef EXPRESSIONEVALUATOR_HPP
#define EXPRESSIONEVALUATOR_HPP

#include <cctype>
#include <cmath>
#include <regex>
#include <sstream>
#include <stack>
#include <string>

class ExpressionEvaluator {
  private:
    std::stack<double> values;
    std::stack<char> ops;

    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    bool isValidNumber(const std::string& number) {
        std::regex numberPattern(R"(^-?(\d+(\.\d*)?|\.\d+)([eE][+-]?\d+)?$)");
        return std::regex_match(number, numberPattern);
    }

    // returns the precedence of the operator
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    bool isleftBracket(char bracket) {
        return bracket == '(' || bracket == '{' || bracket == '[';
    }

    bool isRightBracket(char bracket) {
        return bracket == ')' || bracket == '}' || bracket == ']';
    }

    bool isBracket(char bracket) {
        return isleftBracket(bracket) || isRightBracket(bracket);
    }

    char oppositeBracket(char bracket) {
        switch (bracket) {
        case '(':
            return ')';
        case '{':
            return '}';
        case '[':
            return ']';
        case ')':
            return '(';
        case '}':
            return '{';
        case ']':
            return '[';
        default:
            return '\0';
        }
    }

    bool compute(char op) {
        if (values.size() < 2) return false;
        double b = values.top();
        values.pop();
        double a = values.top();
        values.pop();
        double result;

        switch (op) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b == 0) return false; // Division by zero
            result = a / b;
            break;
        default:
            return false;
        }
        values.push(result);
        return true;
    }

    bool ispartOfNumber(char c) {
        return isdigit(c) || c == '.' || c == 'e' || c == 'E' || c == '+' || c == '-';
    }

    bool _evaluate(const std::string& expression, double& result) {
        bool expectOperator = false;
        bool sign = true; // True for positive, False for negative

        for (size_t i = 0; i < expression.length(); ++i) {
            char c = expression[i];

            if (isspace(c)) {
                continue;
            }

            if (isdigit(c) || c == '.') {
                std::string number;
                if (!sign) {
                    number += '-';
                    sign = true;
                }
                while (i < expression.length() && (ispartOfNumber(expression[i]))) {
                    if (expression[i] == '+' || expression[i] == '-') { // case of scientific notation
                        if (expression[i - 1] != 'e' && expression[i - 1] != 'E') {
                            break;
                        }
                    }
                    number += expression[i];
                    i++;
                }
                --i;
                if (!isValidNumber(number)) {
                    return false;
                }
                values.push(std::stod(number));
                expectOperator = true;
            } else if (isleftBracket(c)) { // if the sign is negative, push the opposite bracket
                if (sign)
                    ops.push(c);
                else {
                    ops.push(oppositeBracket(c));
                    sign = true;
                }
            } else if (isRightBracket(c)) {
                while (!ops.empty() && ops.top() != oppositeBracket(c) && ops.top() != c) {
                    if (isBracket(ops.top())) return false;
                    if (!compute(ops.top())) return false;
                    ops.pop();
                }
                if (ops.empty() && ops.top() != oppositeBracket(c) && ops.top() != c) return false;

                if (isRightBracket(ops.top())) {
                    values.top() *= -1;
                }
                ops.pop();
            } else if (isOperator(c)) {
                if ((c == '-' || c == '+') && !expectOperator) {
                    if (c == '-') {
                        sign = !sign;
                    }
                } else {
                    if (!expectOperator) return false;

                    while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                        if (!compute(ops.top())) return false;
                        ops.pop();
                    }
                    ops.push(c);
                    expectOperator = false;
                }
            } else {
                return false;
            }
        }

        while (!ops.empty()) {
            if (isBracket(ops.top())) return false;
            if (!compute(ops.top())) return false;
            ops.pop();
        }

        if (values.size() != 1) return false;
        result = values.top();
        return true;
    }

  public:
    bool evaluate(const std::string& expression, double& result) {
        std::string Expression = expression;
        return _evaluate(Expression, result);
    }

    void clear() {
        while (!values.empty()) values.pop();
        while (!ops.empty()) ops.pop();
    }
};

#endif
