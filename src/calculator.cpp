#include "../include/calculator.h"
#include <stdexcept>
#include <limits>
#include <vector>
using namespace std;

namespace calculator {

    int add_operation = 0, subtract_operation = 0, multiply_operation = 0, divide_operation = 0;
    char favOperation = '+';

    vector<calculation> history;

    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (b == 0) {
            return numeric_limits<double>::infinity();
        }

        return a / b;
    }

    void addToHistory(double num1, double num2, char operation, double result) {

        switch(operation) {
            case '+':
                add_operation += 1;
                break;
            case '-':
                subtract_operation += 1;
                break;
            case '*':
                multiply_operation += 1;
                break;
            case '/':
                divide_operation += 1;
                break;
            default:
                cout << "An error occurred while checking the operation symbol!" << endl;
                break;
        }

        history.push_back({num1, num2, operation, result});
        return;
    }

    void showHistory() {
        cout << "\n====HISTORY====" << endl;

        if (history.empty()) {
            cout << "History is empty..." << endl;
            return;
        }

        for (int i = 0; i < history.size(); i++) {
            cout << history[i].num1 << " " << history[i].operation << " " << history[i].num2 << " = " << history[i].result << endl;
        }
    }

    void clearHistory() {
        history.clear();

        cout << "History was cleaned!" << endl;
    }

    void showStatistics() {
        cout << "\n====STATISTICS====" << endl;
        cout << "Number of operations: " << history.size() << endl;

        if (!(history.size() == 0)) {
            findFavOperation();
            cout << "Your favorite operation: " << favOperation << endl;
            return;
        }

        cout << "Your favorite operation: None" << endl;
    }

    void findFavOperation() {
        int max_count = add_operation;
        
        if (add_operation > subtract_operation) {
            max_count = add_operation;
            favOperation = '+';
        } if (subtract_operation > max_count) {
            max_count = subtract_operation;
            favOperation = '-';
        } if (multiply_operation > max_count) {
            max_count = multiply_operation;
            favOperation = '*';
        } if (divide_operation > max_count) {
            max_count = divide_operation;
            favOperation = '/';
        }
    }

    bool run() {
        char continue_program = 'y';

        system("clear");

        while (continue_program == 'y' || continue_program == 'Y') {
            int menuIndex;
            double firstNumber, secondNumber;
            char operation, clear_history;

            cout << "====C++ CALCULATOR====\n" << endl;
            cout << "Program menu:" << endl;
            cout << "1. Calculator" << endl;
            cout << "2. History" << endl;
            cout << "3. Statistics" << endl;
            cout << "4. Exit\n" << endl;
            cout << "Choose menu index: ";
            cin >> menuIndex;

            switch(menuIndex) {
                case 1:
                    cout << "\n====CALCULATE====" << endl;
                    cout << "Enter first number: ";
                    cin >> firstNumber;

                    if (cin.fail()) {
                        cout << "Error ocurred!" << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        continue;
                    }

                    cout << "Enter second number: ";
                    cin >> secondNumber;

                    if (cin.fail()) {
                        cout << "Error ocurred!" << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        continue;
                    }

                    cout << "Your numbers: " << firstNumber << " and " << secondNumber << endl;
                    cout << "Which operation would you like?(+, -, *, /): ";
                    cin >> operation;

                    switch (operation) {
                        double result;

                        case '+':
                            result = add(firstNumber, secondNumber);
                            cout << "Result: " << result << endl;
                            addToHistory(firstNumber, secondNumber, operation, result);
                            break;
                        case '-':
                            result = subtract(firstNumber, secondNumber);
                            cout << "Result: " << result << endl;
                            addToHistory(firstNumber, secondNumber, operation, result);
                            break;
                        case '*':
                            result = multiply(firstNumber, secondNumber);
                            cout << "Result: " << result << endl;
                            addToHistory(firstNumber, secondNumber, operation, result);
                            break;
                        case '/':
                            result = divide(firstNumber, secondNumber);
                            cout << "Result: " << result << endl;
                            addToHistory(firstNumber, secondNumber, operation, result);
                            break;
                        default:
                            cout << "Error: Invalid operation!" << endl;
                            break;
                    }

                    cout << "\nContinue program?(y/n): ";
                    cin >> continue_program;

                    system("clear");

                    cin.ignore(1000, '\n');

                    break;
                
                case 2:
                    showHistory();

                    if (!history.empty()) {
                        cout << "\nClear history?(y/n): ";
                        cin >> clear_history;

                        if (clear_history == 'y' || clear_history == 'Y') {
                            clearHistory();
                        }
                    }

                    cout << "\nContinue program?(y/n): ";
                    cin >> continue_program;

                    system("clear");

                    cin.ignore(1000, '\n');

                    break;

                case 3:
                    showStatistics();

                    cout << "\nContinue program?(y/n): ";
                    cin >> continue_program;

                    system("clear");

                    cin.ignore(1000, '\n');
                    
                    break;

                case 4:
                    cout << "Closing programm..." << endl;
                    return true;

                default:
                    cout << "Invalid input!" << endl;
                    return false;
            }

        }

        cout << "Closing program..." << endl;
        return true;
    }
}