import numpy as np

# python의 null 객체 표현
# None으로 표현한다
# 객체가 None인지 아닌지 확인하는 방법  => is 키워드를 이용
if foo is None: # foo 는 객체
    print("this object is None (Null)")
else:
    print( "this object is not None (Null)" )


# numpy summary

# numpy create array
np.array=[1,2,3,4]  # 모두 같은 정수형만 들어감

# numpy create 2 dimention array
x2 = np.random.randint(10, size=(3,4))  # 10 미만의 값이 들어가는 3x4 2차원 배열 생성