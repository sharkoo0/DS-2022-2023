#include "stack.h"
#include <string>

bool isNumber(char c) {
    return c >= '0' && c <= '9';
}

bool isOperation(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int getPriority(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return 3;
    }
    throw "Undefined operation";
}

void evaluate(Stack<int>& nums, Stack<char>& ops) {
    if (nums.getSize() <= 1) {
        return;
    }
    if (ops.peek() == '(') {
        return;
    }
    int operand1 = nums.pop();
    int operand2 = nums.pop();
    switch (ops.peek())
    {
    case '+':
        nums.push(operand2 + operand1);
        break;
    case '-':
        nums.push(operand2 - operand1);
        break;
    case '*':
        nums.push(operand2 * operand1);
        break;
    case '/': {
            if (operand1 == 0) {
                throw std::invalid_argument("Cannot divide by 0");
            }
            nums.push(operand2 / operand1);
            break;
        }
        
    }
}

void rpn(const std::string& expression) {
    Stack<int> numbers;
    Stack<char> operations;

    int size = expression.size();

    for (int i = 0; i < size; ++i) {
        if (expression[i] == '(') {
            operations.push(expression[i]);
        } else if (isNumber(expression[i])) {
            numbers.push(expression[i] - '0');
        } else if (isOperation(expression[i])) {
            if (expression[i] != '(' && getPriority(expression[i]) >= getPriority(operations.peek())) {
                operations.push(expression[i]);
            } else {
                evaluate(numbers, operations);
                if(operations.peek() != '(') {
                    operations.pop();
                }
                operations.push(expression[i]);
            }
        } else if (expression[i] == ')') {
            while (operations.peek() != '(') {
                evaluate(numbers, operations);
                operations.pop();
            }
            operations.pop();
        }
        if (operations.isEmpty()) {
            std::cout << expression << " = " << numbers.peek() << std::endl;
        }
    }
}

int main() {

    // Stack<int> s;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);
    // s.push(6);
    // s.push(7);
    // s.push(8);
    // s.push(9);
    // s.push(10);
    // s.push(11);
    // s.push(12);

    // std::cout << s.peek() << std::endl;
    // std::cout << s.pop() << std::endl;
    // std::cout << s.peek() << std::endl;
    // std::cout << s.isEmpty() << std::endl;

    //Забележка: Помислете как да се преправи задачата, за да може да работи с числа >10 и с отрицателни числа.
    try {
        rpn("(1+2*(3+4)-5)");
        rpn("(1+8*(1-1*(2+3)*5*(4+6))-9*2)");
    } catch (const char* message) {
        std::cout << message << std::endl;
    }
   

    return 0;
}