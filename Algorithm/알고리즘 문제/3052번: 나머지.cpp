#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	// vector에 값을 입력, 그 값을 42로 나눈 값을 벡터에 저장
	std::vector<int> v(10);
	for (int& i : v)
	{
		std::cin >> i;
		i = i % 42;
	}

	// 정렬
	sort(v.begin(), v.end());

	// compare은 정렬된 원소를 순차적으로 비교하다가 달라지는 지점을 나타내는 변수
	// count는 달라지는 지점을 세는 변수
	int count = 1;
	int compare = v[0];

	for (int i = 1; i < 10; i++)
	{
		if (compare != v[i])
		{
			count += 1;
			compare = v[i];
		}
	}

	std::cout << count << std::endl;

	return 0;
}
