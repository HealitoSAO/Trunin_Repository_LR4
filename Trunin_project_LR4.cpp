#include <iostream> 
#include <map> 
#include <string> 
#include <functional>

using namespace std;

// Глобальные переменные 
int A, B, C;

// Функция ввода данных 
function<void()> EnterNumber(int& varLink, string label) { 
    return [&varLink, label]() {
        string raw_input;
        cout << label << ": ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер
        getline(cin, raw_input);
        
        // Цикл для повторного запроса числа, пока не будет введено корректное значение
        while (true) {
            bool isValid = true; // Флаг для проверки корректности ввода
            
            // Проверка, является ли строка корректным целым числом
            if (raw_input.empty() || (raw_input[0] != '-' && !isdigit(raw_input[0]))) {
                isValid = false;
            } else {
                for (size_t i = 1; i < raw_input.length(); ++i) {
                    if (!isdigit(raw_input[i])) {
                        isValid = false;
                        break;
                    }
                }
            }
            if (isValid) {
                varLink = stoi(raw_input); // Преобразуем строку в целое число
                break; // Выход из цикла, если ввод корректен
            } else {
                cout << "Nekorektniy vvod. " << label << ": ";
                getline(cin, raw_input); // Запрашиваем ввод снова
            }
        }
    };
}

// Функция для вычисления остатка от деления разности A и B на C 
void CalcRemainder() { 
    if (C != 0) {
        int remainder = (A - B) % C;
        cout << "Ostatok ot deleniya raznosti A i B na C: " << remainder << endl;
    } else {
        cout << "Oshibka: Delitel C ne mojet byt' nulem " << endl;
    }
}

// Функция для нахождения целой части от деления A на (B + C) 
void CalcIntegerDivision() { 

}

// Структура меню 
struct MenuItem { 
    string title; function<void()> action; 
};

int main() { 
    map<int, MenuItem> menu = { 
        {1, {"Input integer A",  EnterNumber(A, "Enter A") }}, 
        {2, {"Input integer B",  EnterNumber(B, "Enter B") }}, 
        {3, {"Input integer C",  EnterNumber(C, "Enter C") }}, 
        {4, {"Calculate remainder of difference A and B on C", CalcRemainder}}, 
        {5, {"Calculate integer part of division A on (B + C)", CalcIntegerDivision}},
    };
    int choice = 0;
    while (true) {
        cout << "Меню:" << endl;
        for (const auto& item : menu) {
            cout << "Задача " << item.first << ". " << item.second.title << endl;
        }
        cout << "0. Выход" << endl;
        cout << "Введите ваш выбор: ";
        cin >> choice;

        if (choice == 0) {
            cout << "© 2025 First Name LastName" << endl;
            break;
        }

        cout << endl;
        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        } else {
            cout << "Некорректный ввод." << endl;
        }
        cout << endl;
    }
    return 0;
}