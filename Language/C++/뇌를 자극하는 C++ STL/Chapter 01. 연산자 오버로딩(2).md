🔵 STL에 필요한 주요 연산자 오버로딩

🔥 함수 호출 연산자 오버로딩: () 연산자

함수 호출 연산자 오버로딩은 **객체를 함수처럼 동작하게 하는 연산자이다.**

`Print(10)`이라는 함수 호출 문장은 다음 세 가지로 해석할 수 있다.

* 첫째, 함수 호출: Print가 함수 이름이다.
* 둘째, 함수 포인터: Point가 함수 포인터이다.
* 셋째, 함수 객체: Print가 함수 객체이다.

함수 호출 연산자를 정의한 객체를 함수 객체라고 한다.

```cpp
#include <iostream>
using namespace std;

struct FuncObject
{
public:
	void operator() (int arg) const
	{
		cout << "정수: " << arg << endl;
	}
};

void Print1(int arg)
{
	cout << "정수: " << arg << endl;
}

int main()
{
	void (*Print2)(int) = Print1;
	FuncObject Print3;

	Print1(10);
	Print2(10);
	Print3(10); // Print3.operator()(10);  --> '함수 객체'를 사용한 정수 출력

	return 0;
}
```
여러 인자를 받는 함수 호출 연산자를 중복한 예제

: 임시 객체는 그 문장에서 생성되고 그 문장을 벗어나면 소멸된다. 그 문장에서만 임시로 필요한 객체에 사용된다.

```cpp
#include <iostream>
using namespace std;

struct FuncObject
{
public:
	void operator() (int arg) const
	{
		cout << "정수: " << arg << endl;
	}

	void operator() (int arg1, int arg2) const
	{
		cout << "정수: " << arg1 << ',' << arg2 << endl;
	}

	void operator() (int arg1, int arg2, int arg3) const
	{
		cout << "정수: " << arg1 << ',' << arg2 << ',' << arg3 << endl;
	}
};

class Point
{
public:
	Point(int a)
	{
		cout << a << endl;
	}
};

int main()
{
	FuncObject print;
	print(10);                            // 객체 생성 후 호출(암시적)
	print(10, 20);
	print(10, 20, 30);
	cout << endl;

	print.operator()(10);                 // 객체 생성 후 호출(명시적)
	print.operator()(10, 20); 
	print.operator()(10, 20, 30);
	cout << endl;

	FuncObject() (10);                    // 임시 객체로 호출(암시적)
	FuncObject() (10,20);
	FuncObject() (10,20,30);
	cout << endl;

	FuncObject().operator()(10);          // 임시 객체로 호출(명시적)
	FuncObject().operator()(10, 20);
	FuncObject().operator()(10, 20, 30);
	cout << endl;

	return 0;
}
```

🔥 배열 인덱스 연산자 오버로딩: [] 연산자

```cpp
#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

	void Print() const
	{
		cout << x << ',' << y << endl;
	}

	int operator[](int idx) const   // 🎈🎈컨테이너가 관리하는 내부 원소에 접근할 때 사용
	{
		if (idx == 0)
			return x;
		else if (idx == 1)
			return y;
		else
			throw "이럴 수는 없는 거야!";
	}
};

int main()
{
	Point pt(1, 2);

	pt.Print();

	cout << pt[0] << ',' << pt[1] << endl; // pt[0] --> pt.operator[] (0)
	
	return 0;
}
```

[] 연산자 오버로딩은 일반적으로 컨테이너 객체에 사용된다. 즉, 컨테이너 객체가 고나리하는 내부 원소에 접근할 때 사용된다.

```cpp
#include <iostream>
using namespace std;

class Array
{
private:
	int* arr;
	int size;
	int capacity;
public:
	Array(int cap = 100) : arr(0), size(0), capacity(cap)
	{
		arr = new int[capacity];
	}

	~Array()
	{
		delete[] arr;
	}

	void Add(int data)
	{
		if (size < capacity)
			arr[size++] = data;
	}

	int Size() const
	{
		return size;
	}

	int operator[] (int idx) const
	{
		return arr[idx];
	}
};

int main()
{
	Array ar(10);

	ar.Add(10);
	ar.Add(20);
	ar.Add(30);

	for (int i = 0; i < ar.Size(); i++)
		cout << ar[i] << endl;             // arr.operator[](i)

	return 0;
}
```

const 함수와 비 const 함수 모두 제공해주기

```cpp
#include <iostream>
using namespace std;

class Array
{
private:
	int* arr;
	int size;
	int capacity;
public:
	Array(int cap = 100) : arr(0), size(0), capacity(cap)
	{
		arr = new int[capacity];
	}

	~Array()
	{
		delete[] arr;
	}

	void Add(int data)
	{
		if (size < capacity)
			arr[size++] = data;
	}

	int Size() const
	{
		return size;
	}

	int operator[] (int idx) const
	{
		return arr[idx];
	}

	int& operator[] (int idx) 
	{
		return arr[idx];
	}
};

int main()
{
	Array ar(10);
	ar.Add(10);
	ar.Add(20);
	ar.Add(30);
	 
	cout << ar[0] << endl;   // ar.operator[] (int) 호출
	cout << endl;

	const Array& ar2 = ar;   // ar/operator[] (int) const 호출
	cout << ar2[0] << endl;
	cout << endl;

	ar[0] = 100;
	//ar2[0] = 100;    -->    에러! 상수 객체(값)를 반환하므로 대입 x
	
	return 0;
}
```
