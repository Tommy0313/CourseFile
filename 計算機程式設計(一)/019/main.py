def right_triangle(N):
    for i in range(1, N+1):
        for num in range(1,i+1):
            print(num,end="")
        for num in range(i-1,0,-1):
            print(num, end="")
        print("")
def equilateral_triangle(N):
    for i in range(1, N + 1):
        for _ in range(N - i):
            print("_", end="")
        for num in range(1, i + 1):
            print(num, end="")
        for num in range(i - 1, 0, -1):
            print(num, end="")
        for _ in range(N - i):
            print("_", end="")
        print("")
def inverted_triangle(N):
    for i in range(N, 0,-1):
        for _ in range(N - i):
            print("_", end="")
        for num in range(1, i + 1):
            print(num, end="")
        for num in range(i - 1, 0, -1):
            print(num, end="")
        for _ in range(N - i):
            print("_", end="")
        print("")



M = input()
N = int(input())
if(M == "1"):
    right_triangle(N)
elif(M == "2"):
    equilateral_triangle(N)
elif (M == "3"):
    inverted_triangle(N)