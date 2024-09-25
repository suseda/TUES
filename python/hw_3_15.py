
#Решението на задача 1

def get_card_network(card_number):
    l=len(card_number)
    if card_number[0]=='4' and (l==13 or l==16 or l==19):
        return 'Visa'
    elif l==16 and card_number[0]=='5' and (card_number[1]=='1' or card_number[1]=='2' or card_number[1]=='3' or card_number[1]=='4' or card_number[1]=='5'):
        return 'Mastercard'
    elif (l==16 or l==17 or l==18 or l==19) and card_number[0]=='6':
        return 'Discover'
    else:      
        return 'Unknown'

print(get_card_network('4011531243068077'))


#Решението на задача 2


def is_card_number_valid(number):
	tmp = [int(x) for x in number]	

	for i in range(len(tmp) - 2, -1, -2):
		tmp[i] *= 2

		if tmp[i] > 9:
			tmp[i] -= 9
		
	return sum(tmp) % 10 == 0

print(is_card_number_valid('4916734313471210'))




#Решението на задача 3

def get_card_network(card_number):
    l=len(card_number)
    if card_number[0]=='4' and (l==13 or l==16 or l==19):
        return 'Visa'
    elif l==16 and card_number[0]=='5' and (card_number[1]=='1' or card_number[1]=='2' or card_number[1]=='3' or card_number[1]=='4' or card_number[1]=='5'):
        return 'Mastercard'
    elif (l==16 or l==17 or l==18 or l==19) and card_number[0]=='6':
        return 'Discover'
    else:      
        return 'Unknown'

def group_card_numbers(card_numbers):
    visa_cards=[]
    mastercard_cards=[]
    discover_cards=[]
    unknown_cards=[]
    dict_for_cards={'Visa': visa_cards,'Mastercard': mastercard_cards,'Discover': discover_cards,'Unknown': unknown_cards}
    i=0
    l=len(card_numbers)
    while(l!=0):
        if get_card_network(card_numbers[i])=='Visa':
            visa_cards.append(card_numbers[i])
        elif get_card_network(card_numbers[i])=='Mastercard':
            mastercard_cards.append(card_numbers[i])
        elif get_card_network(card_numbers[i])=='Discover':
            discover_cards.append(card_numbers[i])
        else:
            unknown_cards.append(card_numbers[i])
        l=l-1
        i=i+1
    return dict_for_cards



print(group_card_numbers(card_numbers = [
'4916734313471210',
'4916734313471211',
'4485988000328437',
'4916195917598231366',
'5417266585296299',
'5555555555554444',
'5176971378227838',
'6011531243068077',
'6011663835677047',
'6011701484601571523',
'346331303550927',
'343551581289061',
'343551581289060',
'348001148210148',
]))




#Решението на задача 4  (не мога да разбера какво не е наред с кода и защо не тръгва)

def is_card_number_valid(number):
	tmp = [int(x) for x in number]	

	for i in range(len(tmp) - 2, -1, -2):
		tmp[i] *= 2

		if tmp[i] > 9:
			tmp[i] -= 9
		
	return sum(tmp) % 10 == 0

def filter_valid(grouped_card_numbers):
   for key in grouped_card_numbers:
      i=0
      l=len(list(grouped_card_numbers[key]))
      while (l!=0):
            n=grouped_card_numbers[key][i]
            if is_card_number_valid(n)=='True':
               i+=1
               l-=1
            else:
               del grouped_card_numbers[key][i]
               i+=1
               l-=1
   return grouped_card_numbers




print(filter_valid(grouped_card_numbers = {
'Visa':
['4916734313471210','4916734313471211','4485988000328437','4916195917598231366'],
'Mastercard': ['5417266585296299','5555555555554444','5176971378227838'],
'Discover': ['6011531243068077','6011663835677047','6011701484601571523'],
'Unknown':
['346331303550927','343551581289061','348001148210148','343551581289060']
}))
