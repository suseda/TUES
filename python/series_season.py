def combine_series_data(seasons, series, ratings):
    d1 = {}
    d2 = {}
    z = 0
    list1 = []
    e = 0
    j = 0
    for i in series:
        d1[i] = ratings[z]
        list1.append(d1)
        z = z + 1
        d1 = {}
    
    res = len(seasons) - len(series)

    while e < res:
        list1.append(d1)
        e = e + 1 

    for x in seasons:
        d2[x] = list1[j]
        j = j + 1 

    return d2


print(combine_series_data( seasons = ['S001', 'S002', 'S003', 'S004'], series = ['The Mandalorian', 'Game Of Thrones', 'Chernobyl'], ratings = [8.7, 9.4, 9.4]))
