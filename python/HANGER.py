# HANGER GAME 
def game(level):
    if level=='e':
        chances=9
    elif level=='m':
        chances=6
    elif level=='h':
        chances=3
    else:
        return("Invalid level. Try again.")
    secret_word=input("Enter a secret word: ")
    my_list=[]
    list_with_guesses=[]
    m=0
    for n in range(0,len(secret_word)):
        my_list.append(secret_word[n])
    while chances!=0:
        letter=input('Enter a letter: ')
        if letter in my_list and letter not in list_with_guesses:
                m+=1
                print( letter +" in secret_word")
                w=len(secret_word)-m
                print("You have to guess " + str(w)+" more letters" )
                list_with_guesses.append(letter)
                if m==len(secret_word):
                    return ("Congratulations! You win!")
            
        else:
            if chances==9:
                print("|")
                print("|")
                print("|")
                print("|")
                print("|")
                print("|")
                chances-=1
            elif chances==8:
                print("__________")
                print("|")
                print("|")
                print("|")
                print("|")
                print("|")
                print("|")
                chances-=1
            elif chances==7:
                print("__________")
                print("|    |")
                print("|")
                print("|")
                print("|")
                print("|")
                print("|")
                chances-=1
            elif chances==6:
                print("__________")
                print("|    |")
                print("|   [_]")
                print("|")
                print("|")
                print("|")
                print("|")
                chances-=1
            elif chances==5:
                print("__________")
                print("|    |")
                print("|   [_]")
                print("|    |")
                print("|    |")
                print("|")
                print("|")
                chances-=1
            elif chances==4:
                print("__________")
                print("|    |")
                print("|   [_]")
                print("|    |")
                print("|    |")
                print("|   /")
                print("|  /")
                chances-=1
            elif chances==3:
                print("__________")
                print("|    |")
                print("|   [_]")
                print("|    | ")
                print("|    |  ")
                print("|   / \ ")
                print("|  /   \ ")
                chances-=1
            elif chances==2:
                print("__________")
                print("|    |")
                print("|   [_]")
                print("|   /| ")
                print("|  / |  ")
                print("|   / \ ")
                print("|  /   \ ")
                chances-=1
            else:
                print("__________")
                print("|    |")
                print("|   [_]")
                print("|   /|\ ")
                print("|  / | \ ")
                print("|   / \ ")
                print("|  /   \ ")
                chances-=1
            print("You have "+ str(chances) +" chances left")
    return("You were hanged! You lose!")        
print("Let's play HANGER")
print("Choose your level: e-for easy, m-for medium, h-for hard ")
level=input("Enter a level: ")           
print(game(level))


# HANGER GAME WITHOUT PRINTING 
def game(level):
    if level=='e':
        chances=9
    elif level=='m':
        chances=6
    elif level=='h':
        chances=3
    else:
        return("Invalid level. Try again.")
    secret_word=input("Enter a secret word: ")
    my_list=[]
    list_with_guesses=[]
    m=0
    for n in range(0,len(secret_word)):
        my_list.append(secret_word[n])
    while chances!=0:
        letter=input('Enter a letter: ')
        if letter in my_list and letter not in list_with_guesses:
                m+=1
                print( letter +" in secret_word")
                w=len(secret_word)-m
                print("You have to guess " + str(w)+" more letters" )
                list_with_guesses.append(letter)
                if m==len(secret_word):
                    return ("Congratulations! You win!")
            
        else:
            chances-=1
            print("You have "+ str(chances) +" chances left")
    return("You lose")        
print("Let's play HANGER")
print("Choose your level: e-for easy, m-for medium, h-for hard ")
level=input("Enter a level: ")           
print(game(level))
