def  from_morse(encoded):
  morse_code_dict = {'.-  ' : 'a', '-...' : 'b', '-.-.' : 'c', '-.. ' : 'd', '.   ' : 'e', '..-.' : 'f',
   '--. ' : 'g','....' : 'h', '..  ' : 'i', '.---' : 'j', '-.- ' : 'k', '.-..' : 'l', '--  ' : 'm',
    '-.  ' : 'n', '--- ' : 'o', '.--.' : 'p', '--.-' : 'q', '.-. ' : 'r', '... ' : 's', '-   ' : 't', 
    '..- ' : 'u', '...-' : 'v', '.-- ' : 'w', '-..-' : 'x', '-.--' : 'y', '--..' : 'z','    ':' '}
  my_list=[]
  letters=[encoded[i:i+4]for i in range(0,len(encoded),4)]
  for letter in letters:
        my_list.append(morse_code_dict[letter])
  return my_list


print("".join (from_morse(".....   .-...-..---     .-- --- .-. .-..-.. ")))