#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

template <typename T>
class BlackBox {
private:
    std::vector<T> elements;
    static const size_t MAX_SIZE = 100;

public:
    // Порожній конструктор
    BlackBox() {
        std::srand(std::time(nullptr));
    }

    // Конструктор від масиву
    BlackBox(const T* array, size_t size) {
        if (size > MAX_SIZE) {
            throw std::overflow_error("Розмір масиву перевищує максимум!");
        }
        elements.assign(array, array + size);
        std::srand(std::time(nullptr));
    }

    // Метод для додавання елемента
    void push(const T& item) {
        if (elements.size() >= MAX_SIZE) {
            throw std::overflow_error("BlackBox заповнений!");
        }
        elements.push_back(item);
    }

    // Метод для видалення та повернення випадкового елемента
    T pop() {
        if (elements.empty()) {
            throw std::underflow_error("BlackBox порожній!");
        }
        size_t index = std::rand() % elements.size();
        T item = elements[index];
        elements.erase(elements.begin() + index);
        return item;
    }

    // Метод для повернення випадкового елемента (без видалення)
    T xpop() const {
        if (elements.empty()) {
            throw std::underflow_error("BlackBox порожній!");
        }
        size_t index = std::rand() % elements.size();
        return elements[index];
    }

    // Метод для отримання розміру
    size_t size() const {
        return elements.size();
    }

    // Перевірка, чи порожній
    bool isEmpty() const {
        return elements.empty();
    }
};

int main() {
    try {
        BlackBox<int> box;

        // Додавання елементів
        box.push(10);
        box.push(20);
        box.push(30);

        // Виведення випадкового елемента (без видалення)
        std::cout << "Випадковий елемент (xpop): " << box.xpop() << std::endl;

        // Видалення випадкового елемента
        std::cout << "Видалено випадковий елемент (pop): " << box.pop() << std::endl;

        // Розмір після видалення
        std::cout << "Розмір після видалення: " << box.size() << std::endl;

        // Тест із конструктором від масиву
        int array[] = {1, 2, 3, 4, 5};
        BlackBox<int> boxFromArray(array, 5);

        // Виведення випадкового елемента з нового об'єкта
        std::cout << "Випадковий елемент з boxFromArray: " << boxFromArray.xpop() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}
