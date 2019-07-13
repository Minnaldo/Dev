import os
import sys
import json
import urllib.request
import requests

CLIENT_ID = "7CgS6IlL1B7S5VyOlHcp"  # 개발자센터에서 발급받은 Client ID 값
CLIENT_SECRET = "kcjLGp_xot"  # 개발자센터에서 발급받은 Client Secret 값
REQUEST_URL = "https://openapi.naver.com/v1/papago/n2mt"

source = ""
target = ""
text = "반갑습니다"


def _translate(text, src='ko',target='en'):

    text = ''.join(text)

    # print("korean is ")
    # print(korean)
    # params = {"source":"ko", "target":"en", "text":korean}
    # headers = {'Content-Type': 'application/json; charset=utf-8',"X-Naver-Client-Id": CLIENT_ID, "X-Naver-Client-Secret":CLIENT_SECRET}

    response = requests.post(REQUEST_URL, data={"source":src, "target":target, "text":text}, headers={"X-Naver-Client-Id": CLIENT_ID, "X-Naver-Client-Secret":CLIENT_SECRET})

    if response.status_code == 200:
        response_body = response.json()
        translated = response_body["message"]["result"]["translatedText"]
        return translated
    else:
        print("Error Code : "+str(response.status_code) )
        return response.status_code
