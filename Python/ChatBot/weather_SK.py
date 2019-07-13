#-*- coding:utf-8 -*-
import sys
import os
import requests
import geocde_SK as geo

API_KEY = "f6d517b4-d539-44d6-a1bd-9cb6ba3bbd78"
REQUEST_URL = "https://apis.openapi.sk.com/weather/current/hourly"

def get_weather_in_hour(text):

    STATUS_CODE, LAT ,LON = geo.get_location_in_text(text)

    if STATUS_CODE == 200:
        headers = {'Content-Type': 'application/json; charset=utf-8','appKey': API_KEY}
        params = {"version":1 ,"lat":LAT,"lon":LON}
        response = requests.get(REQUEST_URL, params=params, headers=headers)

        if response.status_code == 200:
            response_body = response.json()
            print("성공적으로 Weather 응답을 받았습니다.")

            tmp_list = response_body["weather"]["hourly"]
            ret = "*%s %s %s*의 날씨\n최저기온 : %s / 최고기온 : %s\n%s\n강수확률 %s %%" % (text[0], text[1], text[2], tmp_list[0]["temperature"]["tmin"], tmp_list[0]["temperature"]["tmax"],tmp_list[0]["sky"]["name"], tmp_list[0]["precipitation"]["sinceOntime"])
            print(ret)
            return ret
        else:
            pass
            print("Error code in get_Weather : "+str(response.status_code))
            return response.status_code