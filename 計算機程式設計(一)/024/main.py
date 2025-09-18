
bomb_list = []
money_list = []
win_lose_list = []
computer_money = 0
computer_point = 0
computer_bomb = False
card_to_point = {"A":1, "2":2, "3":3, "4":4, "5":5, "6":6, "7":7, "8":8, "9":9, "10":10, "J":0.5, "Q":0.5, "K":0.5}
player_number = int(input())
money_list = input().split(" ")
for i in range(len(money_list)):
    money_list[i] = int(money_list[i])

for _ in range(player_number):
    bomb_list.append(False)
    win_lose_list.append(0)

card_point_list = input().split(" ")
for i in range(len(card_point_list)):
    card_point_list[i] = card_to_point[card_point_list[i]]

card_point_list = card_point_list[1:] + [card_point_list[0]]


for i in range(player_number):
    while(bomb_list[i] == False):
        word = input()
        if(word == "N"):
            break
        else:
            choose, card = word.split(" ")

            card_point_list[i] += card_to_point[card]

            if(card_point_list[i] > 10.5):
                win_lose_list[i] -= money_list[i]
                computer_money += money_list[i]
                bomb_list[i] = True
            elif(card_point_list[i] == 10.5):
                win_lose_list[i] += money_list[i]
                computer_money -= money_list[i]
                bomb_list[i] = True
                break

first_time_give_card = True

while(computer_bomb == False):
    if(set(bomb_list) == set([True]) or set(card_point_list) == set([10.5])):
        computer_bomb = True
    elif(min(card_point_list[:-1]) >= card_point_list[-1]):
        card = input()
        card_point_list[-1] += card_to_point[card]
        if(card_point_list[-1] >= 10.5):
            computer_bomb = True
    elif(min(card_point_list[:-1]) < card_point_list[-1]):
        computer_bomb = True

for i in range(player_number):
    if (bomb_list[i] == False):
        if (card_point_list[-1] > 10.5):
            win_lose_list[i] += money_list[i]
            computer_money -= money_list[i]
        elif (card_point_list[-1] == 10.5):
            win_lose_list[i] -= money_list[i]
            computer_money += money_list[i]
        elif (card_point_list[-1] < 10.5):
            if(card_point_list[i] > card_point_list[-1]):
                win_lose_list[i] += money_list[i]
                computer_money -= money_list[i]
            elif(card_point_list[i] <= card_point_list[-1]):
                win_lose_list[i] -= money_list[i]
                computer_money += money_list[i]
            else:
                pass

for i in range(player_number):
    print("Player"+str(i+1)+" %+d"%(win_lose_list[i]))

print("Computer "+"%+d"%(computer_money))

