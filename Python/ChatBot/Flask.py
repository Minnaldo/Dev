import re
import urllib.request

from bs4 import BeautifulSoup

from flask import Flask, request, make_response, jsonify
from slack import WebClient
from slackeventsapi import SlackEventAdapter

app = Flask(__name__)

slack_token = "xoxb-678192724978-689616635552-LSB6ZJ0MITmS7LP5ivthZcRU"
slack_client_id = "678192724978.691457971239"
slack_singing_secret = "b3fe7746f46bfd67689fb908b5f28c3b"
slack_verification = "UwmnnjZMtbPYm5Rx1maoYCp9"

# /listening 으로 슬랙 이벤트를 받는다.
slack_events_adaptor = SlackEventAdapter(slack_singing_secret, "/listening", app)
slack_web_client = WebClient(token=slack_token)

# 네이버 크롤링 함수
def _crawl_naver_popular_keywords(text):
    url = re.search(r'(https?://\S+)', text.split('|')[0]).group(0)
    req = urllib.request.Request(url)
    sourcecode = urllib.request.urlopen(url).read()
    soup = BeautifulSoup(sourcecode, "html.parser")
    keywords = []
    for i, keyword in enumerate(soup.find_all("span", class_="ah_k")):
        if i < 20:
            # 한글 지원을 위해 앞에 unicode u를 붙혀준다.
            keywords.append(keyword.get_text())
    return u'\n'.join(keywords)


@slack_events_adaptor.on("app_metion")
def app_metioned(event_data):
    slack_web_client.chat_postMessage(
        channel=event_data["event"]["channel"],
        text="Hello, I am your chatbot!"
    )


@app.route('/', methods=["GET"])
def index():
    return "<h1>Server is ready.</h1>"


@app.route('/elice_info')
def hello_rabbit():
    data = {'animal': 'white', 'charater': 'elice'}
    return jsonify(data)    # dictionary값을 json 형식으로 변환하여 전송

# 잘못된 페이지 접근 시, 에러 메시지 출력
# 에러 핸들링 함수
@app.errorhandler(404)
def page_not_found(error):
    # 뒤의 404는 무엇? ==> 반환 값, 상대방에 알려주는 용도
    return '<h1>404 Error - Page Not Found</h1>', 404

# info 밑의 주소로 접근하면, 이를 변수로 받아 hello, var를 출력
@app.route('/info/<var>')
def hello_user(var):
    return 'Hello, '+var+'!'


if __name__ == "__main__":
    app.run('127.0.0.1', port=8080)
