#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	char alpha[26]{ 0, };

	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		alpha[s[i] - 'a'] += 1;   // 문자열의 원소 - 'a' = 알파벳 배열의 인덱스
	}

	for (const int& i : alpha)
		cout << i << ' ';

	return 0;
}
