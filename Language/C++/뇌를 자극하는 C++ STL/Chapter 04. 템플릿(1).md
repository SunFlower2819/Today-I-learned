# 함수 템플릿

템플릿은 함수 템플릿(Function Template)과 클래스 템플릿(Class Template)이 있습니다.

함수 템플릿은 함수를 만들어내는 틀이며, 클래스 템플릿은 클래스를 만들어내는 틀입니다.

```cpp
#include <iostream>
using namespace std;

template<typename T>
void Print(T a, T b)
{
	cout << a << ',' << b << endl;
}

int main()
{
	Print<int>(10, 20);                    // 정수 출력
	Print<double>(3.14, 5.56);             // 실수 출력
	Print<const char*>("Hello", "World");  // 문자열 출력

	return 0;
}
```

### 🔥템플릿 버전의 `Swap()`

```cpp
#include <iostream>
using namespace std;

template<typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	int n1 = 10, n2 = 20;
	double d1 = 1.1, d2 = 2.2;

	cout << n1 << ", " << n2 << endl;
	Swap(n1, n2);
	cout << n1 << ", " << n2 << endl;
	cout << endl;

	cout << d1 << ", " << d2 << endl;	
	Swap(d1, d2);
	cout << d1 << ", " << d2 << endl;

	return 0;
}
```

### 🔥함수 템플릿의 매개변수로 타입뿐만 아니라 정수 등도 가능하다..!

```cpp
#include <iostream>
using namespace std;

template<typename T, int size> // 🎈🎈함수 템플릿의 매개변수로 타입뿐만 아니러 정수 등도 가능
void PrintArray(T* arr)
{
	for (int i = 0; i < size; i++)
	{
		cout << "[" << i << "]: " << arr[i] << endl;
	}
	cout << endl;
}

int main()
{
	int arr1[5] = { 10, 20, 30, 40, 50 };
	PrintArray<int, 5>(arr1);  // 🎈🎈명시적 호출을 하지 않으면 컴파일 에러 발생

	double arr2[3] = { 0.123, 2.61, 3.14 };
	PrintArray<double, 3>(arr2);

	return 0;
}
```

### 🔥함수 템플릿 특수화

```cpp
#include <iostream>
using namespace std;

class Point
{
	int x;
	int y;
public:
	explicit Point(int x = 0, int y = 0) : x(x), y(y) {}
	void Print() const { cout << x << ',' << y << endl; }
};

template <typename T>    // 근데 여기서 굳이 템플릿 함수로 정의해야할 필요가 있나..? 코드 가독성과 유지보수 땜시?
void Print(T a)
{
	cout << a << endl;
}

template <>
void Print(Point p)
{
	cout << "Print 특수화 버전: ";
	p.Print();
}

int main()
{
	int n = 10;
	double d = 2.5;
	Point pt(2, 3);

	Print(n);
	Print(d);
	Print(pt);     // 특수화된 함수 템플릿이 없으면 당연히 에러가 발생함.

	return 0;
}
```
