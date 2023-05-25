### 🔵toString() 메소드, 객체를 문자열로 변환

Object에는 객체를 문자열로 변환하는 toString()이 있다.

```java
class Point
{
	private int xpos, ypos;
	public Point(int xpos, int ypos)
	{
		this.xpos = xpos;
		this.ypos = ypos;
	}
}

public class HelloToWorld       
{
 	public static void main(String[] args) 
	{              
 		Point p1 = new Point(3,5);
 		System.out.println(p1.toString()); // Hello.Point@5e91993f 출력
	} 
}
```

위의 코드 출력결과를 보면 
기본 toString 메소드는 ``클래스이름@16진수로_표시된_해시코드`` 형태의 문자열을 반환하는 것을 알 수 있다.

따라서 우리는 `toString()`메소드를 오버라이딩하여 사용해야 한다.

```java
class Point
{
	private int xpos, ypos;
	public Point(int xpos, int ypos)
	{
		this.xpos = xpos;
		this.ypos = ypos;
	}
	
	@Override
	public String toString()
	{
		return "xpos = " + xpos + ", ypos = " + ypos;
	}
}

public class HelloToWorld       
{
 	public static void main(String[] args) 
	{              
 		Point p1 = new Point(3,5);

 		System.out.println(p1.toString());  // xpos = 3, ypos = 5 출력
 		System.out.println(p1);             // xpos = 3, ypos = 5 출력
	} 
}
```
이렇게 되면 `Point`클래스의 객체 `p1`의 `toString()` 메소드는 우리가 정의해준 대로 실행된다.
