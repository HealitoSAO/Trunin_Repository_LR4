#include <iostream> 
#include <map> 
#include <string> 
#include <functional>

using namespace std;

// Глобальные переменные 
int A, B, C;

// Функция ввода данных 
function<void()> EnterNumber(int& varLink, string label) { 
    
}

// Функция для вычисления остатка от деления разности A и B на C 
void CalcRemainder() { 

}

// Функция для нахождения целой части от деления A на (B + C) 
void CalcIntegerDivision() { 
    if (B + C != 0) {
        int integerPart = A / (B + C);
        cout << "Tsela ot deleniya A na (B + C): " << integerPart << endl;
    } else {
        cout << "Ot deleniya na (B + C) ne mozhno " << endl;
    }
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