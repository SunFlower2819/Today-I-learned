# 🔵vector 컨테이너

## 🟢vector의 주요 인터페이스와 특징

<table>
  <tr>
    <td colspan="2"><b>생성자</b></td>
  </tr>
  <tr>
    <td>vector v</td>
    <td>v는 빈 컨테이너이다.</td>
  </tr>
  <tr>
    <td>vector v(n)</td>
    <td>v는 기본값으로 초기화된 n개의 원소를 갖는다.</td>
  </tr>
  <tr>
    <td>vector v(n,x)</td>
    <td>v는 x값으로 초기화된 n개의 원소를 갖는다.</td>
  </tr>
  <tr>
    <td>vector v(v2)</td>
    <td>v는 v2 컨테이너의 복사본이다(복사 생성자 호출).</td>
  </tr>
  <tr>
    <td>vector v(b,e)</td>
    <td>v는 반복자 구간 [b,e)로 초기화된 원소를 갖는다.</td>
  </tr>
</table>
<table>
  <tr>
    <td colspan="2"><b>멤버 함수</b></td>
  </tr>
  <tr>
    <td>v.assign(n,x)</td>
    <td>v에 x값으로 n개의 원소를 할당한다.</td>
  </tr>
  <tr>
    <td>v.assign(b,e)</td>
    <td>v를 반복자 구간 [b,e)로 할당한다.</td>
  </tr>
  <tr>
    <td>v.at(i)</td>
    <td>v의 i번째 원소를 참조한다(const, 비 const 버전이 있으며 범위 점검을 포함).</td>
  </tr>
  <tr>
    <td>v.back()</td>
    <td>v의 마지막 원소를 참조한다(const, 비 const 버전이 있음).</td>
  </tr>
  <tr>
    <td>x=v.capacity()</td>
    <td>x는 v에 할당된 공간의 크기</td>
  </tr>
  <tr>
    <td>v.clear</td>
    <td>v의 모든 원소를 제거한다.</td>
  </tr>
</table>
