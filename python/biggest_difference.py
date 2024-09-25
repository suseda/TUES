def biggest_difference(arr):
    res = 0
    for outer_i in range(0, len(arr) - 1): 
        for inner_i in range(outer_i + 1, len(arr)):
            diff = min(arr[outer_i] - arr[inner_i], arr[inner_i] - arr[outer_i])
            if diff < res:
                res = diff

    return res

print(biggest_difference([1, 2]))
print(biggest_difference([1, 2, 3, 4, 5]))
print(biggest_difference([-10, -9, -1]))
print(biggest_difference(range(100)))
        