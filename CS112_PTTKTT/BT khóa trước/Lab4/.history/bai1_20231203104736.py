n = int(input())
res = [""] * (2 * n)
available = [n, n]
TEMP = ["(", ")"]


def check(res):
    pass


def find(cur, res, available):
    # chon (, )
    for i in range(2):
        if available[i]:
            res[cur] = TEMP[i]
            available[i] -= 1

            if cur == 2 * n - 1:
                if check(res):
                    print("".join(res))
            else:
                find(cur + 1, res, available)

            available[i] += 1


