# JAVA

플랫폼에 영향을 받지 않으므로 다양한 환경에서 사용이 가능하다.

자바 컴파일러 -> 바이트 코드 -> 윈도우 자바 가상 머신 -> 윈도우에서 실행
                       -> 리눅스 가상 머신 -> 리눅스에서 실행


C언어는 소스 코드가 윈도우는 윈도우 컴파일러가 리눅스는 리눅스 컴파일러가 각각 실행파일을 만들고 그 환경(OS)에서 사용이 가능하다 하지만 JAVA같은 경우는 가상머신 (JVM)을 사용하기때문에 환경(OS)에 상관없이 코드를 실행할 수 있다.

### JAVA의 장점

- 객체 지향 언어이기 때문에 유지보수가 쉽고 확장성이 좋다.
- 프로그래임이 안정적이다.
- 풍분한 기능을 제공하는 오픈 소스이다.



<details>
<summary> 1강 변수와 자료형 </summary>
<div markdown="1">

### 컴퓨터에서 데이터 표현
- 컴퓨터는 0과 1로만 데이터를 저장 한다.
    - bit(비트) : 컴퓨터가 표현하는 데이터의 최소 단위로 2진수 하나의 값을 저장할 수 있는 메모리 크기
    - byte(바이트) : 1byte = 8bit

### 0과 1의 표현 - 2진수
- 컴퓨터는 0과 1로 자료를 표현한다. 따라서 숫자나 문자도 0과 1의 조합으로 표현된다.

### 음의 정수 표현방법
- 정수의 가장 왼쪽에 존재하는 비트는 부호비트 
    - MSB(Most Significant Bit) 가장 중요한 비트
- 음수를 만드는 방법은 2의 보수를 취한다.
    1. 2진수의 모든 비트를 반대로 바꿈
    2. 반대로 바꾼 값에 1을 더함

### 변수
1. 사람의 나이는 해가 바뀌면 변한다. -> 변수
2. 게임을 할면 게임 레벨이 점점 올라감 -> 변수  

프로그램에서 사용되는 자료를 저장하기 위한 공간이며 할당 받은 메모리의 주소 대신 부르는 이름이다. 프로그램 실행 중에 값을 변경이 가능하며 사용되기 이전에 선언 되어야 한다.

### 변수 선언 시 유의점
1. 변수의 이름은 알파벳, 숫자, _, $로 구성된다.
2. 대소문자를 구분한다.
3. 변수의 이름은 숫자로 시작할 수 없고, 키워드도 변수의 이름으로 사용할 수 없다.
4. 이름 사이에 공백이 있을 수 없다.

<mark>변수의 이름을 정할 때는 변수의 역할에 어울리는, 의미 있는 이름을 지어야 한다.</mark>

### 변수가 저장되는 공간의 특성 - 자료형

||정수형|문자형|실수형|논리형|
|------|---|---|---|---|
|1바이트|byte|-|-|boolean|
|2바이트|short|char|-|-|
|4바이트|int|-|float|-|
|8바이트|long|-|double|-|

변수가 사용할 공간의 크기와 특성에 따라 자료형을 사용하여 변수를 선언한다.

### byte 와 short

- byte : 1바이트 단위의 자료형
    - 동영상, 음악 파일등 실행 파일의 자료를 처리 할 때 사용하기 좋은 자료형
- short : 2바이트 단위의 자료형
    - 주로 c/c++ 언어와의 호환 시 사용


### Int  

자바에서 사용하는 정수에 대한 기본 자료형  

- 4바이트 단위의 자료형
- 프로그램에서 사용하는 모든 숫자(리터럴)은 기본적으로 int(4바이트)로 저장된다.
- 32비트를 초과하는 숫자는 Long 형으로 처리

### Long  

8바이트 자료형이며 가장 큰 정수 자료형이다.  
- 숫자의 뒤에 L또는 l을 써서 long형임을 표시  
ex) int num = 12345678900; ->오류  
    long num = 12345678900L; 으로 표현


