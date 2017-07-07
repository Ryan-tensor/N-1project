## N - 1 프로젝트

### 요약

우리는 N포세대라 불린다. 통계에 따르면 결혼, 꿈과 희망, 내 집 마련, 출산, 인간관계, 건강, 외모 등 많은 것을 포기한 청년이 많다. 머신러닝의 Linear Regression을 통해 내 집 마련에 대한 희망을 지역별 집 시세와 넓이를 예측하여 갖게 하려고 한다. 또한 본 논문을 통하여 파이썬의 ‘Tensorflow'라는 라이브러리를 소개하며 C언어에 비해 간결하고 빠른 개발을 할 수 있음을 알린다.

### Abstract

Surely national economic crisis affects people's lives. Young people today give up marriage, appearance, giving birth, health, appearance and especially purchasing house because of it. These people are called 'Generation of a dark age.' With Linear Regression of machine learning, we can estimate the value of local real estate to help them own house. Library called 'Tensorflow' from Python can prove that Linear Regression is simpler and easier way than the C-language to construct

### [N포세대](https://namu.wiki/w/N%ED%8F%AC%EC%84%B8%EB%8C%80)란?
```
N가지의 것들을 포기한 세대를 뜻하는 신조어. 2010년대 기준으로 청년실업 등의 문제에 
시달리는 20대~30대 한국 젊은이들의 암울한 현실을 일컫는 단어이다. 
일본에서는 Ｎ放世代라는 단어를 한국 N포세대의 뜻으로 쓴다.
```

처음에 나온 건 삼포세대였다. 삼포세대는 연애, 결혼, 출산 세 가지를 포기한 세대란 뜻의 신조어이다. 20대에서 30대에 이르기까지 젊은 층이 좀처럼 연애를 안하려 들고, 연애를 하더라도 결혼을 꺼리며, 결혼을 하더라도 출산을 포기하는 사회적인 현상을 말한다. 여기에 취업/내 집 마련까지 포기하는 경우를 오포세대로 부르더니, 이후로는 인간관계/희망도 포기했다 하여 칠포세대, 건강/외모관리까지 포함해서 구포세대, 마지막으로 꿈도 희망도 없는 삶에 비관하여 삶까지 포기한다고 해서 십포세대 혹은 완포세대 혹은 전포세대 등으로 부른다. 하나하나 부르기엔 어차피 공통선상에 있는 용어들이기에 언론 등에서는 'N포세대'로 통칭한다.

### 서론
우리가 어떤 민족인지 아는가? 과거에는 백의 민족, 현재는 배달의 민족이라는 농담이 있다. 그렇다면 현재 20~30대는 무슨 세대인지 아는가? 바로 **N포세대**이다.
3포세대라는 말은 2011년 경향신문의 기획시리즈 <복지국가를 말한다>의 특별취재팀이 만든 신조어였다. 하지만 거기에 그치지 않고 5포, 7포, 9포, 다포, N포세대에 이르기까지 했다. 결혼, 내 집 마련, 출산, 건강 등을 유지하려면 많은 자원이 소모된다. 그 중압감에 포기하는 청년이 많은데 이러한 소모되는 자원의 구체적인 양을 머신러닝을 통해 안다면 미리 알고 준비하는데 도움이 될 것이라는 생각에 진행하게 되었다. 이 프로젝트에서는 내 집 마련에 중점을 두었고 각 지역의 넓이에 따른 시세를 입력하여 학습시키면 넓이에 따른 가격을 예측할 수 있고 그에 따라 미래를 설계할 수 있을 것이다. 이 프로젝트를 통하여 머신러닝의 개념뿐만 아니라 청년이 희망을 가졌으면 한다.

### 목적
목적은 크게 세가지이다.
```
1.C언어에 비해 Python이 코드가 훨씬 간단하다.
2.머신러닝 라이브러리인 Tensorflow를 소개한다.
3.우리 모두 내 집 마련을 할 수 있다는 희망을 심어준다.
```
###  실험 결과
**실험 환경**

```
*i7-6700HQ (2.6GHz) / Ram : DDR3L, 8Gb / 
*M.2  :250GB / 그래픽카드 : GTX960M
*C언어 IDE : visual studio2015
*파이썬 : python3.6, PyCharm community edition
*tensorflow : 1.1 version
```

**실험 (training set)**
>[서울시 강남구 역삼동](http://realestate.daum.net/maemul/area/3135080/A1A3A4/*/summary)

>[수원시 영통구 영통동](http://realestate.daum.net/maemul/area/3443470/A1A3A4/*/summary)

>[천안시 동남구 목천읍](http://realestate.daum.net/maemul/area/3330840/A1A3A4/*/summary)

**언어별 결과**

| 역삼동| C | Python |
| :------------ | :-----------: | -------------------: |
| cost value    |**3.1718e+8**| 7.8770e+8 |
| w(기울기)     | 810.5 | 1161.5               |
| b(bias값)     | 36405  |8.596|

| 영통동| C | Python |
| :------------ | :-----------: | -------------------: |
| cost value    |2.9602e+7| **5.5351e+6** |
| w(기울기)     | 326.5 | 405.9 |
| b(bias값)     | 4452  |-1.862|

| 목천읍| C | Python |
| :------------ | :-----------: | -------------------: |
| cost value    |2.2156e+7| **5.1579e+6** |
| w(기울기)     | 241.7 | 204.2|
| b(bias값)     | -2553 |9.570|
### 결론
```
역삼동은 1m2 당 800~1150만원, 영통동은 1m2 당 300~450만원, 목천읍은 1m2 당 200~250만원 정도한다는 것을 알 수 있었다.
사회 초년생이 결혼을 하고 첫 집을 구한다면 56m2(17평)기준으로 
강남은 8억 2천, 수원 영통동은 2억2천, 목천읍은 1억 1천의 예상 값이 나왔다. 
(cost value가 낮은 기준 계산) 이렇게 머신러닝을 이용하여 직장과의 교통과 집값을 비교하여 
자신의 현실에 맞는 내 집을 준비하면 구체적인 목표가 설정될 것이다.
```
```
또한 C언어와 파이썬의 코드와 실행결과를 비교해보면 130줄과 30줄의 차이로 4배 이상의 차이가 있었.
C언어로는 머신러닝 이론 그대로 구현하였고 파이썬은 Tensorflow라는 라이브러리를 사용하였고 
정규화가 안 되어 있을수록 C언어의 cost value가 작았으나 정규화에 가까운 training set일 경우 tensorflow의 cost value가 적었다. 
```
```
tensorflow의 라이브러리 안의 소스를 볼 수가 없어 비교는 못하였으나 정규화를 하여 tensorflow를 사용한다면 더 좋은 결과를 얻을 수 있을 것이다.
```
### 참고자료
기초프로그래밍 - 머신러닝예제(C언어로 linear Regression구현)

>[홍정모 교수의 블로그](http://blog.naver.com/atelierjpro/220617527872)


모두를 위한 머신러닝/딥러닝 강의(Python TensorFlow를 이용한 구현)

>[Lab 1~2](https://hunkim.github.io/ml/)
