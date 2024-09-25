
def move(path, name, l):
    if l == 0:
        return name
    
    a = []
    a.append(move(path, name, l-1))

    res = {}
    res[path[-l]] = a

    return res

path = ['nothing', 'to', 'see']
name = 'dont_open.mp4'
print(move(path, name, len(path)))