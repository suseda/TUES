def num_arr(n):
    l=[]
    while n>0:
        l.append(n%10)
        n=n//10
    return list(reversed(l))


def int_palindrome(n):
    num=num_arr(n)
    for i in range(0,len(num)//2):
        if num[i]!=num[len(num)-i-1]:
            return False
    return True        
    
    
print(int_palindrome(1421))






def is_int_palindrome(n):
    n_as_string = str(n)
    return n_as_string == n_as_string[::-1]

print(is_int_palindrome(1))
print(is_int_palindrome(42))
print(is_int_palindrome(100001))
print(is_int_palindrome(999))
print(is_int_palindrome(123))