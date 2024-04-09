🎈🎈**vector는 앞쪽이 막혀 있는 형태로 앞쪽에는 원소를 추가/제거할 수 없으며 뒤쪽에만 추가/제거할 수 있습니다.**

다른 시퀀스컨테이너(list, deque)는 앞쪽에 원소를 추가/제거할 수 있는 `push_front()`와 `pop_front()`를 가집니다. 

---

## 🔥`vector<int>`의 자료형

```cpp
for (int i = 0; i < v.size(); i++)
    cout << v[i] << ' ';
```
위와 같이 코드를 짜면 컴파일러는 경고를 내보낸다. 그 이유는 `v.size()`가 반환하는 타입이 `unsigned int`이기 때문이다.

```cpp
cout << typeid(vector<int>::size_type).name() << endl;  // unsigned __int64 출력
```

따라서 아래와 같은 코드가 바람직하다.

```cpp
int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::size_type i = 0; i < v.size(); i++)
		cout << v[i] << ' ';

	return 0;
}
```
---

## 🔥`vector`의 크기를 반환하는 세 멤버 함수
vector의 크기를 반환하는 세 멤버 함수 `size()`, `capacity()`, `max_size()`를 갖습니다.

`size()`는 저장 원소의 개수이며, `capaicty()`는실제 할당된 메모리 공간의 크기, `max_size()`는 컨테이너에 담을 수 있는 최대 원소의 개수입니다.

아래의 코드를 보고 `size()`와 `capacity()`의 차이점을 이해해보자.

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
	
	for (vector<int>::size_type i = 0; i < v.size(); i++)  // 10 20 30 40 50 출력
		cout << v[i] << ' ';

	cout << endl;

	cout << v.size() << endl;       // 5 출력
	cout << v.capacity() << endl;   // 6 출력
	cout << v.max_size() << endl;   // 4611686018427387903 출력

	return 0;
}
```

`size()`와 `max_size()`는 모든 컨테이너가 가지는 멤버 함수이다. 하지만, `capacity()`는 유일하게 vector만 가지는 멤버 함수입니다.

vector는 배열 기반 컨테이너면서 원소를 컨테이너에 계속 추가(`push_back()` 등을 사용하여..)할 수 있는 컨테이너이다. 여기서는 배열 기반 컨테이너이므로
연속한 메모리를 한 번에 할당하지만, 계속 원소가 추가될 수 있게 해야 하므로 원소가 추가될 때마다 메모리가 자라나게 하려면 메모리를 재할당해야 합니다.

🎈🎈원소가 추가될 때마다 메모리를 재할당하고 이전 원소를 모두 복사해아 한다면 너무나 비효율적입니다. 이때 조금이나마 재할당에 드는 성능 문제를 보완하고자 만들어진 개념이
**capacity**입니다.

원소가 추가될 때마다 메모리를 재할당하지 않고 미리 넉넉한 메모리를 확보하면 재할당과 이전 원소를 복사하는 데 드는 비용을 줄일 수 있습니다.

이것이 컨테이너 중 vector만이 가지고 있는 중요한 특징입니다.

![image](https://github.com/SunFlower2819/Today-I-learned/assets/130738283/2503c0dd-53f3-437b-a24b-76d0e422e811)
사진출처: https://modoocode.com/223 


이처럼 vector는 `push_back()`을 이용해 원소를 계속 추가할 수 있지만, 메모리 재할당과 이전 원소 복사 문제가 발생할 수 있습니다.
그래서 vector는 미리 메모리를 할당할 수 있는 메모리 예약 함수 `reserve()`를 제공합니다.

`reserve()`를 사용하면 미리 메모리를 할당해 `capacity`를 결정하고 vector에 원소가 추가되더라도 메모리를 재할당하지 않습니다.

```cpp
int main()
{
	vector<int> v;

	v.reserve(5); // 메모리 예약 함수
	cout << "size: " << v.size() << " capaicty: " << v.capacity() << endl;
	v.push_back(10);
	cout << "size: " << v.size() << " capaicty: " << v.capacity() << endl;
	v.push_back(20);
	cout << "size: " << v.size() << " capaicty: " << v.capacity() << endl;
	v.push_back(30);
	cout << "size: " << v.size() << " capaicty: " << v.capacity() << endl;
	v.push_back(40);
	cout << "size: " << v.size() << " capaicty: " << v.capacity() << endl;
	v.push_back(50);
	cout << "size: " << v.size() << " capaicty: " << v.capacity() << endl;

	v.push_back(60);
	cout << "size: " << v.size() << " capaicty: " << v.capacity() << endl;   // <-- 🎈🎈이 부분에서는 메모리 재할당 발생 : 메모리 예약 범위를 넘어섰기 떄문


	cout << endl;
	for (vector<int>::size_type i = 0; i < v.size(); i++)
		cout << v[i] << ' ';

	return 0;
}
```
```
출력결과

