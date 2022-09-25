code=[]
def encrypt_data(msg):
    
    for i in msg:
        if ord(i)+shift_number>90:
            extra=ord(i)+shift_number-90
            code.append(chr(64+extra)) 

        elif 65<=ord(i)+shift_number<=90:
            code.append(chr(ord(i)+shift_number))

        else:
            code.append(i)
    return ''.join(code)

def decrypt_data(msg):
    for i in msg:
        
        if ord(i)>64 and ord(i)-shift_number<65:
            extra=65-(ord(i)-shift_number)         
            code.append(chr(91-extra))
            print(91-extra)
        elif 65<=ord(i)-shift_number<=90:
            code.append(chr(ord(i)-shift_number))
        else:
            code.append(i)
    return ''.join(code)

print('Caesar Cipher.')
print('This program is used to encrypt and decrypt code.')
print()
while True:
    feed=input("Do you want to (e)ncrypt or (d)ecrypt data or (ex)it: ").lower()
    print("Please enter the key (0 to 25) to use.")
    shift_number=int(input("> "))
    if feed.startswith("d"):
        print("Enter the msg to derypt.")
        msg=input("> ").upper()
        print(decrypt_data(msg))
        print()
    elif feed.startswith("e"):
        print("Enter the msg to encrypt.")
        msg=input("> ").upper()
        print(encrypt_data(msg))
        print()
    else:
        break