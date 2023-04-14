struct movieItems
{
	char name[100];
	double rate;
};

struct movieItems Movies[100]; // Movies[0].name : Sector 7, Movies[0].rate : 4.6
int itemsCount; // 텍스트 파일에 입력되어 있는 영화의 수

void PrintAllItems(); // 모든 영화를 출력해주는 함수
void PrintAnItem(); // 영화 하나 골라서 출력
void EditAnItem(); // 원하는 영화 하나 수정
void AddAnItem(); // 원하는 영화 하나 추가
void InsertAnItem(); // 영화를 추가하는데 그 위치를 내가 지정할 수 있음. 그러면 차례 또한 밀림.
void DeleteAnItem(); // 영화 하나를 삭제, 그리고 그 위치를 땡겨서 매꿔줌.
void DeleteAllItem(); // 모든 영화 삭제
void SaveFile(); // 파일에 지금의 기록을 저장
void SearchByName(); // 영화 제목으로 검색
