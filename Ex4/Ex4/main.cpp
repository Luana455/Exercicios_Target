#include <iostream>
#include <map>
#include <iomanip>

int main() {
    // Definir o faturamento mensal por estado
    std::map<std::string, double> faturamento_por_estado = {
        {"SP", 67836.43},
        {"RJ", 36678.66},
        {"MG", 29229.88},
        {"ES", 27165.48},
        {"Outros", 19849.53}
    };

    // Calcular o faturamento total mensal
    double faturamento_total = 0.0;
    for (const auto& par : faturamento_por_estado) {
        faturamento_total += par.second;
    }

    // Calcular e imprimir o percentual de representação de cada estado
    std::cout << "Percentual de representacao de cada estado no faturamento mensal:" << std::endl;
    for (const auto& par : faturamento_por_estado) {
        double percentual = (par.second / faturamento_total) * 100.0;
        std::cout << par.first << ": " << std::fixed << std::setprecision(2) << percentual << "%" << std::endl;
    }

    return 0;
}