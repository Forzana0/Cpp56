﻿#include <iostream>

using namespace std;

template<typename B>
B power(B base, int exponent) {
    B result = 1.0;
    int positExp = exponent;
    if (exponent < 0) {
        positExp = -exponent;
    }
    for (int i = 0; i < positExp; ++i) {
        result *= base;
    }
    if (exponent < 0) {
        result = 1.0 / result;
    }
    return result;
}

int sumRange(int a, int b) {
    int sum = 0, start = (a < b) ? a : b, end = (a < b) ? b : a;
    for (int i = start + 1; i < end; ++i) {
        sum += i;
    }
    return sum;
}

bool isPerfect(int number) {
    int sum = 0;
    for (int i = 1; i <= number / 2; ++i) {
        if (number % i == 0) {
            sum += i;
        }
    }
    return sum == number;
}

void findNumbers(int start, int end) {
    cout << "Perfect numbers [" << start << ", " << end << "]:" << endl;
    for (int i = start; i <= end; ++i) {
        if (isPerfect(i)) {
            cout << i << endl;
        }
    }
}

void Card(int number) {
    string suits[] = { "Gold", "Diamonds", "Pencil", "Spider" };
    string ranks[] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Clown", "Queen", "King" };

    int suit = number / 13;
    int rank = number % 13;

    cout << ranks[rank] << " of " << suits[suit] << endl;
}

bool isLucky(int number) {
    int sumFirstHalf = 0;
    int sumSecondHalf = 0;

    for (int i = 0; i < 3; ++i) {
        sumFirstHalf += number % 10;
        number /= 10;
    }

    for (int i = 0; i < 3; ++i) {
        sumSecondHalf += number % 10;
        number /= 10;
    }

    return sumFirstHalf == sumSecondHalf;
}

int main() {
    double baseD;
    int baseI, exponent;

    cout << "Enter base (double): "; cin >> baseD;
    cout << "Enter exponent: "; cin >> exponent;

    double resultD = power(baseD, exponent);
    cout << baseD << " ^ " << exponent << " = " << resultD << endl;

    cout << "Enter base (int): "; cin >> baseI;

    int resultInt = power(baseI, exponent);
    cout << baseI << " ^ " << exponent << " = " << resultInt << endl;

    cout << "Enter two integers: "; int a, b; cin >> a >> b;

    int result = sumRange(a, b); cout << "Sum of numbers between " << a << " and " << b << ": " << result << endl;

    int start, end;

    cout << "Enter start range: "; cin >> start;
    cout << "Enter end range: "; cin >> end;

    findNumbers(start, end);

    cout << "Enter card number (0-51): "; int cardNumber; cin >> cardNumber;

    Card(cardNumber);

    cout << "Enter six-digit number: "; int number; cin >> number;

    if (isLucky(number)) {
        cout << "The number is lucky!" << endl;
    }
    else {
        cout << "The number is not lucky." << endl;
    }
}