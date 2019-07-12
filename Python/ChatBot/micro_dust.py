import urllib.request
import requests
from bs4 import BeautifulSoup

REQUEST_URL = "http://openapi.airkorea.or.kr/openapi/services/rest/ArpltnInforInqireSvc/getMsrstnAcctoRltmMesureDnsty"
SERVICE_KEY = "UnxJ09m406DZCLwoKlvEaPlPeXUTApPaRiWPxtWSswBz9sRda6mK9TJOF2lNEv5XxR4Xjtk%2Bhe5q9IFesyEZOQ%3D%3D"    #
STATION_NAME = "종로구"   # ex) 종로구
DATATERM = "daily"    # ex) daily : 요청 데이터 기간
VERSION = "1.3"  # ex) PM10 , PM25, 1시간 등급 자료가 포함된 결과 표출

# request_url = "http://openapi.airkorea.or.kr/openapi/services/rest/ArpltnInforInqireSvc/getMsrstnAcctoRltmMesureDnsty?stationName=" + \
#     STATION_NAME+"&dataTerm="+DATATERM + \
#     "&pageNo=1&numOfRows=10&ServiceKey="+SERVICE_KEY+"&ver=1.3"


def get_dust_data():
    headers = headers = {'Content-Type': 'application/json; charset=utf-8'}
    param = {'stationName': STATION_NAME, 'dataTerm': DATATERM, 'ver' : VERSION, 'numOfRows' : 5, 'ServiceKey' : SERVICE_KEY}
    req = requests.get(REQUEST_URL, params=param, headers=headers)

    if req.status_code == 200:
        response_body = req.json()
        print(response_body)
        print("성공적으로 요청을 받았습니다")
        return response_body
    else:
        print(req.status_code)
        return req.status_code


print(get_dust_data())