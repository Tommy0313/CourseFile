def peoplePercent(people_number):
    percent_list = []
    percent = 0.01
    people = 0
    for i in range(100):
        now_people = people_number * percent - 0.00000000000001
        if(now_people % 1 != 0):
            now_people = int(now_people) +1

        percent_list.append(int(now_people-people))
        percent += 0.01
        people = now_people

    return percent_list

course_dict = {}
All_course_dict = {}
search_department_dict = dict()

N = int(input())
for _ in range(N):
    course_code, semester, student_number = input().split(" ")
    if (course_code not in All_course_dict):
        All_course_dict[course_code] = set()
    All_course_dict[course_code].add(semester[:-1])

    for _ in range(int(student_number)):
        sentence = input()
        if(sentence[3:6] not in search_department_dict.keys()):
            search_department_dict[sentence[3:6]] = set()
        search_department_dict[sentence[3:6]].add(sentence[:8])
        if("w" in sentence):
            student_id , w = sentence.split(" ")
            if (student_id[3:6] not in course_dict):
                course_dict[student_id[3:6]] = {}
            if (student_id[:3] not in course_dict[student_id[3:6]]):
                course_dict[student_id[3:6]][student_id[0:3]]= {}
            if (semester[:3] not in course_dict[student_id[3:6]][student_id[0:3]]):
                course_dict[student_id[3:6]][student_id[0:3]][semester[:3]] = {}
            if (semester[3] not in course_dict[student_id[3:6]][student_id[0:3]][semester[:3]]):
                course_dict[student_id[3:6]][student_id[0:3]][semester[:3]][semester[3]] = {}
            if (course_code not in course_dict[student_id[3:6]][student_id[0:3]][semester[:3]][semester[3]]):
                course_dict[student_id[3:6]][student_id[0:3]][semester[:3]][semester[3]][course_code] = {}
            course_dict[student_id[3:6]][student_id[0:3]][semester[:3]][semester[3]][course_code][student_id[6:]] = w
        elif(len(sentence.split(" ")) == 2):
            student_id, semester_grade = sentence.split(" ")
            if (student_id[3:6] not in course_dict):
                course_dict[student_id[3:6]] = {}
            if (student_id[:3] not in course_dict[student_id[3:6]]):
                course_dict[student_id[3:6]][student_id[0:3]] = {}
            if (semester[:3] not in course_dict[student_id[3:6]][student_id[0:3]]):
                course_dict[student_id[3:6]][student_id[0:3]][semester[:3]] = {}
            if (semester[3] not in course_dict[student_id[3:6]][student_id[0:3]][semester[:3]]):
                course_dict[student_id[3:6]][student_id[0:3]][semester[:3]][semester[3]] = {}
            if (course_code not in course_dict[student_id[3:6]][student_id[0:3]][semester[:3]][semester[3]]):
                course_dict[student_id[3:6]][student_id[0:3]][semester[:3]][semester[3]][course_code] = {}
            course_dict[student_id[3:6]][student_id[0:3]][semester[:3]][semester[3]][course_code][student_id[6:]] = int(semester_grade)
        else:
            student_id, semester_grade, comprehensive_grade = sentence.split(" ")
            if (student_id[3:6] not in course_dict):
                course_dict[student_id[3:6]] = {}
            if (student_id[:3] not in course_dict[student_id[3:6]]):
                course_dict[student_id[3:6]][student_id[0:3]] = {}
            if (semester[:3] not in course_dict[student_id[3:6]][student_id[0:3]]):
                course_dict[student_id[3:6]][student_id[0:3]][semester[:3]] = {}
            if (semester[3] not in course_dict[student_id[3:6]][student_id[0:3]][semester[:3]]):
                course_dict[student_id[3:6]][student_id[0:3]][semester[:3]][semester[3]] = {}
            if (course_code not in course_dict[student_id[3:6]][student_id[0:3]][semester[:3]][semester[3]]):
                course_dict[student_id[3:6]][student_id[0:3]][semester[:3]][semester[3]][course_code] = {}
            if((int(semester_grade)*0.7 + int(comprehensive_grade)*0.3) % 1 == 0):
                final_grade = int((int(semester_grade)*0.7 + int(comprehensive_grade)*0.3))
            else:
                final_grade = int((int(semester_grade) * 0.7 + int(comprehensive_grade) * 0.3)) + 1
            course_dict[student_id[3:6]][student_id[0:3]][semester[:3]][semester[3]][course_code][student_id[6:]] = int(final_grade)

search_course = input()
search_course_dict = {}

