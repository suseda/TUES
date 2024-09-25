def  list_to_dict(l):
 new_dict={}
 lenght=len(l)
 while lenght>0:
     i=l[0]
     n=i
     new_list=[]
     while n>0:
        new_list.append(l[n])
        del l[n]
        new_dict[i]=new_list
        n=n-1
     del l[n]
     lenght=lenght-i-1
 return new_dict


print( list_to_dict([2, 'a', 'b', 3, 'a', 'b', 'c']))