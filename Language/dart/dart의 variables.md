### 🤞var 키워드
`var`는 메소드나 작은 함수에서 사용되기를 권장된다.
`int`나 `double`같이 명시적으로 형식을 지정하는 건 class의 property에서 사용된다.

### 🤞Nullable variable (Null safety)
Null은 '아무것도 없는 상태'를 의미하기 떄문에 필요하다.
하지만 문제는 Null를 참조하려고 할 때 발생한다.
따라서 우리는 Nullable Variables이 필요하다.

dart에서 기본적으로 모든 변수에 null를 넣을 수 없는 걸로 보인다. 
만약 변수에 null를 넣어주고 싶다면 ?를 사용하여 null를 대입이 가능하도록 따로 선언을 해줘야 하는 것이다.

```dart
void main(){
  String? name = '니꼴라';
  name = null;
  
  print(name?.length);   // name이 널이 아니라면, length 값 가져오기
  
  if(name != null) {
    print(name.length);
  }
}
```

### 🤞late 키워드
late 키워드는 변수를 선언 후에 flutter의 API를 가져온 후 변수에 값을 선언하도록 도와준다. 그리고 만약 그 변수에 값을 넣어주지 않은 상태로 그 변수를 사용하려고 한다면 에러를 발생시킨다. (클래스가 해당)

분명한 목적은 '나는 이 변수를 일단 선언만 하고 반드시 나중에 초기화를 시킬 거야' 라고 명시적으로 알리는 것이라는 생각이 든다.

```dart
void main() {
  late final String name;     //   <-- 이렇게 final 키워드와 같이 쓰이는 듯.
  // do somthing, go to api
  
  name = 'nico';  
  print(name);
}
```

### 🤞const 키워드
dart에서 const는 compile-time constant를 만들어준다.
const는 컴파일할 때 알고 있는 값을 사용해야 한다.
만약 어떤 값인지 모르고, 그 값이 API로부터 오거나 사용자가 화면에서 입력해야 하는 값이라면 그건 const가 아닌 final이나 var가 되어야 한다.

```dart
void main() {
  const name = "tom"; // 컴파일 시점에 바뀌지 않는 값
  final username = fetchAPI(); // 컴파일 시점에 바뀌는 값
}
```
const: 컴파일 시점에 바뀌지 않는 값 (상수)
final: 컴파일 시점에 바뀌는 값 (API에서 받아온 값, 사용자 입력값)

+ 추가로 late 키워드와 const 키워드는 같이 사용될 수 없다.
왜냐하면 const 키워드는 선언과 동시에 값을 할당해줘야 하기 떄문이다.
