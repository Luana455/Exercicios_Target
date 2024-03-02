#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "json.hpp" // Biblioteca JSON para C++

using json = nlohmann::json;

// Fun��o para calcular estat�sticas de faturamento
void calcularEstatisticas(const std::vector<int>& faturamentoDiario) {
    // Encontrar o menor e o maior valor de faturamento
    int menorFaturamento = *std::min_element(faturamentoDiario.begin(), faturamentoDiario.end());
    int maiorFaturamento = *std::max_element(faturamentoDiario.begin(), faturamentoDiario.end());

    // Calcular a m�dia mensal
    double mediaMensal = 0.0;
    int diasComFaturamento = 0;
    for (int faturamento : faturamentoDiario) {
        if (faturamento > 0) {
            mediaMensal += faturamento;
            diasComFaturamento++;
        }
    }
    mediaMensal /= diasComFaturamento;

    // Contar o n�mero de dias com faturamento acima da m�dia mensal
    int diasAcimaMedia = 0;
    for (int faturamento : faturamentoDiario) {
        if (faturamento > mediaMensal) {
            diasAcimaMedia++;
        }
    }

    // Imprimir resultados
    std::cout << "Menor faturamento di�rio: " << menorFaturamento << std::endl;
    std::cout << "Maior faturamento di�rio: " << maiorFaturamento << std::endl;
    std::cout << "N�mero de dias com faturamento acima da m�dia mensal: " << diasAcimaMedia << std::endl;
}

int main() {
    // Carregar dados do arquivo JSON
    std::ifstream arquivo("https://drive.google.com/file/d/1qXvCPjEL4jerElN-hnScoKkEVmSQ8A2L/view");
    json dados;
    arquivo >> dados;

    // Extrair valores de faturamento di�rio do JSON
    std::vector<int> faturamentoDiario = dados["faturamento_diario"];

    // Calcular estat�sticas
    calcularEstatisticas(faturamentoDiario);

    return 0;
}