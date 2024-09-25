def get_fibonacci_number(n): 
 a=1
 b=1
 i=2
 c=1
 while i<n:
     c=a+b
     a=b
     b=c
     i=i+1
 return c

print(get_fibonacci_number(20))
