#include <iostream>

int fact(int n) {
    if (n == 0) {
        return 1;
    }

    return n * fact (n - 1);
}

void task1(int n) {
    if (n == 1) {
        std::cout << n;
        return;
    }

    task1(n - 1);
    std::cout << n;
    task1(n - 1);
}

int main() {
    task1(3);
    std::cout << std::endl;

    
    std::cout << fact(3) << std::endl; 

    return 0;
}