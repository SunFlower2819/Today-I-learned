# 🔵함수 객체 구현

```cpp
#include <iostream>
using namespace std;

bool Pred_less(int a, int b)
{
	return a < b;
}

struct Less
{
	bool operator() (int a, int b)
	{
		return a < b;
	}
};

int main()
{
	Less le;

	cout << Pred_less(10, 20) << endl;
	cout << Pred_less(20, 10) << endl;
	
	cout << endl;

	cout << le(10, 20) << endl;      // le 객체로 암묵적 호출
	cout << le(20, 10) << endl;      // le 객체로 암묵적 호출
	cout << Less()(10, 20) << endl;  // 임시 객체로 암묵적 호출
	cout << Less()(20, 10) << endl;  // 임시 객체로 암묵적 호출
	
	cout << endl;

	cout << le.operator()(10, 20) << endl;      // 명시적 호출
	cout << Less().operator()(10, 20) << endl;  // 명시적 호출

	return 0;
}
```
```
출력결과

1
0

1
0
1
0

1
1
```

### 🔥STL의 less 함수 객체를 사용
```cpp
#include <iostream>
#include <functional>
using namespace std;

typedef less<int> Less;

int main()
{
	Less le;

	cout << le(10, 20) << endl;  // le 객체로 암시적 함수 호출
	cout << le(20, 10) << endl;  // le 객체로 암시적 함수 호출

	cout << le.operator()(10, 20) << endl; // le 객체로 명시적 함수 호출

	cout << Less()(10, 20) << endl;  // 임시 객체로 암시적 함수 호출
	cout << Less()(20, 10) << endl;  // 임시 객체로 암시적 함수 호출

	cout << Less().operator()(10, 20) << endl; // 임시 객체로 명시적 함수 호출

	return 0;
}
```

🎈🎈STL less, greater는 템플릿 클래스이므로 임시 객체를 `less<int>()`, `greater<int>()`와 같이 생성한다.

여기서 `int`는 비교할 값의 타입이다.

```cpp
#include <iostream>
#include <functional>
using namespace std;

struct Less
{
	bool operator() (int a, int b)
	{
		return a < b;
	}
};

struct Greater
{
	bool operator() (int a, int b)
	{
		return a > b;
	}
};

int main()
{
	cout << Less() (10, 20) << endl;    // 사용자 Less, Greater 사용
	cout << Less() (20, 10) << endl;
	cout << Greater() (10, 20) << endl;
	cout << Greater() (20, 10) << endl;

	cout << endl;

	cout << less<int>()(10, 20) << endl;   // STL의 less, greater 사용
	cout << less<int>()(20, 10) << endl;
	cout << greater<int>()(10, 20) << endl;
	cout << greater<int>()(20, 10) << endl;

	return 0;
}
```

### 🔥STL의 plus, minus 함수 객체를 사용
```cpp
#include <iostream>
#include <functional>
using namespace std;

struct Plus
{
	int operator() (int a, int b)
	{
		return a + b;
	}
};

struct Minus
{
	int operator() (int a, int b)
	{
		return a - b;
	}
};

int main()
{
	cout << Plus() (10, 20) << endl;    // 사용자 Plus, Minus 사용
	cout << Plus() (20, 10) << endl;
	cout << Minus() (10, 20) << endl;
	cout << Minus() (20, 10) << endl;

	cout << endl;

	cout << plus<int>()(10, 20) << endl;   // STL의 plus, minus 사용
	cout << plus<int>()(20, 10) << endl;
	cout << minus<int>()(10, 20) << endl;
	cout << minus<int>()(20, 10) << endl;

	return 0;
}
```
