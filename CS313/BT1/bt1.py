ds = []
nhap = input("Nhap vat pham can mua:")
while nhap != "xong":
    ds.append(nhap)
    nhap = input("Nhap vat pham can mua:")

print(f"Danh sach cac vat pham can mua: {ds}")
