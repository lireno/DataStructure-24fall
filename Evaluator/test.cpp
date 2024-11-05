#include "ExpressionEvaluator.hpp"
#include <iostream>
#include <string>
#include <vector>

int main() {
    ExpressionEvaluator evaluator;
    double result;
    std::vector<std::string> expressions = {
        "1 + 2 *3",                  // Simple arithmetic, expected: 7
        "3 +(2 -5) * 4 / 2",         // Mixed operators and parentheses, expected: -3
        "-1 + 2e2* 3",               // Scientific notation, expected: 599
        "23/1e-100",                 // Division with small denominator, expected: 2.3e101
        "-3 * (-2 + (4 -6) * 2)",    // Negative numbers with parentheses, expected: 18
        "(1.5e3 - 1e2) /(2.5 * 10)", // Scientific notation with parentheses, expected: 56
        "-4 + 3 * (2-3e1)+5/2",      // Mixed negative numbers and operations, expected: -85.5
        "[3 +{2 * (4- 2)}]*2",       // Different types of brackets, expected: 14
        "-1 +-2 * 3 -(-4)",          // Continuous negative numbers, expected: -3
        "5.5e2 / 1.1e1 - 3",         // Division with scientific notation, expected: 47
        "2* 3 - (4 / 2+ 1) * 5",     // Nested operations, expected: -5
        "1.2e2 + 3.5 -(4e1/ 2.0)",   // Decimal and scientific notation, expected: 103.5.5
        "3+(4 * 2",                  // Missing closing parenthesis, expected: ILLEGAL
        "5/ (3 -3)",                 // Division by zero, expected: ILLEGAL
        "2e",                        // Incomplete scientific notation, expected: ILLEGAL
        "1 +* 3",                    // Misplaced operator, expected: ILLEGAL
        "{2+ 3)]",                   // Mismatched brackets, expected: ILLEGAL
        "4e2.5",                     // Invalid scientific notation, expected: ILLEGAL
        "++5",                       // Invalid double operator, expected: ILLEGAL
        "3.5.2 + 2",                 // Invalid number format, expected: ILLEGAL
        "(2 + 3))",                  // Extra closing parenthesis, expected: ILLEGAL
        "2 * (3 - 5)) + 4",          // Unbalanced parentheses, expected: ILLEGAL
    };

    for (const auto& expression : expressions) {
        std::cout << "Evaluating: " << expression << " : ";
        if (evaluator.evaluate(expression, result)) {
            std::cout << "Result: " << result << std::endl;
        } else {
            std::cout << "ILLEGAL" << std::endl;
        }
        evaluator.clear(); // Clear the evaluator for the next expression
    }

    return 0;
}
