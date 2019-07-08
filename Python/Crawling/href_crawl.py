import urllib.request
from bs4 import BeautifulSoup


def main():
    print("href 출력해보기")

    list_href = []

    url = "http://sports.donga.com/Enter"
    source_code = urllib.request.urlopen(url).read()
    soup = BeautifulSoup(source_code, "html.parser")

    # 반복문을 사용해 원하는 정보 range(3,23)까지 find("a")["href"] 를 사용해서
    # href 모두 수집하여 list_href에 저장

    for i in range(3, 23):
        link = soup.find_all('a')[i]['href']    # 하이퍼 링크 값을 가져온다
        if link != '#':
            # url주소에서 a 태그 중, i번째의 하이퍼링크를 모두 가져온다
            list_href.append(link)

    print(list_href)


if __name__ == "__main__":
    main()
