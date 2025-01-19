n = int(input())
res = [""] * (2 * n)
available = [n, n]
TEMP = ["(", ")"]


def check(res):
    t = []

    for x in res:
        if x == "(":
            t.append(x)
        else:
            if len(t) == 0:
                return False

            t.pop()

    return len(t) == 0


def find(cur):
    # chon (, )
    for i in range(2):
        if available[i]:
            res[cur] = TEMP[i]
            available[i] -= 1

            if cur == 2 * n - 1:
                if check(res):
                    print("".join(res))
            else:
                find(cur + 1)

            available[i] += 1