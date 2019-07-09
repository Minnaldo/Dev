import urllib.request
from bs4 import BeautifulSoup


def main():
    list_pagination = []

    for i in range(0, 5):
        url = 'http://sports.donga.com/Enter?p=%d1&c=02' % i
        source_code = urllib.request.urlopen(url).read()
        soup = BeautifulSoup(source_code, "html.parser")

        for i in soup.find_all('span', class_='tit'):
            list_pagination.append(i.get_text().strip())

    print(list_pagination)


if __name__ == "__main__":
    main()
