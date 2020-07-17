# 채수기







#### Nextion 디스플레이

Nextion 디스플레이는 손쉽게 GUI 바탕의 터치스크린의 HMI를 꾸밀 수 있는 솔루션이며 자체 SD카드 소켓도 있다. 또 Nextion Editor라는 GUI를 만들 수 있는 별도의 전용프로그램이 있어서 전문지식 비겨적 쉽게 GUI를 만들 수 있는게 큰 장점  (Nextion이 중국회사인건 안비밀..)

내가쓰는 제품은 Nextion HMI LCD, 감압식 터치, 7인치 NX8048T070 , 기본형으로 아래와 같이 생겼다.

<img src="https://cdn.nextion.tech/wp-content/uploads/2017/07/Nextion-7.0-HMI-TFT-LCD-Touch-Display-1.jpg" alt="img" style="zoom: 25%;" />



Nextion Editor 다운로드, 사용법에 관해선 https://kwonkyo.tistory.com/132 이 사이트를 참조



#### Nextion과 아두이노 통신



- Arduino to Nextion : Serial2.print로 nextion에 명령어를 전달할 수 있다.

  ```c++
  Serial2.print("page1_5.n0.val=mb");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
  ```

  넥션은 항상 끝날떄 0xff 를 3번 받으므로 0xff를 3번줘야 명령어의 끝을 인식하여 수행할 수 있게 한다.

  - 주의할점1 : Serial은 보통 pc와 통신이고 nextion 라이브러리를 보면 수정하지 않는한 기본적으로 TX2, RX2가 아두이노와 넥션이 통신하도록 되어있어서 Serial2로 아두이노와 넥션이 통신한다. (아두이노 메가 기준)

  - 주의할점2 :  넥션의 TX핀을 아두이노의 RX핀에 꽂고 RX핀을 아두이노의 TX핀에 꽂아야 통신된다. 필자는 TX끼리 연결해서 왜 통신이 안되는지 좀 헤멨다.

  - 주의할점3 !! : 넥션과 아두이노의 그라운드가 같이 연결되어 있지않으면 서로 통신이 안된다. 전위가 연결되어 있지 않아서인것 같다.(이것때문에 1주일을 쓸데없이 고생했다.)

    

- Nextion to Arduino : 

  ![img1](https://user-images.githubusercontent.com/59247266/87740231-ac163f00-c81c-11ea-826a-8ff9c8f99bd5.png)


  넥션은 명령어를 수행할 때 위와 같은 헥사코드를 송신한다. 위는 넥션에서 get함수를 써서 값을 받을 때 송신하는 헥사코드다. 첫 1바이트는 무슨명령어인지 0x71는 get 명령어를 사용하여 숫자 값을 요청할 때 송신하는 것이고, 그 다음바이트 0X63는 10진수 데이터 99를 의미하는 것이고 뒤 00들은 16의 제곱 이상의 값을 표현할 때 쓰이며 0xff3개는 종료 바이트이다. 우리한테 필요한건 2번째 바이트이므로 이것만 아두이노에서 받으면 된다.

  ```c++
  Serial2.read();            #첫번째 바이트인 0x71 
  mb = Serial2.read();	   #두번째 바이트인 0x63
  ```

  넥션에서 송신하는 데이터를 아두이노가 읽어야되므로 Serial2.read()로 읽어야 하며, 첫 바이트는 흘려야되므로 그냥 Serial2.read()로 한번 읽고 그 다음 데이터가 진짜 필요한 데이터므로 읽어들여서 변수에 저장하면서 넥션에서 아두이노로 통신이 된것이다.



Nextion 명령어나 문법에 관해선 https://m.blog.naver.com/PostView.nhn?blogId=ansdbtls4067&logNo=221606667477&proxyReferer=https:%2F%2Fwww.google.com%2F 이 사이트를 참조

추가적으로 참조할만한 사이트 : https://www.itead.cc/wiki/index.php?title=Nextion_Instruction_Set&oldid,

https://seithan.com/download-nt-ino
