#include <iostream>
#include <vector>
#include <algorithm> // std::lower_bound

using std::vector;
using std::cout;
using std::endl;

// Возвращает введенную пользователем цифру
int getUserDigit() {
    int input = 0;

    // Пока не будет введено нормальное число, выполняем цикл
    while (!(std::cin >> input)) {
        cout << "Error. Enter a number: ";
        // Сбрасываем коматозное состояние cin
        std::cin.clear();
        // Очищаем поток ввода
        fflush(stdin);
    }

    return input;
}

void setSortContainer(vector<int> &container, int value) {
    auto it = std::lower_bound(container.begin(), container.end(), value);
    container.insert(it, value);
};

int main() {
    enum USER_UI { PRINT = -1, EXIT = -2, ALL = -3 };
    const int PRINT_ITEM = 5;
    bool isProcess = true;

    vector<int> container;

    cout << "Menu:" << endl;
    cout << "Enter the value to be placed in the array.\n";
    cout << "Or enter " << USER_UI::PRINT << " to print the fifth element.\n";
    cout << "Or type " << USER_UI::EXIT << " to exit\n";
    cout << "Or type " << USER_UI::ALL << " to print the whole vector: ";

    while(isProcess) {
        int userInput = getUserDigit();

        switch(userInput) {
            case USER_UI::PRINT:
                if (container.size() >= PRINT_ITEM) {
                    cout << "Fifth element: " << (container[PRINT_ITEM] - 1) << endl;
                } else {
                    cout << "The fifth element doesn't exist yet :(" << endl;
                }
                break;
            case USER_UI::ALL:
                cout << "Vector consists of: ";
                for (int i : container) cout << i << " ";
                cout << endl;
                break;
            case USER_UI::EXIT:
                isProcess = false;
                break;
            default:
                setSortContainer(container, userInput);
                break;
        }

        cout << "Value, or " << USER_UI::PRINT << " to print fifth, or " << USER_UI::EXIT << " to exit, or " << USER_UI::ALL << " to print all: ";
    }
}

