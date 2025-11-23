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

        cout << history.back().num1 << " " << history.back().operation << " " << history.back().num2 << " = " << history.back().result << endl;
    }

    bool run() {
        char continue_program = 'y';
        char clear_console;

        system("clear");

        while (continue_program == 'y' || continue_program == 'Y') {
            double firstNumber, secondNumber;
            char operation;

            cout << "====CALCULATOR====" << endl;
            cout << "Enter first number: ";
            cin >> firstNumber;

            if (cin.fail()) {
                cout << "Error ocurred!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                return false;
            }

            cout << "Enter second number: ";
            cin >> secondNumber;

            if (cin.fail()) {
                cout << "Error ocurred!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                return false;
            }

            cout << "Your numbers: " << firstNumber << " and " << secondNumber << endl;
            cout << "Which operation would you like?(+, -, *, /): ";
            cin >> operation;

            switch (operation) {
                double result;

                case '+':
                    result = add(firstNumber, secondNumber);
                    cout << "Result: " << result << endl;
                    // addToHistory(firstNumber, secondNumber, operation, result);
                    break;
                case '-':
                    result = subtract(firstNumber, secondNumber);
                    cout << "Result: " << result << endl;
                    break;
                case '*':
                    result = multiply(firstNumber, secondNumber);
                    cout << "Result: " << result << endl;
                    break;
                case '/':
                    result = divide(firstNumber, secondNumber);
                    cout << "Result: " << result << endl;
                    break;
                default:
                    cout << "Error: Invalid operation!" << endl;
                    break;
            }

            cout << "Continue program?(y/n): ";
            cin >> continue_program;

            system("clear");

            cin.ignore(1000, '\n');
        }

        system("clear");
        return true;
    }
}