import pyautogui, time
time.sleep(5)
f=open("text.txt","r")
print('successful')

while True:
  for w in f:
    pyautogui.typewrite(w)
    pyautogui.press("enter")
    print(w)
    if w=='pls fish':
        time.sleep(45)


    
