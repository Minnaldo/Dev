

# 파이썬에서 파일 불러오기
# 특 1) file.close()를 하지 않아도 된다.
with open('./text.txt') as file:
    print(file.read())

# 파이썬 ''로 시작하는 단어 찾기
# ''로 시작하면 True, 아니면 False
word = 'ssafy elice'
word.startswith('s')    # s로 시작하는지 판단

# sorted advanced
# pairs는 튜플로 구성된 리스트
pairs = [('time', 8),    ('the', 15),    ('turbo', 1) ]
sorted(pairs, key=lambda pair: pair[1])  # key는 예약어인듯
sorted(pairs, key=lambda pair: pair[1], reverse=True)  # 내림차순 정렬


# 파이썬 딕셔너리 dictionary
# dict[key] = value
# dict = (key,value) or [key, value] 로 저장 가능함
# 각 key에 대한 value 값은 서로 다른 자료형을 가진다

# json 을 사용하려면? json 라이브러리를 import 해야 한다
# Json -> dictionary : loads()  => as가 설정 안되어 있다면, json.loads()
# dictionary -> Json : dumps()  => as가 설정 안되어 있다면, json.dumps()

# 파이썬 set
# 집합을 나타내는 데이터 구조, 순서와 중복없이 없다


# 파이썬 csv
# import csv 필요
# reader = csv.reader(file, delimiter=',') 로 comma 단위로 파일을 읽어온다
# 반환은 리스트 타입


# 파이썬 람다함수의 자료구조화
# 람다함수를 변수에 할당한다
# map(변수(람다함수가 할당된), 사용할 변수)
reader = csv.reader(books, delimiter=',')
is_long = lambda row: True if int(row[3]) > 250 else False
get_title = lambda row: row[0]

# 파이썬 필터 filter
# filter(function, iterable)
# iterable 한 데이터를 특정 조건에 일치하는 값만 '추출' 해낼 때 사용하는 함수
long_books = filter(is_long, reader) # filter(조건 함수, 피연산자(데이터))

# 파이썬 맵 map, ==> long_books 조건에 맞는 책의 타이틀을 가져온다
# map (function_to_apply, list_of_inputs)
# list의 element에 함수를 적용시켜 결과를 반환받고 싶을 때 사용
map(get_title,long_books)