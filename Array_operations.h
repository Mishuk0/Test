/// Заголовочный файл для модуля операций над массивами. Дружинин М.Р. ИВТ-23

// Директивы защиты от "множественного включения"
#ifndef ARRAY_OPERATIONS_H
#define ARRAY_OPERATIONS_H

// Подключение стандартной библиотеки iostream для ввода/вывода
#include <iostream>

// Подключение библиотеки для работы с файлами
#include <fstream>

// Подключение библиотеки для доступа к функции генерации случайных чисел
#include <cstdlib>

// Подключение библиотеки для доступа к исключениям
#include <stdexcept>

// Подключение библиотеки для доступа к функциям, связанным с датой и временем
#include <ctime>

// Подключение библиотеки для работы с векторами
#include <vector>

#include <cassert>

// Пространство имен стандартных функций C++
using namespace std;

// Пространство имен модуля операций с массивами
namespace ArrayOperations {

    // Сохранение массива в текстовый файл. Входные данные: массив, длина массива, имя файла.
    void saveArrayToTextFile(const double* arr, size_t n, const string& filename);

    // Сохранение массива в текстовый файл. Входные данные: вектор, имя файла.
    void saveArrayToTextFile(const vector<double>& vec, const string& filename);

    // Сохранение массива в бинарный файл. Входные данные: массив, длина массива, имя файла.
    void saveArrayToBinaryFile(const double* arr, size_t n, const string& filename);

    // Сохранение массива в бинарный файл. Входные данные: вектор, имя файла.
    void saveArrayToBinaryFile(const vector<double>& vec, const string& filename);

    // Чтение массива из текстового файла. Входные данные: переменная которая будет хранить длину массива, имя файла.
    double* loadArrayFromTextFile(size_t& n, const string& filename);

    // Чтение массива из текстового файла. Входные данные: вектор, имя файла.
    void loadArrayFromTextFile(vector<double>& vec, const string& filename);

    // Вычисление суммы выражения (a1/0!)+(a2/1!)+...+(an/(n-1)!). Входные данные: массив, длина массива.
    double calculate(const double* arr, size_t n);

    // Вычисление суммы выражения (a1/0!)+(a2/1!)+...+(an/(n-1)!). Входные данные: вектор.
    double calculate(const std::vector<double>& vec);

    // Вычисление факториала. Входные данные: число.
    double factorial(size_t n);

    // Сохранение результата в текстовый файл. Входные данные: массив, имя файла.
    void saveResult(double result, const string& filename);

    // Функция для заполнения массива случайными числами от 1 до 100. Входные данные: массив, длина массива.
    void fillArrayRandom(double* arr, size_t n);

    // Функция для заполнения массива случайными числами от 1 до 100. Входные данные: вектор.
    void fillArrayRandom(vector<double>& vec);

    // Функция для вывода массива на экран. Входные данные: массив, длина массива.
    void printArray(double* arr, size_t n);

    // Функция для вывода массива на экран. Входные данные: вектор.
    void printArray(const vector<double>& vec);

    // Проверка вычисления факториала
    void testFactorial();
    // Проверка вычислений ряда
    void testCalculate();
    // Проверка заполнения случайными числами
    void testFillArrayRandom();
    // Проверка сохранения и загрузки вектора
    void testSaveAndLoadArray();
    // Функция запуска тестов
    void runAllTests();
}
#endif