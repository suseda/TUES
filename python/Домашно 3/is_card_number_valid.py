def is_card_number_valid(number):
	tmp = [int(x) for x in number]	

	for i in range(len(tmp) - 2, -1, -2):
		tmp[i] *= 2

		if tmp[i] > 9:
			tmp[i] -= 9
		
	return sum(tmp) % 10 == 0

print(is_card_number_valid('4916734313471210'))