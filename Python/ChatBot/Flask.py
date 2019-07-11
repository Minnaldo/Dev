import re
import urllib.request
import os
import sys
import n2mt_naver as translate

from bs4 import BeautifulSoup

from flask import Flask
from slack import WebClient
from slackeventsapi import SlackEventAdapter

SLACK_TOKEN = 'xoxb-678192724978-678367596163-2dxJiqkVhmvJ9LkEE9eH0inm'
SLACK_SIGNING_SECRET = '2fa722ab0f149a693bcded37e4f63155'

app = Flask(__name__)
# /listening 으로 슬랙 이벤트를 받습니다.
slack_events_adaptor = SlackEventAdapter(
    SLACK_SIGNING_SECRET, "/listening", app)
slack_web_client = WebClient(token=SLACK_TOKEN)

# def _crawl_naver_popular_keywords(text):
#     if not "" in text:
#         return "`@<봇이름> <번역할 문장>` 과 같이 멘션해주세요."

#     return u'\n'.join(keywords)


@slack_events_adaptor.on("app_mention")
def app_metioned(event_data):
    chan = event_data["event"]["channel"]
    inputs = event_data["event"]["text"]

    ret = translate.request_Translate(inputs)

    slack_web_client.chat_postMessage(
        channel=chan,
        text=ret
    )


@app.route('/', methods=["GET"])
def index():
    return "<h1>Server is ready.</h1>"


# @app.route('/elice_info')
# def hello_rabbit():
#     data = {'animal': 'white', 'charater': 'elice'}
#     return jsonify(data)    # dictionary값을 json 형식으로 변환하여 전송

# 잘못된 페이지 접근 시, 에러 메시지 출력
# 에러 핸들링 함수
@app.errorhandler(404)
def page_not_found(error):
    # 뒤의 404는 무엇? ==> 반환 값, 상대방에 알려주는 용도
    return '<h1>404 Error - Page Not Found</h1>', 404

# info 밑의 주소로 접근하면, 이를 변수로 받아 hello, var를 출력
# @app.route('/info/<var>')
# def hello_user(var):
#     return 'Hello, '+var+'!'


if __name__ == "__main__":
    sys.path.append("C:\\Users\\student\\Documents\\Dev\\Python\\ChatBot")
    app.run('127.0.0.1', port=5000, Threaded=True)
