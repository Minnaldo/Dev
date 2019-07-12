import os
import sys
import requests

import n2mt_Naver as translate
import weather_SK as weather
import geocde_SK

from bs4 import BeautifulSoup

from flask import Flask
from slack import WebClient
from slackeventsapi import SlackEventAdapter

from threading import Thread

SLACK_TOKEN = 'xoxb-678192724978-678367596163-OvPi5QKe5SDE6DlK4VPe46wx'
SLACK_SIGNING_SECRET = '2fa722ab0f149a693bcded37e4f63155'

app = Flask(__name__)
# /listening 으로 슬랙 이벤트를 받습니다.
slack_events_adaptor = SlackEventAdapter(
    SLACK_SIGNING_SECRET, "/listening", app)
slack_web_client = WebClient(token=SLACK_TOKEN)


@slack_events_adaptor.on("member_joined_channel")
def member_joined_channel(event_data):
    user = event_data["event"]["user"]
    string = user + " has joined.\n도움이 필요하시면 `@<봇이름> help` 와 같이 멘션해주세요"
    Thread(target=post_message, args=(chan, string)).start()


# 멘션한 요청을 받는다
@slack_events_adaptor.on("app_mention")
def app_metioned(event_data):
    chan = event_data["event"]["channel"]
    inputs = event_data["event"]["text"]
    ''' n2ml : call the papago translate
        weather_SK : get weather
    '''
    string = inputs.split(' ')
    del string[0]
    op_code = string[0]
    del string[0]
    # 날씨
    if op_code == "1":
        print("날씨!!!!!!!!!!!!")
        ret = weather.get_weather_in_hour(string)
        print("날씨 결과 \n\n " + ret)
        Thread(target=post_message, args=(chan, ret)).start()
        # 번역
    elif op_code == "2":
        print("번역!!!!!!!!!!!!")
        ret = translate._translate(string)
        print("번역 결과 : " + ret)
        Thread(target=post_message, args=(chan, ret)).start()

    elif op_code == "3":
        ret = ""
    else:
        print("Error Occured")

def post_message(chan, key):
    slack_web_client.chat_postMessage(
        channel=chan,
        text=key
    )


@app.route('/', methods=["GET"])
def index():
    return "<h1>Server is ready.</h1>"

# 잘못된 페이지 접근 시, 에러 메시지 출력
# 에러 핸들링 함수
@app.errorhandler(404)
def page_not_found(error):
    # 뒤의 404는 무엇? ==> 반환 값, 상대방에 알려주는 용도
    return '<h1>404 Error - Page Not Found</h1>', 404


if __name__ == "__main__":
    sys.path.append("C:\\Users\\student\\Documents\\Dev\\Python\\ChatBot")
    app.run('127.0.0.1', port=5000)