### char - 문자 자료형  

컴퓨터에서는 문자도 내부적으로는 비트의 조합으로 표현한다.  
자바에서는 문자를 2바이트로 처리한다.

### 문자 세트
문자를 위한 코드 값(숫자 값)들을 정해 놓은 세트
1. 아스키(ASCII) : 1 바이트로 영문자, 숫자, 특수문자 등을 표현 함
2. 유니코드(Unidocde) : 한글과 같은 복잡한 언어를 표현하기 위한 표준 인콘딩 UTF-8, UTF-16이 대표적이다.


### float, double - 실수 자료형
부동 소수점 방식 : 실수를 지수부와 가수부로 표현 하며 무한의 실수를 표현하기 위한 방식이다.
- 실수 자료형 : float(4바이트) double(8바이트) 
- float으로 선언 시 long과 마찬가지로 f라는 식별자를 사용

### boolean - 논리형
논리값 true(참), false(거짓)을 표현하는 자료형

### 자료형 없이 변수 사용 (자바 10)

- 자료형이 필효한 이유
    - 변수를 선언 할 때는 변수가 사용할 메모리 크기와 타입을 구분하기 위해 사용한다.
- 지역 변수 자료형 추론 
    - 변수에 대입되는 값을 보고 컴파일러가 추론한다.

```java
var num = 10;
// c++ auto와 비슷하다 
// 도중에 타입을 변경할 수 없다.
// 지역 변수에서만 사용가능
```

### 상수
상수 : 변하지 않는 값
- 상수를 선언
    - final 키워드를 사용한다.

```java
final int MAX_NUM = 100;
```

### 리터럴(literal)
리터럴 : 프로그램에서 사용하는 모든 숫자,값 ,논리 값  
ex) 10, 3.14, 'A', true

- 리터럴에 해당되는 값은 특정 메모리 공간의 상수 풀(constant pool)에 있다.
- 필요한 경우 상수 풀에서 가져와서 사용
- 상수 풀에 저장 할 때 정수는 int로 실수는 double로 저장하낟.
- 따라서 Long이나 float값으로 저장해야 하는 경우 식별자를 명시해야 한다.

### 형 변환(type conversion)
자료형은 각각 사용하는 메모리 크기와 방식이 다르다. 서로 다른 자료형의 값이 대입되는 경우 형 변환이 일어난다.
1. 묵시적 형변환 : 작은 수에서 큰 수로, 덜 정밀한 수에서 더 정밀한 수로 대입되는 경우

2. 명시적 형변환 : 묵시적 형 변환의 반대의 경우 변환 되는 자료형을 명함 자료의 손실이 발생 할 수 있다. 

```java
double dNum = 3.14;
int num =(int)dNum; // 직접적으로 자료형을 명시해야 한다.
```


</div> 
</details>

### ----------------------------->1강 변수와 자료형


<details>
<summary> 2강. 다양한 연산자. </summary>
<div markdown="1">

### 항과 연산자
- 항(operand) : 연산에 사용되는 값
- 연산자(operator) : 항을 이용하여 연산하는 기호

|연산자|설명|예시|
|------|---|---|
|단항 연산자|항이 한 개인 연산자|++num|
|이항 연산자|항이 두 개인 연산자|num1 + num2|
|삼항 연산자|항이 세 개인 연산자|(5>3)?1:0|

### 대입 연산자
변수에 값을 대입 하는 연산자
- 연사늬 결과를 변수에 대입
- 우선 순위가 가장 낮음
- 왼쪽 변수(left value)에 오른쪽 변수 (right value)를 댕비

### 부호 연산자
단항 연산자이며 양수/음수의 표현,값의 부호를 변경한다.
- 변수에 +,-를 사용한다고 해서 변수의 값이 변하는 것은 아님
- 변수의 값을 변경하려면 대입연산자를 사용

