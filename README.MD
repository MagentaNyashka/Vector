Спроектировать и реализовать класс Vector, предназначенный для работы с векторами.
Класс должен позволять создавать векторы различных размеров. 
В классе должны быть определены следующие конструкторы:
по умолчанию,
по целому числу, задающему размер вектора,
конструктор копирования.
Должны быть перегружены следующие операторы: +, -, * (скалярное для двух векторов и для числа и вектора), оператор индексирования [] для доступа к элементу вектора, =, +=, -=, *= (правым операндом может быть как вектор, так и число), ==, !=, << (вывод в поток типа ostream). Реализовать деструктор.
Разработанный класс Vector должен допускать такое использование:
```
#include <iostream>

using namespace std;


int main()
{
	Vector a;
	Vector b(2);
	Vector c(3);

	for (int i = 0; i < 2; i++)
		b[i] = i;

	b *= 2;
	b = a = b + b;

	if (a != b) cout << "Something wrong\n";
	else cout << "As expected\n";

	b += c; //эта строчка работать не должна, потому что векторы
	// разной размерности складывать нельзя

	cout << a << endl
		<< c << endl
		<< b << endl;

	return 0;
}
```