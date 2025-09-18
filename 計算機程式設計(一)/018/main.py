
def equilateral_triangle(N, symbol = "#"):
    for i in range(N):
        for j in range(N*2-1):
            if(((N*2)//2-i-1)<=j and j <=((N*2)//2+i-1)):
                print("*",end="")
            else:
                print(symbol, end="")
        print("")
def inverted_triangle(N, symbol = "#"):
    for i in range(N):
        for j in range(N*2-1):
            if(i>j or N*2-1-i<=j):
                print(symbol,end="")
            else:
                print("*", end="")
        print("")
def diamond(N):
    N = (N+1)//2
    N = N-1
    for i in range(N,-1,-1):
        if(i != 0):
            for j in range(i):
                print(" ",end="")
        for j in range((N+1-i)*2-1):
            print("*", end="")
        print("")
    for i in range(N):
        print(" ", end="")
        for j in range(i):
            print(" ",end="")
        for j in range((N-i)*2-1):
            print("*", end="")
        print("")

def fish(N):
    for i in range((N+1)//2):
        if(i ==0):
            for j in range((N+1)//2):
                if ((N // 2 - i) <= j and j <= (N // 2 + i)):
                    print("*", end="")
                elif(j >= N + N//2 - i):
                    print("-", end="")
                else:
                    print(" ", end="")
            print("")

        else:
            for j in range(N + N//2):
                if ((N // 2 - i) <= j and j <= (N // 2 + i)):
                    print("*", end="")
                elif(j >= N + N//2 - i):
                    print("-", end="")
                else:
                    print(" ", end="")
            print("")

    for i in range((N+1)//2, -1, -1):
        if(i >= (N+1)//2 -1):
            pass
        else:
            if (i == 0):
                for j in range((N + 1) // 2):
                    if ((N // 2 - i) <= j and j <= (N // 2 + i)):
                        print("*", end="")
                    elif (j >= N + N // 2 - i):
                        print("-", end="")
                    else:
                        print(" ", end="")
                print("")

            else:
                for j in range(N + N//2):
                    if ((N // 2 - i) <= j and j <= (N // 2 + i)):
                        print("*", end="")
                    elif(j >= N + N//2 - i):
                        print("-", end="")
                    else:
                        print(" ", end="")
                print("")

C = input()
N = int(input())
if(3<=N<=49 and N%2==1):
    if(C == "1"):
        equilateral_triangle(N)
    elif(C == "2"):
        inverted_triangle(N)
    elif (C == "3"):
        diamond(N)
    elif(C == "4"):
        fish(N)
else:
    print("error")