for department in course_dict:
    for in_school_grade in sorted(course_dict[department].keys()):
        for semester in course_dict[department][in_school_grade]:
            print(department, in_school_grade, semester)
            this_semester = {}
            for semester_oneandtwo in course_dict[department][in_school_grade][semester]:
                for course_code in course_dict[department][in_school_grade][semester][semester_oneandtwo]:
                    for student_id in course_dict[department][in_school_grade][semester][semester_oneandtwo][course_code]:
                        if(student_id not in this_semester):
                            this_semester[student_id] = [[],[]]
                        if(course_dict[department][in_school_grade][semester][semester_oneandtwo][course_code][student_id] != "w"):
                            for _ in range(int(course_code[-1])):
                                this_semester[student_id][0].append(course_dict[department][in_school_grade][semester][semester_oneandtwo][course_code][student_id])
                            this_semester[student_id][1].append("T")
                        else:
                            this_semester[student_id][1].append("w")

            for student_id in this_semester:
                if(this_semester[student_id][0] != []):
                    this_semester[student_id][0] = int(sum(this_semester[student_id][0])/len(this_semester[student_id][0]))
                else:
                    this_semester[student_id][0] = 0

            this_semester = sorted(this_semester.items(), key=lambda x: x[0])
            this_semester = sorted(this_semester, key=lambda x:x[1][0], reverse=True)

            percent_list = peoplePercent(len(this_semester))
            for rank in range(3):
                W_numbers = 0
                for TorW in this_semester[rank][1][1]:
                    if(TorW == 'w'):
                        W_numbers += 1

                for index in range(100):
                    if(percent_list[index] > 0):
                        percent_list[index] -= 1
                        break

                print(in_school_grade+department+this_semester[rank][0], this_semester[rank][1][0], str(index+1)+"%", str(int(W_numbers/len(this_semester[rank][1][1])*100))+"%")

All_course_list = sorted(All_course_dict.items(), key=lambda x:x[0])

for index in range(len(All_course_list)):
    year_list = sorted(sorted(All_course_list[index][1]),key=len)
    for year in year_list:
        this_course_grade_dict = {}
        print(All_course_list[index][0], year)
        for department in course_dict:
            for in_school_grade in course_dict[department]:
                for semester in course_dict[department][in_school_grade]:
                    for semester_oneandtwo in course_dict[department][in_school_grade][semester]:
                        for course_code in course_dict[department][in_school_grade][semester][semester_oneandtwo]:
                            if(semester == year and course_code == All_course_list[index][0]):
                                for student_last_number in course_dict[department][in_school_grade][semester][semester_oneandtwo][course_code].keys():
                                    this_course_grade_dict[in_school_grade+department+student_last_number] = course_dict[department][in_school_grade][semester][semester_oneandtwo][course_code][student_last_number]

        this_course_grade_without_w_dict = dict(filter(lambda x: x[1] != "w", this_course_grade_dict.items()))
        this_course_grade_list = list(filter(lambda x: x != "w", this_course_grade_dict.values()))
        this_course_cancel_list = list(filter(lambda x: x == "w", this_course_grade_dict.values()))

        print(this_course_grade_dict[max(this_course_grade_without_w_dict, key=lambda key: int(this_course_grade_dict[key]))], int(sum(this_course_grade_list)/len(this_course_grade_list)), this_course_grade_dict[min(this_course_grade_without_w_dict, key=lambda key: int(this_course_grade_dict[key]))], str(int(len(this_course_cancel_list)/len(this_course_grade_dict)*100))+"%")

        this_course_grade_without_w_list = sorted(this_course_grade_without_w_dict.items(), key=lambda x: x[0])
        this_course_grade_without_w_list = sorted(this_course_grade_without_w_list, key=lambda x: x[1], reverse=True)

        percent_list = peoplePercent(len(this_course_grade_dict))
        for rank in range(3):
            for percent in range(100):
                if (percent_list[percent] > 0):
                    percent_list[percent] -= 1
                    break

            print(this_course_grade_without_w_list[rank][0], this_course_grade_without_w_list[rank][1], str(percent+1)+"%")


for department in course_dict:
    for in_school_grade in course_dict[department]:
        for semester in course_dict[department][in_school_grade]:
            for semester_oneandtwo in course_dict[department][in_school_grade][semester]:
                for course_code in course_dict[department][in_school_grade][semester][semester_oneandtwo]:
                    if(search_course == course_code):
                        for student_last_number in course_dict[department][in_school_grade][semester][semester_oneandtwo][course_code].keys():
                            if(course_dict[department][in_school_grade][semester][semester_oneandtwo][course_code][student_last_number] != "w"):
                                if(in_school_grade+department+student_last_number not in search_course_dict.keys()):
                                    search_course_dict[in_school_grade+department+student_last_number] = course_dict[department][in_school_grade][semester][semester_oneandtwo][course_code][student_last_number]
                                elif(course_dict[department][in_school_grade][semester][semester_oneandtwo][course_code][student_last_number] > search_course_dict[in_school_grade+department+student_last_number]):
                                    search_course_dict[in_school_grade + department + student_last_number] = course_dict[department][in_school_grade][semester][semester_oneandtwo][course_code][student_last_number]

search_course_list = sorted(search_course_dict.items(), key=lambda x: x[0])
search_course_list = sorted(search_course_list, key=lambda x: x[1], reverse=True)
search_department_list = sorted(search_department_dict.items(), key=lambda x: len(x[1]), reverse=True)
if(len(search_department_list) >= 2):
    print(search_course_list[0][0], search_course_list[1][0], search_department_list[0][0], search_department_list[1][0])
else:
    print(search_course_list[0][0], search_course_list[1][0], search_department_list[0][0])