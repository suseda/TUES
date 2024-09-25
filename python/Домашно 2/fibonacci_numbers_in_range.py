def get_fibonacci_numbers_in_range(low, high):
 my_list=[]
 a,b,i,c=0,1,2,0
 while c<low:
     c=a+b
     a=b
     b=c
     i=i+1
 my_list.append(str(c))
 for c in range(low,high+1):
     c=a+b
     a=b
     b=c       
     if c<high+1:
         my_list.append(str(c))
         x = ",".join(my_list)
 return x

print (get_fibonacci_numbers_in_range(13,55))


      
      
 