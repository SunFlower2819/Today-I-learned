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
