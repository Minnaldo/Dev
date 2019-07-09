import numpy as np  # 계산 모듈
import matplotlib.pyplot as plt # 차트 모듈
7

def main():
    print("----산포도1----")

    x = np.arange(0, 100)
    y = np.arange(0, 100)
    plt.plot(x, y, "o")     #plt.plot(x, y, "k"), 마지막 파라미터는 점의 모양?

    print("----산포도2----")

    line = plt.figure()

    np.random.seed(5)   # 시드값 가지는 랜덤
    x = np.arange(1, 101)
    y = 20 + 3 * x + np.random.normal(0, 40, 100)   # normal은 정규분포
    plt.plot(x, y, "o")
    plt.show()

    print("----파이차트----")

    slices_hours = [12.5, 25.0, 62.5]   # 퍼센티지를 적는다
    activities = ["Sleep", "Work", "Nothing"]   # 퍼센티지에 할당되는 라벨
    color = ["gray", "blue", "red"] # 순서를 맞춘다

    # 파이차트를 그린다
    plt.pie(slices_hours, labels=activities, colors=color, startangle=90, autopct='%.1f%%')

    plt.savefig("image.svg", format="svg")


if __name__ == "__main__":
    main()