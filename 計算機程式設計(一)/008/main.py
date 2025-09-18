isError = False
isCorret = True
classHour = [str(x) for x in range(1,10)] + ['a','b','c']

courseNumber1 = input()
courseHours1 = int(input())
courseTimeList1 = []
for i in range(courseHours1):
    word = input()
    if(int(word[0])>5 or int(word[0])<1 ):
        isError = True
    if (word[1] not in classHour):
        isError = True
    courseTimeList1.append(word)

courseNumber2 = input()
courseHours2 = int(input())
courseTimeList2 = []
for i in range(courseHours2):
    word = input()
    if (int(word[0]) > 5 or int(word[0]) < 1):
        isError = True
    if (word[1] not in classHour):
        isError = True
    courseTimeList2.append(word)

courseNumber3 = input()
courseHours3 = int(input())
courseTimeList3 = []
for i in range(courseHours3):
    word = input()
    if (int(word[0]) > 5 or int(word[0]) < 1):
        isError = True
    if (word[1] not in classHour):
        isError = True
    courseTimeList3.append(word)

if(isError):
    print(-1)

else:
    for courseTime in courseTimeList1:
        if courseTime in courseTimeList2:
            print("{0},{1},{2}".format(courseNumber1,courseNumber2,courseTime))
            isCorret = False
        if courseTime in courseTimeList3:
            print("{0},{1},{2}".format(courseNumber1, courseNumber3, courseTime))
            isCorret = False

    for courseTime in courseTimeList2:
        if courseTime in courseTimeList3:
            print("{0},{1},{2}".format(courseNumber2, courseNumber3, courseTime))
            isCorret = False

    if(isCorret):
        print("correct")