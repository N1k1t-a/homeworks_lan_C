#include "tsp.h"
#include <iostream>

/**
 * @brief Точка входа в программу
 * @param argc Количество аргументов командной строки
 * @param argv Массив аргументов командной строки
 * @return Код возврата (0 - успех, 1 - ошибка)
 */
int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << std::endl;
        std::cerr << "Example: " << argv[0] << " input.txt output.dot" << std::endl;
        return 1;
    }

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];

    // Загрузка графа из файла
    std::vector<std::vector<int>> graph;
    if (!loadGraph(inputFile, graph)) {
        return 1;
    }

    std::cout << "Graph loaded successfully. Vertices: " << graph.size() << std::endl;

    // Решение задачи коммивояжера
    std::cout << "Solving TSP..." << std::endl;
    TSPResult result = solveTSP(graph);

    if (result.bestPath.empty()) {
        std::cerr << "Error: No solution found" << std::endl;
        return 1;
    }

    // Вывод результата в консоль
    std::cout << "Optimal path: ";
    for (size_t i = 0; i < result.bestPath.size(); i++) {
        std::cout << result.bestPath[i];
        if (i < result.bestPath.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << " -> " << result.bestPath[0] << std::endl;
    std::cout << "Minimum distance: " << result.minDistance << std::endl;

    // Сохранение результата в файл
    if (!saveGraphviz(outputFile, graph, result)) {
        return 1;
    }

    std::cout << "Result saved to " << outputFile << std::endl;

    return 0;
}
