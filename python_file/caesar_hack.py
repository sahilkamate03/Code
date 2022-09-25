code=[]
print("This program is to hack caesar cipher encryption.")
print()
print("Enter the msg to decrypt")
msg=input("> ").upper()

for n in range(0,26):
    shift_number=n
    for i in msg:
    
        if ord(i)>64 and ord(i)-shift_number<65:
            extra=65-(ord(i)-shift_number)         
            code.append(chr(91-extra))
            # print(91-extra)
        elif 65<=ord(i)-shift_number<=90:
            code.append(chr(ord(i)-shift_number))
        else:
            code.append(i)
    print(f"#{n} {''.join(code)}")
    code.clear()
