def sum_min_max(my_list):
    maximum,minimum=0,0
    for i in range(0, len(my_list)): 
        my_list[i] = int(my_list[i]) 
        
    maximum=max(my_list)
    minimum=min(my_list)
    return maximum+minimum
    
    
print(sum_min_max([1,7,-5]))