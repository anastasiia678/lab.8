#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::string filename_in, filename_out;

    // Введення розміру масиву та імені вхідного файлу
    std::cout << "Введіть розмір масиву: ";
    std::cin >> n;
    std::cout << "Введіть ім'я вхідного файлу: ";
    std::cin >> filename_in;

    // Відкриття вхідного файлу та зчитування масиву
    std::ifstream input_file(filename_in);
    if (!input_file) {
        std::cerr << "Не вдалося відкрити файл " << filename_in << std::endl;
        return 1;
    }
    std::vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        input_file >> array[i];
    }
    input_file.close();

    // Потроєння елементів з непарними індексами
    std::transform(array.begin(), array.end(), array.begin(),
                   [index = 0](int element) mutable {
                       return (index++ % 2 != 0) ? element * 3 : element;
                   });

    // Введення імені вихідного файлу
    std::cout << "Введіть ім'я вихідного файлу: ";
    std::cin >> filename_out;

    // Запис масиву у вихідний файл
    std::ofstream output_file(filename_out);
    if (!output_file) {
        std::cerr << "Не вдалося створити файл " << filename_out << std::endl;
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        output_file << array[i] << " ";
    }
    output_file.close();

    std::cout << "Результати записано у файл " << filename_out << std::endl;

    return 0;
}
