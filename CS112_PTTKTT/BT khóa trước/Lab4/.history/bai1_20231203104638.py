n = int(input())
res = [""] * (2 * n)
available = [n, n]
TEMP = ["(", ")"]


def find(cur, res, available):
    # chon (, )
    for i in range(2):
        if available[i]:
            res[cur] = TEMP[i] 