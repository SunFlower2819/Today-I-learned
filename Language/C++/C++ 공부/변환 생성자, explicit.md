### 변환 생성자(Converting Constructor)

> 매개변수를 가지고 있는 생성자가 존재시 컴파일러가 자동 형변환을 통해
호출할 수 있는 생성자.

```cpp
#include <iostream>
using namespace std;

class MyClass
{
private:
	int num;
public:
	MyClass(int x) : num(x)
	{}

	int getNum() const
	{
		return num;
	}
};

void myFunc(const MyClass& ref)
{
	cout << "myFunc() " << ref.getNum() << endl;
}

int main()
{
	MyClass A(100);
	myFunc(A);       // 일반적으로 함수를 호출하는 경우

	myFunc(300);     // 🎈🎈 인자를 300을 넣었는데 컴파일 오류가 발생하지 않는다.

	return 0;
}
```

`myFunc()`는 `MyClass`객체에 대한 참조값을 매개변수로 받는다. 그렇다면 어떻게 `myFunc(300)`이 오류가 발생하지 않는걸까?

**이는 컴파일러가 `myFunc()`를 호출하면서 묵시적 변환을 통해 300이라는 인자값을 `MyClass`의 변환 생성자의 매개변수 값으로 활용해
임시 객체를 만들고 그 임시 객체를 인자값으로 넣었기 때문이다.**
<br>
<br>
<br>
<br>
추가적으로, 당연히 아래의 코드처럼 `myFunc()`의 매개변수 `MyClass& ref`를 `const`형이 아니도록 하면 오류가 발생한다.
```cpp
void myFunc(MyClass& ref)   // 🎈🎈 const를 빼버리면 오류!!
{
	cout << "myFunc() " << ref.getNum() << endl;
}
```
만약 `const`를 붙이기 싫다면 아래와 같이 일반적인 객체 선언으로 매개변수를 지정하면 된다.
```cpp
void myFunc(MyClass foo)   
{
	cout << "myFunc() " << ref.getNum() << endl;
}
```
---
### explict 키워드

묵시적 변환을 허용하면 코드가 실제로 어떻게 작동되는지 알아보기가 어려워 오해를 일으킬 수 있다.

이를 막기 우해 변환 생성자를 정의할 경우에는 앞에 `explicit`라는 키워드를 사용하여 묵시적 변환을 막을 수 있다.

> *explicit: 명백한*

```cpp
#include <iostream>
using namespace std;

class MyClass
{
private:
	int num;
public:
	explicit MyClass(int x) : num(x)
	{}

	int getNum() const
	{
		return num;
	}
};

void myFunc(const MyClass& ref)
{
	cout << "myFunc() " << ref.getNum() << endl;
}

int main()
{
	MyClass A(100);
	myFunc(A);

	myFunc(300);   // ❌ 오류 발생!!

	return 0;
}
```
