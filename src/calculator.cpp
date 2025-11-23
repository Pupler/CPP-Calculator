#include "../include/calculator.h"
#include <stdexcept>
#include <limits>
#include <vector>
using namespace std;

namespace calculator {

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
        history.push_back({num1, num2, operation, result});

        // cout << history.back().num1 << " " << history.back().operation << " " << history.back().num2 << " = " << history.back().result << endl;
    }

    bool run() {
        char continue_program = 'y';
        char clear_console;

        system("clear");

        while (continue_program == 'y' || continue_program == 'Y') {
            int menuIndex;
            double firstNumber, secondNumber;
            char operation;

            cout << "====C++ CALCULATOR====\n" << endl;
            cout << "Program menu:" << endl;
            cout << "1. Calculator" << endl;
            cout << "2. History" << endl;
            cout << "3. Exit\n" << endl;
            cout << "Choose menu index: ";
            cin >> menuIndex;

            switch(menuIndex) {
                case 1:
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

                    cout << "Continue program?(y/n): ";
                    cin >> continue_program;

                    system("clear");

                    cin.ignore(1000, '\n');

                    break;
                
                case 2:
                    cout << "Soon...\n" << endl;
                    break;

                case 3:
                    cout << "Closing program..." << endl;
                    return true;

                default:
                    cout << "Invalid input!" << endl;
                    return false;
            }

        }

        system("clear");
        return true;
    }
}