import urllib.request
from bs4 import BeautifulSoup


def main():

    comments = []

    # 댓글을 가져와야 하는 URL 3개를 반복문을 이용해서 한꺼번에 가져오기
    # url = "https://himchanyoon1992.tistory.com/2"
    # url = "https://himchanyoon1992.tistory.com/3"
    # url = "https://himchanyoon1992.tistory.com/4"

    for i in range(2, 5):
        url = 'https://himchanyoon1992.tistory.com/%d' % i
        source_code = urllib.request.urlopen(url).read()
        soup = BeautifulSoup(source_code, "html.parser")

        # find 와 find_all의 차이? 어쩔땐 attribute 오류, 어떨 땐 가능
        for comment in soup.find('ul', class_='list_reply').find_all('li'):
            comments.append(comment.find(
                'span', class_='txt_reply').get_text())

    print(comments)

    # 결과물
    # ['1번 페이지 댓글 1', '1번 페이지 댓글 2', '1번 페이지 댓글 3', '2번 페이지 댓글 1', '2번 페이지 댓글 2', '2번 페이지 댓글 3', '3번 페이지 댓글 1', '3번 페이지 댓글 2', '3번 페이지 댓글 3']


if __name__ == "__main__":
    main()
