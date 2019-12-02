##  step-2 코드 설명

### 파일 설명
#### game.h
- 게임을 진행하게끔 도와주는 함수가 있는 파일이다.

#### menu.h
- 게임이 시작하면 메뉴 선택을 담당하는 파일이다.

#### player.h
- 실제 들어온 데이터를 처리하는 함수를 가지고 있는 파일이다.

#### team.h
- player들의 모임인 team을 관장하는 파일이다.

#### util.h
- 확률을 계산하는 함수가 들어있는 파일이다.
- 확률은 int를 반환하는 rand() 함수를 위하여, float형식인 타율을 int로 변환 후 계산한다. 


### 진행방식
- 진행방식은 step-1과 비슷하다. 다만 각각의 행동을 수행하는 위치가 달라졌다.
- 전반적인 게임 진행은 game.h에서 담당한다. game.h에는 team1과 team2 두 개의 팀이 있다.
- game.h에서는 게임 진행 로직(Logic) 중에서 팀과 관련된 부분을(팀 순서 변경, 팀 기록 초기화 등), player.h에서는 게임 진행 로직 중에서 선수와 관련된 데이터를 처리하는 부분(배트 휘두르는 함수)으로 나눠진다.
- team에는 record가 존재하여 각각의 팀은 개별적으로 record가 관리된다. 또한 여러 명의 player는 team에 속해 있다.
- 실질적인 각각의 데이터는 step-1과 마찬가지로 record-book.h에서 담당한다. 


### 이미지 예시
![image](https://user-images.githubusercontent.com/47213425/69952297-40f05480-153a-11ea-8306-1922aa4ebf48.png)
![image](https://user-images.githubusercontent.com/47213425/69952337-52d1f780-153a-11ea-93f7-2a741b5035d2.png)
