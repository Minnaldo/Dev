import urllib.request
from bs4 import BeautifulSoup


def main():
    # URL 데이터를 가져올 사이트 url 입력
    url = "https://himchanyoon1992.tistory.com/1"

    # URL 에 있는 HTML 코드를 soup에 저장합니다.
    source_code = urllib.request.urlopen(url).read()
    soup = BeautifulSoup(source_code, "html.parser")

    comments = []

    # 댓글 부분을 찾아서 list에 하나씩 댓글을 삽입합니다.
    for comment in soup.find('div', class_='area_reply').find('ul', class_='list_reply').find_all('li'):
        comments.append(comment.find('span', class_='txt_reply').get_text())

    # list를 출력합니다.
    print(comments)


if __name__ == "__main__":
    main()
