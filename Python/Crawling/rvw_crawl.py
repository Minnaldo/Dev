rv_title=[]
    for i in soup.find('ul', class_='rvw_list_area' ).find_all('li'):   # ul 태그 rvw_lsit_area이름을 갖는 클래스를 찾아, 그에 속한 모든 li태그를 수집
        rv_title.append(i.find('strong').get_text())    # rv_title 리스트에, 위에서 찾은 li 태그 내의 strong 태그를 찾아, 문자를 가져옴