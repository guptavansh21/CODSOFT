#include <iostream>

void calculator() {
    double num1, num2;
    char op;

    std::cout << "\n--- SIMPLE CALCULATOR (CODSOFT C++) ---\n";
    
    // User se pehla number input lo
    std::cout << "Enter first number: ";
    std::cin >> num1;

    // Operation select karne ko bolo
    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> op;

    // User se doosra number input lo
    std::cout << "Enter second number: ";
    std::cin >> num2;

    double result;
    bool valid_op = true;

    // Calculation ke liye switch statement use karo
    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            // Division by zero check
            if (num2 == 0) {
                std::cout << "❌ Error! Division by zero is not allowed.\n";
                valid_op = false;
            } else {
                result = num1 / num2;
            }
            break;
        default:
            std::cout << "❌ Error! Invalid operator.\n";
            valid_op = false;
    }

    // Result display karo
    if (valid_op) {
        std::cout << "\nResult: " << num1 << " " << op << " " << num2 << " = " << result << "\n";
    }
}

int main() {
    calculator();
    return 0;
}