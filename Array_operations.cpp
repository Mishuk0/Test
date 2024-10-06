/// Модуль операций над массивами. Дружинин М.Р. ИВТ-23

// Включения заголовочного файла модуля операций с массивами
#include "Array_operations.h"

// Пространство имен стандартных функций C++
using namespace std;


namespace ArrayOperations {

    // Сохранение массива в текстовый файл. Входные данные: массив, длина массива, имя файла.
    void saveArrayToTextFile(const double* arr, size_t n, const string& filename) {
        ofstream outfile(filename);
        if (!outfile) {
            throw runtime_error("Ошибка открытия файла для записи: " + filename);
        }
        for (int i = 0; i < n; ++i) {
            outfile << arr[i] << endl;
        }
        outfile.close();
    }

    // Сохранение массива в текстовый файл. Входные данные: вектор, имя файла.
    void saveArrayToTextFile(const vector<double>& vec, const string& filename) {
        std::ofstream outfile(filename);
        if (!outfile) {
            throw std::runtime_error("Error opening file for writing: " + filename);
        }
        for (const double& element : vec) {
            outfile << element << std::endl;
        }
        outfile.close();
    }

    // Сохранение массива в бинарный файла. Входные данные: массив, длина массива, имя файла.
    void saveArrayToBinaryFile(const double* arr, size_t n, const string& filename) {
        ofstream outfile(filename, ios::binary);
        if (!outfile) {
            throw runtime_error("Ошибка открытия файла для записи: " + filename);
        }
        outfile.write(reinterpret_cast<const char*>(arr), n * sizeof(double));
        outfile.close();
    }

    // Сохранение массива в бинарный файла. Входные данные: вектор, имя файла.
    void saveArrayToBinaryFile(const vector<double>& vec, const string& filename) {
        ofstream outfile(filename, ios::binary);
        if (!outfile) {
            throw runtime_error("Ошибка открытия файла для записи: " + filename);
        }

        // Записываем данные вектора в файл.
        outfile.write(reinterpret_cast<const char*>(vec.data()), vec.size() * sizeof(double));

        outfile.close();
    }

    // Чтение массива из текстового файла. Входные данные: переменная которая будет хранить длину массива, имя файла.
    double* loadArrayFromTextFile(size_t& n, const string& filename) {
        ifstream infile(filename);
        if (!infile) {
            throw runtime_error("Ошибка открытия файла для чтения: " + filename);
        }
        n = 0;
        double temp;
        while (infile >> temp) {
            ++n;
        }
        infile.clear();
        infile.seekg(0, ios::beg);

        double* arr = new double[n];
        for (int i = 0; i < n; ++i) {
            infile >> arr[i];
        }
        infile.close();
        return arr;
    }

    // Чтение массива из текстового файла. Входные данные: вектор, имя файла.
    void loadArrayFromTextFile(vector<double>& vec, const string& filename) {
        ifstream infile(filename);
        if (!infile) {
            throw runtime_error("Ошибка открытия файла для чтения: " + filename);
        }
        double temp;
        while (infile >> temp) {
            // Добавляем каждый считанный элемент в конец вектора.
            vec.push_back(temp); 
        }
        infile.close();
    }

    // Вычисление суммы выражения (a1/0!)+(a2/1!)+...+(an/(n-1)!). Входные данные: массив, длина массива.
    double calculate(const double* arr, size_t n) {
        double result = 0;
        for (int i = 0; i < n; ++i) {
            result += arr[i] / factorial(i);
        }
        return result;
    }

    // Вычисление суммы выражения (a1/0!)+(a2/1!)+...+(an/(n-1)!). Входные данные: вектор.
    double calculate(const vector<double>& vec) {
        double result = 0;
        for (size_t i = 0; i < vec.size(); ++i) {
            result += vec[i] / factorial(i);
        }
        return result;
    }

    // Вычисление факториала. Входные данные: число.
    double factorial(size_t n) {
        if (n == 0) {
            return 1.0;
        } else {
        return n * factorial(n - 1);
        }
    }

    // Сохранение результата в текстовый файл. Входные данные: массив, имя файла.
    void saveResult(double result, const string& filename) {
        ofstream outfile(filename);
        if (!outfile) {
            throw runtime_error("Ошибка открытия файла для записи: " + filename);
        }
        outfile << result << endl;
        outfile.close();
    }

    // Функция для заполнения массива случайными числами от 1 до 100. Входные данные: массив, длина массива.
    void fillArrayRandom(double* arr, size_t n) {
        if (n <= 0) {
            throw invalid_argument("Размер массива не должен быть меньше 1");
        }

        // Инициализация генератора случайных чисел (один раз при первом вызове)
        srand(static_cast<unsigned int>(time(nullptr)));

        for (int i = 0; i < n; ++i) {
            arr[i] = (rand() % 100) + 1;  // Генерация случайного числа от 1 до 100
        }
    }

    // Функция для заполнения массива случайными числами от 1 до 100. Входные данные: вектор.
    void fillArrayRandom(vector<double>& vec) {
        srand(static_cast<unsigned int>(time(nullptr)));
        for (double& element : vec) {
            element = (std::rand() % 100) + 1;
        }
    }

    // Функция для вывода массива на экран. Входные данные: массив, длина массива.
    void printArray(double* arr, size_t n) {
        for (int i = 0; i <= n - 1; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Функция для вывода массива на экран. Входные данные: вектор.
    void printArray(const vector<double>& vec) {
        for (double val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }

    // ФУНКЦИИ ТЕСТОВ

    // Проверка вычисления факториала
    void testFactorial() {
        assert(factorial(0) == 1);
        assert(factorial(1) == 1);
        assert(factorial(2) == 2);
        assert(factorial(3) == 6);
        assert(factorial(4) == 24);
        assert(factorial(5) == 120);
    }

    // Проверка вычислений ряда
    void testCalculate() {
        vector<double> vec1 = {1.0, 2.0, 3.0};
        assert(calculate(vec1) == 1.0 / 1 + 2.0 / 1 + 3.0 / 2); // (1/0!) + (2/1!) + (3/2!)

        vector<double> vec2 = {0.0, 0.0, 0.0};
        assert(calculate(vec2) == 0.0); // Все элементы равны нулю, результат должен быть 0
    }

    // Проверка заполнения случайными числами
    void testFillArrayRandom() {
        size_t n = 10;
        double* arr = new double[n];
        fillArrayRandom(arr, n);
    
        for (size_t i = 0; i < n; ++i) {
            assert(arr[i] >= 1 && arr[i] <= 100);
        }
        delete[] arr;
    }

    // Проверка сохранения и загрузки вектора
    void testSaveAndLoadArray() {
        vector<double> vec = {1.0, 2.0, 3.0};
        string filename = "test_output.txt";

        // Сохранение массива в текстовый файл и чтение из него
        saveArrayToTextFile(vec, filename);
        vector<double> loadedVec;
        loadArrayFromTextFile(loadedVec, filename);

        assert(vec == loadedVec); // Проверяем, что загруженные данные совпадают с сохраненными
    }

    // Функция запуска тестов
    void runAllTests() {
        testFactorial();
        testCalculate();
        testFillArrayRandom();
        testSaveAndLoadArray();
    }
}