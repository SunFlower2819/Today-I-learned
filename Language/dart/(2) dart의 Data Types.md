### 🤞List

```dart
void main() {
  var addNumFive = true;
  
  List<int> int_numbers = [
    1,
    2,
    3,
    if(addNumFive) 5,  // 만약 addNumFive가 true면 리스트에 5를 추가해라 (Collection If)
  ];
  
  var double_numbers = [3.13, 13.13, 4.1];  // List<double> 타입
  
  print(int_numbers);      // [1,2,3,5] 출력
  print(double_numbers); 
}
```

### 🤞String Interpolation
```dart
void main() {
  String name = "선태욱";
  int age = 20;
  
  String s = "Hello my name is $name, and I'm ${age + 4} years old.";
  
  print(s); // Hello my name is 선태욱, and I'm 24 years old. 
}
```

### 🤞Collection For 
```dart
void main() {
  var newFriends = [
    '최재영', 
    '이민학', 
    '김효태'
    
  ];
  
  var myFriends = [
    '조세광', 
    '문경훈', 
    '김은찬',
    
    for (var friend in newFriends) "new!$friend" // 이 반복문의 문자열을 리스트에 추가
  ];
  
  print(myFriends);
}
```

### 🤞Maps

```
void main() {
  var school_num = {
    "선태욱": 2288065,
    "김효태": 2288053,
    "최재영": 1988032,
  };
  
  Map<int, String> desk_num = {
    1: "1번 테이블",
    2: "2번 테이블",
    3: "3번 테이블",
  };
  
  print(school_num);
  print(desk_num);
}
```

### 🤞Sets

요소가 하나씩 있어야 하면 `Set` 아니면 `List`

```
void main() {
  Set<int> unique_num = {1,2,3};
  unique_num.add(1);
  unique_num.add(1);   // 아무리 1을 추가해도 여전히 Set에는 1이 하나이다.
  unique_num.add(4);
  
  print(unique_num);  // {1, 2, 3, 4}
  
  List<int> just_num = [1,2,3];
  just_num.add(1);
  just_num.add(1);
  
  print(just_num);    // [1, 2, 3, 1, 1]  <-- 1이 두번 추가됨
}
``` 
