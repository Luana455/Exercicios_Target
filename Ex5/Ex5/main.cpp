#include <iostream>
#include <string>

int main()
{
    // Definir a string a ser invertida
    std::string input_string = "String teste";

    // Calcular o comprimento da string
    int length = input_string.length();

    // Criar uma string para armazenar o resultado invertido
    std::string inverted_string;

    // Inverter os caracteres da string
    for (int i = length - 1; i >= 0; i--) {
        inverted_string += input_string[i];
    }

    // Imprimir a string invertida
    std::cout << "String invertida: " << inverted_string << std::endl;

    return 0;
}