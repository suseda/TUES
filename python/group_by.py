def group_by(rule,items):
    d1={ 'positive': [], 'negative': [], 'neutral': [] }
    d2={ 'odd': [], 'even': [] }
    if rule == 'sign':
        for i in items:
            if int(i)>0:
                d1['positive'].append(i)
            elif int(i)<0:
                d1['negative'].append(i)
            else:
                d1['neutral'].append(i)
        return d1
    else:
        for i in items:
            if int(i)%2==0:
                d2['even'].append(i)
            else:
                d2['odd'].append(i)
        return d2

print(group_by('sign',[1, 2, 3, -4, -5, 6, -7, 8, 9, 0]))
print(group_by('parity', [1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0]))
print(group_by('parity', [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]))
print(group_by('sign', [1, 2, 3, -4, -4, -5, 6, -7, 8, 9, 0, 0]))