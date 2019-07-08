import urllib.request
from bs4 import BeautifulSoup



def main():
    print("영화 리뷰")

    # 리뷰를 수집할 사이트 주소 입력
    url = "https://movie.naver.com/movie/bi/mi/review.nhn?code=168058#"


    # URL 주소에 있는 HTML 코드를 soup에 저장합니다.
    source_code = urllib.request.urlopen(url).read()
    soup = BeautifulSoup(source_code, "html.parser")

    # 1. 리뷰가 있는 있는 ul 태그 찾기
    # 2. ul 안에 있는 모든 li 태그 찾기
    # 3. li 태그 안에 있는 strong 태그에서 get_text()로 텍스트 추출
    rv_title=[]
    for i in soup.find('ul', class_='rvw_list_area' ).find_all('li'):
        rv_title.append(i.find('strong').get_text())

    print(rv_title)

if __name__ == "__main__":
    main()
