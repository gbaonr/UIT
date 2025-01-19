import math

EPS = 1e-6


def find(cur, need, res, heso):
    for i in [x * 0.25 for x in range(1, 41)]:
        res[cur] = i

        if cur == len(heso) - 1:
            total = 0
            for j, h in range(len(heso)):
                total += res[j] * heso[j] / 100

            total = round(total, 1)

            if abs(total - need) <= EPS:
                print(" ".join(map(str, ["%.3g" % v for v in res])))
        else:
            find(cur + 1, need, res, heso)


if __name__ == "__main__":
    n = int(input())
    heso = list(map(int, input().split()))
    need = float(input())
    res = [0] * n
    find(0, need, res, heso)
