#include <iostream>
using namespace std;

// 두 개의 정수를 받아 합을 리턴하는 함수
int add(int num1, int num2)
{
	return num1 + num2;
}

// 두 개의 정수를 받아 큰 값을 리턴하는 함수
int bigger(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

// 매개 변수가 3으로 나누어지면 true, 아니면 false를 리턴하는 함수
bool divideBy3(int num)
{
	return (num % 3 == 0);
}

int main()
{
	int num1, num2;
	cout << "두 개의 정수 입력>>";
	cin >> num1 >> num2;
	cout << "두 수의 합은: " << add(num1, num2) << endl << endl;

	int a, b, n;
	cout << "두 개의 정수 입력>>";
	cin >> a >> b;
	n = bigger(a, b);
	cout << a << "중 " << b << "중 큰 값은 " << n << "입니다.\n";

	if (divideBy3(n))
		cout << n << "은(는) " << "3의 배수입니다.\n";
	else
		cout << n << "은(는) " << "3의 배수가 아닙니다.\n";

	return 0;
}
