# 🔵STL을 한눈에

## 🟢컨테이너

컨테이너는 같은 타입을 저장, 관리할 목적으로 만들어진 클래스입니다. 컨테이너는 두 가지로 나눕니다.(총 7가지 컨테이너를 제공)

* 표준 시퀀스 컨테이너(standard sequence container): 컨테이너 원소가 자신만의 삽입 위치(순서)를 가지는 컨테이너(vector, deque, list: 선형적)
* 표준 연관 컨테이너(standard associative container): 저장 원소가 삽입 순서와 다르게 **특정 정렬 기준**에 의해 자동 정렬되는 컨테이너(set, multiset, map, multimap: 비선형적)

정리하면 삽입 순서로 정렬되는 컨테이너는 `vector`, `deque`, `list`으로 총 3가지가 있고, 
특정한 정렬 기준에 의해 자동으로 정렬되는 컨테이너는 `set`, `multiset`, `map`, `multimap`으로 총 4가지가 있다.

또한, 컨테이너는 데이터를 하나의 연속한 메모리 단위로 저장하느냐에 따라 두 가지로 나눕니다.

* 배열 기반 컨테이너(array-based container): 데이터 여러 개가 하나의 메모리 단위에 저장됩니다.(vector, deque)
* 노드 기반 컨테이너(node-based constainer): 데이터 하나를 하나의 메모리 단위에 저장합니다.(list, set, multiset, map, multimap)

**이런 컨테이너 종류는성능이나 메모리 사용, 지원 인터페이스(알고리즘, 멤버 함수) 등에 큰 차이를 보이며 컨테이너의 특징을 만들어 냅니다. 그래서 상당히 중요합니다.** 

---
아래는 `vector` 컨테이너를 사용한 예시 코드이다.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// int 타입(정수)을 저장하는 컨테이너 v를 생성합니다.
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (unsigned int i = 0; i < v.size(); i++)
		cout << v[i] << endl; // v[i]는 i번째 index의 정수 반환: operator[] 연산자로 저장 원소에 접근

	return 0;
}
```
