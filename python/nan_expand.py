def nan_expand(num):
    if num > 0 :
        n="NaN"
        for num in range(0,num):
            l="Not a "
            n= l + n
        return n
    else:
        return ""


print(nan_expand(0))