##  step-3 코드 설명

### 파일 설명
#### board.h
- 게임 UI를 담당하는 파일이다.
- 게임 속 데이터 결과가 이 파일에 모여서 사용자에게 보여진다.

### 진행방식
- 진행방식은 step-2과 비슷하다. 다만 각각의 행동을 수행하는 방법이 달라졌다.
- step-2와 달리 step-3는 한 투구씩 상황을 진행할 수 있어야 한다.
- 또한, 특정 이닝 말까지 게임을 진행하는 상황을 만들어야 했다.
- 먼저, 한 투구씩 상황을 진행할 수 있는 함수를 만든 다음, 이를 특정 이닝까지 반복문을 계속해서 돌려주는 방식으로 구현했다. 사용자가 특정 숫자를 입력하면 그 특정 숫자 이닝까지 게임이 진행된다. 이 때문에, 4회 때, 숫자 2를 입력해도 아무런 일이 일어나지 않는다. 2이닝은 이미 지난 이닝이여서 도달할 수 없기에 존재할 수 없다. 
- step-2와 또 다른 점은, board를 통해서 결과를 사용자에게 보여준다는 점이다. 이를 위해, board에서 처라한 데이터를 string형식으로 변환하는 함수와 사용자에게 직접 보여주는 함수가 따로 존재한다. 

### 이미지 예시
![image](https://user-images.githubusercontent.com/47213425/69952710-1bb01600-153b-11ea-991b-40c98a2438e3.png)
![image](https://user-images.githubusercontent.com/47213425/69952608-e6a3c380-153a-11ea-8ea5-798243ceac28.png)
