# multimap 컨테이너
map 컨테이너에 중복 원소(key)를 허용해야 한다면 multimap 컨테이너를 사용합니다.

map은 key를 중복해서 컨테이너에 저장할 수 없지만 multimap은 여러 key를 중복해서 저장할 수 있습니다.

이것이 map과 유일한 차이점입니다.

multimap은 map과 같은 인터페이스, 템플릿 형식, 내장 멤버 형식을 제공한다. 

***중복 key를 허용하는 multimap은 `[]`연산자를 제공하지 않습니다.***

## 🔥multimap의 `count()`와 `find()`
```cpp
#include <iostream>
#include <map>
using namespace std;

int main()
{
	multimap<int, int> mm;

	mm.insert(pair<int, int>(5, 100));
	mm.insert(pair<int, int>(3, 100));
	mm.insert(pair<int, int>(8, 30));
	mm.insert(pair<int, int>(3, 40));
	mm.insert(pair<int, int>(1, 70));
	mm.insert(pair<int, int>(7, 100));
	mm.insert(pair<int, int>(8, 50));

	multimap<int, int>::iterator iter;
	for (iter = mm.begin(); iter != mm.end(); ++iter)
		cout << "(" << iter->first << ", " << iter->second << ") ";
	cout << endl;

	cout << "key 3의 원소의 개수는 " << mm.count(3) << endl; // 2

	iter = mm.find(3);   // find()는 multimap에 저장된 key가 3인 첫번째 원소의 위치를 반환, 없으면 끝 위치 반환 
	if (iter != mm.end())
		cout << "첫 번째 key 3에 매핑된 value: " << iter->second << endl; // 100

	return 0;
}
```

```
실행결과

(1, 70) (3, 100) (3, 40) (5, 100) (7, 100) (8, 30) (8, 50)
key 3의 원소의 개수는 2
첫 번째 key 3에 매핑된 value: 100
```


## 🔥multimap의 `lower_bound()`, `upper_bound()`, `equal_range()`
```cpp
#include <iostream>
#include <map>
using namespace std;

int main()
{
	multimap<int, int> mm;

	mm.insert(pair<int, int>(5, 100));
	mm.insert(pair<int, int>(3, 100));
	mm.insert(pair<int, int>(8, 30));
	mm.insert(pair<int, int>(3, 40));
	mm.insert(pair<int, int>(1, 70));
	mm.insert(pair<int, int>(7, 100));
	mm.insert(pair<int, int>(8, 50));     // (1, 70) (3, 100) (3, 40) (5, 100) (7, 100) (8, 30) (8, 50) 순으로 정렬

	multimap<int, int>::iterator lower_iter;
	multimap<int, int>::iterator upper_iter;

	lower_iter = mm.lower_bound(3); // (3,100) 위치 가리킴
	upper_iter = mm.upper_bound(3); // (5, 100) 위치 가리킴

	cout << "구간 [lower_iter, upper_iter)의 순차열: ";
	multimap<int, int>::iterator iter;
	for (iter = lower_iter; iter != upper_iter; ++iter)
		cout << "(" << iter->first << ", " << iter->second << ") ";
	cout << endl;

	pair<multimap<int, int>::iterator, multimap<int, int>::iterator> iter_pair;
	iter_pair = mm.equal_range(3);

	cout << "구간 [iter_pair.first, iter_pair.second)의 순차열: ";
	for (iter = iter_pair.first; iter != iter_pair.second; ++iter)
		cout << "(" << iter->first << ", " << iter->second << ") ";
	cout << endl;

	return 0;
}
```

```
실행결과

구간 [lower_iter, upper_iter)의 순차열: (3, 100) (3, 40)
구간 [iter_pair.first, iter_pair.second)의 순차열: (3, 100) (3, 40)
```
![KakaoTalk_20240430_184950666](https://github.com/SunFlower2819/Today-I-learned/assets/130738283/c8fa8e74-a033-4b0d-9b46-21452072e52e)


<br>

multimap은 중복 원소(key)를 허용한다는 것 외에 map과 특징이 같다.
