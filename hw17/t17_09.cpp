#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <algorithm>

class CustomString {
private:
    std::string str;
    std::unordered_set<char> allowed_chars;

    // Перевірка на допустимість символу
    bool isAllowed(char ch) const {
        return allowed_chars.find(ch) != allowed_chars.end();
    }

public:
    // Конструктор
    CustomString(const std::unordered_set<char>& allowed)
        : allowed_chars(allowed) {}

    // Метод введення з консолі
    void inputFromConsole() {
        std::cout << "Введіть рядок: ";
        std::string input;
        std::getline(std::cin, input);
        setString(input);
    }

    // Метод виведення в консоль
    void outputToConsole() const {
        std::cout << "Рядок: " << str << std::endl;
    }

    // Метод введення з файлу
    void inputFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Помилка відкриття файлу для читання!");
        }
        std::string input;
        std::getline(file, input);
        file.close();
        setString(input);
    }

    // Метод виведення у файл
    void outputToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Помилка відкриття файлу для запису!");
        }
        file << str;
        file.close();
    }

    // Встановлення нового рядка (фільтрація символів)
    void setString(const std::string& input) {
        str.clear();
        for (char ch : input) {
            if (isAllowed(ch)) {
                str += ch;
            }
        }
    }

    // Додавання допустимих символів
    void addAllowedChars(const std::unordered_set<char>& new_chars) {
        allowed_chars.insert(new_chars.begin(), new_chars.end());
    }

    // Видалення допустимих символів
    void removeAllowedChars(const std::unordered_set<char>& chars_to_remove) {
        for (char ch : chars_to_remove) {
            allowed_chars.erase(ch);
        }
    }

    // Отримання довжини рядка
    size_t length() const {
        return str.size();
    }

    // Конкатенація з іншим об'єктом CustomString
    void concatenate(const CustomString& other) {
        for (char ch : other.str) {
            if (isAllowed(ch)) {
                str += ch;
            }
        }
    }

    // Генерація хешу рядка
    size_t hash() const {
        std::hash<std::string> hasher;
        return hasher(str);
    }
};

int main() {
    // Встановлюємо допустимі символи
    std::unordered_set<char> allowed = {'a', 'b', 'c', '1', '2', '3', ' '};
    CustomString myString(allowed);

    try {
        // Введення з консолі
        myString.inputFromConsole();
        myString.outputToConsole();

        // Виведення у файл
        myString.outputToFile("output.txt");

        // Введення з файлу
        myString.inputFromFile("output.txt");
        myString.outputToConsole();

        // Додавання символів
        std::unordered_set<char> newChars = {'d', 'e', 'f'};
        myString.addAllowedChars(newChars);

        // Конкатенація
        CustomString anotherString(newChars);
        anotherString.setString("def 123");
        myString.concatenate(anotherString);
        myString.outputToConsole();

        // Хеш
        std::cout << "Хеш рядка: " << myString.hash() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
