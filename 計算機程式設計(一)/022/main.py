def Duplicate(card_list):
    if(len(card_list) == len(set(card_list))):
        return False
    else:
        return True

def ErrorInput(card_list):
    new_card_list = []
    if(len(card_list) != 5):
        return True,new_card_list
    for card in card_list:
        if(len(card) != 2):
            if(len(card) == 3 and card[:2] == "10"):
                card = [card[:2],card[2]]
            else:
                return True,new_card_list
        else:
            card = [card[0],card[1]]

        if(card[0] not in ["A","2","3","4","5","6","7","8","9","10","J","Q","K"]):
            return True,new_card_list
        elif(card[1] not in ["S","H","D","C"]):
            return True,new_card_list

        new_card_list.append(card)

    return False,new_card_list

def StrToNumStr(number_str):
    if(number_str == "A"):
        return "1"
    elif(number_str == "J"):
        return "11"
    elif (number_str == "Q"):
        return "12"
    elif (number_str == "K"):
        return "13"
    else:
        return number_str

def StrNumToStr(number_str):
    if(number_str == "1"):
        return "A"
    elif(number_str == "11"):
        return "J"
    elif (number_str == "12"):
        return "Q"
    elif (number_str == "13"):
        return "K"
    else:
        return number_str

def CardListToList(card_list,x):
    list = []
    for card in card_list:
        list.append(card[x])

    return list

def ContinueNumber(number_str):
    continuenumber_list = []
    number_str = StrToNumStr(number_str)
    number = int(number_str)
    for _ in range(5):
        if(number > 13):
            number = 1
        continuenumber_list.append(StrNumToStr(str(number)))
        number += 1

    return sorted(continuenumber_list)

def One_pair2(card_list):
    number_list = CardListToList(card_list, 0)
    for number in set(number_list):
        if (number_list.count(number) == 2):
            return True

    return False
def Two_pairs3(card_list):
    number_list = CardListToList(card_list, 0)
    if (len(set(number_list)) == 3):
        return True
    else:
        return False

def Three_of_a_kind4(card_list):
    number_list = CardListToList(card_list, 0)
    for number in set(number_list):
        if (number_list.count(number) == 3):
            return True

    return False
def Straight5(card_list):
    number_list = CardListToList(card_list,0)
    for number in number_list:
        if(sorted(number_list) == ContinueNumber(number)):
            return True

    return False

def Flush6(card_list):
    flower_list = CardListToList(card_list, 1)
    if (len(set(flower_list)) == 1):
        return True
    else:
        return False

def Full_House7(card_list):
    number_list = CardListToList(card_list, 0)
    if (len(set(number_list)) == 2):
        return True
    else:
        return False
def Four_of_a_kind8(card_list):
    number_list = CardListToList(card_list, 0)
    if(len(set(number_list)) == 2):
        for number in set(number_list):
            if(number_list.count(number) == 4):
                return True

    return False

def Straight_flush9(card_list):
    isStraight = Straight5(card_list)

    if(isStraight and Flush6(card_list)):
        return True
    else:
        return False

output_list = []
all_card_list = []

number = int(input())

if(2<=number<=5):
    for _ in range(number):

        list = input().split(" ")

        card_list = list[1:]
        name = list[0]
        all_card_list += card_list

        isDuplicate = Duplicate(all_card_list)
        isErrorInput,card_list = ErrorInput(card_list)

        if isErrorInput:
            output_list.append([name, "Error input"])
        elif isDuplicate:
            output_list.append([name, "Duplicate deal"])
        else:
            if Straight_flush9(card_list):
                output_list.append([name, 9])
            elif Four_of_a_kind8(card_list):
                output_list.append([name, 8])
            elif Full_House7(card_list):
                output_list.append([name, 7])
            elif Flush6(card_list):
                output_list.append([name, 6])
            elif Straight5(card_list):
                output_list.append([name, 5])
            elif Three_of_a_kind4(card_list):
                output_list.append([name, 4])
            elif Two_pairs3(card_list):
                output_list.append([name, 3])
            elif One_pair2(card_list):
                output_list.append([name, 2])
            else:
                output_list.append([name, 1])

    name_list = CardListToList(output_list, 0)
    number_list = CardListToList(output_list, 1)

    if("Error input" in number_list):
        print("Error input")
    elif("Duplicate deal" in number_list):
        print("Duplicate deal")
    else:
        name_number_list = []
        for number in sorted(tuple(set(number_list)))[::-1]:
            for i in range(len(output_list)):
                if(number_list[i] == number):
                    name_number_list.append([name_list[i],number_list[i]])

        for name,number in name_number_list:
            print(name,number)

else:
    print("Error input")