### 산술 연산자
사칙연산에 사용되는 연산자
|연산자|설명|예시|
|------|---|---|
|+|두 항을 더한다|5 + 3|
|-|앞에 있는 항에서 뒤에 있는 항을 뺀다|5 - 3|
|*|두 항을 곱한다|5 * 3|
|/|앞에 있는 항에서 뒤에 있는 항을 나누어 몫을 구한다|5 / 3|
|%|앞에 있는 항에서 뒤에 있는 항을 나누어 나머지를 구한다|5 % 3|

### 증가 감소 연산자
단항 연산자
- 1만큼 더하거나 1만큼 뺄 때 사용
- 항의 앞/뒤 위치에 따라 결과가 달라진다

|연산자|설명|예시|
|------|---|---|
|++|항의 값에 1을 더한다 |num++ 끝나고 더함 ++num 더하고 끝냄|
|--|항에 값에서 1을 뺀다|num--|

### 관계 연산자
이항 연산자
- 연산의 결과가 true OR false로 반환 됨

### 논리 연산자
관계 연산자와 혼합하여 많이 사용 된다.
- 연산의 결과가 true OR false로 반환 됨

|연산자|설명|예시|
|------|---|---|
|"&&"|두 항이 모두 참인 경우에만 결과 값이 참|1<2 && 2<3 -> 참|
|"||"|두 항 중 하나만 참이면 참이다 |1<2 || 2>3 ->참|
|"!"|단항 연산자이며 참은 거짓으로 거짓은 참으로 바꾼다|!(1>2) ->참 |

#### # 논리 합에서 이미 앞에 항이 참이면 뒤에 항은 연산하지 않는다.
#### # 논리 곱에서 이미 앞에 항이 거짓이면 뒤에 항은 연산하지 않는다.

### 조건 연산자
삼항 연산자
- 조건 식의 결과가 참인 경우와 거짓인 경우에 따라 다른 식이나 결과가 수행된다
- 제어문 중 조건문을 간단히 표현할 때 사용할 수 있음

```java
int num = (5>3) ?10 :20;
```

### 비트 연산자
비트 연산자는 정수에만 사용할 수 있다.


|연산자|설명|예시|
|------|---|---|
|~|비트의 반전 (1의 보수) | A = ~A;|
|&|비트 단위 AND |1 & 1 1반환 그 외는 0|
|OR(|)|비트 단위 OR| 0 OR 0 0반환 그 외는 1|
|^|비트 단위 XOR |두 개의 비트가 서로 다른 경우 1을 반환|
|<<|왼쪽 shif| a<<2 변수 a를 2비트 만큼 왼쪽으로 이동|
|>>|오른쪽 shif| a>>2 변수 a를 2비트 만큼 오른쪽으로 이동|
|>>>|오른쪽 shif| >>와 동일한 연산이지만 채워지는 비트가 부호와 상관없이 0임|


</div>
</details>

### ----------------------------->2강 다양한 연산자.

<details>
<summary> 3강 제어문/조건문  </summary>
<div markdown="1">

### 조건문 
주어진 조건에 따라 다른 수행문이 실행되도록 프로그래밍 하는것

```java
if(조건식){
    수행문;
}

else if(조건 2){
    수행문;
}

else{
    수행문;
}
```

### switch-case문
조건식의 결과가 정수 또는 문자열의 값이고 그 값에 따라 수행문이 결정될 때
- if-else, if-else문을 대신하여 사용

```java
switch(num){
    case 1 : num1= num;
            break;
    case 2 : num2= num;
            break;
    default : num = num;
}
```

### 반복문
주어진 조건이 만족할 때까지 수행문을 반복적으로 수행한다.
- while, do-while,for 문이 있음
- 조건의 만족과 반복 가능 여부에 대해 정확한 코딩을 해야 함

### while문
조건식이 참인 동안 수행문을 반복해서 수행
- 무한루프에 빠지지않게 하기 위해서 반복문을 탈출하게 만들어야 함

