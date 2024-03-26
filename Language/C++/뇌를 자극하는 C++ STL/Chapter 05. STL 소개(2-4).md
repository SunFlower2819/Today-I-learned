# 🔵어댑터

```
어댑터(영어: adapter, adaptor)는 다른 전기나 기계 장치를 서로 연결해서 작동할 수 있도록 만들어 주는 결합 도구다.
```

어댑터는 구성 요소의 인터페이스를 변경합니다. ==> 무슨 말인가 싶지? 

STL의 어댑터로는 컨테이너 어댑터, 반복자 어댑터, 함수 어댑터가 있습니다.
* 컨테이너 어댑터(container adaptor): `stack, queue, priority_queue`
* 반복자 어댑터(iterator adaptor): `reverse_adaptor, back_insert_iterator, front_insert_iterator, insert_iterator`
* 함수 어댑터(function adaptor): `바인더(binder), 부정자(negator), 함수 포인터 어댑터(adaptor for pointers to functions)`

대표적인 컨테이너 어댑터가 `stack`입니다. `stack`컨테이너 어댑터는 일반 컨테이너를 LIFO 방식의 스택 컨테이너로 변환합니다.  <== 구성 요소의 인터페이스를 변경한다는 말이 이런 말.

`empty`, `size`, `push_back`, `pop_back`, `back` 인터페이스(멤버함수)를 지원하는 컨테이너는 모두 stack 컨테이너 어댑터를 사용하여 LIFO 방식의 스택으로 변환할 수 있습니다.

stack 컨테이너 어댑터의 디폴트 컨테이너는 deque 컨테이너입니다.

---

대표적인 반복자 어댑터가 `reverse_iterator`입니다. `reverse_iterator`는 일반 반복자의 동작 방식을 반대로 동작시키는 역방향 반복자(reverse iterator)로 변환합니다.

대표적인 함수 어댑터가 부정자 `not2`입니다. `not2`는 조건자 함수 객체(이항)를 NOT(반대)로 변환합니다.(조건자는 bool 타입을 반환하는 함수류입니다.)


아래 코드는 stack 컨테이너를 이용한 코드이다.
```cpp
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> st;  // 디폴트 컨테이너 deque

	st.push(10);
	st.push(20);
	st.push(30);

	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	st.pop();

	if (st.empty()) // 스택이 비었는지 확인
		cout << "stack에 데이터 없음" << endl;

	return 0;
}
```
아래는 stack 컨테이너 어댑터의 컨테이너로 vector를 적용한 코드이다. 위와 다른건 컨테이너를 deque가 아닌 vector를 사용했다는 것뿐
```cpp
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	stack<int, vector<int>> st;  // vector 컨테이너를 이용한 stack 컨테이너 생성

	st.push(10);
	st.push(20);
	st.push(30);

	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	st.pop();

	if (st.empty()) // 스택이 비었는지 확인
		cout << "stack에 데이터 없음" << endl;

	return 0;
}
```

---

반복자 어댑터 `reverse_iterator`를 이용해 정방향 반복자를 역방향 반복자로 변환해보겠습니다.

아래는 반복자 어댑터 `reverse_iterator`를 이용해 `vector`의 반복자를 역방향 반복자로 변경한 코드이다.

```cpp
#include <iostream>
#include <stack>
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

	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	// 일반 반복자 iterator를 역방향 반복자 reverse_iterator로 변환
	reverse_iterator<vector<int>::iterator> rither(v.end());        // <-- ✅동작 원리 아래에 설명
	reverse_iterator<vector<int>::iterator> end_rither(v.begin());

	for (; rither != end_rither; rither++)
		cout << *rither << " ";

	return 0;
}
```

✅`reverse_iterator<vector<int>::iterator> rither(v.end());` 이 문장은 `rither`가 `v.end()`로 부터 한칸 뒤를 가리키도록 하는 의미이다.
마찬가지로 `reverse_iterator<vector<int>::iterator> end_rither(v.begin());` 이 문장은 `end_rither`가 `v.begin()`의 한칸 뒤를 가리키도록 한다.

![image](https://github.com/SunFlower2819/Today-I-learned/assets/130738283/2e556341-dab7-49e9-be57-0a9afdac45f0)

---

마지막으로 대표적인 함수 어댑터 `not2`의 동작을 보자.

`not2`는 조건자 함수 객체를 반대 의미의 조건자 함수 객체로 변경하는 어댑터입니다.

이항 조건자 `less`를 NOT 시키는 아래 코드를 보자.

```cpp
#include <iostream>
#include <functional>
using namespace std;

int main()
{
	cout << less<int>()(10, 20) << endl;
	cout << less<int>()(20, 20) << endl;
	cout << less<int>()(20, 10) << endl;
	cout << "==============================" << endl;
	cout << not2(less<int>())(10, 20) << endl;
	cout << not2(less<int>())(20, 20) << endl;
	cout << not2(less<int>())(20, 10) << endl;

	cout << endl;

	less<int> le;
	cout << le(10, 20) << endl;
	cout << le(20, 20) << endl;
	cout << le(20, 10) << endl;
	cout << "==============================" << endl;
	cout << not2(le)(10, 20) << endl;
	cout << not2(le)(20, 20) << endl;
	cout << not2(le)(20, 10) << endl;

	return 0;
}
```

```
출력결과

1
0
0
==============================
0
1
1

1
0
0
==============================
0
1
1
```
