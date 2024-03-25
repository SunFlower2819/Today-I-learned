## 🟢반복자(Iterator)

반복자는 포인터와 비슷하게 동작합니다.
반복자는 컨테이너에 저장된 원소를 순회하고 접근하는 일반화된 방법을 제공합니다.

반복자는 컨테이너와 알고리즘이 하나로 동작하게 묶어주는 인터페이스 역할을 합니다.

이 반복자 덕에 알고리즘은 특정 컨테이너에 종속적이지 않고 독립적이면서도 언제든지 컨테이너와 결합하여 동작할 수 있습니다. (아.. 직 이해가 잘 안되는데..? 반복자의 존재 이유가 아직 잘 와닿지 않네) 

---

반복자는 다음과 같은 특징이 있습니다. 반복자의 특징은 포인터와 같습니다.

* 반복자는 컨테이너 내부의 원소(객체)를 가리키고 접근할 수 있어야 합니다. (*연산자 제공)
* 반복자는 다음 원소로 이동하고 컨테이너의 모든 원소르 순회할 수 있어야 합니다. (++연산자 제공, !=,== 비교 연산자 제공)

STL에서 컨테이너 원소(객체)의 집합을 순차열(sequence)라고 합니다. 순차열 개념은 원소의 순서 있는 집합을 의미합니다. 순차열은 하나의 시작과 하나의 끝을 갖습니다.
여기서 

🎈🎈**반복자는 순차열의 한 원소를 가리킵니다.**

STL의 모든 컨테이너는 자신만의 반복자를 제공합니다. 멤버 함수 `begin()`과 `end()`가 순차열의 시작과 끝을 가리키는 반복자를 반환합니다.

***주의할 점: 순차열의 시작과 끝에서 끝은 실제 원소가 아닌 끝을 표시하는(past-the-end)하는 원소입니다.***

![image](https://github.com/SunFlower2819/Today-I-learned/assets/130738283/eaffab30-4699-4842-8735-297086622ca2)

아래는 vector의 반복자를 사용하여 정수를 출력한 코드이다.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << endl;

	return 0;
}
```
🎈🎈착각하면 안되는게 포인터가 아니라 `*`연산자를 제공해줘서 포인터와 비슷하게 작동하는 거임

---

반복자는 다음과 같이 다섯 범주로 나뉩니다.
* 입력 반복자(Input iterator): 현 위치의 원소를 한 번만 읽을 수 있는 반복자
* 출력 반복자(output iterator): 현 위치의 원소를 한 번만 쓸 수 있는 반복자
* 순방향 반복자(forword iterator): 입력, 출력 반복자 기능에 순방향으로 이동(++)이 가능한 재할당될 수있는 반복자
* 양방향 반복자(bidirectional iterator): 순방향 반복자 기능에 역방향으로 이동(--)이 가능한 반복자 --> list, set, multiset, map, multimap
* 임의 접근 반복자(random access iterator): 양방향 반복자 기능에 +, -, +=, -=, [] 연산이 가능한 반복자 --> vector, deque

모든 컨테이너는 양방향 반복자 이상을 제공.

`vector`, `deque`는 임의 접근 반복자를 제공.

---

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter = v.begin(); // 시작 원소를 가리키는 반복자
	cout << iter[0] << endl;  // [] 연산
	cout << iter[1] << endl;
	cout << iter[2] << endl;
	cout << iter[3] << endl;
	cout << iter[4] << endl;
	cout << endl;

	iter += 2;  // += 연산
	cout << *iter << endl;
	cout << endl;

	vector<int>::iterator iter2 = iter + 2; // + 연산
	cout << *iter2 << endl;

	return 0;
}
```

아래는 vector 반복자 코드를 deque로만 바꾼 코드이다.

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main()
{
	deque<int> dq;

	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	dq.push_back(40);
	dq.push_back(50);

	deque<int>::iterator iter = dq.begin();
	cout << iter[0] << endl;
	cout << iter[1] << endl;
	cout << iter[2] << endl;
	cout << iter[3] << endl;
	cout << iter[4] << endl;
	cout << endl;

	iter += 2;
	cout << *iter << endl;
	cout << endl;

	deque<int>::iterator iter2 = iter + 2;
	cout << *iter2 << endl;

	return 0;
}
```
