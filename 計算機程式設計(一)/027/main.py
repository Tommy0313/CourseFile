N  = int(input())
D  = int(input())

str_list = []

for _ in range(N):
    str_list.append(input())

for sentence in str_list:
    depth = 0
    words = ""
    now_symbol_list = []
    fail = False
    for char in sentence:
        if(char == '('):
            now_symbol_list.append(")")
            depth += 1
        elif(char == '['):
            now_symbol_list.append("]")
            depth += 1
        elif(char == '{'):
            now_symbol_list.append("}")
            depth += 1
        elif(len(now_symbol_list)!=0):
            if(char.isalpha() == False and char != now_symbol_list[-1]):
                fail = True
            elif(char == now_symbol_list[-1]):
                depth -= 1
                now_symbol_list.pop()
            elif (D == depth):
                words += char
        elif(char in [")","]","}"] and len(now_symbol_list) == 0):
            fail = True

    if(fail or len(now_symbol_list) != 0):
        print("fail")
    else:
        if(words == ""):
            print("pass, EMPTY")
        else:
            print("pass, "+words)