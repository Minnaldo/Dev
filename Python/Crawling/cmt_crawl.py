import urllib.request
from bs4 import BeautifulSoup


def main():
    print("커뮤니티 댓글")

    # 댓글를 수집할 사이트 주소 입력
    url = "https://pann.nate.com/talk/344083297"

    # URL 주소에 있는 HTML 코드를 soup에 저장합니다.
    source_code = urllib.request.urlopen(url).read()
    soup = BeautifulSoup(source_code, "html.parser")

    # 1. 댓글이 있는 태크 dd 찾기
    # 2. class_="usertxt class 찾기"
    # for 반복문과 get_text()를 사용해서 출력

    cmt_list = []
    for i in soup.find_all('dd', class_='usertxt'):
        cmt_list.append(i.get_text().strip())

    print(cmt_list)


if __name__ == "__main__":
    main()
