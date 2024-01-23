![image](https://github.com/SunFlower2819/Today-I-learned/assets/130738283/226da234-717c-40fb-b181-21adf1fd60af)


`#include <GL/glew.h>`  에서 에러 발생

---

### OpenGL이란?
우선 위의 에러를 이해하기 위해서는 **OpenGL (Open Graphics Library)** 이 뭔지 이해해야 한다.

 **OpenGL**은**그래픽 하드웨어(GPU)와 통신할 수 있도록 지원해주는 API 또는 표준 규격**을 뜻한다. 그리고
 **GPU를 이용한 하드웨어 가속화**를 통해 렌더링을 해서 **2D, 3D 벡터 그래픽을 표현**할 수 있게 해준다.

 여기서 **하드웨어 가속**은 어떤 작업을 CPU가 처리하는 것이 아닌 **해당 작업에 최적화된 다른 하드웨어(그래픽 카드나 사운드 카드 등)에게 작업을 전송**하여 해당 하드웨어가 **CPU 보다 더 빠르게 고품질의 작업을 처리하는 것**을 뜻한다.

결론은 아래와 같다.

* **OpenGL이란 GPU와 통신할 수 있도록 지원해주는 API 또는 표준 규격이다.** 
* **하드웨어 가속이란 특정 작업을 CPU가 아닌 해당 작업에 최적화된 다른 하드웨어(GPU 등)에게 작업을 처리하게 하는 것을 뜻한다.**

출처: https://medium.com/@su_bak/opengl-%EC%9D%B4%EB%9E%80-ad19cf68c948

이제 GLEW가 무엇인지 알아보자

---

### GLEW란?

**GLEW**는 **The OpenGL Extension Wrangler Library**의 준말로, 크로스 플랫폼 오픈소스 C/C++ 확장 라이브러리입니다.  **GLEW**는 **OpenGL**의 새로운 기능을 제공하는 하나의 헤더파일입니다. **OpenGL**에서 기본적으로 제공하지 않는 기능들을 제공하기 때문에 모든 컴퓨터에서 잘 작동한다는 보장은 없지만 상당히 유용한 기능들을 제공한다.

**OpenGL**은 하나의 라이브러리가 아니기 때문에 프로젝트에 간단하게 연결할수가 없습니다. 그래서 **GLEW** 같은 라이브러리의 도움을 받습니다. **glew.h**와 같은 헤더파일만 include 하면 **OpenGL의 기능**들을 쉽게 사용할 수 있게 된다.

출처: https://justdoitproject.tistory.com/15 [JUST DO IT PROJECT:티스토리]

---

### vcpkg란?

위의 라이브러리를 내가 손수 추가하기에는 번거롭다. 이를 해결해주는 것이 있는데, 바로 **vcpkg**이다. 
**vckpg**는 Windows, linux와 MacOs 에서 C와 C++ 라이브러리 관리를 도와준다.

또한, vcpkg를 비주얼 스튜디오와 연동하면, 헤더 파일만 포함시켜도 라이브러리가 자동으로 링크된다.

이를 설치하는 과정은 https://github.com/microsoft/vcpkg/blob/master/README_ko_KR.md 에 있다.
