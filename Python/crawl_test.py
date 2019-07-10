import re
import urllib.request
from bs4 import BeautifulSoup

# 크롤링 함수 구현하기
def _crawl(text):
    # 여기에 함수를 구현해봅시다.
    # 1페이지 부터 20페이지 까지 "스파이더맨 : 파 프롬 홈" 의 네티즌 리뷰를 크롤링
    message=[]
    for i in range(1,21):
        url = "https://movie.naver.com/movie/bi/mi/pointWriteFormList.nhn?code=173123&type=after&isActualPointWriteExecute=false&isMileageSubscriptionAlready=false&isMileageSubscriptionReject=false&page=%d" %i
        source_code = urllib.request.urlopen(url).read()
        soup = BeautifulSoup(source_code, 'html.parser')

        for read in soup.find('div', class_='score_result').find_all('div', class_='score_reple'):
            message.append(read.find('p').get_text())

    return u'\n'.join(message)


print(_crawl("tag"))