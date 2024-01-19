#include <iostream>

int main()
{
	int N, M; // 1~N개의 바구니에 M번 공을 넣는다.
	int i, j, k; // i부터 j번째 바구니에 k번호의 공을 넣는다.

	std::cin >> N >> M;

	int* bucket = new int[N + 1] {0};  // 0번 인덱스 바구니는 비워둬야함. 따라서 N+1을 통해 N개의 바구니를 동적할당

	for (int g = 0; g < M; g++)
	{
		std::cin >> i >> j >> k;
		
		for (int f = i; f <= j; f++)
		{
			bucket[f] = k;
		}
	}

	for (int i = 1; i <= N; i++)
		std::cout << bucket[i] << ' ';

	delete[] bucket;

	return 0;
}
