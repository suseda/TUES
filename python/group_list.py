def group(l):
    new_list=[]
    for i in l:
        if new_list and new_list[-1][0]==i:
             new_list[-1].append(i)
        else:
             new_list.append([i])
    return new_list



print(group([1, 2, 1, 2, 3, 3]))