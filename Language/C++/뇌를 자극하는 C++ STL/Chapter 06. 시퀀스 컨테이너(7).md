![image](https://github.com/SunFlower2819/Today-I-learned/assets/130738283/04c6828a-e129-4a8b-b18b-79bbdb339edb)

list는 시퀀스 컨테이너이므로 원소의 저장 위치(순서)가 정해지며 노드 기반 컨테이너이므로 원소가 각각의 노드에 저장됩니다.
각 노드는 앞쪽, 뒤쪽 노드와 연결된 형태로 ***이중 연결 리스트***입니다.

list는 노드 기반 컨테이너로 `at()`과 `[]`연산자가 없으며 임의 접근 반복자가 아닌 양방향 반복자를 제공합니다.
그래서 모든 원소를 탐색하려면 양방향 반복자의 연산인 `++`,`--`를 사용합니다.

---

## 🔥list의 원소 추가와 반복자
```cpp
#include <iostream>
#include <list> 
using namespace std;

int main()
{
	list<int> lt;

	lt.push_back(10); // 뒤쪽에 추가
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(40);
	lt.push_back(50);

	list<int>::iterator iter;
	for (iter = lt.begin(); iter != lt.end(); iter++) // 10 20 30 40 50 출력
		cout << *iter << " ";
	cout << endl;

	lt.push_front(100); // 앞쪽에 추가
	lt.push_front(200);

	for (iter = lt.begin(); iter != lt.end(); iter++) // 200 100 10 20 30 40 50 출력
		cout << *iter << " ";
	
	return 0;
}
```
---

## 🔥list의 `insert()`와 `erase()`
***list의 가장 큰 특징 중 하나는 순차열 중간에 원소를 삽입(insert), 제거(erase)하더라도 상수 시간 복잡도의 수행 성능을 보인다는 점입니다.
배열 기반 컨테이너 vector나 deque처럼 원소를 밀어내지 않고 노드를 서로 연결하기만 하면 되기 때문입니다.***

```
또한, 노드 기반 컨테이너 삽입(insert)과 제거(erase) 동작은 반복자를 무효화시키지 않습니다.
반복자가 가리키는 원소 자체가 제거되지 않는 한 반복자가 가리키는 원소는 그대로 존재합니다.
하지만 배열 기반 컨테이너(vector, deque)의 반복자는 원소의 삽입과 제거 동작이 발생하면
메모리가 재할당되거나 원소가 이동할 수 있으므로 반복자가 무효화됩니다.

-> 위의 문단이 이해가 안됐다. 근데 그냥 쉽게 말하면 list는 노드 기반 컨테이너이기 때문에
   원소를 삽입하거나 제거하는 과정에서 메모리의 재할당이 필요없지만,
   vector 같이 배열 기반 컨테이너는 원소를 삽입하거나 제거하는 과정에서
   메모리 재할당이 일어난다는 의미이다.

   아래에 코드와 그림으로 보자.
```

```cpp
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main()
{
	list<int> lt;
	vector<int> v;

	lt.push_back(10); 
	lt.push_back(20);
	lt.push_back(30);

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	list<int>::iterator Liter = lt.begin();
	vector<int>::iterator Viter = v.begin();

	Liter++; // 원소 20을 가리킴
	Viter++; // 원소 20을 가리킴

	Liter = lt.insert(Liter, 999);
	Viter = v.insert(Viter, 999);

	cout << *Liter << endl; // 999 출력 
	cout << *Viter << endl; // 999 출력

	for (Liter = lt.begin(); Liter != lt.end(); Liter++)  // 10 999 20 30 출력
		cout << *Liter << " ";
	cout << endl;

	for (Viter = v.begin(); Viter != v.end(); Viter++)   // 10 999 20 30 출력
		cout << *Viter << " ";

	return 0;
}
```

아래의 그림처럼 `v`에 999를 삽입하면 다음 원소부터 모두 뒤로 밀려나며 할당된 메모리 공간이 부족하면 메모리 재할당이 발생한다.
하지만, `lt`는 원소(노드) 하나만을 삽입하므로 속도가 빠르며 반복자들이 무효화되지 않는다. 

또한, `erase()`함수의 동작도 '삽입'동작과 같은 특징을 보인다.

![image](https://github.com/SunFlower2819/Today-I-learned/assets/130738283/1b4cccea-f54e-4371-a456-111ed616d5c0)

---

## 🔥list의 `remove()`와 `remove_if()`
`remove()` 멤버 함수는 컨테이너의 모든 원소를 순차적으로 검색하며 해당 원소를 제거합니다.

list의 `remove()`는 `erase()`처럼 해당 값의 노드만을 제거하므로 속도가 빠르며 유일하게 list만이 `remove()`멤버 함수를 가지므로 반복자가 아닌 원소의 값으로
컨테이너의 원소 제거해야 한다면 list 컨테이너를 선택하는 것이 좋습니다.

```cpp
#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> lt;

	lt.push_back(0); 
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(0);
	lt.push_back(50);
	lt.push_back(0);
	lt.push_back(70);
	lt.push_back(0);
	lt.push_back(0);

	for (list<int>::iterator iter = lt.begin(); iter != lt.end(); iter++) // 0 20 30 0 50 0 70 0 0 출력
		cout << *iter << " ";
	cout << endl;

	lt.remove(0); // 0 원소의 노드를 모두 제거

	for (list<int>::iterator iter = lt.begin(); iter != lt.end(); iter++) // 20 30 50 70 출력
		cout << *iter << " ";

	return 0;
}
```
<br>

`remove_if()` 멤버 함수는 단항 조건자(predicate)가 참인 모든 원소를 제거합니다.

조건자는 bool 형식을 반환하는 함수류(함수, 함수 객체, 함수 포인터)입니다.
```cpp
#include <iostream>
#include <list>
using namespace std;

bool Predicate(int n) // 단한 조건자
{
	return 10 <= n && n <= 30;
}

int main()
{
	list<int> lt;

	lt.push_back(10); 
	lt.push_back(20); 
	lt.push_back(30); 
	lt.push_back(40); 
	lt.push_back(50); 

	for (list<int>::iterator iter = lt.begin(); iter != lt.end(); iter++) // 10 20 30 40 50 출력
		cout << *iter << " ";
	cout << endl;

	lt.remove_if(Predicate); // 조건자가 참임 모든 원소를 제

	for (list<int>::iterator iter = lt.begin(); iter != lt.end(); iter++) // 40 50 출력
		cout << *iter << " ";

	return 0;
}
```

---

## 🔥list의 `splice()`
순서가 있는 노드 기반 컨테이너 `list`는 이런 특징을 잘 반영하듯 `splice()`라는 멤버 함수를 가집니다.
`splice()`는 다른 `list` 컨테이너의 순차열을 잘라붙일 수 있습니다.

> splice (verb) : 접착하다 <br>
> to join two pieces of rope, film, etc. together at their ends in order to form one long piece:

***반복자가 가리키는 위치에 `list`를 접착한다.***

```cpp
#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> lt1;
	list<int> lt2;

	lt1.push_back(10); 
	lt1.push_back(20); 
	lt1.push_back(30); 
	lt1.push_back(40); 
	lt1.push_back(50); 

	lt2.push_back(100);
	lt2.push_back(200);
	lt2.push_back(300);
	lt2.push_back(400);
	lt2.push_back(500);
	
	cout << "lt1: ";
	for (list<int>::iterator iter = lt1.begin(); iter != lt1.end(); iter++) // 10 20 30 40 50 출력
		cout << *iter << " ";
	cout << endl;

	cout << "lt2: ";
	for (list<int>::iterator iter = lt2.begin(); iter != lt2.end(); iter++) // 100 200 300 400 500 출력
		cout << *iter << " ";
	cout << endl;

	list<int>::iterator iter = lt1.begin();
	iter++;
	iter++;

	lt1.splice(iter, lt2);

	cout << "lt1: ";
	for (list<int>::iterator iter = lt1.begin(); iter != lt1.end(); iter++) // 10 20 100 200 300 400 500 30 40 50 출력 <-- 원래 30 자리에 list2를 splice
		cout << *iter << " ";
	cout << endl;

	cout << "lt2: ";
	for (list<int>::iterator iter = lt2.begin(); iter != lt2.end(); iter++) // 🎈🎈아무것도 출력안됨. 
		cout << *iter << " ";
	cout << endl << endl;

	//------------------------------------------------------------------------------------------------------

	list<int> lt3;
	list<int> lt4;

	lt3.push_back(10);
	lt3.push_back(20);
	lt3.push_back(30);
	lt3.push_back(40);
	lt3.push_back(50);

	lt4.push_back(100);
	lt4.push_back(200);
	lt4.push_back(300);
	lt4.push_back(400);
	lt4.push_back(500);

	cout << "lt3: ";
	for (list<int>::iterator iter = lt3.begin(); iter != lt3.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "lt4: ";
	for (list<int>::iterator iter = lt4.begin(); iter != lt4.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	list<int>::iterator iter3 = lt3.begin();
	iter3++;
	iter3++; // lt3의 30을 가리킴

	list<int>::iterator iter4 = lt4.begin();
	iter4++; // lt4의 200을 가리킴
	
	lt3.splice(iter3, lt4, iter4); // 🎈🎈iter3의 위치에 lt4의 반복자 iter4를 접착해라

	cout << "lt3: ";
	for (list<int>::iterator iter = lt3.begin(); iter != lt3.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "lt4: ";
	for (list<int>::iterator iter = lt4.begin(); iter != lt4.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	return 0;
}
```
```
출력결과

lt1: 10 20 30 40 50
lt2: 100 200 300 400 500
lt1: 10 20 100 200 300 400 500 30 40 50
lt2:

lt3: 10 20 30 40 50
lt4: 100 200 300 400 500
lt3: 10 20 200 30 40 50
lt4: 100 300 400 500
```

---

## 🔥list의 `reverse()`
만약 모든 원소의 순차열을 반대로 뒤집어야 한다면 `list`의 `reverse()` 멤버 함수를 사용하면됩니다.
`reverse()`는 이중 연결 리스트의 탐색 경로를 서로 바꿈으로써 순차열을 리버스시킵니다.

```cpp
#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> lt;

	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(40);
	lt.push_back(50);

	for (list<int>::iterator iter = lt.begin(); iter != lt.end(); iter++) // 10 20 30 40 50 출력
		cout << *iter << " ";
	cout << endl;

	lt.reverse();

	for (list<int>::iterator iter = lt.begin(); iter != lt.end(); iter++) // 50 40 30 20 10 출력
		cout << *iter << " ";

	return 0;
}
```

---

## 🔥list의 `unique()`
원소를 중복되지 않게 하나씩만 남기고 싶다면 `unique()` 멤버 함수를 사용합니다.
주의할 점은 `unique()` 멤버 함수는 인접한 원소를 하나만 남기므로 연속하지 않는 원소는 중복될 수 있습니다.

그니까 `10 10 20 30 40 40 10 30` 이렇게 있으면 `10 20 30 40 10 30`이 출력된다는 것이다.

```cpp
#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> lt;

	lt.push_back(10);
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(40);
	lt.push_back(40);
	lt.push_back(10);
	lt.push_back(30);

	for (list<int>::iterator iter = lt.begin(); iter != lt.end(); iter++) // 10 10 20 30 40 40 10 30 출력 
		cout << *iter << " ";
	cout << endl;

	lt.unique();

	for (list<int>::iterator iter = lt.begin(); iter != lt.end(); iter++) // 10 20 30 40 10 30 출력
		cout << *iter << " ";

	return 0;
}
```

<br>

또한 `unique()` 멤버 함수로 모든 원소를 유일하게 만들고자 한다면 원소를 정렬한 후 `unique()`를 수행하면 됩니다. (`sort()` 제공)

또한, `list`는 조건자 버전의 `unique()` 멤버 함수도 제공합니다. 이항 조건자를 인자로 받는 이 버전의 함수는 연속한 두 원소를 인자로 받아 조건자가 참이면 원소를 제거합니다.

```cpp
#include <iostream>
#include <list>
using namespace std;

bool Predicate(int first, int second)
{
	return second - first <= 0;
}

int main()
{
	list<int> lt;

	lt.push_back(10);
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(40);
	lt.push_back(40);
	lt.push_back(10);
	lt.push_back(30);

	for (list<int>::iterator iter = lt.begin(); iter != lt.end(); iter++) // 10 10 20 30 40 40 10 30 출력 
		cout << *iter << " ";
	cout << endl;

	lt.unique(Predicate);

	for (list<int>::iterator iter = lt.begin(); iter != lt.end(); iter++) // 10 20 30 40 출력
		cout << *iter << " ";

	return 0;
}
```

---

## 🔥list의 `sort()`
`list`는 정렬을 위한 멤버 함수 `sort()`를 제공합니다. 정렬을 수행할 수 있는 컨테이너는 시퀀스 컨테이너(vector, deque, list)입니다.

연관 컨테이너는 자체 정렬 기준에 의해 자동 정렬됩니다.

시퀀스 컨테이너 중 vector와 deque는 `sort()`알고리즘을 사용하여 빠르게 정렬할 수 있지만, list는 `sort()` 알고리즘을 수행할 수 없습니다.
`sort()` 알고리즘은 임의 접근 반복자(대부분 quick sort로 구현됨)를 지원하는 컨테이너만 사용할 수 있기 때문입니다.

그래서 list는 자체 정렬 멤버함수 `sort()`를 제공합니다. 

```cpp
#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> lt;

	lt.push_back(40);
	lt.push_back(20);
	lt.push_back(10);
	lt.push_back(50);
	lt.push_back(30);

	for (list<int>::iterator iter = lt.begin(); iter != lt.end(); iter++) // 40 20 10 50 30 출력
		cout << *iter << " ";
	cout << endl;

	lt.sort(); // 오름차순(less) 정렬

	for (list<int>::iterator iter = lt.begin(); iter != lt.end(); iter++) // 10 20 30 40 50 출
		cout << *iter << " ";

	return 0;
}
```

<br>

`sort()`의 조건자 버전을 사용하면 정렬 기준을 바꿀 수 있습니다. `sort()`는 이항 조건자를 사용하며 이항 조건자가 참이면 두 원소(left, right)를 바꾸지 않고 거짓이면
두 원소를 바꿔가며 정렬합니다.

`greater`나 `less` 조건자는 <functional> 헤더에 들어 있지만 일반적으로 컨테이너(list) 헤더에서 포함하므로 include를 생략했습니다.

```cpp
#include <iostream>
#include <list>
using namespace std;

struct Greater
{
	bool operator() (int left, int right) const
	{
		return left > right;
	}
};

int main()
{
	list<int> lt;

	lt.push_back(40);
	lt.push_back(20);
	lt.push_back(10);
	lt.push_back(50);
	lt.push_back(30);

	for (list<int>::iterator iter = lt.begin(); iter != lt.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	lt.sort(greater<int>()); // 조건자 greater를 사용하여 내림차순 정렬
	for (list<int>::iterator iter = lt.begin(); iter != lt.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	lt.sort(less<int>()); // 조건자 less를 사용하여 다시 오름차순 정렬
	for (list<int>::iterator iter = lt.begin(); iter != lt.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	lt.sort(Greater()); // 사용자 정의 조건자를 사용하여 내림차순 정렬
	for (list<int>::iterator iter = lt.begin(); iter != lt.end(); iter++)
		cout << *iter << " ";

	return 0;
}
```

```
출력결과
40 20 10 50 30
50 40 30 20 10
10 20 30 40 50
50 40 30 20 10
```

---

## 🔥list의 `merge()`
합병은 정렬된 두 list를 하나의 정렬된 list로 합병하므로 합병할 두 list는 정렬되어 있어야합니다.

`splice()`와 비교하여 알아두면 좋습니다.

```cpp
#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> lt1;
	list<int> lt2;

	lt1.push_back(10);
	lt1.push_back(20);
	lt1.push_back(30);
	lt1.push_back(40);
	lt1.push_back(50);

	lt2.push_back(15);
	lt2.push_back(25);
	lt2.push_back(35);

	cout << "lt1: ";
	for (list<int>::iterator iter = lt1.begin(); iter != lt1.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "lt2: ";
	for (list<int>::iterator iter = lt2.begin(); iter != lt2.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "--------------" << endl;

	lt1.merge(lt2); // lt2를 lt1으로 합병 정렬. 정렬 기준은 less

	cout << "lt1: ";
	for (list<int>::iterator iter = lt1.begin(); iter != lt1.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "lt2: ";
	for (list<int>::iterator iter = lt2.begin(); iter != lt2.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	return 0;
}
```
```
출력결과
lt1: 10 20 30 40 50
lt2: 15 25 35
--------------
lt1: 10 15 20 25 30 35 40 50
lt2:
```
위의 코드는 `lt1`에 `lt2`를 합병해 정렬하는 코드다. `lt2`의 원소는 합병되어 사라진다.

***🎈🎈`merge()` 멤버 함수는 `lt1`과 `lt2`가 오름차순으로 정렬되어 있다는 가정하에 동작한다. 즉, 내림차순으로 정렬되어 있으면 오류를 발생시킨다.***

list가 다른 정렬 기준을 사용하고있다면 조건자 버전 `merge()` 멤버 함수를 사용하여 합병해야 합니다.
만약 정렬 기준이 틀렸거나 합병할 list가 정렬돼 있지 않다면 `merge()` 멤버 함수는 실패하며 오류가 발생합니다.

아래 코드는 조건자 버전 `merge()` 예시 코드이며, 합병할 두 list에 맞춰 조건자를 지정해야 한다. 

```cpp
#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> lt1;
	list<int> lt2;
	lt1.push_back(50);
	lt1.push_back(40);
	lt1.push_back(30);
	lt1.push_back(20);
	lt1.push_back(10);

	// lt1과 lt2는 정렬 방식이 같음
	// greater 조건자( > 연산 ) 정렬 기준 사용
	lt2.push_back(35);
	lt2.push_back(25);
	lt2.push_back(15);

	cout << "lt1: ";
	for (list<int>::iterator iter = lt1.begin(); iter != lt1.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "lt2: ";
	for (list<int>::iterator iter = lt2.begin(); iter != lt2.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "--------------" << endl;

	lt1.merge(lt2, greater<int>());

	cout << "lt1: ";
	for (list<int>::iterator iter = lt1.begin(); iter != lt1.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "lt2: ";
	for (list<int>::iterator iter = lt2.begin(); iter != lt2.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	return 0;
}
```
```
출력결과

lt1: 50 40 30 20 10
lt2: 35 25 15
--------------
lt1: 50 40 35 30 25 20 15 10
lt2:
```

🎈🎈 **`lt1`과 `lt2`를 합병 정렬할 때 정렬 기준을 `lt1`과 `lt2`와 같게 지정하지 않으면 오류가 발생합니다.**

