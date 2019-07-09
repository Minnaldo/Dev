import matplotlib.pyplot as plt # 차트 모듈
import numpy as np


def main():
    x = [1,2,3,4,5,6,7,8,9]
    y = [1,2,3,4,5,6,7,8,9]

    plt.plot(x, y)  # 리스트를 받아서 출력을 한다
    plt.xlabel('x_axis')    # x축 라벨
    plt.ylabel('y_axis')    # y축 라벨
    plt.title('sample_chart')   # 그래프 제목

    plt.savefig("image.svg", formate="svg") # svg 이미지로 저장

if __name__ == "__main__":
    main()