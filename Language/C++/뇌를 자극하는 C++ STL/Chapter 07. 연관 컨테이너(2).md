set은 컨테이너에 원서(key)를 저장(삽입)하는 유일한 멤버 함수 `insert()`를 제공합니다. 연관 컨테이너 정렬 기준이 있으므로 `insert()`에 의해 삽입된 원소는
자동 정렬됩니다.

set에서 원소(10,30,40,50,70,80,90)를 key라 하며 이 키를 비교하여 내부 원소를 정렬합니다.

set은 그림처럼 모든원소(key)가 유일합니다. 원소의 중복을 허용한다면 ***multiset***을 사용해야 합니다.

![image](https://github.com/SunFlower2819/Today-I-learned/assets/130738283/6093007f-71cc-48f2-9cd4-5a7f31a2ad80)

***연관 컨테이너는 특정 정렬 기준(조건자)에 따라 원소를 자동 정렬하는 컨테이너 입니다.***

정렬 기준은 템플릿 매개변수에 지정할 수 있으며, 기본 정렬 기준은 less 조건자입니다.

연관 컨테이너는 균형 이진 트리를 사용하므로찾기 연산 <`find()`, `lower_bound()`, `upper_bound()`, `equal_range()`, `count()`>에 뛰어난 성능(로그 시간)을
보이며 `insert()` 멤버 함수를 이용한 삽입도 로그 시간 복잡도를 보인다.

---
 
## 🔥insert() 그리고 pair

```cpp
#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);
	s.insert(90);

	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	s.insert(50); // 중복 원소(key) 삽입 실패!!
	s.insert(50);

	for (iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	return 0;
}
```

<br>

set이 원소가 중복됨으로써 삽입에 실패했을 때, 반환하는 값은 pair 객체이다.

pair의 first는 삽입된 원소(key)의 위치를 가리키는 반복자이고, second는 삽입의 성공 여부에 대한 true(성공), 실패(false)를 나타내는 bool 값이다. 

![image](https://github.com/SunFlower2819/Today-I-learned/assets/130738283/91857eee-6945-43d4-85b4-3f672027d6da)


아래는 `insert()` 멤버 함수의 실패 시 반환값(pair 객체)에 대한 예제 코드이다.

```cpp
#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;
	pair<set<int>::iterator, bool> pr; // pr.first는 set<int>::iterator형, pr.second는 bool형

	pr = s.insert(50); // pair<set<int>::iterator, bool> 객체 반환 --> <50을 가리키는 반복자, true> 반환
	s.insert(40);
	s.insert(80);

	if (pr.second == true)
		cout << *pr.first << " 삽입 성공!" << endl;
	else
		cout << *pr.first << " 삽입 실패!(이미 존재)" << endl;

	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	pr = s.insert(50); // --> <50을 가리키는 반복자, false> 반환

	if (pr.second == true)
		cout << *pr.first << " 삽입 성공!" << endl;
	else
		cout << *pr.first << " 삽입 실패!(이미 존재)" << endl;

	for (iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	return 0;
}
```
```
실행결과

50 삽입 성공!
40 50 80
50 삽입 실패!(이미 존재)
40 50 80
```

<br>

연관 컨테이너는 시퀀서 컨테이너처럼 삽입할위치(반복자)를 지정하는 버전과 삽입할 구간(반복자 쌍)을 지정하는 버전의 `insert()`도 제공합니다.

단, 원소(key)의 삽입 위치를 지정하는 버전은 삽입 탐색을 시작할 위치로 삽입 위치가 정렬 순서와 맞는다면 바로 삽입되지만 아니라면 로그 시간이 걸립니다.

그니까, 쉽게 말하자면 삽입할 원소가 반복자의 위치부터 탐색할 때 정렬 기준에 맞는 원소라면 바로 삽입이 되지만, 아니면 다시 탐색을 해야하기 때문에 로그 시간이 걸린다는 뜻이다.

`10 30 40 50 60` 에서 `s.insert(pr.first, 55);`을 사용해서 반복자가 `50`을 가리키고 넣고 싶은 원소가 `55`라면 바로 넣어지지만, 넣고 싶은 원소가 `15`라면 삽입 탐색을 해야한다.

```cpp
#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;
	pair<set<int>::iterator, bool> pr;

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);
	pr = s.insert(90); //pr.first는 90원소의 반복자, pr.second는 true

	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); ++iter) // 10 30 40 50 70 80 90 출력
		cout << *iter << " "; 
	cout << endl;

	s.insert(pr.first, 85);    // 90 원소의 반복자에서 검색 시작 후 삽입

	for (iter = s.begin(); iter != s.end(); ++iter) // 10 30 40 50 70 80 85 90 출력
		cout << *iter << " ";
	cout << endl;

	return 0;
}
```

<br>

연관컨테이너의 기본 정렬 기준은 조건자 `less`을 사용합니다. 기본 정렬 기준은 템플릿 매개 변수를 사용해 바꿀 수 있습니다.

```cpp
#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int, greater<int>> s; // 정렬 기준으로 greater<int> 조건자 사용

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);

	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); ++iter) // 80 70 50 40 30 10 출력
		cout << *iter << " ";
	cout << endl;

	return 0;
}
```
<br>

set은 사용 중인 정렬 기준 조건자를 반환하는 멤버 함수 `key_comp()`와 `value_comp()`를 제공합니다.
이때 정렬 기준 형식은 typedef 내장 멤버 형식 `key_compare`와 `value_compare`로 제공합니다.

```cpp
#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int, less<int>> s_less;
	set<int, greater<int>> s_greater;

	s_less.insert(50);
	s_less.insert(30);
	s_less.insert(80);

	s_greater.insert(40);
	s_greater.insert(10);
	s_greater.insert(70);

	set<int, less<int>>::key_compare l_cmp = s_less.key_comp();
	cout << l_cmp(10, 20) << endl; // 10 < 20 연산 => 참

	set<int, greater<int>>::key_compare g_cmp = s_greater.key_comp();
	cout << g_cmp(10, 20) << endl; // 10 > 20 연산 => 거짓

	cout << "key_compare type: " << typeid(s_less.key_comp()).name() << endl;
	cout << "key_compare type: " << typeid(s_greater.key_comp()).name() << endl;

	cout << "value_compare type: " << typeid(s_less.value_comp()).name() << endl;
	cout << "value_compare type: " << typeid(s_greater.value_comp()).name() << endl;

	return 0;
}
```
```
출력결과

1
0
key_compare type: struct std::less<int>
key_compare type: struct std::greater<int>
value_compare type: struct std::less<int>
value_compare type: struct std::greater<int>
```

***🎈🎈연관 컨테이너는 모두 같은 인터페이스의 멤버 함수를 제공합니다. 이 연관 컨테이너의 핵심 인터페이스는 찾기 관련 멤버 함수입니다.***

찾기 관련 멤버 함수는 정렬 기준으로 트리의 루트 노드부터 자식 노드로 검색을 진행하므로 로그 시간 복잡도에 실행되며 `count()`, `find()`, `lower_bound()`, `upper_bound()`,
`equal_range()` 멤버 함수입니다.

원소의 중복을 허용하지 않는 set 컨테이너는 원소(key)와 일치하는 개수를 반환하는 `count()` 멤버 함수가 굳이 필요 없지만 연관 컨테이너의 인터페이스가 모두 같으므로
set도 `count()` 멤버 함수를 제공합니다.

---

## 🔥원소의 개수를 반환하는 `count()`
실행 시간은 로그 시간 복잡도입니다.

```cpp
#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(10);
	s.insert(20);

	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++) // 10 20 30 50 80 출력
		cout << *iter << " ";
	cout << endl;

	cout << "원소 50의 개수: " << s.count(50) << endl;    // 1 출력
	cout << "원소 100의 개수: " << s.count(100) << endl;  // 0 출력 

	return 0;
}
```

---

## 🔥원소를 검색하는 `find()`
`find()`는 연관 컨테이너의 핵심 멤버 함수이다.

`find()`는 key(원소)를 검색하여 key를 가리키는 반복자를 반환합니다.

만약 key(원소)가 없으면 끝 표시(past-the-end) 반복자를 반환합니다.

`end()` 멤버 함수가 끝 표시 반복자를 반환하므로 `end()` 멤버 함수와 비교해 검색이 성공했는지 성공하지 못했는지 판단합니다.

```cpp
#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(10);
	s.insert(20);

	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++) // 10 20 30 50 80 출
		cout << *iter << " ";
	cout << endl;

	iter = s.find(30);
	if (iter != s.end())
		cout << *iter << "가 s에 있습니다!" << endl;  // 30가 s에 있습니다! 출력 
	else
		cout << "30이 s에 없습니다!" << endl;

	return 0;
}
```

여기서 주의할 점이 있습니다. 연관 컨테이너의 찾기 관련 멤버 함수는 key(원소)를 찾을 때 `==`연산을 사용하지 않습니다.
연관 컨테이너는 정렬 기준에 의해 key(원소)가 정렬되어 있으므로 컨테이너의 정렬 기준 조건자를 이용해 찾기 연산을 수행합니다.

그니까 내부적으로 `find()`와 같이 연관 컨테이너의 찾기 관련 멤버 함수는 `==`연산으로 key를 찾는 것이 아니라, 컨테이너의 정렬 기준 조건자를 이용해 찾는다는 의미이다.

아래가 그 예시 코드이다.

```cpp
#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int, less<int>> s;

	// 30과 50의 비교
	cout << (!s.key_comp() (30, 50) && !s.key_comp()(50, 30)) << endl; // 0 출력

	// 30과 30의 비교
	cout << (!s.key_comp() (30, 30) && !s.key_comp()(30, 30)) << endl; // 1 출력

	return 0;
}
```

```cpp
(!s.key_comp() (30, 50) && !s.key_comp()(50, 30))
```
에서 `!s.key_comp() (30, 50)`은 `!(30 < 50)`으로 false 지만, `!s.key_comp()(50, 30)`은 `!(50 < 30)`은 true이므로 결국 false다. (false && true 이므로)

하지만

```cpp
(!s.key_comp() (30, 30) && !s.key_comp()(30, 30))
```
에서 `!s.key_comp() (30, 30)`은 true이고 `!s.key_comp()(30, 30))` 또한 true 이므로 true이다.

---

## 🔥set의 멤버함수 `lower_bound()`와 `upper_bound()`
`lower_bound()`는 찾은 원소의 시작 반복자를 반환하며 `upper_bound()`는 찾은 원소의 다음 원소를 가리키는 반복자를 반환한다.

그래서 찾은 원소는 구간 [ `lower_bound()`, `upper_bound()` ]로 표현할 수 있으며, `lower_bound()`와 `upper_bound()`가 같다면 찾는 원소가 없는 것이다.

사실 중복 원소를 갖지 않는 set에서 두 멤버 함수는 큰 의미가 있지 않지만, multiset이나 multimap에서는 유용하게 사용된다.

```cpp
#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int, less<int>> s;

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);
	s.insert(90);

	for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	set<int>::iterator iter_lower;
	set<int>::iterator iter_upper;

	iter_lower = s.lower_bound(30);
	iter_upper = s.upper_bound(30);
	cout << *iter_lower << endl;    // 30 출력
	cout << *iter_upper << endl;    // 40 출력

	iter_lower = s.lower_bound(999);
	iter_upper = s.upper_bound(999);
	if (iter_lower != iter_upper)
		cout << "999가 s에 있습니다!" << endl;  // <-- 이게 출력
	else
		cout << "999가 s에 없습니다!" << endl;

	return 0;
}
```

![image](https://github.com/SunFlower2819/Today-I-learned/assets/130738283/d117089b-c830-4981-b093-b57b61e7b49d)

---

## 🔥`lower_bound()`와 `upper_bound()`의 반복자 쌍을 pair 객체로 반환하는 `equal_range()`

`equal_range()`는 `lower_bound()`와 `upper_bound()`의 반복자 쌍을 pair 객체로 반환합니다.

```cpp
#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int, less<int>> s;

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);
	s.insert(90);

	for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	pair<set<int>::iterator, set<int>::iterator> iter_pair;

	iter_pair = s.equal_range(30);
	cout << *iter_pair.first << endl;    // 30 출력
	cout << *iter_pair.second << endl;    // 40 출력

	iter_pair = s.equal_range(999);
	if (*iter_pair.first != *iter_pair.second)
		cout << "999가 s에 있습니다!" << endl;
	else
		cout << "999가 s에 없습니다!" << endl;

	return 0;
}
```

# set의 주요 특징 정리
set은 대표적인 연관 컨테이너이자 노드 기반 컨테이너입니다. 연관 컨테이너는 특정 정렬 기준에 의해 원소가 자동 정렬되는 컨테이너 입니다.

또한, 원소 찾기(검색)를 로그 시간 복잡도에 수행할 수 있도록 균형 이진 트리로 구현되며 여러 찾기 관련 함수를 제공하는 것이 특징입니다. 

연관 컨테이너(set, multiset, map, multimap)는 모두 같은 인터페이스의 멤버 함수를 제공합니다.

![image](https://github.com/SunFlower2819/Today-I-learned/assets/130738283/3b310fdd-27d8-4618-9b01-156806611323)

<br>

set은 연관컨테이너이므로 컨테이너 앞, 뒤에 추가하거나 제거하는 멤버 함수류 `push_front()`, `pop_front()`, `push_back()`, `pop_back()` 멤버 함수를 제공하지 않습니다.
(🎈🎈사실 당연하다. 어처피 자동으로 정렬하기 때문에 저러한 기능도 필요가 없다. 앞에 넣든 뒤에서 넣든 원소가 자기 자리를 찾아가기 때문이다.)

***연관 컨테이너의 핵심은 빠른 원소 찾기이며 균형 이진 트리를 이용한 로그 시간 검색 복잡도를 보장합니다.***

원소를 저장하기 위해 사용되는 멤버 함수는 `insert()`가 유일합니다.

***set을 구성하는 원소는 삽입, 검색, 제거 등에 모두 이용된다. 따라서 set뿐만 아니라 모든 연관 컨테이너의 key는 변경할 수 없다.***

마지막으로 연관 컨테이너는 양방향 반복자를 지원하며 멤버 함수 `begin()`, `end()`, `rbegin()`, `rend()`는 순차열의 시작과 끝을 가리키는 반복자를 반환합니다. 
