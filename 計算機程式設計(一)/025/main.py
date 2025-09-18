card_to_point = {"A":1, "2":2, "3":3, "4":4, "5":5, "6":6, "7":7, "8":8, "9":9, "10":10, "J":11, "Q":12, "K":13}
def card_split(card_list):
    point_list = []
    flower_list = []
    for card in card_list:
        point_list.append(card[1:])
        flower_list.append(card[0])

    return point_list, flower_list

def number_return(number):
    if(number > 13):
        number = number - 13
    return number

def Straighth(point_list):
    point_list = sorted(point_list)
    for i in range(len(point_list)):
        compare_card_list = []
        for j in range(point_list[i], point_list[i] + 5):
            compare_card_list.append(number_return(j))

        compare_card_list = sorted(compare_card_list)
        if(point_list == compare_card_list):
            return True

    return False

A_card_list = input().split(" ")
B_card_list = input().split(" ")
table_card_list = input().split(" ")
All_card_list = A_card_list + B_card_list + table_card_list
A_card_list = A_card_list + table_card_list
B_card_list = B_card_list + table_card_list

A_card_number_list = []
B_card_number_list = []
error_input = False
Duplicate_deal = False
if(len(set(All_card_list)) != len(All_card_list)):
    Duplicate_deal = True

all_point_list, all_flower_list = card_split(All_card_list)
for point in all_point_list:
    if(point not in ["A","2","3","4","5","6","7","8","9","10","J","Q","K"]):
        error_input = True

for flower in all_flower_list:
    if(flower not in ["H","S","D","C"]):
        error_input = True

if(error_input == False and Duplicate_deal == False):
    for i in range(len(A_card_list)):
        new_card_list = A_card_list[:i] + A_card_list[i+1:]
        point_list, flower_list = card_split(new_card_list)
        point_list = sorted(point_list)
        index = 0
        two_pair_number = 0
        three_pair_number = 0
        four_pair_number = 0
        same_word = 0
        calculate = False
        for index in range(4):
            if(point_list[index] == point_list[index+1]):
                same_word += 1
            else:
                calculate = True
            if(calculate or index == 3):
                if(same_word == 1):
                    two_pair_number += 1
                elif(same_word == 2):
                    three_pair_number += 1
                elif(same_word == 3):
                    four_pair_number += 1
                same_word = 0
                calculate = False

        for i in range(len(point_list)):
            point_list[i] = card_to_point[point_list[i]]
        if (Straighth(point_list) and len(set(flower_list)) == 1):
            A_card_number_list.append(9)
        elif (four_pair_number == 1):
            A_card_number_list.append(8)
        elif (three_pair_number == 1 and two_pair_number == 1):
            A_card_number_list.append(7)
        elif (len(set(flower_list)) == 1):
            A_card_number_list.append(6)
        elif (Straighth(point_list)):
            A_card_number_list.append(5)
        elif (three_pair_number == 1):
            A_card_number_list.append(4)
        elif (two_pair_number == 2):
            A_card_number_list.append(3)
        elif (two_pair_number == 1):
            A_card_number_list.append(2)
        else:
            A_card_number_list.append(1)

    for i in range(len(B_card_list)):
        new_card_list = B_card_list[:i] + B_card_list[i+1:]
        point_list, flower_list = card_split(new_card_list)
        point_list = sorted(point_list)
        index = 0
        two_pair_number = 0
        three_pair_number = 0
        four_pair_number = 0
        same_word = 0
        calculate = False
        for index in range(4):
            if (point_list[index] == point_list[index + 1]):
                same_word += 1
            else:
                calculate = True
            if (calculate or index == 3):
                if (same_word == 1):
                    two_pair_number += 1
                elif (same_word == 2):
                    three_pair_number += 1
                elif (same_word == 3):
                    four_pair_number += 1
                same_word = 0
                calculate = False

        for i in range(len(point_list)):
            point_list[i] = card_to_point[point_list[i]]

        if (Straighth(point_list) and len(set(flower_list)) == 1):
            B_card_number_list.append(9)
        elif (four_pair_number == 1):
            B_card_number_list.append(8)
        elif (three_pair_number == 1 and two_pair_number == 1):
            B_card_number_list.append(7)
        elif (len(set(flower_list)) == 1):
            B_card_number_list.append(6)
        elif (Straighth(point_list)):
            B_card_number_list.append(5)
        elif (three_pair_number == 1):
            B_card_number_list.append(4)
        elif (two_pair_number == 2):
            B_card_number_list.append(3)
        elif (two_pair_number == 1):
            B_card_number_list.append(2)
        else:
            B_card_number_list.append(1)
if(error_input):
    print("Error input")
elif(Duplicate_deal):
    print("Duplicate deal")
else:
    if(max(B_card_number_list) == max(A_card_number_list)):
        print("Tie")
    else:
        if(max(B_card_number_list) > max(A_card_number_list)):
            print("B", max(B_card_number_list))
        else:
            print("A", max(A_card_number_list))
