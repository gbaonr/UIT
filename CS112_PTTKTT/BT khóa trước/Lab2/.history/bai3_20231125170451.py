EPS = 1e-6
NUMS = [0.25 * i for i in range(1, 41)]


def find(cur):
    global total

    for num in NUMS:
        res[cur] = num
        total += num * heso[cur] / 100
        round_total = round(total + EPS, 1)

        if round_total <= need:
            if cur == len(heso) - 1:
                if total == need:
                    print(" ".join(map(str, ["%.3g" % v for v in res])))
            else:
                find(cur + 1)

        total -= num * heso[cur] / 100


n = int(input())

heso = []
for i in range(n):
    x = int(input())
    heso.append(x)

need = float(input())
res = [0] * n
total = 0

find(0)
