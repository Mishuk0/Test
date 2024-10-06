/// Заголовочный файл модуля шаблонных функций. Дружинин М.Р. ИВТ-23

// Директивы защиты от "множественного включения"
#ifndef TEMPLATE_ARRAY_OPERATIONS_H
#define TEMPLATE_ARRAY_OPERATIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

// Пространство имен стандартных функций C++
using namespace std;

namespace TemplateOperations {

    // Сохранение массива в текстовый файл.
    template <typename T>
    void saveArrayToTextFile(const T* arr, size_t n, const string& filename);

    // Сохранение вектора в текстовый файл.
    template <typename T>
    void saveArrayToTextFile(const vector<T>& vec, const string& filename);

    // Сохранение массива в бинарный файл.
    template <typename T>
    void saveArrayToBinaryFile(const T* arr, size_t n, const string& filename);

    // Сохранение вектора в бинарный файл.
    template <typename T>
    void saveArrayToBinaryFile(const vector<T>& vec, const string& filename);

    // Чтение массива из текстового файла.
    template <typename T>
    T* loadArrayFromTextFile(size_t& n, const string& filename);
    
    // Чтение вектора из текстового файла.
    template <typename T>
    void loadArrayFromTextFile(vector<T>& vec, const string& filename);

    // Вычисление суммы выражения (a1/0!)+(a2/1!)+...+(an/(n-1)!).
    template <typename T>
    double calculate(const T* arr, int n);

    // Вычисление суммы выражения (a1/0!)+(a2/1!)+...+(an/(n-1)!).
    template <typename T>
    double calculate(const vector<T>& vec);

    // Заполнение массива случайными числами от 1 до 100.
    template <typename T>
    void fillArrayRandom(T* arr, size_t n);

    // Заполнение вектора случайными числами от 1 до 100.
    template <typename T>
    void fillArrayRandom(vector<T>& vec);

    // Вывод массива на экран.
    template <typename T>
    void printArray(const T* arr, size_t n);

    // Вывод вектора на экран.
    template <typename T>
    void printArray(const vector<T>& vec);

} 
#endif 