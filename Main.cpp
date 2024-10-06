/// Главный файл программы. Дружинин М.Р. ИВТ-23

/*
Даны натуральное число n, действительные числа a1,..., an. Вычислить:
(a1/0!)+(a2/1!)+...+(an/(n-1)!)
*/

// Подключение стандартной библиотеки iostream для ввода/вывода
#include <iostream>

// Подключение библиотеки для конвертации строки в число с плавающей запятой
#include <string>

// Подклюючение Windows API для подключения функций работы с операционной системой Windows
#include <Windows.h>

// Включение заголовочное файла модуля операций с массивами
#include "array_operations.h"

// Пространство имен стандартных функций C++
using namespace std;

// Пространство имен модуля операций с массивами
using namespace ArrayOperations;

// Функция вывода подсказки
void printHelp() {
         cout << "Использование программы для вычисления суммы ряда:\n"
              << "Стандартный запуск без аргументов: ./Имя_исполняемого_файла\n"
              << "Входные данные:\n"
              << "  help, --help         Показывает подсказку\n"
              << "  a1 a2 a3 ... an      Элементы ряда\n"
              << "  Имя_файла.txt(.bin)  Имя файла откуда считывать данные\n";
}

// Главная функция программы
int main(int argc, char* argv[]) {

    // Запуск тестов
    runAllTests();

    // Смена кодировки вывода терминала
    SetConsoleOutputCP(CP_UTF8);

    double* arr = nullptr;
    size_t n = 0;
    char choice;

    try {
        if (argc > 1) {
            if (strcmp(argv[1], "help") == 0 || strcmp(argv[1], "--help") == 0) {
                printHelp();
                return 0;
            }

            // Если аргументов 2
            if (argc == 2) {
                arr = loadArrayFromTextFile(n, argv[1]); // Чтение из файла
            } else {
                // Входные данные как числа
                n = argc - 1;
                arr = new double[n];
                for (int i = 0; i < n; ++i) {
                    arr[i] = stod(argv[i + 1]);
                }
            }

            double result = calculate(arr, n); // Расчёт суммы ряда
            cout << "Результат: " << result << endl;

            // Сохранение результата
            cout << "Сохранить результаты в текстовый файл? (y): ";
            cin >> choice;
            if (choice == 'y') {
                saveResult(result, "Result.txt");
                cout << "Результат сохранен в Result.txt\n";
            } 

            // Освобождение памяти
            delete[] arr;

        } else {
            // Ввод данных вручную
            cout << "Введите количество элементов: ";
            cin >> n;
            arr = new double[n];
            cout << "Хотите заполнить массив вручную(m) или заполнить случайными(r) числами? (m/r) ";
            cin >> choice;
            if (choice == 'm') {
                cout << "Введите элементы a1,..., an: ";
                for (int i = 0; i < n; ++i) {
                    cin >> arr[i];
                }
            } else if (choice == 'r') {
                fillArrayRandom(arr, n);
                cout << "Массив, заполненный случайными числами: ";
                printArray(arr, n);
            }
    
            double result = calculate(arr, n); // Расчёт суммы ряда
            cout << "Результат: " << result << endl;

            // Сохранение результата
            cout << "Сохранить результаты в текстовый файл? (y): ";
            cin >> choice;
            if (choice == 'y') {
                saveResult(result, "Result.txt");
                cout << "Результат сохранен в Result.txt\n";
            } 

            // Сохранение введенного массива в файл?
            cout << "Сохранить введенные элементы в текстовый(t) или бинарный(b) файл? (t/b): ";
            cin >> choice;
            if (choice == 't') {
                saveArrayToTextFile(arr, n, "output.txt");
                cout << "Элементы сохранены в output.txt\n";
            } else if (choice == 'b') {
                saveArrayToBinaryFile(arr, n, "output.bin");
                cout << "Элементы сохранены в output.bin\n";
            } 

            // Освобождение памяти
            delete[] arr;
        }

    } catch (const exception& ex) {
        cerr << "Error: " << ex.what() << endl;
        if (arr) {
            delete[] arr;
        }
        return 1;
    }

    return 0;
}