```java
while(조건식){
    수행문1;
    .... 반복
}
```

### for문
반복문 중 가장 많이 사용하는 반복문
- 주로 조건이 횟수인 경우 사용
- 초기화식, 조건식, 증감식을 한꺼번에 작성

```java
for(int i=0; i<=10; i++){
    System.out.println(i);
}
```

</div>
</details>

### ----------------------------->3강 제어문/조건문

<details>
<summary> 4강 배열 </summary>
<div markdown="1">


- 변수가 많아져 하나하나 변수를 선언하기 힘들 때 사용가능하다.
- 배열은 처음 선언이후 크기가 변하지 않는다.
- 인덱스는 0번부터 시작한다.
- 배열.length 를 이용하면 배열의 크기를 알아낼 수 있다.
- for 블록 안에서 선언된 변수는 for문이 끝나면 사라진다.

```java
int [] arr1 = new int[10];
// int형 배열을 선언하는 방법

int [] arr2 = new int[] {1,2,3,4};
int [] arr3 = {1,2,3,4};

// 선언과 동시에 초기화하는 2가지 방법

int [] Arr = new int[100];

for(int i=0; i<100; i++){
		Arr[i] = i;
}
// 반복문을 사용하여 배열에 접근하는 방법
```

### 2차원 배열

배열안의 배열이다.

- Y(행), X(열)로 생성이 된다.
- Arr[0] = 3 처럼 1차원 대입식은 불가능하다. -> Arr[0][1] = 10; 모든 인덱스를 표시해줘야 한다.
```java
int [][] Arr = new int[3][4];
// YX의 크기로 생성이 된다.
```

### 크기가 다른 배열생성도 가능하다. !!
각 인덱스마다 다른 크기의 배열생성 가능

<img width="702" alt="스크린샷 2022-08-05 오후 6 23 07" src="https://user-images.githubusercontent.com/79856225/183047231-26c12ebf-57e0-4770-8fa5-45e603a12c19.png">

### for each

- for each는 2가지 값만 넣어준다.
for(type값을 받아줄 변수 이름 : 출력하고 싶은 자료구조)
- c++의 for(auto a: arr) 문과 같은 구조이다.
- 단 자동 형변환 auto는 사용이 안된다.. var를 사용하자



</div>
</details>


### ----------------------------->4강 배열


<details>
<summary> 5강 클래스 </summary>
<div markdown="1">

### 객체지향 언어

- 프로그램을 구성하는 요소는 객체이며 이것이 상호작용 하도록 프로그래밍
- 클래스 : 객체를 만들기 위한 틀

ex) 객체 : 붕어빵

클래스 : 붕어빵 틀

```java
public class Car{
	
}

public class CarEx{
	public static void main(String [] args){
		Car c1 = new Car(); 
// new를 사용하여 객체를 만들어야 함
	}
}
```

### 자바에는 2가지 타입이 존재한다.

1. 기본형 타입
    - 논리형, 문자형, 정수형, 실수형
2. 참조형 타입
    - 기본형을 제외한 모든 타입

```java
int i = 4; //기본형 타입
String str = new String("HELLO"); //참조형 타입
```

 new라는 키워드는 메모리에 올려달라는 의미이다 c에서 동적할당과 같은 개념이며 이렇게 메모리에 올라간 클래스를 **인스턴스**라고 말한다.

메모리에 올라간 인스턴스를 가리키는 변수 = 참조하는 변수 = 레퍼런스하는 변수  모두 같은 말이다. 

- 인스턴스를 가지고 있는게 아니라 가리키고 있다는 의미이다 즉 **포인터**

### 클래스는 모두 참조형이다

String은 자바에서 가장 많이 사용하는 클래스이다.

### 특징 1. String은 예외적은 new연산자 없이도 생성이 가능하지만 약간의 차이가 있다.

