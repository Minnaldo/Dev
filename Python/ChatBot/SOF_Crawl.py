from bs4 import BeautifulSoup
import urllib.request


def crawl_sof(url):
    source_code = urllib.request.urlopen(url).read()
    soup = BeautifulSoup(source_code, 'html.parser')
    ret_ans=[]
    print(soup.find_all('div', class_='summary'))
    # for ret in soup.find_all('div', class_='question-summary search-result'):
    #     new_link = ret.find(
    #         'div', class_='question-summary search-result').find('div', class_='reuslt-link')
    #     sub_url = 'https://stackoverflow.com'+new_link.get('href')

    #     code = urllib.request.urlopen(sub_url).read()
    #     soup2 = BeautifulSoup(code, 'html.parser')
    #     ans = soup2.find(id='answers')
    #     head = soup2.find('div', class_='inner-content clearfix').find('h1',class_='grid--cell fs-headline1 fl1 ow-break-word').get_text()
    #     ret_ans.append(head)
    #     for aa in ans.find_all('div', class_='post-text'):
    #         ret_ans.append(aa.get_text())

print(crawl_sof('https://stackoverflow.com/search?q=how+to+convert+in+python'))