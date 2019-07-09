def func(a, b):
    return a+b


def condition(listed):
    if 'a' in listed:
        print('a가 listed 안에 있습니다.')
    else:
        print('a가 listed 안에 없습니다.')

# 파이썬에서 for와 dictionary를 같이 쓰면 key값으로만 참조하므로 for i in dictionary에서 i는 키값만 가져온다


def print_dict(dict):
    for i in dict:
        print(i)

# 파이썬 map 내장 함수
# map( @param1 규칙 함수, @param2 자료형 )
#ex) 입력에서 공백을 제거한 후, int형으로 바꾸는 규칙을 적용해 list에 저장 후 N과 M에 해당 값 저장
N, M = list(map(lambda x: int(x), input.split(" ")))


# 파이썬의 print로 자료구조를 출력시 괄호 또한 같이 출력이 된다
print(func(1, 2))
print(condition(['a', 'b', 'c', 'd']))

tuple_data1 = ('H', 12, 26, 's')  # tuple 선언
dict_data1 = {'이름': '엘리스', '취미': '프로그래밍', '키': 185, '몸무게': 70}  # dictionary 선언
print(print_dict(dict_data1))


# 파이썬의 정수형 자료
int_data = 10   # 정수
bin_data = 0b10  # 2진수
oct_data = 0o10  # 8진수
hex_data = 0x10  # 16진수
long_data = 1234567890123456789

# 파이썬 실수형 자료
f1 = 1.0
f2 = 3.14
f3 = 1.56e3  # ==> 1.56 * (10^3), e(숫자)를 쓰면 10^(숫자)를 뜻한다

# 복소수형 : 숫자 뒤에 j를 붙인다, complex(3,4) = 3+4j의 뜻이 된다

# 파이썬의 거듭제곱
multiple = 2**3  # 2^3 in c++

# 파이썬 불리언
aa = True   # or 1
bb = False  # or 0

# 파이썬 논리 연산자
bool1 = True
bool2 = False
bool3 = 1
bool4 = 0

#  불리언 형태에서만 and, or not을 사용
# 정수형 형태에서는 기존 다른 언어와 같은 논리연산 가능
print(bool1 and bool2)
print(bool1 or bool2)


list_data11 = [1, [1, 2], 'hello']
print(list_data11[1][1])    # 리스트 안의 리스트에 접근하는 방법

# 파이썬 리스트 끝에서부터 접근 : '-' 이용
print(list_data11[-1])  # 'hello'가 출력됨, -1이 뒤에서 가장 첫번째임 not 0

# 파이썬 문자열 슬라이싱
# 시작 인덱스 이상, 끝 인덱스 미만의 자료를 접근합니다.
# 변수명[시작 인덱스:끝 인덱스:스텝]
strdata = 'Time is money!!'
print(strdata[::2])  # = strdata[0::2] = strdata[0:16:2]
print(strdata[0:])  # print all data
print(strdata[:])  # print all
print(strdata[:-1])   # print all ?


# sequence data 반복
laugh = 'ha'
# 'hahaha'를 출력합니다.
print(laugh * 3)

# 파이썬 요소 체크 : 자료형 안에 요소가 있는지 확인한다
# 값 in 자료, 값에는 문자열 정수형 모두 가능하며, 자료형에는 모든 오브젝트가 가능하다

# 문자열끼리 + 연산을 할때 자동적으로 다른 문자열 사이에 whitespace가 삽입된다


# 문자열 포맷팅
# 실습에 사용할 변수를 선언합니다.
txt1 = '자바'
txt2 = '파이썬'
num1 = 5
num2 = 10

# 1. 포맷 문자열을 이용해 '나는 자바보다 파이썬에 더 익숙합니다.'를 출력해보세요.
print('나느 %s보다 %s에 더 익숙합니다' % (txt1, txt2))

# 2. 포맷 문자열을 이용해 '파이썬은 자바보다 10배 더 쉽습니다.'를 출력해보세요.
print('%s은 %s보다 10배 더 쉽습니다' % (txt1, txt2))

# 3. 포맷 문자열과 위 변수만을 이용해 '5 + 10 = 15'을 출력해보세요.
print('%d + %d' % (num1, num2))

