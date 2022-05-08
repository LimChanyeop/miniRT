# miniRT
42Cursus RayTracing Subject

레이트레이싱을 활용하여 다양한 도형을 시각화하는 프로그램입니다.

<h3>prerequisite</h3>
MAC OS 환경에서 구동됩니다.

<h3> Usage </h3>
ex) ./miniRT ./scene/test.rt

프로그램은 첫번째 인자로 장면.rt 파일을 받습니다.<br>
make 명령어를 입력하면 빌드가 완료되며 실행파일인 miniRT가 생성됩니다.
.rt에는 창과 렌더링 된 이미지의 size가 포함됩니다. miniRT 실행파일은 아무 양의 정수인 size로 렌더링 가능합니다.<br>


<h3>[RT 파일 용법]</h3>
  
각 타입은 1개 이상의 \n(뉴라인)으로 구분할 수 있습니다.<br>
각 정보 타입은 하나 이상의 ‘ ‘(공백)으로 분리 할 수 있습니다.<br>
대문자로 정의 된 요소는 장면에서 한 번만 선언 할 수 있습니다.<br>
각 요소의 첫 번째 정보는 type identifier(1 ~ 2 개의 문자로 구성됨)와 그에 따르는 각 개체에 대한 모든 구체적인 정보가 순서에 맞게 적혀있습니다. 
<br>
아래는 유형 식별자(R,A,c,l,sp,pl,sq,cy,tr)와 그에 따라 각 함수에서 파싱되어야 할 요소들 입니다..<br><br>
- <b>R 해상도</b><br>
x<br>
y<br>

- <b>A 주변광</b><br>
밝기 [0.0 ~ 1.0]<br>
색 R,G,B [0 ~ 255]<br>

- <b>c 카메라</b><br>
시각 view point x,y,z<br>
3d normalized orientation vector [-1 ~ 1] x,y,z<br>
화각 FOV [0 ~ 180]<br>

- <b>l 스포트라이트</b><br>
좌표 x,y,z<br>
밝기 [0.0 ~ 1.0]<br>
색 R,G,B [0 ~ 255]<br>

- <b>sp 구</b><br>
구의 중심점 좌표 x,y,z<br>
지름<br>
색 R,G,B [0 ~ 255]<br>

- <b>pl 평면</b><br>
좌표 x,y,z<br>
3d normalized orientation vector [-1 ~ 1] x,y,z<br>
색 R,G,B [0 ~ 255]<br>

- <b>sq 사각형</b><br>
사각형의 중심점 좌표 x,y,z<br>
3d normalized orientation vector [-1 ~ 1] x,y,z<br>
변의 길이<br>
색 R,G,B [0 ~ 255]<br>

- <b>cy 원기둥</b><br>
좌표 x,y,z<br>
3d normalized orientation vector [-1 ~ 1] x,y,z<br>
원기둥 지름<br>
원기둥 높이<br>
색 R,G,B [0 ~ 255]<br>

- <b>tr 삼각형</b><br>
꼭지점 1의 좌표 x,y,z<br>
꼭지점 2의 좌표 x,y,z<br>
꼭지점 3의 좌표 x,y,z<br>
색 R,G,B [0 ~ 255]

- Display Example

<img width="1552" alt="image" src="https://user-images.githubusercontent.com/58672664/167284873-146f0948-3b01-41cc-bb63-1b3918a855cd.png">
