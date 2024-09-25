def max_consecutive(l):
	if len(l) == 0:
		return 0
		
	res = 0
	current_longest = 1
	current = l[0]
	for e in l:
		if e == current:
		    current_longest += 1
		else:
		    if current_longest > res:
		        res = current_longest
		        
		    current = e
		    current_longest = 1
		    
	return res

print(max_consecutive([1, 2, 3, 3, 3, 3, 4, 3, 3]))