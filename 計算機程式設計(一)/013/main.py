linearNumber = int(input())
linearLength = set()
for i in range(linearNumber):
    linearStr = input()
    start, end = linearStr.split(" ")
    linearLength = linearLength | set([x for x in range(int(start),int(end))])

print(len(linearLength))