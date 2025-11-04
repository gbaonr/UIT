num = int(input("Enter a number: "))
i = 2
while i < num:
    if num % i == 0:
        print(f"Num chia het cho {i}")
        print(" --> Khong phai so nguyen to")
        break
    i += 1

if i == num:
    print(" --> La so nguyen to")
