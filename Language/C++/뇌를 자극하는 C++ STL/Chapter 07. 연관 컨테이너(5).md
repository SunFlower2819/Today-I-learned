map은 set처럼 컨테이너에 원소(key,value의 쌍)를 삽입하는 유일한 멤버 함수 `insert()`를 제공합니다.

기본 정렬 기준은 less이며, 컨테이너의 모든 key는 ***유일합니다.***

원소의 중복을 허용해야 한다면 multimap을 사용해야 합니다.

![image](https://github.com/SunFlower2819/Today-I-learned/assets/130738283/9984b59a-0327-41c6-b91f-22e591da6aa0)

map의 원소는 pair 객체로 저장되며 pair 객체의 first 멤버 변수는 key로 second 멤버 변수는 value입니다.
원소를 저장하는 `inerst()`멤버 함수는 pair 객체를 인자로 받아 map의 원소인 key와 value의 쌍을 저장합니다.

---

## 🔥map의 `insert()`

```cpp
#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, int> m;

	m.insert(pair<int, int>(5, 100));  // 임시 pair 객체 생성 후 저장
	m.insert(pair<int, int>(3, 100));
	m.insert(pair<int, int>(8, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(1, 70));
	m.insert(pair<int, int>(7, 100));
	
	pair<int, int> pr(9, 50);
	m.insert(pr); // pr 객체 생성 후 저장

	map<int, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "(" << (*iter).first << ", " << (*iter).second << ") ";
	cout << endl;

	// 반복자는 -> 연산자가 operator오버로딩이 되어 있으므로
	// 포인터 멤버를 ->연산자로 접근할 수 있다.
	for(iter = m.begin(); iter != m.end(); ++iter)
		cout << "(" << iter->first << ", " << iter->second << ") ";

	return 0;
}
```
```
출력결과
(1, 70) (3, 100) (4, 40) (5, 100) (7, 100) (8, 30) (9, 50)
(1, 70) (3, 100) (4, 40) (5, 100) (7, 100) (8, 30) (9, 50)
```

<br>

map의 `insert()` 멤버 함수는 set처럼 저정한 원소의 위치를 가리키는 반복자와 삽입 성공 여부를 나타내는 bool 값을 pair 객체로 반환합니다.

```cpp
#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, int> m;
	pair<map<int, int>::iterator, bool> pr;

	m.insert(pair<int, int>(5, 100));  // 임시 pair 객체 생성 후 저장
	m.insert(pair<int, int>(3, 100));
	m.insert(pair<int, int>(8, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(1, 70));
	m.insert(pair<int, int>(7, 100));
	
	pr = m.insert(pair<int, int>(9, 50)); // 성공!
	if (pr.second == true)
		cout << "key: " << pr.first->first << ", value: " << pr.first->second << " 삽입 성공!" << endl;
	else
		cout << "key 9가 이미 m에 있습니다." << endl;

	//------------------------------------------------------

	pr = m.insert(pair<int, int>(9, 50)); // 실패
	if (pr.second == true)
		cout << "key: " << pr.first->first << ", value: " << pr.first->second << endl;
	else
		cout << "key 9가 이미 m에 있습니다." << endl;

	return 0;
}
```
```
출력결과

key: 9, value: 50 삽입 성공!
key 9가 이미 m에 있습니다.
```

## 🔥map의 `[]`연산자
map은 `[]` 연산자를 사용하여 쉽게 원소(key,value)를 추가하거나 value 값을 갱신할 수 있습니다.
key에 해당하는 원소가 map에 없다면 추가 연산을 수행합니다.

key에 해당하는 원소가 있다면 key에 해당하는 원소의 value를 갱신하는 연산을 수행합니다.

```cpp
#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, int> m;

	m[5] = 100; // key 5, value 100의 원소를 m에 삽입한다.
	m[3] = 50;
	m[8] = 30;
	m[1] = 20;
	m[2] = 70;
	m[4] = 100;

	map<int, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "(" << iter->first << ", " << iter->second << ") ";
	cout << endl;

	m[5] = 999; // 🎈🎈key 5의 value를 999로 갱신!!
	m[1] = 0;   // key 1의 value를 0으로 갱신!!

	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "(" << iter->first << ", " << iter->second << ") ";
	cout << endl;

	return 0;
}
```
```
출력결과

(1, 20) (2, 70) (3, 50) (4, 100) (5, 100) (8, 30)
(1, 0) (2, 70) (3, 50) (4, 100) (5, 999) (8, 30)
```

## 🔥map의 정렬 기준 
map 컨테이너의 기본 정렬 기준은 less입니다. 정렬 기준을 바꾸려면 템플릿 형식의 세 번째 인자를 이용합니다.

***🎈🎈key를 기준으로 내림차순으로 정렬하는 코드이다. 또한 `[]`연산자의 인덱스는 key이고, 이를 이용해서 value를 출력한다.***

```cpp
#include <iostream>
#include <map>
using namespace std;

int main()
{
	// greater 정렬 기준의 key:int, value:string 타입의 컨테이너 m 생성
	map<int, string, greater<int>> m;

	m[5] = "five"; 
	m[3] = "three";
	m[8] = "eight";
	m[1] = "one";
	m[2] = "two";
	m[4] = "four";
	m[9] = "nine";

	map<int, string, greater<int>>::iterator iter;
	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "(" << iter->first << ", " << iter->second << ") ";
	cout << endl;

	cout << m[9] << " "; // key와 매핑된 value 출력
	cout << m[8] << " ";
	cout << m[5] << " ";
	cout << m[4] << " ";
	cout << m[3] << " ";
	cout << m[2] << " ";
	cout << m[1] << " " << endl;

	return 0;
}
```
```
실행결과

(9, nine) (8, eight) (5, five) (4, four) (3, three) (2, two) (1, one)
nine eight five four three two one
```

## 🔥map의 `find()`, `lower_bound()`, `upper_bound()`, `equal_range()`

```cpp
#include <iostream>
#include <map>
using namespace std;

int main()
{
	// greater 정렬 기준의 key:int, value:string 타입의 컨테이너 m 생성
	map<int, string, greater<int>> m;

	m[5] = "five"; 
	m[3] = "three";
	m[8] = "eight";
	m[1] = "one";
	m[2] = "two";
	m[4] = "four";
	m[9] = "nine";

	map<int, string, greater<int>>::iterator iter;
	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "(" << iter->first << ", " << iter->second << ") ";
	cout << endl;

	iter = m.find(8);
	if (iter != m.end())
		cout << "key 8에 매핑된 value: " << iter->second << endl << endl;

	//-----------------------------------------------------------------------

	map<int, string>::iterator lower_iter;
	map<int, string>::iterator upper_iter;
	lower_iter = m.lower_bound(5);
	upper_iter = m.upper_bound(5);
	
	cout << "구간 [lower_iter, upper_iter)의 순차열: ";
	for (iter = lower_iter; iter != upper_iter; ++iter)
		cout << "(" << iter->first << ", " << iter->second << ") ";
	cout << endl << endl;;

	pair<map<int, string>::iterator, map<int, string>::iterator> iter_pair;
	iter_pair = m.equal_range(5);

	cout << "구간 [iter_pair.first, iter_pair.second)의 순차열: ";
	for (iter = iter_pair.first; iter != iter_pair.second; ++iter)
		cout << "(" << iter->first << ", " << iter->second << ") ";
	cout << endl;

	return 0;
}
```
```
출력결과

(9, nine) (8, eight) (5, five) (4, four) (3, three) (2, two) (1, one)
key 8에 매핑된 value: eight

구간 [lower_iter, upper_iter)의 순차열: (5, five)

구간 [iter_pair.first, iter_pair.second)의 순차열: (5, five)
```

<br>

```cpp
	pair<map<int, string>::iterator, map<int, string>::iterator> iter_pair;
	iter_pair = m.equal_range(5);
```
위의 코드가 헷갈려서 아래의 그림을 그려봤다.

![image](https://github.com/SunFlower2819/Today-I-learned/assets/130738283/b3d8439c-698a-45d4-ba06-e13a6cec55d6)

---
# map의 주요 특징 정리
map은 대표적인 연관 컨테이너이자 노드 기반 컨테이너입니다. 그래서 특정 정렬 기준으로 원소(key)가 자동 정렬되며 연관 컨테이너(set, multiset, map, multimap)는 모두
같은 인터페이스의 멤버 함수를 제공합니다.

set의 원소는 key만으로 이뤄지지만 map의 원소는 key와 value 쌍으로 이뤄집니다.

map은 `[]`연산자를 이용해 원소(key,value)를 추가하거나 key에 매팽된 value의 참조를 반환할 수 있습니다.

map도 set처럼 연관 컨테이너이므로 컨테이너 앞, 뒤에 추가하거나 제거하는 멤버 함수류를 제공하지 않으며 원소를 참조하는 front()와 back() 멤버 함수도 제공하지 않습니다.

연관 컨테이너의 핵심은 빠른 원소 찾기(검색)이며 균형 이진 트리를 이용한 로그 시간 검색 복잡도를 보장합니다.

`[]`연산자를 사용하여 원소를 추가할 수도 있지만, `insert()`멤버 함수로 원소를 추가할 수 있습니다.

