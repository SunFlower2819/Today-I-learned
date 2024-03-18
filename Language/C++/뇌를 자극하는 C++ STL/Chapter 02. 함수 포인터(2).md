# 🔵함수 포인터의 종류

C++에서 함수는 정적 함수와 멤버 함수로 나눌 수 있다.

> 정적 함수: 전역 함수, namespace 내의 전역 함수, static 멤버 함수

함수 호출은 세 가지가 있다.
1. 정적 함수 호출(정적 함수)
2. 객체로 멤버 함수 호출(멤버 함수) : `p1.Print();`
3. 객체의 주소로 멤버 함수 호출(멤버 함수) : `p2->Print();` // p2는 포인터

---
## ❤️정적 함수 호출

```cpp
#include <iostream>
using namespace std;

void Print(int n)
{
	cout << "전역함수: " << n << endl;
}

namespace A
{
	void Print(int n)
	{
		cout << "namespace A 전역 함수: " << n << endl;
	}
}

class Point
{
public:
	static void Print(int n)
	{
		cout << "Point 클래스의 정적 멤버 함수: " << n << endl;
	}
};

int main()
{
	void (*pf)(int);    // 정적 포인터 선언
	 
	Print(10);          // 1.namespace 없는 전역 함수 호출
	A::Print(20);       // 2.namespace A의 전역 함수 호출
	Point::Print(30);   // 3.Point 클래스의 정적 멤버 함수 호출

	pf = Print;         
	pf(10);             // 1.함수 포인터로 namespace 없는 전역 함수 호출

	pf = A::Print;
	pf(20);             // 2.함수 포인터로 namespace A의 전역 함수 호출

	pf = Point::Print;
	pf(30);             // 3. 함수 포인터로 Point 클래스의 정적 멤버 함수 호출

	return 0;
}
```

## ❤️객체와 주소로 멤버 함수 호출

멤버 함수 포인터는 함수 포인터 선언에 어떤 클래스의 멤버 함수를 가리킬 것인지 클래스 이름을 지정해야 한다.

`void Point::Print(int n)`인 멤버 함수의 포인터는 `void (Point::*pf)(int)`처럼 선언한다. 

✅그러면 애초에 함수 포인터의 주인은 정해져있는 것과 다름없는거 아닌가..?

```cpp
#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	explicit Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	void Print() const { cout << x << ',' << y << endl; }
	void PrintInt(int n) { cout << "테스트 정수 : " << n << endl; }
};

int main()
{
	Point p1(1, 2);
	Point* p2 = new Point(3, 5);

	void(Point:: * pf1) () const;
	pf1 = &Point::Print;            // 🎈🎈얘는 &를 붙여줘야 하네??
	void (Point:: * pf2) (int);
	pf2 = &Point::PrintInt;

	(p1.*pf1)();        // 객체로 멤버 함수 포인터를 이용한 호출
	(p1.*pf2)(10);

	(p2->*pf1)();       // 주소로 멤버 함수 포인터를 이용한 호출
	(p2->*pf2)(20);

	delete p2;

	return 0;
}
```
