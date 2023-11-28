#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <Windows.h>

void generateFrequencyDictionary(const std::string& inputFileName, const std::string& outputFileName) {
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл: " << inputFileName << std::endl;
        return;
    }

    // Словарь для хранения частоты слов
    std::map<std::string, int> wordFrequency;

    std::string word;
    while (inputFile >> word) 
        wordFrequency[word]++;

    inputFile.close();

    // Вывод информации обо всех словах
    std::cout << "Частотный словарь слов:" << std::endl;
    for (const auto& pair : wordFrequency) 
    {
        std::cout << pair.first << ": " << pair.second << " раз" << std::endl;
    }

    // нахождение наиболее часто встречающеегося слова
    auto mostFrequentWord = std::max_element(
        wordFrequency.begin(), wordFrequency.end(),
        [](const auto& a, const auto& b) { return a.second < b.second; });

    std::cout << "Наиболее часто встречающееся слово: " << mostFrequentWord->first
        << " (встречается " << mostFrequentWord->second << " раз)" << std::endl;

    // Запись результата в файл
    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) 
    {
        std::cerr << "Не удалось создать файл: " << outputFileName << std::endl;
        return;
    }

    for (const auto& pair : wordFrequency) 
    {
        outputFile << pair.first << ": " << pair.second << " раз" << std::endl;
    }

    std::cout << "Результат записан в файл: " << outputFileName << std::endl;

    outputFile.close();
}

int main() 
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string inputFileName = "inputFileName.txt"; 
    std::string outputFileName = "outputFileName.txt";

    generateFrequencyDictionary(inputFileName, outputFileName);

    return 0;
}
