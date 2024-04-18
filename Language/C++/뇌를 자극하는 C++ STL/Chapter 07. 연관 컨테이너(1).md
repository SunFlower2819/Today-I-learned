# set 컨테이너
set 컨테이너는 연관 컨테이너 중 단순한 컨테이너로 key라 불리는 원소(value)의 집합으로 이뤄진 컨테이너입니다.
모든 연관 컨테이너는 노드 기반 컨테이너이며 균형 이진 트리로 구현되므로 균형 이진 트리의 모든 특징을 가집니다.

> 균형 이진 트리?

## 🔥set 주요 인터페이스와 특징

시퀀스 컨테이너와 달리 모든 연관 컨테이너(set, multiset, map, multimap)는 같은 인터페이스(생성자, 멤버 함수, 연산자)를 제공한다.

<table>
  <tr>
    <td colspan="2"><b>생성자</b></td>
  </tr>
  <tr>
    <td>set s</td>
    <td>s는 빈 컨테이너다.</td>
  </tr>
  <tr>
    <td>set s(pred)</td>
    <td>s는 빈 컨테이너로 정렬 기준은 pred 조건자를 사용한다.</td>
  </tr>
  <tr>
    <td>set s(s2)</td>
    <td>s는 s2 컨테이너의 복사본이다(복사 생성자 호출).</td>
  </tr>
  <tr>
    <td>set s(b,e)</td>
    <td>s는 반복자 구간 [b,e)로 초기화된 원소를 갖는다.</td>
  </tr>
  <tr>
    <td>set s(b,e,pred)</td>
    <td>s는 반복자 구간 [b,e)로 초기화된 원소를 갖는다. 정렬 기준은 pred 조건자를 사용한다.</td>
  </tr>
</table>

<table>
  <tr>
    <td colspan="2"><b>멤버 함수</b></td>
  </tr>
  <tr>
    <td>p=s.begin()</td>
    <td>p는 s의 첫 원소를 가리키는 반복자다(const, 비 const 버전이 있음).</td>
  </tr>
  <tr>
    <td>s.clear()</td>
    <td>s의 모든 원소를 제거한다.</td>
  </tr>
  <tr>
    <td>n=s.count(k)</td>
    <td>원소 k의 개수를 반환한다.</td>
  </tr>
  <tr>
    <td>s.empty()</td>
    <td>s가 비었는지 조사한다.</td>
  </tr>
  <tr>
    <td>p=s.end()</td>
    <td>p는 s의 끝을 표식하는 반복자다(const, 비 const 버전이 있음).</td>
  </tr>
  <tr>
    <td>pr=s.equal_range(k)</td>
    <td>pr은 k원소의 반복자 구간인 pair 객체다(const, 비 const 버전이 있음).</td>
  </tr>
  <tr>
    <td>q=s.erase(p)</td>
    <td>p가 가리키는 원소를 제거한다. q는 다음 원소를 가리킨다.</td>
  </tr>
  <tr>
    <td>q=s.erase(b,e)</td>
    <td>반복자 구간 [b,e)의 모든 원소를 제거한다. q는 다음 원소다.</td>
  </tr>
  <tr>
    <td>n=s.erase(k)</td>
    <td>k원소를 모두 제거한다. n은 제거한 개수다.</td>
  </tr>
  <tr>
    <td>p=s.find(k)</td>
    <td>p는 k원소의 위치를 가리키는 반복자다(const, 비 const 버전이 있음).</td>
  </tr>
  <tr>
    <td>pr=s.insert(k)</td>
    <td>s컨테이너에 k를 삽입한다. pr은 삽입한 원소를 가리키는반복자와 성공 여부의 bool 값인 pair 객체다.</td>
  </tr>
  <tr>
    <td>q=s.insert(p,k)</td>
    <td>p가 가리키는 위치부터 빠르게 k를 삽입한다. q는 삽입한 원소를 가리키는 반복자다.</td>
  </tr>
  <tr>
    <td>s.insert(b,e)</td>
    <td>반복자 구간 [b,e)의 원소를 삽입한다.</td>
  </tr>
  <tr>
    <td>pred=s.key_comp()</td>
    <td>pred는 s의 key 정렬 기준인 조건자다(key_compare 타입).</td>
  </tr>
  <tr>
    <td>p=s.lower_bound(k)</td>
    <td>p는 k의 시작 구간을 가리키는 반복자다(const, 비 const 버전이 있음).</td>
  </tr>
  <tr>
    <td>n=s.max_size()</td>
    <td>n은 s가 담을 수 있는 최대 원소의 개수다(메모리의 크기).</td>
  </tr>
  <tr>
    <td>p=s.rbegin()</td>
    <td>p는 s의 역 순차열의 첫 원소를 가리키는 반복자다.(const, 비 const 버전이 있음).</td>
  </tr>
  <tr>
    <td>p=s.rend()</td>
    <td>p는 s의 역 순차열의 끝을 표식하는 반복자다(const, 비 const 버전이 있음).</td>
  </tr>
  <tr>
    <td>s.size()</td>
    <td>s의 원소의 개수다.</td>
  </tr>
  <tr>
    <td>s.swap(s2)</td>
    <td>s와 s2를 swap한다. </td>
  </tr>
  <tr>
    <td>p=s.upper_bound(k)</td>
    <td>p는 k의 끝 구간을 가리키는 반복자다(const, 비 const 버전이 있음).</td>
  </tr>
  <tr>
    <td>pred=s.value_comp()</td>
    <td>pred는 s의 value 정렬 기준인 조건자다(value_compare 타입).</td>
  </tr>
