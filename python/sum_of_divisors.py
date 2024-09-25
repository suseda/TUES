def sum_of_divisors(num):
    res=0
    for i in range(1,num+1):
        if num%i==0:
            res=res+i
    return res


print(sum_of_divisors(1000))