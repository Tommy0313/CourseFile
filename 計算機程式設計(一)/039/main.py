def circleTheMatrix(x_list, circle_numbers, N):
    circle_matrix = []
    for i in range(N):
        circle_matrix.append([])
        for j in range(N):
            if(x_list[i*N+j] in circle_numbers):
                circle_matrix[i].append(1)
            else:
                circle_matrix[i].append(0)

    return circle_matrix

def countTotalLineNumber(x_matrix, N):
    line_number = 0
    for i in range(N):
        number = 0
        for j in range(N):
            number += x_matrix[i][j]
        if(number == N):
            line_number += 1

    for i in range(N):
        number = 0
        for j in range(N):
            number += x_matrix[j][i]
        if(number == N):
            line_number += 1

    number = 0
    for i in range(N):
        number += x_matrix[i][i]
    if (number == N):
        line_number += 1

    number = 0
    for i in range(N):
        number += x_matrix[N-i-1][i]
    if (number == N):
        line_number += 1

    return line_number


N = int(input())
M = int(input())
A_list = input().split(" ")
B_list = input().split(" ")
cricle_numbers = input().split(" ")

A_matrix = circleTheMatrix(A_list, cricle_numbers, N)
B_matrix = circleTheMatrix(B_list, cricle_numbers, N)
A_line_number = countTotalLineNumber(A_matrix, N)
B_line_number = countTotalLineNumber(B_matrix, N)

if(A_line_number>B_line_number):
    print("A Win")
elif(A_line_number==B_line_number):
    print("Tie")
else:
    print("B Win")