</table>

<table>
  <tr>
    <td colspan="2"><b>연산자</b></td>
  </tr>
  <tr>
    <td>s1 == s2</td>
    <td>s1과 s2의 모든 원소가 같은가?(bool 형식)</td>
  </tr>
  <tr>
    <td>s1 != s2</td>
    <td>s1과 s2의 모든 원소 중 하나라도 다른 원소가 있는가?(bool 형식)</td>
  </tr>
  <tr>
    <td>s1 < s2</td>
    <td>문자열 비교처럼 s2가 s1보다 큰가?(bool 형식)</td>
  </tr>
  <tr>
    <td>s1 <= s2</td>
    <td>문자열 비교처럼 s2가 s1보다 크거나 같은가?(bool 형식)</td>
  </tr>
  <tr>
    <td>s1 > s2</td>
    <td>문자열 비교처럼 s2가 s1보다 작은가?(bool 형식)</td>
  </tr>
  <tr>
    <td>s1 >= s2</td>
    <td>문자열 비교처럼 s2가 s1보다 작거나 같은가?(bool 형식)</td>
  </tr>
</table>

<table>
  <tr>
    <td colspan="2"><b>멤버 형식</b></td>
  </tr>
  <tr>
    <td>allocator_type</td>
    <td>메모리 관리자 형식</td>
  </tr>
  <tr>
    <td>const_iterator</td>
    <td>const 반복자 형식</td>
  </tr>
  <tr>
    <td>const_pointer</td>
    <td>const value_type* 형식</td>
  </tr>
  <tr>
    <td>const_reference</td>
    <td>const value_type& 형식</td>
  </tr>
  <tr>
    <td>const_reverse_iterator</td>
    <td>const 역 반복자 형식</td>
  </tr>
  <tr>
    <td>difference_type</td>
    <td>두 반복자 차이의 형식</td>
  </tr>
  <tr>
    <td>iterator</td>
    <td>반복자 형식</td>
  </tr>
  <tr>
    <td>key_compare</td>
    <td>키(key) 조건자(비교) 형식(set은 key가 value이므로 value_compare와 같음)</td>
  </tr>
  <tr>
    <td>key_type</td>
    <td>키(key)의 형식(set은 key가 value이므로 value_type과 같음)</td>
  </tr>
  <tr>
    <td>pointer</td>
    <td>value_type* 형식</td>
  </tr>
  <tr>
    <td>reference</td>
    <td>value_type& 형식</td>
  </tr>
  <tr>
    <td>reverse_iterator</td>
    <td>역 반복자 형식</td>
  </tr>
  <tr>
    <td>size_type</td>
    <td>첨자(index)나 원소의 개수 등의 형식</td>
  </tr>
  <tr>
    <td>value_compare</td>
    <td>원소 조건자(비교) 형식</td>
  </tr>
  <tr>
    <td>value_type</td>
    <td>원소의 형식</td>
  </tr>
</table>







































