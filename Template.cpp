// Модуль шаблонных функций. Дружинин М.Р. ИВТ-23

// Включение заголовочного файла шаблонных функций
#include "Template.h"

// Пространство имен стандартных функций C++
using namespace std;

namespace TemplateOperations {

    // Сохранение массива в текстовый файл.
    template <typename T>
    void saveArrayToTextFile(const T* arr, size_t n, const string& filename) {
        ofstream outfile(filename);
        if (!outfile) {
            throw runtime_error("Ошибка открытия файла для записи: " + filename);
        }
        for (int i = 0; i < n; ++i) {
            outfile << arr[i] << endl;
        }
        outfile.close();
    }

    // Сохранение вектора в текстовый файл.
    template <typename T>
    void saveArrayToTextFile(const vector<T>& vec, const string& filename) {
        ofstream outfile(filename);
        if (!outfile) {
            throw runtime_error("Ошибка открытия файла для записи: " + filename);
        }
        for (const T& element : vec) {
            outfile << element << endl;
        }
        outfile.close();
    }

    // Сохранение массива в бинарный файл.
    template <typename T>
    void saveArrayToBinaryFile(const T* arr, size_t n, const string& filename) {
        ofstream outfile(filename, ios::binary);
        if (!outfile) {
            throw runtime_error("Ошибка открытия файла для записи: " + filename);
        }
        outfile.write(reinterpret_cast<const char*>(arr), n * sizeof(T));
        outfile.close();
    }

    // Сохранение вектора в бинарный файл.
    template <typename T>
    void saveArrayToBinaryFile(const vector<T>& vec, const string& filename) {
        ofstream outfile(filename, ios::binary);
        if (!outfile) {
            throw runtime_error("Ошибка открытия файла для записи: " + filename);
        }
        outfile.write(reinterpret_cast<const char*>(vec.data()), vec.size() * sizeof(T));
        outfile.close();
    }

    // Чтение массива из текстового файла.
    template <typename T>
    T* loadArrayFromTextFile(size_t& n, const string& filename) {
        ifstream infile(filename);
        if (!infile) {
            throw runtime_error("Ошибка открытия файла для чтения: " + filename);
        }

        n = 0;
        T temp;
        while (infile >> temp) {
            ++n;
        }

        infile.clear();
        infile.seekg(0, ios::beg);

        T* arr = new T[n];
        for (int i = 0; i < n; ++i) {
            infile >> arr[i];
        }
        infile.close();
        return arr;
    }

    // Чтение вектора из текстового файла.
    template <typename T>
    void loadArrayFromTextFile(vector<T>& vec, const string& filename) {
        ifstream infile(filename);
        if (!infile) {
            throw runtime_error("Ошибка открытия файла для чтения: " + filename);
        }

        T temp;
        while (infile >> temp) {
            vec.push_back(temp);
        }
        infile.close();
    }

    // Вычисление суммы выражения (a1/0!)+(a2/1!)+...+(an/(n-1)!).
    template <typename T>
    double calculate(const T* arr, size_t n) {
        double result = 0;
        for (int i = 0; i < n; ++i) {
            result += arr[i] / factorial(i);
        }
        return result;
    }

    // Вычисление суммы выражения (a1/0!)+(a2/1!)+...+(an/(n-1)!).
    template <typename T>
    double calculate(const vector<T>& vec) {
        double result = 0;
        for (size_t i = 0; i < vec.size(); ++i) {
            result += vec[i] / factorial(i);
        }
        return result;
    }

    // Заполнение массива случайными числами от 1 до 100.
    template <typename T>
    void fillArrayRandom(T* arr, size_t n) {
        if (n <= 0) {
            throw invalid_argument("Размер массива не должен быть меньше 1");
        }
        srand(static_cast<unsigned int>(time(nullptr)));
        for (int i = 0; i < n; ++i) {
            arr[i] = static_cast<T>((rand() % 100) + 1);
        }
    }

    // Заполнение вектора случайными числами от 1 до 100.
    template <typename T>
    void fillArrayRandom(vector<T>& vec) {
        srand(static_cast<unsigned int>(time(nullptr)));
        for (T& element : vec) {
            element = static_cast<T>((rand() % 100) + 1);
        }
    }

    // Вывод массива на экран.
    template <typename T>
    void printArray(const T* arr, size_t n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Вывод вектора на экран.
    template <typename T>
    void printArray(const vector<T>& vec) {
        for (const T& val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }

} 