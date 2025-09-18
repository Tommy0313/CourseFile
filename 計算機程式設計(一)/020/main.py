def generate_array(n):
    array = []
    for i in range(n):
        array.append([])
        for j in range(n):
            array[i].append(i*n+j+1)
    return array

def left(array):
    new_array = generate_array(len(array))
    for i in range(len(array)):
        for j in range(len(array)):
            new_array[j][i] = array [i][j]

    new_array = new_array[::-1]

    return new_array

def right(array):
    new_array = generate_array(len(array))
    for i in range(len(array)):
        for j in range(len(array)):
            new_array[j][i] = array [i][j]

    for i in range(len(array)):
        new_array[i] = new_array[i][::-1]

    return new_array

def show_array(array):
    for i in range(len(array)):
        for j in range(len(array)):
            print(array[i][j],end=" ")

        print("")

n = int(input())

Right_Left = input()

array = generate_array(n)

for word in Right_Left:
    if(word == "R"):
        array = right(array)
    elif(word == "L"):
        array = left(array)

show_array(array)