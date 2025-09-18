def game(array):
    for i in range(4):
        if len(set(array[i]))==4 and 0 in array[i]:
            array[i][array[i].index(0)] = 10 - sum(array[i])

    for j in range(4):
        column = []
        for i in range(4):
            column.append(array[i][j])
        if len(set(column))==4 and 0 in column:
            array[column.index(0)][j] = 10 - sum(column)


    for num in range(4):
        grid = []
        for i in range(2):
            for j in range(2):
                grid.append(int(array[i+num//2*2][j+num%2*2]))
        if len(set(grid))==4 and 0 in grid:
            x = grid.index(0)//2
            y = grid.index(0)%2
            array[x + num//2*2][y+num%2*2] = 10 - sum(grid)

    for i in range(4):
        done = True
        if(0 in array[i]):
            done = False
            break

    if(done == True):
        return array


    return game(array)




array = []

for i in range(4):
    word = input()
    array.append([int(x) for x in word.split(" ")])

array = game(array)
for i in range(len(array)):
    for j in range(len(array)):
        print(array[i][j],end=" ")
    print()





