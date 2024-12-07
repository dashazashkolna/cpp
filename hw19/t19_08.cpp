#include <iostream>
#include <list>
#include <cmath>
#include <stdexcept>
#include <algorithm>

class NumberStorage {
private:
    std::list<int> numbers;

public:
    // Додавання числа
    void add(int number) {
        numbers.push_back(number);
    }

    // Видалення числа
    void remove(int number) {
        auto it = std::find(numbers.begin(), numbers.end(), number);
        if (it != numbers.end()) {
            numbers.erase(it);
        } else {
            throw std::runtime_error("Число не знайдено для видалення!");
        }
    }

    // Пошук числа, найближчого до заданого
    int findClosest(int target) const {
        if (numbers.empty()) {
            throw std::runtime_error("Список порожній, немає числа для пошуку!");
        }

        auto closest = numbers.begin();
        int minDifference = std::abs(*closest - target);

        for (auto it = numbers.begin(); it != numbers.end(); ++it) {
            int currentDifference = std::abs(*it - target);
            if (currentDifference < minDifference) {
                closest = it;
                minDifference = currentDifference;
            }
        }

        return *closest;
    }

    // Вивід усіх чисел
    void print() const {
        for (int number : numbers) {
            std::cout << number << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    try {
        NumberStorage storage;

        // Додавання чисел
        storage.add(10);
        storage.add(20);
        storage.add(30);
        storage.add(40);

        std::cout << "Числа в списку: ";
        storage.print();

        // Пошук найближчого числа
        int target = 25;
        std::cout << "Найближче до " << target << ": " << storage.findClosest(target) << "\n";

        // Видалення числа
        storage.remove(20);
        std::cout << "Числа після видалення 20: ";
        storage.print();

        // Спроба пошуку у порожньому списку (для перевірки виключень)
        storage.remove(10);
        storage.remove(30);
        storage.remove(40);
        storage.findClosest(15);  // Це викличе виключення

    } catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}
