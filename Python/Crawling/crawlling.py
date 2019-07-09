import urllib.request
from bs4 import BeautifulSoup

"""
* 네이버 인기검색어 크롤링
"""

def main():

    # URL 데이터를 가져올 사이트 url 입력
    url = "http://www.naver.com"

    # URL 주소에 있는 HTML 코드를 soup에 저장합니다.
    source_code = urllib.request.urlopen(url).read()
    soup = BeautifulSoup(source_code, "html.parser")

    list = []

    for naver_text in soup.find_all('span', class_="ah_k"): # span태그 중, ah_k를 갖는 클래스를 찾는다
        if naver_text.get_text() not in list:   # not in --> 리스트에 해당 요소가 없을 때
            list.append(naver_text.get_text())

    print(list)


if __name__ == "__main__":
    main()
