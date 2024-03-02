#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "json.hpp" // Biblioteca JSON para C++

using json = nlohmann::json;

// Função para calcular estatísticas de faturamento
void calcularEstatisticas(const std::vector<int>& faturamentoDiario) {
    // Encontrar o menor e o maior valor de faturamento
    int menorFaturamento = *std::min_element(faturamentoDiario.begin(), faturamentoDiario.end());
    int maiorFaturamento = *std::max_element(faturamentoDiario.begin(), faturamentoDiario.end());

    // Calcular a média mensal
    double mediaMensal = 0.0;
    int diasComFaturamento = 0;
    for (int faturamento : faturamentoDiario) {
        if (faturamento > 0) {
            mediaMensal += faturamento;
            diasComFaturamento++;
        }
    }
    mediaMensal /= diasComFaturamento;

    // Contar o número de dias com faturamento acima da média mensal
    int diasAcimaMedia = 0;
    for (int faturamento : faturamentoDiario) {
        if (faturamento > mediaMensal) {
            diasAcimaMedia++;
        }
    }

    // Imprimir resultados
    std::cout << "Menor faturamento diário: " << menorFaturamento << std::endl;
    std::cout << "Maior faturamento diário: " << maiorFaturamento << std::endl;
    std::cout << "Número de dias com faturamento acima da média mensal: " << diasAcimaMedia << std::endl;
}

int main() {
    // Carregar dados do arquivo JSON
    std::ifstream arquivo("https://drive.google.com/file/d/1qXvCPjEL4jerElN-hnScoKkEVmSQ8A2L/view");
    json dados;
    arquivo >> dados;

    // Extrair valores de faturamento diário do JSON
    std::vector<int> faturamentoDiario = dados["faturamento_diario"];

    // Calcular estatísticas
    calcularEstatisticas(faturamentoDiario);

    return 0;
}