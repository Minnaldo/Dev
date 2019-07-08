import urllib.request
from bs4 import BeautifulSoup


def main():
    list_href = []
    list_content = []

    url = "https://news.sbs.co.kr/news/newsflash.do?plink=GNB&cooper=SBSNEWS"
    source_code = urllib.request.urlopen(url).read()
    soup = BeautifulSoup(source_code, "html.parser")

    for href in soup.find_all('div', class_='mfn_inner'):
        list_href.append('https://news.sbs.co.kr'+href.find('a')['href'])

    for i in range(0, len(list_href)):
        url = list_href[i]  # 찾아온 하이퍼 링크 수만큼 돌며, 하이퍼링크를 url변수에 할당
        source_code = urllib.request.urlopen(url).read()
        soup = BeautifulSoup(source_code, "html.parser")

        list_content.append(soup.find('div', class_='text_area').get_text())

    print(list_href)
    print(list_content)


if __name__ == "__main__":
    main()
