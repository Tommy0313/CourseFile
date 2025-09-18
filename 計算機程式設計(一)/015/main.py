import statistics

def number_round(number):
    number = number * 10000
    number = number // 10

    if(number % 10 > 5):
        number += 10
    elif(number % 10 == 5) and (number//10 % 2 != 0):
        number += 10
    number = number // 10
    number = number / 100

    return number

def number_round2(number):
    number = number * 10000
    number = number // 10

    if(number % 10 >= 5):
        number += 10
    number = number // 10
    number = number / 100

    return number

def mode(list):
    list = sorted(list)
    list_set = tuple(list)
    number_list = []
    for number in list_set:
        number_list.append(list.count(number))
    return list_set[number_list.index(max(number_list))]

number = int(input())

BMI_list = []

for _ in range(number):
    str = input()
    height, weight = str.split(" ")
    height = float(height)
    weight = float(weight)
    BMI = number_round(weight / (height * height))
    BMI_list.append(BMI)

BMI_list = sorted(BMI_list)

print("{:.2f}".format(max(BMI_list)))
print("{:.2f}".format(min(BMI_list)))

if(len(BMI_list) %2 == 0):
    print("{:.2f}".format(number_round2((BMI_list[len(BMI_list)//2] + BMI_list[len(BMI_list)//2-1]) / 2)))
else:
    print("{:.2f}".format(BMI_list[len(BMI_list)//2]))

print("{:.2f}".format(mode(BMI_list)))

