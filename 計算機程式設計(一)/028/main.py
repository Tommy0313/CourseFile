A = input()
B = input()
X = input()
Y = input()

C = A + " " + B
C_words_number = 0
D_words_number = 0
print(C)

C_list = C.split(" ")
C_lower_list = []
for word in C_list:
    C_lower_list.append(word.lower())
    C_words_number += len(word)

D_list = []
for i in range(len(C_lower_list)):
    if(C_lower_list[i] == X.lower()):
        D_list.append(Y)
        D_words_number += len(Y)
    else:
        D_list.append(C_list[i])
        D_words_number += len(C_list[i])

for word in D_list:
    print(word, end=" ")
print()
print(C_words_number, D_words_number)

D_reverse_list = []
for word in D_list:
    if(word.lower() == Y.lower()):
        D_reverse_list.append(Y[::-1])
    else:
        D_reverse_list.append(word)

for word in D_reverse_list:
    print(word, end=" ")
print()

new_C = C[::abs(len(X) - len(Y))]
space = False
for char in new_C:
    if(char == " " and space == False):
        space = True
        print(" ", end="")
    elif(space == True and char != ""):
        space = False
    if(char != " "):
        print(char,end="")