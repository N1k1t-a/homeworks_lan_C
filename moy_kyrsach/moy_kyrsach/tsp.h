#pragma once

#include <vector>
#include <string>

/**
 * @brief Структура для хранения результата решения задачи коммивояжера
 */
struct TSPResult {
    std::vector<int> bestPath;  // Оптимальный маршрут
    int minDistance;            // Минимальная длина маршрута
};

/**
 * @brief Загружает граф из файла
 * @param filename Имя входного файла
 * @param graph Матрица смежности графа (выходной параметр)
 * @return true если загрузка успешна, false в противном случае
 */
bool loadGraph(const std::string& filename, std::vector<std::vector<int>>& graph);

/**
 * @brief Вычисляет длину заданного маршрута
 * @param graph Матрица смежности графа
 * @param path Маршрут (последовательность вершин)
 * @return Длина маршрута, -1 если маршрут невозможен
 */
int calculatePathLength(const std::vector<std::vector<int>>& graph, const std::vector<int>& path);

/**
 * @brief Решает задачу коммивояжера переборным алгоритмом
 * @param graph Матрица смежности графа
 * @return Результат решения (оптимальный маршрут и его длина)
 */
TSPResult solveTSP(const std::vector<std::vector<int>>& graph);

/**
 * @brief Сохраняет результат в формате Graphviz DOT
 * @param filename Имя выходного файла
 * @param graph Матрица смежности графа
 * @param result Результат решения задачи
 * @return true если сохранение успешно, false в противном случае
 */
bool saveGraphviz(const std::string& filename,
                  const std::vector<std::vector<int>>& graph,
                  const TSPResult& result);
