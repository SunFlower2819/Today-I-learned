# 🔵알고리즘

STL 알고리즘은 일곱 가지의 범주로 분류합니다.
* 원소를 수정하지 않는 알고리즘(nonmodifying algorithms)
* 원소를 수정하는 알고리즘(modifiying algorithms)
* 제거 알고리즘(remove algorithms)
* 변경 알고리즘(mutating algorithms)
* 정렬 알고리즘(sort algorithms)
* 정렬된 범위 알고리즘(sorted range algorithms)
* 수치 알고리즘(numeric algorithms)

STL 알고리즘은 아주 일반적입니다. 일반적이라는 의미는 특정 컨테이너나 원소 타입에 종속적이지 않다는 뜻입니다.
예를 들어 `find`알고리즘은 ***순방향 반복자***를 요구하기 때문에 순반향 반복자만 지원하는 컨테이너(순차열)라면 어떤 컨테이너가 와도 알고리즘을 수행할 수 있으며
컨테이너 원소가 정소, 실수, 문자열 혹은 사용자 정의 타입이어도 가능합니다.

아래는 `find` 알고리즘 코드이다.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> v;
	
	v.push_back("HELLO");
	v.push_back("HI");
	v.push_back("BYE");
	v.push_back("GOOD");
	v.push_back("APPLE");

	vector<string>::iterator iter;
	iter = find(v.begin(), v.end(), "GOOD");  // [begin, end)에서 "GOOD" 찾기
	cout << *iter << endl;
	
	iter = find(v.begin(), v.end(), "SHIT");  // [begin, end)에서 "SHIT" 찾기
	if (iter == v.end())                      // "SHIT"이 없으면 iter == v.end() 임
		cout << "SHIT이 없음!!" << endl;

	return 0;
}
```
---

순차열을 정렬하는 `sort`알고리즘은 ***임의 접근 반복자***를 요구하므로 vector, deque는 `sort`알고리즘을 수행할 수 있지만 다른 컨테이너는 불가능합니다.
사실 연관 컨테이너는 컨테이너만의 정렬 기준을 가지고 있기 때문에 `sort`알고리즘 적용 자체가 말이 안 됩니다.

아래는 에러 코드이다.
```cpp
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v;
	v.push_back(30);
	v.push_back(10);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	list<int> lt;
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(40);
	lt.push_back(50);

	sort(v.begin(), v.end());
	sort(lt.begin(), lt.end());  // <-- ❌에러 발생!!

	vector<int>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++)  // 10 20 30 40 50으로 정렬돼서 출력
		cout << *iter << endl;

	return 0;
}
```

# 🔵함수 객체

STL에서 함수 객체는 클라이언트가 정의한 동작을 다른 구성 요소에 반영하려 할 때 사용됩니다.
함수 객체를 사용하면 STL 구성 요소를 더욱 유연하게 사용할 수 있습니다.
특히 많은 STL 알고리즘이 함수 객체, 함수, 함수 포인터 등의 함수로를 인자로 받아 알고리즘을 유연하게 동작시킵니다.

아래의 코드는 sort 알고리즘에 함수 객체 less와 greater을 적용한 코드다.

만약 이해가 안된다면 `Chapter 04. 템플릿(3).md`를 보면 도움이 된다.

https://github.com/SunFlower2819/Today-I-learned/blob/main/Language/C%2B%2B/%EB%87%8C%EB%A5%BC%20%EC%9E%90%EA%B7%B9%ED%95%98%EB%8A%94%20C%2B%2B%20STL/Chapter%2004.%20%ED%85%9C%ED%94%8C%EB%A6%BF(3).md#%ED%95%A8%EC%88%98-%EA%B0%9D%EC%B2%B4%EB%A5%BC-%EC%82%AC%EC%9A%A9%ED%95%98%EC%97%AC-%EC%B6%9C%EB%A0%A5

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v;
	v.push_back(30);
	v.push_back(10);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	sort(v.begin(), v.end(), less<int>());
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)  // 10 20 30 40 50으로 정렬돼서 출력
		cout << *iter << " ";

	cout << endl;

	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)  // 50 40 30 20 10으로 정렬돼서 출력
		cout << *iter << " ";

	return 0;
}
```
