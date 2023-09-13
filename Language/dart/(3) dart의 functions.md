### 🤞Defining a Function

```dart
String sayHello(var name) {
  return "Hello $name !!";
}

void main() {
  print(sayHello("선태욱"));
}
```

```dart
String sayHello(var name) => "Hello~~ $name !!";   // 한줄 짜리 함수는 이렇게 줄일 수 있음 

void main() {
  print(sayHello("선태욱"));
}
```

