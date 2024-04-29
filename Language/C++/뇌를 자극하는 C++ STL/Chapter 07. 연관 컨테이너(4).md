# map 컨테이너 
map 컨테이너는 연관 컨테이너 중 자주 사용하는 컨테이너로 원소로 key와 value의 쌍으로 저장합니다.

set은 원소로 key 하나만을 저장하지만, map은 원소로 key와 value의 쌍(pair 객체)을 저장합니다.

set처럼 원소의 key는 컨테이너에 중복 저장될 수 없으며 중복 key를 저장해야 한다면 multimap을 사용해야 합니다.

# map의 주요 인터페이스와 특징
map도 연관 컨테이너이므로 set과 같은 인터페이스 멤버 함수를 제공하며 템플릿 형식과 내장 멤버 형식만이 약간의 차이를 보입니다.

특히, map은 []연산자를 제공하여 key에 해당하는 원소의 value에 쉽게 접근하거나 변경할 수 있습니다.

<table>
  <tr>
    <td colspan="2"><b>연산자</b></td>
  </tr>
  <tr>
    <td>m[k]=v</td>
    <td>m 컨테이너에 원소(k,v)를 추가하거나 key에 해당하는 원소의 value를 v로 갱신한다.</td>
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
    <td>키(key) 조건자(비교) 형식</td>
  </tr>
  <tr>
    <td>key_type</td>
    <td>키(key)의 형식</td>
  </tr>
    <tr>
    <td>mapped_type</td>
    <td>값(value)의 형식</td>
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
