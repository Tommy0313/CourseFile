def binarytodicimal(binary,number):
    if(number == 0):
        return int(binary[number])*(2**(len(binary)-number-1))
    return int(binary[number])*(2**(len(binary)-number-1))+binarytodicimal(binary,number-1)

def time(decimal):
    if(decimal == 1 or decimal == 0):
        return 0
    if(decimal%2 == 0):
        return 1 + time(decimal//2)
    else:
        return 1 + time((decimal+1) // 2)

input_list = []

while True:
    logic_input = input()
    if(logic_input == "0"):
        pass
    elif(logic_input == "-1"):
        break
    else:
        input_list.append(logic_input)

for logic in input_list:
    decimal_number = binarytodicimal(logic,len(logic)-1)
    decimal_time = 0
    for number in range(0,decimal_number+1):
        decimal_time += time(number)
    binary_time = ""
    for i in range(14):
        binary_time += str(decimal_time%2)
        decimal_time = decimal_time//2
    print(binary_time[::-1])