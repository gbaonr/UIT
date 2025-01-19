EPS = 1e-6
NUMS = [0.25 * i for i in range(1, 41)]


def find(cur):
    for num in NUMS: 
        res[cur] = i

        if cur == len(heso) - 1:
            total = 0
            for j, h in enumerate(heso):
                total += res[j] * h / 100

            total = round(total, 1)

            if abs(total - need) <= EPS:
                print(" ".join(map(str, ["%.3g" % v for v in res])))
        else:
            find(cur + 1)


n = int(input())
heso = list(map(int, input().split()))
need = float(input())
res = [0] * n
find(0)
