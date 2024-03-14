## 🔵 타입 변환 연산자 오버로딩

사용자가 직접 정의해서 사용할 수 있는 타입 변환은 두 가지가 있다.

* 첫째, 생성자를 이용한 타입 변환
* 둘째, 타입 변환 연산자 오버로딩을 이용한 타입 변환
---
### 🔥 생성자를 이용한 타입 변환

```cpp
#include <iostream>
using namespace std;

class A {};

class B
{
public:
	B() { cout << "B() 생성자" << endl; }
	B(A& _a) { cout << "B(A_a) 생성자" << endl; }
	B(int n) { cout << "B(int n) 생성자" << endl; }
	B(double d) { cout << "B(doubel d) 생성자" << endl; }   
};

int main()
{
	A a;
	int n = 10;
	double d = 5.5;

	B b;   // B() 생성자 호출
	b = a; // b = B(a) 암시적 생성자 호출 후 대입 !   <-- 🎈🎈 이게 이해가 안갔었음
	b = n; // b = B(n) 암시적 생성자 호출 후 대입 !             b = n; 이라는 문장을 사용하면 B(n)이라는 임시 객체가 생성이 되고, 그 생성된 객체를 다시 b에 넣어주는 것이다.
	b = d; // b = B(d) 암시적 생성자 호출 후 대입 !             즉, B(n)이라는 임시객체가 생성되면서 생성자가 호출되는 거임

	return 0;
}
```
<br>

이를 방지하기 위해서 `explicit` 키워드가 사용된다.

```cpp
#include <iostream>
using namespace std;

class A {};

class B
{
public:
	explicit B() { cout << "B() 생성자" << endl; }
	explicit B(A& _a) { cout << "B(A_a) 생성자" << endl; }
	explicit B(int n) { cout << "B(int n) 생성자" << endl; }
	explicit B(double d) { cout << "B(doubel d) 생성자" << endl; }
};

int main()
{
	A a;
	int n = 10;
	double d = 5.5;

	B b;   // B() 생성자 호출

	//b = a;    <-- 오류 발생❌
	b = B(a);

	//b = n;    <-- 오류 발생❌
	b = B(n);
	
	//b = d;    <-- 오류 발생❌
	b = B(d);

	return 0;
}
```

---
### 🔥 타입 변환 연산자 오버로딩을 이용한 타입 변환

```cpp
#include <iostream>
using namespace std;

class A {};

class B
{
public:
	operator A()  // 🎈🎈반환 타입 지정X
	{ 
		cout << "operator A() 호출" << endl;
		return A();
	}

	operator int()
	{
		cout << "operator int() 호출" << endl;
		return int();
	}

	operator double()
	{
		cout << "operator double() 호출" << endl;
		return double();
	}
};

int main()
{
	A a;
	int n = 10;
	double d = 5.5;

	B b;
	a = b; // a = b.operator A(); 암시적 호출
	n = b;
	d = b;

	cout << endl;

	a = b.operator A();  // 명시적 호출
	n = b.operator int();
	d = b.operator double();

	return 0;
}
```

<br>
<br>

✅Q.해결해야 하는 물음..

```cpp
#include <iostream>
using namespace std;

class Point
{
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	void Print() const { cout << x << ',' << y << endl; }
	operator int() const
	{
		return x;
	}
};

int main()
{
	int n = 10;

	Point pt(2, 3);

	pt = Point(20, 5); // 이렇게 하면 20이 출력된다.. 왜지???
	n = pt; 
	cout << n << endl;  // 20 출력

	pt = (20, 5); // 이렇게 하면 5가 출력된다.. 왜지???
	n = pt;
	cout << n << endl;  // 5 출력

	return 0;
}
```
