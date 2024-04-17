#include <iostream>
#include <fstream>

// Функція для обміну двох елементів місцями
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Алгоритм сортування Шейкерна
void shaker_sort(int array[], int size) {
    bool swapped = true;
    int start = 0;
    int end = size - 1;

    while (swapped) {
        swapped = false;

        // Переміщення найбільшого елемента до кінця
        for (int i = start; i < end; ++i) {
            if (array[i] > array[i + 1]) {
                swap(array[i], array[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;

        // Зменшення "end", оскільки найбільший елемент уже на своєму місці
        --end;

        // Переміщення найменшого елемента до початку
        for (int i = end - 1; i >= start; --i) {
            if (array[i] > array[i + 1]) {
                swap(array[i], array[i + 1]);
                swapped = true;
            }
        }

        // Збільшення "start", оскільки найменший елемент уже на своєму місці
        ++start;
    }
}

// Функція для зчитування масиву з текстового файлу
void read_array_from_file(const std::string& filename, int array[], int size) {
    std::ifstream file(filename);
    int i = 0;
    int num;
    while (file >> num && i < size) {
        array[i++] = num;
    }
}

// Функція для виведення масиву в консоль
void print_array(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int size = 7; // Розмір масиву
    int array[size];

    // Зчитування масиву з файлу
    read_array_from_file("array.txt", array, size);

    // Виведення початкового масиву
    std::cout << "Початковий масив: ";
    print_array(array, size);

    // Сортування методом Шейкерна
    shaker_sort(array, size);

    // Виведення відсортованого масиву
    std::cout << "Відсортований масив: ";
    print_array(array, size);

    return 0;
}
