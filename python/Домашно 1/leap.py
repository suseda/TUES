number = input('enter a number: ')
number_int=int(number)
if number_int % 4==0 and not number_int % 100==0 or number_int % 400==0 :
    print('leap')
else:
    print('not leap') 