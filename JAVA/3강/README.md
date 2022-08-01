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