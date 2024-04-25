***multiset 컨테이너는 중복 원소를 컨테이너에 저장할 수 있다는 것 외에는 set과 다른 것이 없습니다.***

set처럼 원소가 자동 정렬되는 연관 컨테이너에 노드 기반 컨테이너입니다.

multiset은 템플릿 형식, 주요 인터페이스, 멤버의 형식이 모두 set과 같습니다.

---

## 🔥multiset의 `insert()`
multiset의 `insert()`는 key(원소)가 중복 저장될 수 있기 때문에 set처럼 저장 위치와 삽입 성공 여부의 bool 값을 반환하는 pair 객체가 아닌
저장된 위치만을 가리키는 반복자를 반환합니다. 

```cpp
#include <iostream>
#include <set>
using namespace std;

int main()
{
	multiset<int> ms;
	multiset<int>::iterator iter;

	ms.insert(50);
	ms.insert(30);
	ms.insert(80);
	ms.insert(80); // 80 중복
	ms.insert(30); // 30 중복
	ms.insert(70);
	iter = ms.insert(10);

	cout << "iter의 원소: " << *iter << endl;          // iter의 원소: 10 

	for (iter = ms.begin(); iter != ms.end(); ++iter)  // 10 30 30 50 70 80 80 
		cout << *iter << " ";
	cout << endl;

	return 0;
}
```

## 🔥multiset의 `count()`, `find()`, `lower_bound()`, `upper_bound()`, `equal_range()` 멤버 함수

```cpp
#include <iostream>
#include <set>
using namespace std;

int main()
{
	multiset<int> ms;
	multiset<int>::iterator iter;

	ms.insert(50);
	ms.insert(30);
	ms.insert(80);
	ms.insert(80); // 80 중복
	ms.insert(30); // 30 중복
	ms.insert(70);
	iter = ms.insert(10);

	for (iter = ms.begin(); iter != ms.end(); ++iter) // 10 30 30 50 70 80 80
		cout << *iter << " ";
	cout << endl;

	cout << "30 원소의 개수: " << ms.count(30) << endl; // 30 원소의 개수: 2

	iter = ms.find(30);
	cout << "iter: " << *iter << endl; // iter: 30

	multiset<int>::iterator lower_iter;
	multiset<int>::iterator upper_iter;

	lower_iter = ms.lower_bound(30);
	upper_iter = ms.upper_bound(30);
	cout << "lower_iter: " << *lower_iter << ", ";
	cout << "upper_iter: " << *upper_iter << endl; // lower_iter: 30, upper_iter: 50

	cout << "구간 [lower_iter, upper_iter)의 순차열: ";
	for (iter = lower_iter; iter != upper_iter; iter++) // 구간 [lower_iter, upper_iter)의 순차열: 30 30
		cout << *iter << " ";
	cout << endl;

	return 0;
}
```
```
출력결과

10 30 30 50 70 80 80
30 원소의 개수: 2
iter: 30
lower_iter: 30, upper_iter: 50
구간 [lower_iter, upper_iter)의 순차열: 30 30
```

<br> 

쉽지만 아래의 코드를 그림으로 나타내면 다음과 같다.

```cpp
lower_iter = ms.lower_bound(30);
upper_iter = ms.upper_bound(30);

cout << "구간 [lower_iter, upper_iter)의 순차열: ";

for (iter = lower_iter; iter != upper_iter; iter++) // 구간 [lower_iter, upper_iter)의 순차열: 30 30
  cout << *iter << " ";
```
![image](https://github.com/SunFlower2819/Today-I-learned/assets/130738283/bfb43c07-e3de-4fb1-afee-9304912fa040)

## 🔥`equal_range()` 멤버 함수
`equal_range()` 멤버 함수는 원소의 구간을 pair 객체로 반환합니다.
`lower_bound()`와 `upper_bound()`가 반환하는 반복자 쌍입니다.

```cpp
#include <iostream>
#include <set>
using namespace std;

int main()
{
	multiset<int> ms;
	multiset<int>::iterator iter;

	ms.insert(50);
	ms.insert(30);
	ms.insert(80);
	ms.insert(80); // 80 중복
	ms.insert(30); // 30 중복
	ms.insert(70);
	iter = ms.insert(10);

	for (iter = ms.begin(); iter != ms.end(); ++iter) // 10 30 30 50 70 80 80 출력
		cout << *iter << " ";
	cout << endl;

	// multiset의 반복자 쌍(pair) 객체 생성
	pair<multiset<int>::iterator, multiset<int>::iterator> iter_pair;
	iter_pair = ms.equal_range(30);

	for (iter = iter_pair.first; iter != iter_pair.second; ++iter) // 30 30 출력
		cout << *iter << " ";
	cout << endl;

	return 0;
}
```

`equal_range()`가 찾는 원소의 시작 반복자와 끝 반복자 쌍을 반환합니다.

만약 `iter_pair.first`와 `iter_pair.second`가 같다면 찾는 원소가 없습니다.
