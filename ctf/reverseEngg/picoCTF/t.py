flag ="ioT{6bt_nt4_f8d269}"
for i in range(0, len(flag), 2):
	print(''.join(chr((ord(flag[i]) << 8) + ord(flag[i + 1])) ))