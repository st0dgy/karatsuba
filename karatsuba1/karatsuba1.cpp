﻿#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include <iostream>

using namespace std;



int getLength(long long value) {
	int counter = 0;
	while (value != 0) {
		counter++;
		value /= 10;
	}
	return counter;
}

long long multiply(long long x, long long y) {
	int xLength = getLength(x);
	int yLength = getLength(y);

	// найбільший із двох довжин
	int N = (int)(fmax(xLength, yLength));

	// якщо максимальна довжина досить маленька, швидше просто перемножити два числа
	if (N < 10)
		return x * y;

	
	N = (N / 2) + (N % 2);
	// зсув для десяткової системи числення
	long long multiplier = pow(10, N);

	long long b = x / multiplier;
	long long a = x - (b * multiplier);
	long long d = y / multiplier;
	long long c = y - (d * multiplier);

	long long d0 = multiply(a, c);
	long long d1 = multiply(a + b, c + d);
	long long d2 = multiply(b, d);

	// формула с(t)
	return d0 + ((d1 - d0 - d2) * multiplier) + (d2 * (long long)(pow(10, 2 * N)));

}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    long long a, b, c, d;
    cout << "Вітаю тебе у калькуляторі добутку комплексних чисел!" << endl;
    cout << "Я навіть не хочу питати, навіщо тобі обраховувати добуток чисел, які не існують насправді, тому перейдемо одразу до справи... " << endl;
    cout << "a: "; cin >> a;
    cout << "b: "; cin >> b;
    cout << "c: "; cin >> c;
    cout << "d: "; cin >> d;
    cout << "r = " << (a * c - b * d) << endl;
    cout << "s = " << (a * d + b * c) << "i" << endl;
}