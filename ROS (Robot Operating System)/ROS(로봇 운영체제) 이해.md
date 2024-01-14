## 🤞ROS 구성
#### ❤️Client Libraries 
- 다양한 프로그래밍 언어(C, Python)를 지원하기 위함
- libraries roscpp, rospy

#### ❤️하드웨어 인터페이스
- 하드웨어 제어를 위함

#### ❤️데이터 통신을 위한 커뮤니케이션

#### ❤️Robotics Application Framework
- 다양한 로보틱스 응용프로그램 작성 위함

#### ❤️Robotics Application
- Robotics Application Framework 기반의 서비스용 응용프로그램

#### ❤️Simulation
- 가상의 공간에서 로봇을 제어해 볼 수 있는 시뮬레이션

#### ❤️Software Development Tool

## 🤞ROS 특징
#### ❤️분산 프로세스
- 최소 단위의 실행 가능한 프로세서(Node) 형태로 프로그램, 각 프로세스는 독립적으로 실행되면서 데이터를 주고 받음
- Node 간의 송/수신되는 데이터인 메시지를 저장하고 재사용 가능

#### ❤️패키지 단위 관리
- 같은 목적을 갖는 다양한 프로세스를 패키지 단위로 관리하기 때문에 개발, 공유, 수정 후 재배포 쉬움

#### ❤️공개 repository
- 개발자가 선호하는 공개 repository(GitHub 등) 등에 패키지를 공개 및 각 라이선스 배포

#### ❤️API(Application Programming Interface) 형태
- ROS를 활용한 프로그램을 개발할 때 단순히 API를 불러와 자신이 사용하던 코드에 쉽게 삽입할 수 있도록 설계
- ROS 프로그래밍과 C++, Python 프로그램

#### ❤️복수의 프로그래밍 언어 지원
- 다양한 언어를 지원하기 위해 Client Library를 제공
- Python, C++ 등 로봇 분야에서 많이 사용하는 프로그래밍 언어와 Java, C# 등의 언어에서도 사용가능

#### ❤️로봇에 대한 표준 메시지 정의
- 카메라, IMU, 레이저, 센서와 경로 및 지도 등의 네비게이션 데이터 등 표준 메시지 정의   <br>
   => 모듈화, 협업 작업을 유도, 효율성 향상

#### ❤️로봇 기하학 라이브러리 제공
- 진단 시스템, 센싱과 인식 레벨의 라이브러리

#### ❤️네이게이션
- 로봇에서 많이 사용되는 로봇의 포즈(위치/자세) 추정, 지도내의 자기 위치 추정 제공
- 지도 작성에 필요한 SLAM, 작성된 지도 내에서 목적지를 찾아가는 Navigation 라이브러리를 제공

#### ❤️Manipulation (운동학: Kinematics)
- 로봇 암에 사용되는 IK(Inverse Kinematics: Task -> Joint), FK(Forward Kinematics: Joint -> Task) 제공
- Pick and Place (평면상의 물체 위치 선정과 객체를 잡는 과정)를 지원 <br>
  => Manipulation algorithm tools 제공 (Moveit: 운동 계획과 제어를 위한 도구 toolkit)

## 🤞ROS Master
- 실행 명령어 : roscore
- Node와 Node 사이의 연결과 메시지 통신을 위한 네임 서버와 같은 역할
- Master가 실행하면 각 node의 이름을 등록, 필요에 따라 정보를 받음
    - Master 없이, node간의 접속, topic 서비스와 같은 메시지를 통신할 수 없음
- Master는 http 기반의 프로토콜인 XMLRPC(XML-Remote Procedure Call)를 이용 slave와 통신
    - ROS 구동하면, master는 사용자가 정해 놓은 ROS_MASTER_URL 변수에 기재된 URL 주소와 포트를 갖음
 
## 🤞ROS 용어
#### ❤️ROS Node
- ROS에서 실행되는 최소 단위의 프로세서를 의미, 즉 하나의 실행 가능한 프로그램
- 하나의 목적에 하나의 node를 작성(각 프로그램 세분화)
   - 센서 드라이브, 센서 데이터를 이용한 변환, 장애물 판단, 모터 구동, Encoder 입력, 네이게이션 등 세분화된 node
- node 구동 후 master에 node name, topic 및 service name, message type(ROS naming 사용), URL address, Port를 등록
   - for publisher, subscriber, service server, service client에서 사용하기 위해
- 각 node는 node 간에 topic과 service를 이용하여 message를 주고 받음
   - node는 master와 통신할 때 XMLRPC(eXtensible Markup Language-Remote Procedure Call) 이용
   - node 간의 통신에서는 XMLRPC나 TCP/IP 통신 계열의 TCPROS(ROS message 통신)를 이용
- URL 주소와 Port는 현재 노드가 실행 중인 컴퓨터에 저장돤 `ROS_HOSTNAME 환경변수` 값을 URL 주소로 사용

#### ❤️ROS Pacakge
- ROS 응용프로그램은 Package 단위로 개발 <br>
 => Pacakge는 최소한 하나의 node를 포함하거나 다른 Package의 node를 실행하기 위한 설정 파일을 포함

#### ❤️ROS Message
- 노드 간의 데이터를 주고 받음. 메시지는 integer, floating point, Boolean 같은 변수 형태

#### ❤️ROS Topic
- Publisher node와 Subscriber node가 주고 받는 내용
- ROS Topic 통신 방식은 비동기 방식(필요에 따라 data 송수신)
  
#### ❤️ROS Service
- ROS Service는 동기 방식
- Service는 Topic과는 달리 일회성 메시지 통신, 서비스의 요청과 응답이 완료되면 연결된 두 노드의 접속은 끊김

#### ❤️ROS Action
- 비동기 방식 양방향 메시지 통신
  
action goal    :  `action server <- action client`  <br>
feedback       :  `action server -> action client`  (중간 값을 전송) <br>
action result  :  `action server -> action client` 
