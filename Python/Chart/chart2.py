from matplotlib import pyplot as plt


def main():
    print("비교 차트 그리기")

    plt.xlabel("person")
    plt.ylabel("grade")

    # Python, 리스트로 들어갈 수 있다
    # 앞 쪽 리스트는 x축 값, 뒤 쪽 리스트는 y축 값
    plt.plot(['a', 'b', 'c', 'd', 'e'], [100, 97, 46, 28, 80])

    # Java
    plt.plot(['a', 'b', 'c', 'd', 'e'], [58, 28, 37, 83, 22])

    plt.savefig("image.svg", format="svg")


if __name__ == "__main__":
    main()
