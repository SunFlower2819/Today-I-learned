#include <iostream>
#include <string>
using namespace std;

int main()
{
	int index = 0;
	int sum = 0, number;
	int first = 0, last = 0;
	string str;

	cout << "7+23+5+100+25와 같이 덧셈 문자열을 입력하세요." << endl;
	getline(cin, str);

	while (str.find('+', index) != string::npos)
	{
		// index에 +앞의 인덱스를 저장한다. 그리고 last변수에 index를 저장한다.
		index = str.find('+', index) + 1;
		last = index;

		// substr()을 사용하여 first부터 last - 1 까지 문자열을 추출한다.
		// 그리고 추출한 문자열을 stoi()를 사용하여 정수로 변환한다.
		// 그리고 sum에 더한다.
		number = stoi(str.substr(first, last));
		cout << number << endl;
		sum = sum + number;

		// last값을 first변수에 넣어준다. 
		// 다음 숫자를 추출할 때, first부터 시작하기 때문이다.
		first = last;
	}
	
	// 남아있는 숫자를 추출해준다.
	number = stoi(str.substr(first, last));
	cout << number << endl;
	sum = sum + number;

	cout << "숫자들의 합은 ";
	cout << sum << endl;

	return 0;
}
