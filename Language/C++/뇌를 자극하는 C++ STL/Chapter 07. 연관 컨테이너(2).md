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
