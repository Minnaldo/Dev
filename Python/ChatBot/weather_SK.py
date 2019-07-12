#-*- coding:utf-8 -*-
import sys
import requests
import getcoding_sk as geo
​

API_KEY = "f6d517b4-d539-44d6-a1bd-9cb6ba3bbd78"
REQUEST_URL = "https://apis.openapi.sk.com/weather/current/hourly"

# 현재 날씨(시간별)
url_hourly = url_weather+'current/hourly'
# 현재 날씨(분별)
url_minutely = url_weather+'current/minutely'
# 간편 날씨 (어제, 오늘, 내일, 모레)
url_summary = url_weather+'summary'

def get_weather_in_hour(text):

    STATUS_CODE, LAT ,LON = geo.get_location_in_text(text)

    if STATUS_CODE == 200:
        headers = {'Content-Type': 'application/json; charset=utf-8','appKey': API_KEY}
        params = {"version":1 ,"lat":LAT,"lon":LON}
        response = requests.get(REQUEST_URL, params=param, headers=headers)

        if response.status_code == 200:
            response_body = response.json()
            print("성공적으로 Weather 응답을 받았습니다.")
            ret = (response.status_code, response_body["coordinateInfo"]["lat"],response_body["coordinateInfo"]["lon"])
            return ret
        else:
            pass
            print("Error code in get_Weather : "+str(response.status_code))
            return response.status_code