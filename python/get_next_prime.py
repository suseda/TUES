def is_prime(n):  
 if n> 1:  
    for i in range(2,n):  
        if (n % i) == 0:  
            return (False)  
    else:  
        return (True)  
         
 else:  
    return (False)
  

def get_next_prime(N): 
    
    if (N <= 1): 
        return 2
  
    prime = N 
    found = False
  
    while(not found): 
        prime = prime + 1
  
        if(is_prime(prime) == True): 
            found = True
  
    return prime 



print(get_next_prime(13))