```java
String str1 = "Hello"; // ->상수영역에있는 Hello를 가르키고 있다.
String str2 = "Hello"; // ->상수영역에있는 Hello를 가르키고 있다.
String str3 = new String("Hello"); //상수영역에 있는걸 참조하는게 아니라 새롭게 힙영역에 생성한다.

////////////////////// 차이점 비교 ////////////////////
if(str1==str2) --> true 둘은 상수영역에 있는 같은 레퍼런스를 참조하고 있다 
if(str1 == str3) --> false str1은 상수영역 str3은 힙영역에 새롭게 생성된 인스턴스이다.
```

사람이 보기에는 같은 Hello이지만 자바는 new로 생성된 string과 그냥 생성된 string을 다르게 생각한다.

### 특징 2. String은 다른 클래스와 다르게 한 번 생성된  클래스는 변하지 않는다.

```java
// str1.을 이용하여 메서드 확인
System.out.println(str1.substring(3)); //3번 인덱스부터 잘라져서 보여짐
System.out.println(str1); // 내부의 값은 변하지 않음
// 즉 수행하기 전에 새로운 스트링을 만들어서 반환한다고 생각하면 된다.
```

### 클래스의 구성요소 : 필드

ex)

객체 : 자동차 

필드 : 자동차의 구성요소 (속성)

1. 차 이름
2. 차량번호

객체 : 학생

필드 : 학생의 구성요소(속성)

1. 이름
2. 번호

```java
public class Car{
	String name;
	int number;
}
//자동차 클래스 생성

public static void main(String[] args){
	Car c1 = new Car();
	Car c2 = new Car();
	
	c1.name = "소방차";
	c1.number = 1234;

	c2.name = "구급차";
	c2.number = 1111;
// 자동차 객체를 생성한 후 속성 값 삽입

	System.out.println(c1.name);
	System.out.println(c1.number);
// c1 객체 확인
	System.out.println(c2.name);
	System.out.println(c2.number);
// c2 객체 확인
}
```

**각각**의  자동차 **객체 생성**되었고 각자 다른값이 들어있는걸 확인할 수 있다.

### 객체 지향 언어 : 하나의 사물을  하나의 클래스로 설명

- 사물
    - 상태 → 필드
        - 이름, 차량번호
    - 행동 → 메소드
        - 전진,후진

- 메소드 :  함수와 같다 입력값 —> 결과값
    - 입력값 : 매개변수(인자)
    - 결과값 : 리턴값 (반환값)

- 메소드 : 클래스가 가지고 있는 기능

public 리턴타입(ex int) 메소드 이름(매개변수){
	구현
}

### 다양한 메소드 선언

```java
public void method1(){ //리턴값이 없다면 void를 사용
	System.out.println("mthod1이 실행됨");
}

public void method2(int value){ //정수형 인자를 받음
	System.out.println(value + "method2가 실행됨");
}

public int method3(){
	System.out.println("method3이 실행됨");
	return 10;
} // 리턴값을 설정했으니 리턴값을 줘야함

public void method4(int x, int y){ //여러개의 인자를 받음
		System.out.println(x+y + "method4가 실행됨");
}

public int method5(int x){ //정수형 인자를 받음
		System.out.println(x + "method5가 실행됨");
		return x*2;
} // 받은 인자를 이용하여 리턴
```

선언한 메소드 사용 

- 위에 클래스를 생성했다고 가정하고 진행(Myclass)
- 실행 시 선언했던 조건을 맞춰줘야 한다.

```java
public static void main(String [] args){
		Myclass myclass = new Myclass();
		// myclass.을 이용하여 메소드 접근가능
		myclass.method1();

		myclass.method2(10); //정수형을 무조건 넣어줘야 한다.

		int value = myclass.method3(); //리턴값을 받아낼 변수가 필요
		System.out.println(value);  //받은 값 확인

		myclass.method4(3,4); //2개의 정수값을 인자로

		int value1 = myclass.method5(10); //정수 인자를 이용하여 리턴값 받음
		System.out.println(value1); //확인
}
```

