#include <iostream>
#include <string>
using namespace std;

struct Human {
    string name;
    string surname;
    char sex;
    int day, month, year;
};

int surname_letter(Human* employees, int n, char letter, Human* found_employees) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (employees[i].surname[0] == letter) {
            found_employees[count] = employees[i];
            count++;
        }
    }
    return count;
}

Human oldest(Human* employees, int n) {
    Human oldest_male;
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (employees[i].sex == 'M') {
            if (!found || (employees[i].year < oldest_male.year) ||
                (employees[i].year == oldest_male.year && employees[i].month < oldest_male.month) ||
                (employees[i].year == oldest_male.year && employees[i].month == oldest_male.month && employees[i].day < oldest_male.day)) {
                oldest_male = employees[i];
                found = true;
            }
        }
    }

    if (!found) {
        oldest_male = {"", "", ' ', 0, 0, 0};
    }

    return oldest_male;
}

int main() {
    int n;
    cout << "К-сть співробітників: ";
    cin >> n;
    Human* employees = new Human[n];

    for (int i = 0; i < n; i++) {
        cout << "Співробітник #" << i + 1 << ":" << endl;
        cout << "Прізвище: ";
        cin >> employees[i].surname;
        cout << "Ім'я: ";
        cin >> employees[i].name;
        cout << "Стать (M/F): ";
        cin >> employees[i].sex;
        cout << "Дата народження (день місяць рік): ";
        cin >> employees[i].day >> employees[i].month >> employees[i].year;
    }

    char letter;
    cout << "\nВведіть першу літеру за прізвищем: ";
    cin >> letter;

    Human* found_employees = new Human[n];
    int found_count = surname_letter(employees, n, letter, found_employees);

    if (found_count > 0) {
        cout << "\nСпівробітники, прізвища яких починаються на '" << letter << "':" << endl;
        for (int i = 0; i < found_count; i++) {
            cout << found_employees[i].surname << " " << found_employees[i].name << " "
                 << found_employees[i].day << "." << found_employees[i].month << "." << found_employees[i].year << endl;
        }
    } else {
        cout << "Співробітників з прізвищем на літеру '" << letter << "' не знайдено." << endl;
    }

    // Пошук найстаршого чоловіка
    Human oldest_male = oldest(employees, n);
    if (oldest_male.sex == 'M') {
        cout << "\nНайстарший чоловік:" << endl;
        cout << oldest_male.surname << " " << oldest_male.name << " "
             << oldest_male.day << "." << oldest_male.month << "." << oldest_male.year << endl;
    }

    delete[] employees;
    delete[] found_employees;

    return 0;
}
