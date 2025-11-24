#pragma once

#include <iostream>

namespace calculator {

    struct calculation {
        double num1;
        double num2;
        char operation;
        double result;
    };

    double add(double a, double b);

    double subtract(double a, double b);

    double multiply(double a, double b);

    double divide(double a, double b);

    void addToHistory(double num1, double num2, char operation, double result);

    void showHistory();

    void clearHistory();

    void showStatistics();

    void findFavOperation();

    bool run();
}