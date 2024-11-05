#include "ExpressionEvaluator.hpp"
#include <iostream>
#include <string>

int main() {
    std::string expression;
    ExpressionEvaluator evaluator;
    double result;

    while (true) {
        std::cout << "Enter an expression (or enter 0 to exit): ";
        std::getline(std::cin, expression);

        if (expression.empty()) {
            continue;
        }

        if (expression.back() == '=') {
            expression.pop_back();
        }

        if (expression == "0") {
            std::cout << "Exiting program." << std::endl;
            break;
        }

        if (evaluator.evaluate(expression, result)) {
            std::cout << "Result: " << result << std::endl;
        } else {
            std::cout << "ILLEGAL" << std::endl;
        }

        evaluator.clear();
    }

    return 0;
}
