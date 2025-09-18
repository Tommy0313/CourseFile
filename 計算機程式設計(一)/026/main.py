n  = int(input())
m  = int(input())
a  = int(input())
b  = float(input())
c  = int(input())
d  = float(input())

cure_people_list = []

#d = d + (a / n)

unsick_peoplpe = int((1 - d) * n)

stop = False

now_total_sick_people = a
total_sick_people = a
today_total_sick_people = a
yesterday_total_sick_people = a

for _ in range(c):
    cure_people_list.append(0)

cure_people_list[-1] = a

print(1, now_total_sick_people, a, 0)

for i in range(m-1):
    if(stop == False):
        x = (b / c) * (1 - d)
        y = int(yesterday_total_sick_people * x)
    else:
        y = 0
    if(now_total_sick_people + y > unsick_peoplpe and stop == False):
        y = unsick_peoplpe - now_total_sick_people
        stop = True
    cure_people = cure_people_list[0]
    now_total_sick_people -= cure_people
    cure_people_list[:-1] = cure_people_list[1:]
    cure_people_list[-1] = y
    total_sick_people += y
    today_total_sick_people = y
    now_total_sick_people += y
    yesterday_total_sick_people = now_total_sick_people
    print(i + 2, now_total_sick_people, y, cure_people)
    d = d + ((cure_people) / n)

print(total_sick_people)


