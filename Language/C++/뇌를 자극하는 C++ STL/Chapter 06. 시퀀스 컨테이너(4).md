# 🔵deque 컨테이너

## 🟢deque의 주요 인터페이스와 특징

<table>
  <tr>
    <td colspan="2"><b>생성자</b></td>
  </tr>
  <tr>
    <td>deque dq</td>
    <td>dq는 빈 컨테이너이다.</td>
  </tr>
  <tr>
    <td>deque dq(n)</td>
    <td>dq는 기본값으로 초기화된 n개의 원소를 갖는다.</td>
  </tr>
  <tr>
    <td>deque dq(n,x)</td>
    <td>dq는 x로 초기화된 n개의 원소를 갖는다.</td>
  </tr>
  <tr>
    <td>deque dq(dq2)</td>
    <td>dq는 dq2 컨테이너의 복사본이다(복사 생성자 호출).</td>
  </tr>
  <tr>
    <td>deque dq(b,e)</td>
    <td>dq는 반복자 구간 [b,e)로 초기화된 원소를 갖는다.</td>
  </tr>
</table>

<table>
  <tr>
    <td colspan="2"><b>멤버 함수</b></td>
  </tr>
  <tr>
    <td>dq.assign(n,x)</td>
    <td>dq에 x값으로 n개의 원소를 할당한다.</td>
  </tr>
  <tr>
    <td>dq.assign(b,e)</td>
    <td>dq를 반복자 구간 [b,e)로 할당한다.</td>
  </tr>
  <tr>
    <td>dq.at(i)</td>
    <td>dq의 i번째 원소를 참조한다(const, 비 const 버전이 있으며 범위 점검을 포함).</td>
  </tr>
  <tr>
    <td>dq.back()</td>
    <td>dq의 마지막 원소를 참조한다(const, 비 const 버전이 있음).</td>
  </tr>
  <tr>
    <td>p=dq.begin()</td>
    <td>p는 dq의 첫 원소를 가리키는 반복자다(const, 비 const 버전이 있음).</td>
  </tr>
  <tr>
    <td>dq.clear()</td>
    <td>dq의 모든 원소를 제거한다.</td>
  </tr>
  <tr>
    <td>dq.empty()</td>
    <td>dq가 비었는지 조사한다.</td>
  </tr>
  <tr>
    <td>p=dq.end()</td>
    <td>p는 dq의 끝을 표식하는 반복자다(const, 비 const 버전이 있음).</td>
  </tr>
  <tr>
    <td>q=dq.erase(p)</td>
    <td>p가 가리키는 원소를 제거한다. q는 다음 원소를 가리킨다.</td>
  </tr>
  <tr>
    <td>q=dq.clear(b,e)</td>
    <td>반복자 구간 [b,e)의 모든 원소를 제거한다. q는 다음 원소다.</td>
  </tr>
  <tr>
    <td>dq.front()</td>
    <td>dq의 첫 번째 원소를 참조한다(const, 비 const 버전이 있음).</td>
  </tr>
  <tr>
    <td>q=dq.insert(p,x)</td>
    <td>p가 가리키는 위치에 x값을 삽입한다. q는 삽입한 원소를 가리키는 반복자다.</td>
  </tr>
  <tr>
    <td>dq.insert(p,n,x)</td>
    <td>p가 가리키는 위치에 n개의 x값을 삽입한다.</td>
  </tr>
  <tr>
    <td>dq.insert(p,b,e)</td>
    <td>p가 가리키는 위치에 반복자 구간 [b,e)의 원소를 삽입한다.</td>
  </tr>
  <tr>
    <td>x=dq.max_size()</td>
    <td>x는 dq가 담을 수 있는 최대 원소의 개수(메모리의 크기)다.</td>
  </tr>
  <tr>
    <td>dq.pop_back()</td>
    <td>dq의 마지막 원소를 제거한다.</td>
  </tr>
  <tr>
    <td>dq.pop_front()</td>
    <td>dq의 첫 원소를 제거한다.</td>
  </tr>
  <tr>
    <td>dq.push_back(x)</td>
    <td>dq의 끝에 x를 추가한다.</td>
  </tr>
  <tr>
    <td>dq.push_front(x)</td>
    <td>dq의 앞쪽에 x를 추가한다.</td>
  </tr>
  <tr>
    <td>p=dq.rbegin()</td>
    <td>p는 dq의 역 순차열의 첫 원소를 가리키는 반복자다(const, 비 const 버전이 있음).</td>
  </tr>
  <tr>
    <td>p=dq.rend()</td>
    <td>p는 dq의 역 순차의 끝을 표식하는 반복자다(const, 비 const 버전이 있음).</td>
  </tr>
  <tr>
    <td>dq.resize(n)</td>
    <td>dq의 크기를 n으로 변경하고 확장되는 공간의 값을 기본값으로 초기화한다.</td>
  </tr>
  <tr>
    <td>dq.resize(n,x)</td>
    <td>dq의 크기를 n으로 변경하고 확장되는 공간의 값을 x값으로 초기화한다.</td>
  </tr>
  <tr>
    <td>dq.size()</td>
    <td>dq 원소의 개수다.</td>
  </tr>
  <tr>
    <td>dq.swap(dq2)</td>
    <td>dq와 dq2를 swap 한다.</td>
  </tr>
</table>

<table>
  <tr>
    <td colspan="2"><b>연산자</b></td>
  </tr>
  <tr>
    <td>dq1 == dq2</td>
    <td>dq1과 dq2의 모든 원소가 같은가?(bool 형식)</td>
  </tr>
  <tr>
    <td>dq1 != dq2</td>
    <td>dq1과 dq2의 모든 원소 중 하나라도 다른 원소가 있는가?(bool 형식)</td>
  </tr>
  <tr>
    <td>dq1 < dq2</td>
    <td>문자열 비교처럼 dq2가 dq1보다 큰가?(bool 형식)</td>
  </tr>
  <tr>
    <td>dq1 <= dq2</td>
    <td>문자열 비교처럼 dq2가 dq1보다 크거나 같은가?(bool 형식)</td>
  </tr>
  <tr>
    <td>dq1 > dq2</td>
    <td>문자열 비교처럼 dq2가 dq1보다 작은가?(bool 형식)</td>
  </tr>
  <tr>
    <td>dq1 >= dq2</td>
    <td>문자열 비교처럼 dq2가 dq1보다 작거나 같은가?(bool 형식)</td>
  </tr>
  <tr>
    <td>dq[i]</td>
    <td>dq의 i번째 원소를 참조한다(const, 비 const 버전이 있으며 범위 점검이 없음).</td>
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
    <td>value_type</td>
    <td>원소의 형식</td>
  </tr>
</table>





































