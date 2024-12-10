#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N;
	std::cin >> N;

	// 정수를 입력받으라고 했기 떄문에 double이 아닌 int형을 써줘야 한다.
	std::vector<int> v(N);
	for (int& i : v)
		std::cin >> i;

	// vector의 요소 중 최댓값을 선별
	auto M = std::max_element(v.begin(), v.end());

	// 평균을 구하기 위해 변수에 vector의 모든 요소의 합을 구해준다.
	double totalAverage = 0;
	for (int k = 0; k < N; k++)
	{
		totalAverage += (double(v[k]) / (*M) * 100.0); // double로 형변환을 해야 나누기 연산에서 값을 잃지 않는다.
	}
	totalAverage /= N; // 평균 구해주기

	std::cout << totalAverage << std::endl;

	return 0;
}
