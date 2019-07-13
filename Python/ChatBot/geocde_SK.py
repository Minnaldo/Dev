import sys
import os
import requests

API_KEY = "f6d517b4-d539-44d6-a1bd-9cb6ba3bbd78"
REQUEST_URL = "	https://apis.openapi.sk.com/tmap/geo/geocoding"  # POST 방식을 사용하고 싶다
VERSION = "1"
CITY_DO = ""
GU_GUN = ""
DONG = ""


def get_location_in_text(text):
    # loc_list = text.split(' ')
    CITY_DO = text[0]
    GU_GUN = text[1]
    DONG = text[2]

    headers = {'Content-Type': 'application/json; charset=utf-8',
               'appKey': API_KEY}
    param = {"version": VERSION, "city_do": CITY_DO,
             "gu_gun": GU_GUN, "dong": DONG}

    response = requests.get(REQUEST_URL, params=param, headers=headers)
    ret = ()

    if response.status_code == 200:
        response_body = response.json()
        print("성공적으로 GeoCode 응답을 받았습니다.")
        ret = (response.status_code, response_body["coordinateInfo"]["lat"],
               response_body["coordinateInfo"]["lon"])
        print("location--------------------")
        print(ret)
        print("location--------------------")

        return ret
    else:
        pass
        print("Error code get_Geocode : "+str(response.status_code))
        return response.status_code
