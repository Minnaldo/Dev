# -*- coding: utf-8 -*-
import re
import urllib.request

from bs4 import BeautifulSoup

from flask import Flask
from slack import WebClient
from slackeventsapi import SlackEventAdapter


SLACK_TOKEN = 'xoxb-678192724978-678367596163-D1vxSc3nPY8EdPgBKDGLcghI'
SLACK_SIGNING_SECRET = 'c0b3981ed401aa916ce6d3363f7077ee'

app = Flask(__name__)
# /listening 으로 슬랙 이벤트를 받습니다.
slack_events_adaptor = SlackEventAdapter(SLACK_SIGNING_SECRET, "/listening", app)
slack_web_client = WebClient(token=SLACK_TOKEN)


# 크롤링 함수 구현하기
def _crawl(text):
    # 여기에 함수를 구현해봅시다.
    # 1페이지 부터 20페이지 까지 "스파이더맨 : 파 프롬 홈" 의 네티즌 리뷰를 크롤링
    message=[]
    for i in range(1,21):
        url = "https://movie.naver.com/movie/bi/mi/pointWriteFormList.nhn?code=173123&type=after&isActualPointWriteExecute=false&isMileageSubscriptionAlready=false&isMileageSubscriptionReject=false&page=%d" %i
        source_code = urllib.request.urlopen(url).read()
        soup = BeautifulSoup(source_code, 'html.parser')

        for read in soup.find('div', class_='score_result').find_all('div', class_='score_reple'):
            message.append(read.find('p').get_text())

    return u'\n'.join(message)


# 챗봇이 멘션을 받았을 경우
@slack_events_adaptor.on("app_mention")
def app_mentioned(event_data):
    channel = event_data["event"]["channel"]
    text = event_data["event"]["text"]

    message = _crawl(text)
    slack_web_client.chat_postMessage(
        channel=channel,
        text=message
    )


# / 로 접속하면 서버가 준비되었다고 알려줍니다.
@app.route("/", methods=["GET"])
def index():
    return "<h1>Server is ready.</h1>"


if __name__ == '__main__':
    app.run('0.0.0.0', port=8080)
