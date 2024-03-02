#include <iostream>

bool pertenceSequenciaFibonacci(int num) {
    int a = 0, b = 1, c;
    while (a <= num) {
        if (a == num) {
            return true;
        }
        c = a + b;
        a = b;
        b = c;
    }
    return false;
}

int main() 
{
    int numero;
    std::cout << "Digite um numero: ";
    std::cin >> numero;

    if (pertenceSequenciaFibonacci(numero)) {
        std::cout << "O numero " << numero << " pertence a sequencia de Fibonacci.\n";
    }
    else {
        std::cout << "O numero " << numero << " nao pertence a sequencia de Fibonacci.\n";
    }

    return 0;
}