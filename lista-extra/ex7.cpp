#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Função de comparação para ordenar as frases pela primeira letra da primeira palavra
bool compareFirstLetter(const std::string& a, const std::string& b) {
    return a[0] < b[0];
}

int main() {
    std::vector<std::string> frases;

    // Leitura das frases até encontrar "ASC" ou "DESC"
    std::string input;
    while (std::getline(std::cin, input) && input != "ASC" && input != "DESC") {
        frases.push_back(input);
    }

    // Ordenação das frases pela primeira letra da primeira palavra
    std::sort(frases.begin(), frases.end(), compareFirstLetter);

    // Impressão das frases ordenadas
    for (std::vector<std::string>::const_iterator it = frases.begin(); it != frases.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}
