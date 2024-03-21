# 🔵STL을 위한 템플릿 예제

### 🔥명시적으로 함수 템플릿을 호출한 예제이다.
 
```cpp
#include <iostream>
#include <string>
using namespace std;

template<typename IterT, typename Func>
void For_each(IterT begin, IterT end, Func pf)
{
	while (begin != end)
	{
		pf(*begin++);
	}
}

void PrintInt(int data)
{
	cout << data << " ";
}

void PrintString(string data)
{
	cout << data << " ";
}

int main()
{
	int arr[5] = { 10, 20, 30, 40, 50 };
	For_each<int*, void(*)(int)>(arr, arr + 5, PrintInt);
	cout << endl;

	string sarr[3] = { "Hello", "!!", "World" };
	For_each<string*, void(*)(string)>(sarr, sarr + 3, PrintString);

	return 0;
}
```

### 🔥`PrintInt()`와 `PrintString()`이 다른 것은 타입뿐이므로 이 출력 함수도 템플릿 함수로 작성해보겠다.

```cpp
#include <iostream>
#include <string>
using namespace std;

template<typename IterT, typename Func>
void For_each(IterT begin, IterT end, Func pf)
{
	while (begin != end)
	{
		pf(*begin++);
	}
}

template<typename T>
void Print(T data)
{
	cout << data << " ";
}

int main()
{
	int arr[5] = { 10, 20, 30, 40, 50 };
	// For_each<int*, void(*)(int)>(arr, arr + 5, Print);  🎈🎈 Print의 data가 무슨 타입을 출력할지 알려줘야함(이렇게 하거나, 아래처럼 하거나)
	For_each(arr, arr + 5, Print<int>);
	cout << endl;

	string sarr[3] = { "Hello", "!!", "World" };
	// For_each<string*, void(*)(string)>(sarr, sarr + 3, Print);
        For_each(sarr, sarr + 3, Print<string>);
	return 0;
}
```

### 🔥함수 객체를 사용하여 출력

이 코드에서 템플릿형 임시 객체를 인자로 넘겨준다는 부분에서 헷갈렸다.

```cpp
#include <iostream>
#include <string>
using namespace std;

template<typename IterT, typename Func>
void For_each(IterT begin, IterT end, Func pf) // 🎈🎈3.PrintFunctor<int> pf = PrintFunctor<int>()
{
	while (begin != end)
	{
		pf(*begin++); // 🎈🎈4.pf.operator()(*begin++)
	}
}

template<typename T>
struct PrintFunctor
{
	string sep;

	PrintFunctor(const string& s = " ") : sep(s) {}

	void operator() (T data) const
	{
		cout << data << sep;
	}
};


int main()
{
	int arr[5] = { 10, 20, 30, 40, 50 };
	For_each(arr, arr + 5, PrintFunctor<int>());  // 🎈🎈2.PrintFunctor<int>()을 인자로 Func pf에 넘겨줘야 하잖아.. || PrintFunctor<int>()는 클래스 이름으로 만든 임시객체이고..
	cout << endl;

	// 🎈🎈1.어려울게 없어. typename Func에서 typename만 PrintFunctor<int>으로 바꿔주면 되는거야. 그니까 Func이 PrintFunctor<int> 형이 되는거지

	string sarr[3] = { "Hello", "!!", "World" };
	For_each(sarr, sarr + 3, PrintFunctor<string>("*\n"));

	return 0;
}
```

```
출력 결과

10 20 30 40 50
Hello*
!!*
World*
```

### 🔥STL에서 데이터의 쌍을 표현할 때 항상 사용되는 pair 클래스를 템플릿으로 구현

```cpp
#include <iostream>
#include <string>
using namespace std;

template<typename T1, typename T2>
struct Pair
{
	T1 first;
	T2 second;
	Pair(const T1& ft, const T2& f2) : first(ft), second(f2) {}
};

int main()
{
	// Pair 클래스 구현
	Pair<int, int> p1(10, 20);
	cout << p1.first << ',' << p1.second << endl;
	Pair<int, string> p2(500, "WOW");
	cout << p2.first << ',' << p2.second << endl;
	
	cout << endl;

	// pair STL
	pair<int, int> p3(50, 20);
	cout << p3.first << ',' << p3.second << endl;
	pair<int, string> p4(200, "Hmm...");
	cout << p4.first << ',' << p4.second << endl;

	return 0;
}
```

# 🟠문제

Stack이랑 Queue 간단 구현

```cpp
#include <iostream>
using namespace std;

template<typename T>
class Stack
{
	T* data;
	int size;
	int capacity = 0;
public:
	Stack(int size = 100) : size(size)
	{
		data = new T[size];
	}

	void Push(T d)
	{
		if (capacity < size)
			data[capacity++] = d;
	}

	T Pop()
	{
		return data[--capacity];
	}

	bool Empty()
	{
		if (capacity == 0)
		{
			cout << "더 이상 제거 불가" << endl;
			return true;
		}
		else
			return false;
	}

	~Stack()
	{
		delete[] data;
	}
};

template<typename T>
class Queue
{
	T* data;
	int size;
	int capacity = 0;
public:
	Queue(int size = 100) : size(size)
	{
		data = new T[size];
	}

	void Push(T d)
	{
		if (capacity < size)
			data[capacity++] = d;
	}

	T Pop()
	{
		T popData = data[0];

		for (int i = 0; i < capacity - 1; i++)
		{
			data[i] = data[i + 1];
		}
		capacity--;

		return popData;
	}

	bool Empty()
	{
		if (capacity == 0)
		{
			cout << "더 이상 제거 불가" << endl;
			return true;
		}
		else
			return false;
	}

	~Queue()
	{
		delete[] data;
	}
};

int main()
{
	Stack<const char*> st;
	st.Push("HELDFLDOI");
	st.Push("DFBRDFBF");
	st.Push("ABCDEFG");

	if (!st.Empty())
		cout << st.Pop() << endl;
	if (!st.Empty())
		cout << st.Pop() << endl;
	if (!st.Empty())
		cout << st.Pop() << endl;
	if (!st.Empty())
		cout << st.Pop() << endl;

	//-------------------------------------------------

	Queue<const char*> q;
	q.Push("QQQQQQQ");
	q.Push("WWWWWWW");
	q.Push("EEEEEEE");

	if (!q.Empty())
		cout << q.Pop() << endl;
	if (!q.Empty())
		cout << q.Pop() << endl;
	if (!q.Empty())
		cout << q.Pop() << endl;
	if (!q.Empty())
		cout << q.Pop() << endl;

	return 0;
}
```
