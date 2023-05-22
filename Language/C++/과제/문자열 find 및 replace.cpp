#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	string f;
	string r;
	int find_index = 0;

	cout << "여러 줄의 문자열을 입력하세요. 입력의 끝은 &문자입니다." << endl;
	getline(cin, str, '&');

	cout << '\n';

	// 버퍼 비워주기
	cin.ignore();

	// 찾고 싶은 문자열 입력
	cout << "find: ";
	getline(cin, f);

	// 치환하고 싶은 문자열 입력
	cout << "replace: ";
	getline(cin, r);

	// find_index에 찾은 값의 시작 인덱스를 저장. 못 찾으면 반복문 종료
	while ((find_index = str.find(f, find_index)) != string::npos)
	{
		// find_index부터 f.length()전 까지 r로 치환
		str.replace(find_index, f.length(), r);

		// 찾은 인덱스에 치환된 문자열의 길이를 더해줘서, 그 부분부터 다시 탐색
		find_index += r.length();
	}

	cout << str << endl;
	return 0;
}
