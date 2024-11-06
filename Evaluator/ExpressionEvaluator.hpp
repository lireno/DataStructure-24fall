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

    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    bool isMatchingBracket(char left, char right) {
        return (left == '(' && right == ')') ||
               (left == '{' && right == '}') ||
               (left == '[' && right == ']');
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

    bool partOfNumber(char c) {
        return isdigit(c) || c == '.' || c == 'e' || c == 'E' || c == '+' || c == '-' || c == ' ';
    }

    bool _evaluate(const std::string& expression, double& result) {
        bool expectOperator = false;
        bool minus_flag = false;

        for (size_t i = 0; i < expression.length(); ++i) {
            char c = expression[i];

            if (isspace(c) || c == ',') {
                continue;
            }

            if (isdigit(c) || c == '.') {
                std::string number;
                if (minus_flag) {
                    number += '-';
                    minus_flag = false;
                }
                while (i < expression.length() && (partOfNumber(expression[i]))) {
                    if (expression[i] == '+' || expression[i] == '-') {
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
            } else if (c == '(' || c == '{' || c == '[') {
                ops.push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                while (!ops.empty() && !isMatchingBracket(ops.top(), c)) {
                    if (ops.top() == '(' || ops.top() == '{' || ops.top() == '[') return false;
                    if (!compute(ops.top())) return false;
                    ops.pop();
                }
                if (ops.empty() || !isMatchingBracket(ops.top(), c)) return false;
                ops.pop();
            } else if (isOperator(c)) {
                if (c == '-' && !expectOperator && !minus_flag) {
                    char c_next = expression[i + 1];
                    if (!(isdigit(c_next) || c_next == '.')) {
                        return false;
                    }
                    minus_flag = true;
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
            if (ops.top() == '(' || ops.top() == '{' || ops.top() == '[') return false;
            if (!compute(ops.top())) return false;
            ops.pop();
        }

        if (values.size() != 1) return false;
        result = values.top();
        return true;
    }

  public:
    bool evaluate(const std::string& expression, double& result) {
        std::string cleanedExpression = expression;
        return _evaluate(cleanedExpression, result);
    }

    void clear() {
        while (!values.empty()) values.pop();
        while (!ops.empty()) ops.pop();
    }
};

#endif