size: 0 capaicty: 5
size: 1 capaicty: 5
size: 2 capaicty: 5
size: 3 capaicty: 5
size: 4 capaicty: 5
size: 5 capaicty: 5
size: 6 capaicty: 7

10 20 30 40 50 60
```

<br>
생성자를 사용하여 size를 미리 확보할 수 있습니다. 이때 원소의 값은 기본값(원소의 기본 생성자 호출 값)으로 초기화됩니다.

```cpp
vector<int> v1(5); // 0으로 초기화된 size가 5인 컨테이너
vector<int> v2(10,5); // 5로 초기화된 size가 10인 컨테이너
```

<br>
생성자뿐만 아니라 `resize()` 멤버 함수를 사용하여 컨테이너 size를 변경할 수 있습니다.

**🎈🎈주의할 점은 size를 키울 때 capacity도 늘어나지만, size를 줄일 때는 capacity가 줄지 않는다는 것입니다.**
```cpp
int main()
{
	vector<int> v(5);

	for (int i = 0; i < v.size(); i++)
		v[i] = i + 1;

	for (vector<int>::size_type i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << endl;
	cout << "size: " << v.size() << " capcity: " << v.capacity() << endl << endl;

	v.resize(10, 5);  // 7로 초기화된 size가 10인 컨테이너로 확장

	for (vector<int>::size_type i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << endl;
	cout << "size: " << v.size() << " capcity: " << v.capacity() << endl << endl;

	v.resize(3);  // 기본값 0으로 초기화된 size가 3인 컨테이너로 축소

	for (vector<int>::size_type i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << endl;
	cout << "size: " << v.size() << " capcity: " << v.capacity() << endl << endl;   // 🎈🎈capacity는 변화 없음

	return 0;
}
```
```
출력결과
1 2 3 4 5
size: 5 capcity: 5

1 2 3 4 5 7 7 7 7 7
size: 10 capcity: 10

1 2 3
size: 3 capcity: 10
```

<br>
또한 `v.clear()`를 사용해서 `v`를 비워도 `size`는 0이 되지만 `capacity`의 크기는 여전하다.

만약 메모리가 부족한 상태라면 너무 비효율적이다. `capacity`를 0으로 만드는 함수는 존재하지 않지만 C++에서 권장하는 `swap`방법이 있다.

---

## 🔥`swap`을 사용하여 capacity를 0으로 만드는 방법
임시 객체와 `swap`한 v는 당연하게도 `size`와 `capacity`가 0입니다.

```cpp
int main()
{
	vector<int> v(10);

	cout << "size: " << v.size();
	cout << " capacity: " << v.capacity() << endl;   // size: 10 capacity: 10 출력

	vector<int>().swap(v);

	cout << "size: " << v.size();
	cout << " capacity: " << v.capacity() << endl;   // size: 0 capacity: 0   출력

	return 0;
}
```

