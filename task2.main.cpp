#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

// Функція для генерації випадкових чисел у діапазоні [min, max]
int generate_random(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Функція для зчитування матриці з файлу
void read_matrix_from_file(const std::string& filename, int** matrix, int rows, int cols) {
    std::ifstream file(filename);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            file >> matrix[i][j];
        }
    }
}

// Функція для запису матриці у файл
void write_matrix_to_file(const std::string& filename, int** matrix, int rows, int cols) {
    std::ofstream file(filename);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            file << matrix[i][j] << " ";
        }
        file << std::endl;
    }
    file.close();
}

// Функція для пошуку максимального елемента у кожному стовпці
void find_max_in_columns(int** matrix, int rows, int cols, int* max_values) {
    for (int j = 0; j < cols; ++j) {
        int max_val = matrix[0][j];
        for (int i = 1; i < rows; ++i) {
            if (matrix[i][j] > max_val) {
                max_val = matrix[i][j];
            }
        }
        max_values[j] = max_val;
    }
}

int main() {
    srand(time(NULL)); // Ініціалізація генератора випадкових чисел

    int M, N;

    // Введення розмірів матриці
    std::cout << "Введіть кількість рядків матриці: ";
    std::cin >> M;
    std::cout << "Введіть кількість стовпців матриці: ";
    std::cin >> N;

    // Виділення пам'яті під матрицю та масив максимальних значень
    int** matrix = new int*[M];
    for (int i = 0; i < M; ++i) {
        matrix[i] = new int[N];
    }
    int* max_values = new int[N];

    // Генерація та виведення вихідної матриці
    std::cout << "Вихідна матриця:" << std::endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = generate_random(1, 100); // Генерація випадкового числа в діапазоні [1, 100]
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Запис вихідної матриці у файл
    write_matrix_to_file("matr_in_n.txt", matrix, M, N);

    // Пошук максимального елемента у кожному стовпці
    find_max_in_columns(matrix, M, N, max_values);

    // Дописування максимальних елементів у файл
    std::ofstream file("matr_in_n.txt", std::ios_base::app);
    file << "Максимальні елементи у кожному стовпці:" << std::endl;
    for (int j = 0; j < N; ++j) {
        file << max_values[j] << " ";
    }
    file << std::endl;
    file.close();

    // Звільнення пам'яті
    for (int i = 0; i < M; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] max_values;

    return 0;
}