### 필요한 클래스를 구현하는 방법도 있지만 이미 만들어진 클래스들을 이용할 수 있다.

자주 사용하는 String 클래스의 메소드 확인

```java
public static void main(String[] args){
    String str = "Hello";
    str.length(); // 문자열의 길이를 반환해주며 공백도 하나의 문자로 인식한다.
    str.concat(" World"); // 문자열을 더해준다 -> Hello World
    /* 
        이때 str을 확인해보면 Hello World가 아닌 Hello로 나온다. 
        즉 concat을 사용하면 새롭게 생성한 String Hello World를 반환하다.
    */
    str = str.concat(" World"); // 이 처럼 사용해야 str값이 변환된다.

    str.substring(3); //3번 인덱스부터 잘라준다.
    str.substring(3,6); // 3번부터 6번까지 인덱스를 잘라준다.    
    }
```

### 변수의 사용범위 : 변수가 선언된 블록

```java
public class VariableScopeExam{
	int globalscope = 10;
	
	public void scopeType1(int value){
		int localscope =20;
		globalscope = value; //가능
		localscope = 40; //가능
	}
	
	public void scopeType2(int value){
		globalscope = value; //가능
		localscope = 40; //불가능
	}
	
	public static void main(String[] args){
		globalscope = 100; //불가능
		localscope = value; //불가능
	}
}
```

### 모든 클래스는 인스턴스화 하지 않은 채로 사용할 수 없다.

- 붕어빵틀 ≠ 붕어빵

### **static** 키워드를 사용하면 인스턴스화(객체를 생성) 하지않아도 사용이 가능하다.

```java
public class VariableScopeExam{
	int globalscope = 10;
	static int staticValue = 10;
	
	public void scopeType1(int value){
		int localscope =20;
		globalscope = value; //가능
		localscope = 40; //가능
	}
	
	public void scopeType2(int value){
		globalscope = value; //가능
		localscope = 40; //불가능
	}
	
	public static void main(String[] args){
		globalscope = 100; //불가능
		localscope = value; //불가능
		staticValue = 20 // 가능
	
		VariableScopeExam v1 =new VariableScopeExam();
		VariableScopeExam v2 =new VariableScopeExam();
		v1.globalscope = 100; 
		v2.globalscope = 200;
	// 위처럼 객체를 생성해서 사용해야 하며 각각 다른객체 이므로 다른값이 들어간다.
		v1.staticValue = 100;
		v2.staticValue = 200;
	// static 필드는 값을 공유하므로 두 객체는 같은값을 가지고 있다.
	}
}
```

### 클래스 변수

- static한 변수, 값을 저장할 수 있는 공간이 하나뿐이여서 값을 공유한다.
- 클래스 이름을 직접 사용하는 것이 가능하다.
    - 클래스이름.클래스변수명
    
    ex)  VariableScopeExam.staticValue
    

### 글로벌 변수를 선언할 때 static을 사용하면 되는것인가?!

### JDK5에서 추가된 문법이다 (enum)

- 기존 사용방식

```java
public class EnumEx{
	public static final String MALE ="MALE";
	public static final String FEMALE ="FEMALE";
	
	public static void main(String [] args){
		String gender1; //MALE 과 FEMAL 둘 중 하나의 값을 넣고싶음
		gender1 = EnumEx.MALE;
		gender1 = EnumEx.FEMALE;
		gender1 = "boy"; //하지만 다른 string 값이 들어와도 오류를 발생시키지 않는다.
	
		Gender gender2;
		gender2 = Gender.MALE;
		gender2 = Gender.FEMALE;
		gender2 = "boy"; //에러 
	}
enum Gender{
		MALE,FEMALE; 
	}
}
```

위처럼 특정 값만 사용할 때는 열거형을 사용하면 좋다

- 다른값이 들어왔을 때 오류가 생길 수 있을때 사용하면 좋아보인다.

</div>
</details>

