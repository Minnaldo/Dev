# -*- coding: utf-8 -*-
import re
import urllib.request

from bs4 import BeautifulSoup

from flask import Flask


SLACK_TOKEN = 'xoxb-678192724978-678367596163-D1vxSc3nPY8EdPgBKDGLcghI'
SLACK_SIGNING_SECRET = 'c0b3981ed401aa916ce6d3363f7077ee'


app = Flask(__name__)
# /listening 으로 슬랙 이벤트를 받습니다.
slack_events_adaptor = SlackEventAdapter(SLACK_SIGNING_SECRET, "/listening", app)
slack_web_client = WebClient(token=SLACK_TOKEN)


# 크롤링 함수 구현하기
def _crawl_music_chart(text):
    if not "music" in text:
        return "`@<봇이름> music` 과 같이 멘션해주세요."

    # 여기에 함수를 구현해봅시다.
    url = "https://music.bugs.co.kr/chart"
    source_code = urllib.request.urlopen(url).read()
    soup = BeautifulSoup(source_code, 'html.parser')

    message = []
    for ret in soup.find('tbody').find_all('tr'):
        rank = ret.find('strong').get_text()
        title = ret.find('p', class_='title').find('a').get_text()
        artist = ret.find('p', class_='artist').find('a').get_text()
        message.append(str(rank+"위 : "+title+" / "+artist))
    # 한글 지원을 위해 앞에 unicode u를 붙여준다
    return u'\n'.join(message)




# 챗봇이 멘션을 받았을 경우
@slack_events_adaptor.on("app_mention")
def app_mentioned(event_data):
    channel = event_data["event"]["channel"]
    text = event_data["event"]["text"]

    message = _crawl_music_chart(text)
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
