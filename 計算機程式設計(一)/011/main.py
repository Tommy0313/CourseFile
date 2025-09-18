import math
def discount(numberBook):
    if(numberBook<=10):
        return 4
    elif(11<=numberBook<=20):
        return 1
    elif (21 <= numberBook <= 30):
        return 2
    else:
        return 3

def countMoney(X_list):
    money = int(X_list[0]) * (float(X_list[discount(int(X_list[0]))])/100) * int(X_list[5])
    return math.ceil(money)


A = input()
B = input()
C = input()

A_list = A.split(",") + ['100', '380']
B_list = B.split(",") + ['100', '1200']
C_list = C.split(",") + ['100', '180']

money_list = []
name_list = ['A','B','C']

for X in [A_list,B_list,C_list]:
    money_list.append(countMoney(X))

new_money_list = sorted(money_list)

for i in range(3)[::-1]:
    print("{0},{1}".format(name_list[money_list.index(new_money_list[i])],new_money_list[i]))
    name_list.pop(money_list.index(new_money_list[i]))
    money_list.pop(money_list.index(new_money_list[i]))

print(sum(new_money_list))

