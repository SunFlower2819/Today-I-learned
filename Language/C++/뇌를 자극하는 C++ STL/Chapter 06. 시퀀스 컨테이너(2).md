🎈🎈**vector는 앞쪽이 막혀 있는 형태로 앞쪽에는 원소를 추가/제거할 수 없으며 뒤쪽에만 추가/제거할 수 있습니다.**

다른 시퀀스컨테이너(list, deque)는 앞쪽에 원소를 추가/제거할 수 있는 `push_front()`와 `pop_front()`를 가집니다. 

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
