number = input('enter a number: ')
number_int=int(number)
if number_int % 5==0 and number_int % 11==0:
    print('yes')
else:
    print('no') 