### ----------------------------->5강 클래스

<details>
<summary> 6강 클래스 다듬기 </summary>
<div markdown="1">

### new 연산자를 사용하면 반드시 생성자가 나와야 함

1. 리턴 타입이 없다.
2. 매개 변수가 없는 생성자를 기본생성자라 하고 자동으로 만들어진다.
→ 생성자를 하나라도 만든다면 기본생성자는 만들어지지 않는다.

```java
public class Car{
	String name;
	int Number;
}
Car c1 = new Car(); 
// car()이 부분이 생성자이다.

// 위 처럼 아무런 생성자를 만들지 않는다면 자동으로 만들어진다.

public Car(String n){
	name = n;
}

Car c1 = new Car();  //오류
Car c1 = new Car("소방차"); 
// Car라는 객체가 생성되면서 매개변수를 이용하여 생성되며 기본생성자는 만들어지지 않는다.
```

객체가 만들어지면서 기본적으로 부여할 속성이 있다면 생성자를 잘 이용하면 될듯 하다.	

### 객체 자신을 참조하는 This

```java
public Car(String name){
	name = name
} //이름이 똑같기 때문에 컴파일러는 동일한 값을 가르킨다.

public Car(String name){
	this.name = name;
}
// 객체 자신을 참조하는 this를 이용!!
```


### 메소드 오버로딩을 사용하면 매개변수의 수, 타입이 다른경우에 동일한 이름의 메소드를 여러개 정의할 수 있다.

1. 정수 2개를 받아 그 합을 리턴하는 메소드
2. 정수 3개를 받아 그 합을 리턴하는 메소드
3. 문자열 2개를 받아 그 합을 리턴하는 메소드

위 예시 처럼 각각 **타입**과 **매개변수의 수**가 다른경우 사용이 가능하다.

```java
public int plus(int x, int y){
	return x+y;
} // int 타입과 int형 매개변수 2개

public int plus(int x, int y, int z){
	return x+y+z;
} // int 타입과 int형 매개변수 3개

public String plus(String x, String y){
	return x+y;
} // String 타입과 String 형 매개변수 2개
```

### 생성자도 메소드와 마찬가지로 여러개로 생성이 가능하며 이를 생성자 오버로딩이라 한다.

```java
Car c1 = new Car("소방차");
Car c2 = new Car(); // 기본 생성자는 다른 생성자가 있으면 자동으로 생성되지 않는다.
```

기본생성자를 사용하고 싶다면 마찬가지로 미리 정의해둬야 한다.

### this() : 자신의 생성자를 이용하여 초기화 가능

- 자신이 정의해둔 **생성자 조건에 맞게** 선언해야한다.

```jsx
public car(){
	//this.name = "이름없음"
	//this.Number = 0;
	this("이름없음", 0); 
// 아래에 있는 생성자를 이용하여 초기화 가능

} //기본 생성자 오버로딩

public car(String name, int Number){
	this.name = name;
	this.Number = Number;
} // 생성자 오버로딩
```
### 패키지 : 서로 관련이 있는 클래스 또는 인터페이스들을 묶어 놓은 묶음

- 파일들이 많아지면 관련있는 파일끼리 묶어 하나의 폴더에 보관한다.
- package 이름은 대부분 도메인 이름을 **거꾸로 적은 후 프로젝트 이름을 붙여 사용한다.**
- 패키지가 있는 클래스를 사용할 때는 import를 이용
- 패캐지 이름은 숫자로 시작할 수 없다.

```java
package 패키지명;
// import 패키지명.*;을 이용하여 사용하여야 한다.
public class 클래스 이름{
	...
}
```

</div>
</details>

### ----------------------------->6강 클래스 다듬기

<details>
<summary> 7강 상속 </summary>
<div markdown="1">

</div>
</details>

### ----------------------------->7강 상속



<!--
<details>
<summary>  </summary>
<div markdown="1">

</div>
</details>
----------------------
-->