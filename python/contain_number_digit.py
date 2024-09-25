def contain_number_digit(num,digit):
 while num>0:
  v=num%10
  num=num//10 
  if v==digit:
      return True
 return False

print(contain_number_digit(1234,3))



def contains_digit(number, digit):
    num = str(number)
    if str(digit) in num:
        return True
    return False
     
print(contains_digit(12346789, 5))




def contains_digit(number, digit):
    number_as_string = str(number)
    digit_as_string = str(digit)
    return digit_as_string in number_as_string

print(contains_digit(123, 4))
print(contains_digit(42, 2))
print(contains_digit(1000, 0))
print(contains_digit(12346789, 5))