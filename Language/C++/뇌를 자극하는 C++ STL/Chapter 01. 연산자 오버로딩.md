## 🔵 연산자 오버로딩 사용

```cpp
#include <iostream>

class Point
{
private:
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y)
	{}

	void Print() const
	{
		std::cout << x << ',' << y << std::endl;
	}

	const Point operator+ (const Point& arg) const
	{
		Point pt;
		pt.x = this->x + arg.x;
		pt.y = this->y + arg.y;

		return pt;
	}
};

int main()
{
	Point p1(2, 4);
	Point p2(5, 6);
	Point p3;

	p3 = p1 + p2; // p3 = p1.operator+(p2);
	p3.Print();

	return 0;
}
```


## 🔵 단항 연산자 오버로딩

### 🔥++ 연산자 오버로딩
```cpp
#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y)
	{}

	void Print() const
	{
		std::cout << x << ',' << y << std::endl;
	}

	const Point& operator++() 
	{
		this->x++;
		this->y++;
		return *this;
	}

	//Point operator++()  // 이것도 문제 없는 데 왜 위처럼 const& 형으로 반환을 하는 걸까?
	//{
	//	this->x++;
	//	this->y++;
	//	return *this;
	//}

	const Point& operator++(int) 
	{
		const Point pt(x, y);
		++*this;
		return pt;
	}
};

int main()
{
	Point p1(2, 4);
	Point p2(5, 6);
	Point result;

	result = ++p1;
	p1.Print();      // 3,5
	result.Print();  // 3,5

	result = p2++;
	p2.Print();      // 6,7
	result.Print();  // 5,6

	return 0;
}
```

### 🔥-- 연산자 오버로딩
```cpp
#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y)
	{}

	void Print() const
	{
		std::cout << x << ',' << y << std::endl;
	}

	const Point& operator--() 
	{
		x--;
		y--;
		return *this;
	}

	const Point& operator--(int) 
	{
		const Point pt(x, y);
		--*this;
		return pt;
	}
};

int main()
{
	Point p1(2, 4);
	Point p2(5, 6);
	Point result;

	result = --p1;   // result = p1.operator--();
	p1.Print();      // 1,4
	result.Print();  // 1,4

	result = p2--;   // result = p1.operator--(0);
	p2.Print();      // 4,5
	result.Print();  // 5,6

	return 0;
}
```
