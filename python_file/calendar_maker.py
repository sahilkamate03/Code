import datetime

DAYS=['SUNDAY','MONDAY','TUESDAY','WEDNESDAY','THURSDAY','FRIDAY','SATURDAY']
MONTHS=['JANUARY','FEBRUARY','MARCH','APRIL','MAY','JUNE','JULY','AUGUST','SEPTEMBER','OCTOBER','NOVEMBER','DECEMBER']

while True:
    print('Enter the Year')
    response = input('> ')

    if response.isdecimal() and int(response)>0:
        year =int(response)
        break

    print('Please enter correct input')

while True:
    print('Enter the Month')
    response = input('> ')

    if not response.isdecimal():
        print ('Please enter numeric month')
        continue
    
    month= int (response)
    print(month)
    if 1<=int(response)<=12:
        break
    print('please enter month between 1 t 12')

def getCal(month,year):
    calText=''
    calText += (' '*34) + MONTHS[month-1] +' '+ str(year) + '\n'
    calText +='...Sunday....Monday.....Tuesday.....Wednesday.....Thursday.....Friday.....Saturday...\n'
    weekseperator='+-----------'*7 + '+\n'
    emptyspace= '|           '*7+'|\n'

    current_date=datetime.date(year,month,1)

    while (current_date.weekday() !=6):
        current_date-=datetime.timedelta(days=1)
    
    while True:
        calText+=weekseperator
        dayrow=''
        for i in range(7):
            daynumber = str(current_date.day).rjust(2)
            # print(daynumber)
            dayrow+='|'+daynumber+(' '*9)
            current_date+=datetime.timedelta(days=1)
        dayrow+='|\n'
        calText+=dayrow
        for i in range(3):
            calText+=emptyspace

        if current_date.month !=month:
            break
    
    calText+=weekseperator
    print(calText)

getCal(month,year)