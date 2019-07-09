import urllib.request
from bs4 import BeautifulSoup


def main():
    print("최신 뉴스 기사 href 수집")

    # href 수집할 사이트 주소 입력
    url = "https://news.nate.com/recent?mid=n0100"

    source_code = urllib.request.urlopen(url).read()
    soup = BeautifulSoup(source_code, "html.parser")

    # 1. a 태그가 있는 div 태그 및 class 찾기
    # 2. find("a")["href"]로 href 추출
    # 3. "//"로 시작하는 링크는 앞에 "http:"를 추가하여
    #    완전한 링크 만들기
    linkList = []
    for i in soup.find_all('div', class_='mlt01'):
        linkList.append('http:'+i.find('a')['href'])

    print(linkList)


if __name__ == "__main__":
    main()
