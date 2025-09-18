
isError = False
isCorret = True
classHour = [str(x) for x in range(1,10)] + ['a','b','c']

number = int(input())

course_dict = {}
course_dict2 = {}

for _ in range(number):


    courseNumber = input()
    courseHours = int(input())
    courseTimeList = []
    for i in range(courseHours):
        word = input()
        if(int(word[0])>5 or int(word[0])<1 ):
            isError = True
        if (word[1] not in classHour):
            isError = True
        courseTimeList.append(word)

    course_dict[courseNumber] = courseTimeList
    course_dict2[courseNumber] = courseTimeList


if(isError):
    print(-1)

else:
    for courseNumber in course_dict.keys():
        courseTimeList = course_dict[courseNumber]
        course_dict2.pop(courseNumber)
        for courseTime in courseTimeList:
            for courseNumber_temp in course_dict2.keys():
                courseTimeList_temp = course_dict2[courseNumber_temp]
                if(courseNumber != courseNumber_temp):
                    if courseTime in courseTimeList_temp:
                        print("{0},{1},{2}".format(courseNumber, courseNumber_temp, courseTime))
                        isCorret = False

    if(isCorret):
        print("correct")