## 🔥deque의 특징
deque는 vector와 매우 유사한 컨테이너입니다. deque는 시퀀스 컨테이너이며 배열 기반 컨테이너입니다.

deque가 vector와 다른 점은 메모리 블록 할당 정책입니다. vector의 장점이자 단점인 하나의 메모리 블록 할당 정책은 배열처럼 정수 연산만으로 원소에 접근하고 빠르게 값을 읽고 쓸 수 있습니다.
하지만 새로운 원소가 추가될 때 ***메모리 재할당***과 ***이전 원소 복사 문제***가 발생하여 성능이 저하될 수 있습니다.

***deque는 이처럼 vector의 단점을 해결하기 위해 여러 개의 메모리 블록을 할당하고 사용자에게는 하나의 블록처럼 보이게 하는 정책을 사용합니다.***

***원소의 추가시 메모리가 부족할때마다 일정한 크기의 새로운 메모리 블록을 할당하여 이전 메모리를 제거하거나 이전 원소를 복사하는 등의 연산을 수행하지 않습니다.***

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main()
{
	deque<int> dq;

	for (int i = 0; i < 10; i++)
		dq.push_back((i + 1) * 10);

	for (deque<int>::size_type i = 0; i < dq.size(); i++) // 10 20 30 40 50 60 70 80 90 100 출력
		cout << dq[i] << " ";
	cout << endl;

	return 0;
}
```


![image](https://github.com/SunFlower2819/Today-I-learned/assets/130738283/acdddb93-4a45-41d3-b8bd-485463ad81d2)

출력결과나 사용 인터페이스 모두 vector와 같다. 배열 기반 컨테이너이므로 `[]`연산자도 제공합니다. vector와 다른 점은 위처럼 ***메모리 할당 정책***입니다.

---

## 🔥deque의 `push_front()`
원소를 앞쪽에 추가하면 새로운 메모리 블록을 할당하고 원소를 저장해 갑니다.

```cpp
int main()
{
	deque<int> dq;

	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	dq.push_back(40);
	dq.push_back(50);

	for (deque<int>::size_type i = 0; i < dq.size(); i++) // 10 20 30 40 50 출력
		cout << dq[i] << " ";
	cout << endl;

	dq.push_front(200); // 앞쪽에 추가
	dq.push_front(100);

	for (deque<int>::size_type i = 0; i < dq.size(); i++) // 100 200 10 20 30 40 50 출력
		cout << dq[i] << " ";

	return 0;
}
```

---

## 🔥deque는 임의 접근 반복자를 지원한다.
STL 컨테이너 중 deque와 vector는 배열 기반 컨테이너로서 임의 접근 반복자를 지원합니다. 노드 기반 컨테이너인 나머지 컨테이너 list, set, multiset, map, multimap은 양방향 반복자를 지원합니다. 

🎈🎈사실 deque와 vector는 메모리 할당 정책과 deque는 앞쪽에서 데이터를 넣고 뺄수 있다는 것을 빼면 다 같다고 봐도 무방해보인다. 

```cpp
int main()
{
	deque<int> dq;

	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	dq.push_back(40);
	dq.push_back(50);

	deque<int>::iterator iter;

	for (iter = dq.begin(); iter != dq.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	// 임의 접근 반복자가 지원하는 연산을 수행
	iter = dq.begin() + 2;  // 반복자에 dq.begin()+2
	cout << *iter << endl;

	iter += 2;              // 반복자에 +2
	cout << *iter << endl;

	iter -= 3;              // 반복자에 -3
	cout << *iter << endl;
		
	return 0;
}
```

---

## 🔥deque의 `insert()`
아래 코드를 보면 `iter`가 가리키는 위치보다 삽입할 원소(500)가 앞쪽에 삽입됩니다.

삽입(insert), 제거(erase) 동작은 vector와 같습니다.

***🎈🎈차이점은 vector보다 효율적으로 동작한다는 사실입니다.***

dq에 500을 삽입하면 앞쪽 원소의 개수가 적기 때문에 앞쪽으로 밀어내며 삽입됩니다.

```cpp
int main()
{
	deque<int> dq;

	for (int i = 0; i < 10; i++)
		dq.push_back((i + 1) * 10);
	
	deque<int>::iterator iter;
	deque<int>::iterator iter2;
	for (iter = dq.begin(); iter != dq.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	iter = dq.begin() + 2;  // 반복자에 dq.begin()+2
	iter2 = dq.insert(iter, 500);
	cout << *iter2 << endl;

	for (iter = dq.begin(); iter != dq.end(); iter++)
		cout << *iter << " ";

	return 0;
}
```
![image](https://github.com/SunFlower2819/Today-I-learned/assets/130738283/6b486d52-882d-4444-8c43-fcacc2cc026b)

🎈🎈***사실 이건 내부 기술적인걸 떠나서, `iter`가 가리키는 앞쪽으로 값(500)이 `insert`가 된다는 건 vector랑 똑같음.***

---

## 🔥deque의 주요 특징 정리
deque는 시퀀스 컨테이너이며 배열 기반 컨테이너입니다. 그래서 vector와 유사한 특징을 가지며 임의 접근 반복자를 지원합니다. 

🎈🎈***vector와 다른 점은 원소가 메모리 블록에 연속하게 저장되지만 하나의 메모리 블록이 아닌 여러 메모리 블록에 나뉘어 저장된다는 것입니다.***  

그렇다 보니 deque는 원소를 앞쪽과 뒤쪽에 모두 추가할 수 있으며 배열 기반 컨테이너의 특징을 가지면서도 vector보다 조금 더 효율적으로 동작합니다.

deque가 시퀀스 기반 컨테이너이므로 `insert()`나 `erase()` 멤버 함수가 호출되면 삽입, 제거될 위치부터 모든 원소를 밀어내야 합니다. 상당히 비효율적으로 동작하지만
vector보다는 조금 더 효율적으로 동작합니다. vector는 모든 원소를 뒤쪽으로만 밀어낼 수 있지만 deque는 뒤쪽이나 앞쪽으로 밀어낼 수 있기 때문입니다.
