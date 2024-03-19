# 🔵함수 객체란

함수 객체(Function Object)는 함수처럼 동작하는 객체입니다.

함수처럼 동작하려면 객체가 '()' 연산자를 정의해야 합니다.

**다시 말해 '()' 연산자를 오버로딩한 객체입니다.**

함수 객체는 함수자(Functor)라 불리기도 합니다.

```cpp
#include <iostream>
using namespace std;

void Print()
{
	cout << "전역 함수!" << endl;
}

void Print(int a, int b)
{
	cout << "전역 함수: " << a << ',' << b << endl;
}

struct Functor
{
	void operator() ()
	{
		cout << "함수 객체!" << endl;
	}

	void operator() (int a, int b)
	{
		cout << "함수 객체: " << a << ',' << b << endl;
	}
};

int main()
{
	Functor functor;

	Print();       // 전역 함수!     
	functor();     // 함수 객체!       -->    functor.operator() ();

	cout << endl;

	Print(1, 2);   // 전역 함수: 1,2
	functor(3, 5); // 함수 객체: 3,5

	return 0;
}
```

---

## ❤️함수 객체의 장점

초깃값 0을 시작으로 `add()` 함수롤 호출할 때마다 정수를 누적하고 반환한다.

```cpp
#include <iostream>
using namespace std;

class Adder
{
	int total;
public:
	explicit Adder(int n = 0) :total(n) {}

	int operator() (int n)
	{
		return total += n;
	}

	void Print()
	{
		cout << total << endl;
	}
};

int main()
{
	Adder add(0);  // 초깃값: 0
	 
	add(10);       // 0 + 10 = 10
	add(20);       // 10 + 20 = 30
	add(30);       // 30 + 30 = 60

	add.Print();   // 60 출력

	return 0;
}
```
