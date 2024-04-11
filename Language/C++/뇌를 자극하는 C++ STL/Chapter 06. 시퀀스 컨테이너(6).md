# 🔵list 컨테이너

## 🟢list 주요 인터페이스와 특징

<table>
  <tr>
    <td colspan="2"><b>생성자</b></td>
  </tr>
  <tr>
    <td>list lt</td>
    <td>lt는 빈 컨테이너다.</td>
  </tr>
  <tr>
    <td>list lt(n)</td>
    <td>lt는 기본값으로 초기화된 n개의 원소를 갖는다.</td>
  </tr>
  <tr>
    <td>list lt(n,x)</td>
    <td>lt는 x값으로 초기화된 n개의 원소를 갖는다.</td>
  </tr>
  <tr>
    <td>list lt(lt2)</td>
    <td>lt는 lt2 컨테이너의 복사본이다(복사 생성자 호출).</td>
  </tr>
  <tr>
    <td>list lt(b,e)</td>
    <td>lt는 반복자 구간 [b,e)로 초기화된 원소를 갖는다.</td>
  </tr>
</table>

<table>
  <tr>
    <td colspan="2"><b>멤버 함수</b></td>
  </tr>
  <tr>
    <td>lt.assign(n,x)</td>
    <td>lt에 x값으로 n개의 원소로 할당한다.</td>
  </tr>
  <tr>
    <td>lt.assign(b,e)</td>
    <td>lt를 반복자 구간 [b,e)로 할당한다.</td>
  </tr>
  <tr>
    <td>lt.back()</td>
    <td>lt의 마지막 원소를 참조한다(const, 비 const 버전이 있음).</td>
  </tr>
  <tr>
    <td>p=lt.begin()</td>
    <td>p는 lt의 첫 원소를 가리키는 반복자다(const, 비 const 버전이 있음).</td>
  </tr>
  <tr>
    <td>lt.clear()</td>
    <td>lt의 모든 원소를 제거한다.</td>
  </tr>
  <tr>
    <td>lt.clear()</td>
    <td>lt의 모든 원소를 제거한다.</td>
  </tr>
  <tr>
    <td>lt.empty()</td>
    <td>lt가 비었는지 조사한다.</td>
  </tr>
  <tr>
    <td>p=lt.end()</td>
    <td>p는 lt의 끝을 표식하는 반복자다(const, 비 const 버전이 있음)</td>
  </tr>
  <tr>
    <td>q=lt.erase(p)</td>
    <td>p가 가리키는 원소를 제거한다. q는 다음 원솔,ㄹ 가리킨다.</td>
  </tr>
  <tr>
    <td>q=lt.erase(b,e)</td>
    <td>반복자 구간 [b,e)의 모든 원소를 제거한다. q는 다음 원소다.</td>
  </tr>
  <tr>
    <td>lt.front()</td>
    <td>lt의 첫 번째 원소를 참조한다.(const, 비 const 버전이 있음). </td>
  </tr>
  <tr>
    <td>q=lt.insert(p,x)</td>
    <td>p가 가리키는 위치에 x값을 삽입한다. q는 삽입한 원소를 가리키는 반복자다.</td>
  </tr>
  <tr>
    <td>lt.insert(p,n,x)</td>
    <td>p가 가리키는 위치에 n개의 x값을 삽입한다.</td>
  </tr>
  <tr>
    <td>x=lt.max_size()</td>
    <td>x는 lt가 담을 수 있는 최대 원소의 개수다(메모리의 크기).</td>
  </tr>
  <tr>
    <td>lt.merge(lt2)</td>
    <td>lt2를 lt로 합병 정렬한다(오름차 순: less).</td>
  </tr>
  <tr>
    <td>lt.merge(lt2,pred)</td>
    <td>lt2를 lt로 합병 정렬한다. pred(조건자)를 기준으로 합병한다(pred는 이항 조건자).</td>
  </tr>
  <tr>
    <td>lt.pop_back()</td>
    <td>lt의 마지막 원소를 제거한.</td>
  </tr>
  <tr>
    <td>lt.pop_front()</td>
    <td>lt의 첫 원소를 제거한다.</td>
  </tr>
  <tr>
    <td>lt.push_back(x)</td>
    <td>lt의 끝에 x를 추가한다.</td>
  </tr>
  <tr>
    <td>lt.push_front(x)</td>
    <td>lt의 앞쪽에 x를 추가한다.</td>
  </tr>
  <tr>
    <td>p=lt.rbegin()</td>
    <td>p는 lt의 역 순차열의 첫 원소를 가리키는 반복자다(const, 비 const 버전이 있음).</td>
  </tr>
  <tr>
    <td>lt.remove(x)</td>
    <td>x의 원소를 모두 제거한다.</td>
  </tr>
  <tr>
    <td>lt.remove_if(pred)</td>
    <td>pred(단항 조건자)가 '참'인 모든 원소를 제거한다.</td>
  </tr>
  <tr>
    <td>p=lt.rend()</td>
    <td>p는 lt의 역 순차열의 끝을 표식하는 반복자다(const, 비 const 버전이 있음).</td>
  </tr>
  <tr>
    <td>lt.resize(n)</td>
    <td>lt의 크기를 n으로 변경하고 확장되는 공간의 값을 기본값으로 초기화한다.</td>
  </tr>
  <tr>
    <td>lt.resize(n,x)</td>
    <td>lt의 크기를 n으로 변경하고 확장되는 공간의 값을 x값으로 초기화한다.</td>
  </tr>
  <tr>
    <td>lt.reverse()</td>
    <td>lt의 순차열을 뒤집는다.</td>
  </tr>
  <tr>
    <td>lt.size()</td>
    <td>lt의 원소의 개수다.</td>
  </tr>
  <tr>
    <td>lt.sort()</td>
    <td>lt의 모든 원소를 오름차순(less)으로 정렬한다.</td>
  </tr>
  <tr>
    <td>lt.sort(pred)</td>
    <td>lt의 모든 원소를 pred(조건자)를 기준으로 정렬한다. pred(조건자)는 이항 조건자다.</td>
  </tr>
  <tr>
    <td>lt.splice(p,lt2)</td>
    <td>p가 가리키는 위치에 lt2의 모든 원소를 잘라 붙인다.</td>
  </tr>
  <tr>
    <td>lt.splice(p,lt2,q)</td>
    <td>p가 가리키는 위치에 lt2의 q가 가리키는 원소를 잘라 붙인다.</td>
  </tr>
  <tr>
    <td>lt.splice(p,lt2,b,e)</td>
    <td>p가 가리키는 위치에 lt2의 순차열 [b,e)을 잘라 붙인다.</td>
  </tr>
  <tr>
    <td>lt.swap(lt2)</td>
    <td>lt와 lt2를 swap한다.</td>
  </tr>
  <tr>
    <td>lt.unique()</td>
    <td>인접한 원소의 값이 같다면 유일한 원소의 순차열로 만든다.</td>
  </tr>
  <tr>
    <td>lt.unique(pred)</td>
    <td>인접한 원소가 pred(이항 조건자)의 기준에 맞다면 유일한 원소의 순차열로 만든.</td>
  </tr>
</table>

<table>
  <tr>
    <td colspan="2"><b>연산자</b></td>
  </tr>
  <tr>
    <td>lt1 == lt2</td>
    <td>lt1과 lt2 모든 원소가 같은가?(bool 형식)</td>
  </tr>
  <tr>
    <td>lt1 != lt2</td>
    <td>lt1과 lt2의 모든 원소 중 하나라도 다른 원소가 있는가?(bool 형식)</td>
  </tr>
  <tr>
    <td>lt1 < lt2</td>
    <td>문자열 비교처럼 lt2가 lt1보다 큰가?(bool 형식)</td>
  </tr>
  <tr>
    <td>lt1 <= lt2</td>
    <td>문자열 비교처럼 lt2가 lt1보다 크거나 같은가?(bool 형식)</td>
  </tr>
  <tr>
    <td>lt1 > lt2</td>
    <td>문자열 비교처럼 lt2가 lt1보다 작은가?(bool 형식)</td>
  </tr>
  <tr>
    <td>lt1 >= lt2</td>
    <td>문자열 비교처럼 lt2가 lt1 보다 작거나 같은가?(bool 형식)</td>
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