# 4. 포맷 문자열을 이용해 '작년 세계 경제 성장률은 전년에 비해 5% 포인트 증가했다.'를 출력해보세요.
print('작년 세계 경제 성장률은 전년에 비해 %d%% 포인트 증가했다' % num1)


# \(엔터를 누른다) 는 문자를 개행하지않고 계속 출력하도록 한다


# 파이썬 함수의 가변인자 받기
# asterisk를 이용한다
def func(*kwargs):
    print(kwargs)

# 파이썬은 다수의 인자를 리턴할 수 있다
# 튜플의 형태로 리턴을 한다


def reverse(x, y, z):
    return (z, y, x)

# 파이썬 모듈 임포트1
# 다른 파이썬 파일을 가져 올 수 있다 ==> import 이용
# 타 파일의 함수를 사용하려면 ==> import mylib  mylib.func()

# 파이썬 모듈 임포트2
# from ~ import (ex. from 모듈이름 import 함수 이름)
# 이와 같이 특정함수를 임포트하는 경우, 모듈 전체를 임포트할 때와 다르게 호출하는 함수의 앞에 모듈이름을 붙이지 않는다 ( 호출시 간소화 )


# 클래스 선언
class MyClass():
    var = '안녕하세요'

    def sayHello(self):     # self는 클래스를 가리킨다. self는 함수의 접근지정자와 같은 느낌
        print(self.var)  # 클래스 멤버변수를 가져와 사용한다


obj = MyClass()  # 클래스 객체 생성
print(obj.var)
obj.sayHello()


class MyClass:
    # 클래스 생성자
    def __init__(self, txt):  # txt를 인자로 받는 클래스 생성자
        self.var = txt
        print('MyClass 인스턴스 객체가 생성되었습니다.')

    # 클래스 소멸자
    def __del__(self):
        print('MyClass 인스턴스 객체가 메모리에서 제거됩니다.')


obj = MyClass('안녕하세요')     # 클래스 생성자(초기화) 값으로 넘겨줌
print(obj.var)
del obj  # 클래스 인스턴스 제거, 제거시 문구 출력함


# 예외 처리 try ~ except
try:
    print("block try")
except:
    print("except block")


# 예외 처리 2 try ~ except ~ else
try:
        # 오류 발생 가능성이 높은 코드
    print("block try")
except:
    # 오류가 발생할 경우 실행되는 코드
    print("block except")
else:
    # 오류가 발생하지 않을 경우 실행되는 코드
    print("block else")

# 예외 처리 3 try ~ except ~ finally
try:
        # 오류 발생 가능성이 높은 코드
    print("block try")
except:
            # 오류가 발생할 경우 실행되는 코드
    print("block except")
finally:
                # 오류 발생 유무와 상관 없이 실행
    print("block finally")


# 예약어 Exception : 오류가 발생한 원인을 출력 받을 수 있다.
try:
        # 오류가 발생할 가능성이 높은 코드
    print("오류 발생이 높은 코드")
except Exception as e:
    print(e)        # 에러발생 원인을 출력할 수 있다.


# 사용자 입력
a = input("<값>을 입력하세요: ")        # 사용자로부터 받은 입력을 a에 넣는다
print(a)

# 자료형 확인 : type() 을 이용해 자료형을 확인할 수 있다.
print(type(MyClass))

# 파이썬 내장함수 divmod(int, int) ==> 나눗셈의 몫과 나머지를 튜플형태로 반환

# round() 함수 : 반올림 값을 리턴함
# 두번째 인자 값이 1, 2, 3 일 때, 각 두번 째, 세번 째, 네번 째 자리에서 반올림
# 두번째 인자 값이 -1, -2, -3 일 때, 1의자리, 100의자리에서 반올림


# split() 과 반대로 join() 메소드는 문자열을 결합할 때 사용한다
# join()은 인자로 리스트를 반환한다
# '-'로 연결하려면 ==> '-'.join(list)

# 파이썬 람다함수
# lambda (변수) : (리턴 값)
add = lambda x, y : x + y   # lambda와 :사이 값 = 사용할 변수, x+y 리턴 값


# 파이썬 정규식
# import re ==> re 라이브러리를 사용한다

# 파이썬에서 엑셀로 저장하기
# Openpyxl 라이브러리를 이용한다