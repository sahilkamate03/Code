flag ="灩捯䍔䙻ㄶ形楴獟楮獴㌴摟潦弸彤㔲挶戹㍽"
print(flag.encode("utf-16-be"))
exit(0)
for i in range(0 , len(flag)):
    print(chr(ord(flag[i])>>8) ,end ='')
    print(chr(ord(flag[i]>>8) & 11111111) ,end ='')
