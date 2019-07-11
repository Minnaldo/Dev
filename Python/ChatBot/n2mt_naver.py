import os
import sys
import json
import urllib.request

client_id = "7CgS6IlL1B7S5VyOlHcp"  # 개발자센터에서 발급받은 Client ID 값
client_secret = "kcjLGp_xot"  # 개발자센터에서 발급받은 Client Secret 값

source = ""
target = ""
text = "반갑습니다"


def request_Translate(text):
    encText = urllib.parse.quote(text)
    data = "source=ko&target=en&text=" + encText
    url = "https://openapi.naver.com/v1/papago/n2mt"

    request = urllib.request.Request(url)
    request.add_header("X-Naver-Client-Id", client_id)
    request.add_header("X-Naver-Client-Secret", client_secret)
    response = urllib.request.urlopen(request, data=data.encode("utf-8"))
    rescode = response.getcode()

    if(rescode == 200):
        response_body = response.read()
        ret = response_body.decode('utf-8')  # @param : ret is dictionary
        dic = json.loads(ret)
        translated = dic["message"]["result"]["translatedText"]
        return translated
    else:
        return "Error Code:" + str(rescode)
