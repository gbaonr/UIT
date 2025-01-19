n = int(input("Nhap n: "))
sum = 0
for i in range(1, n+1):
    for j in range(1, i*i+1):
        sum+=1
print("sum = ", sum)
hehe =2*n*n*n + 3*n*n + n
hehe /= 6
print("hehe = ", hehe)