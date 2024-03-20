# 🔵클래스 템플릿
```cpp
#include <iostream>
using namespace std;

template<typename T>
class Array
{
	T* buf;
	int size;
	int capacity;
public:
	explicit Array(int cap = 100) : buf(0), size(0), capacity(cap)
	{
		buf = new T[capacity];
	}

	~Array() { delete[] buf; }

	void Add(T data)
	{
		buf[size++] = data;
	}

	T operator[](int idx) const
	{
		return buf[idx];
	}

	int GetSize()const
	{
		return size;
	}
};

int main()
{
	Array<int> iarr;
	iarr.Add(10);
	iarr.Add(20);
	iarr.Add(30);

	for (int i = 0; i < iarr.GetSize(); i++)
		cout << iarr[i] << " ";
	cout << endl;

	Array<double> darr;
	darr.Add(10.01);
	darr.Add(20.02);
	darr.Add(30.03);

	for (int i = 0; i < darr.GetSize(); i++)
		cout << darr[i] << " ";
	cout << endl;

	Array<string> sarr;
	sarr.Add("Hello");
	sarr.Add("World");
	sarr.Add("!!!!");

	for (int i = 0; i < sarr.GetSize(); i++)
		cout << sarr[i] << " ";

	return 0;
}
```


### 🔥템플릿의 디폴트 매개변수 값 지정
```cpp
#include <iostream>
using namespace std;

template<typename T = int, int capT = 100> // 🎈🎈int, 100 디폴트 매개변수 값 지정
class Array
{
	T* buf;
	int size;
	int capacity;
public:
	explicit Array(int cap = capT) : buf(0), size(0), capacity(cap)
	{
		buf = new T[capacity];
	}

	~Array() { delete[] buf; }

	void Add(T data)
	{
		buf[size++] = data;
	}

	T operator[](int idx) const
	{
		return buf[idx];
	}

	int GetSize()const
	{
		return size;
	}
};

int main()
{
	Array<> iarr;  // 디폴트 매개변수 값 int, 100 사용
	iarr.Add(10);
	iarr.Add(20);
	iarr.Add(30);

	for (int i = 0; i < iarr.GetSize(); i++)
		cout << iarr[i] << " ";
	cout << endl;

	Array<double> darr; // 디폴트 매개변수 값 100 사용
	darr.Add(10.01);
	darr.Add(20.02);
	darr.Add(30.03);

	for (int i = 0; i < darr.GetSize(); i++)
		cout << darr[i] << " ";
	cout << endl;

	Array<string, 10> sarr; // 디폴트 매개변수 사용 x
	sarr.Add("Hello");
	sarr.Add("World");
	sarr.Add("!!!!");

	for (int i = 0; i < sarr.GetSize(); i++)
		cout << sarr[i] << " ";

	return 0;
}
```

### 🔥특수화 템플릿 클래스

클래스 템플릿 특수화(class Template Specialization)는 함수 템플릿 특수화처럼 일반 버전의 템플릿을 사용할 수 없는 경우나 성능 개선이나 특수한 기능 등을 위해 특수화 버전을
별도로 제공하고자 할 때 사용한다.

```cpp
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class ObjectInfo
{
	T data;
public:
	ObjectInfo(const T& d) : data(d) {}

	void Print()
	{
		cout << "타입: " << typeid(data).name() << endl;
		cout << "크기: " << sizeof(data) << endl;
		cout << "값: " << data << endl;
		cout << endl;
	}
};

// 🎈🎈T를 string으로 특수화(클래스 템플릿 특수화)
template<>
class ObjectInfo<string>
{
	string data;
public:
	ObjectInfo(const string& d) : data(d) {}

	void Print()
	{
		cout << "타입: string" << endl;
		cout << "문자열 길이: " << data.size() << endl;
		cout << "값: " << data << endl;
		cout << endl;
	}
};

int main()
{
	ObjectInfo<int> d1(10);
	d1.Print();

	ObjectInfo<double> d2(5.5);
	d2.Print();

	ObjectInfo<string> d3("Hello!");
	d3.Print();

	return 0;
}
```
