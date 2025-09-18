def getTriangle(a, b, c):
    triangle_list = sorted([a,b,c])

    return triangle_list

def number_round(number):
    number = number * 10000
    number = number // 10

    if(number % 10 >= 5):
        number += 10
    number = number // 10
    number = number / 100

    return number

def abc(a,b,c):
    s = (a+b+c)/2
    area = (s*(s-a)*(s-b)*(s-c))**0.5

    return number_round(area)

number = int(input())

print_list = []
area_list = []

allIsNotTriangle = True

for _ in range(number):

    str = input()
    a,b,c = str.split(" ")
    a = int(a)
    b = int(b)
    c = int(c)

    triangle_list = getTriangle(a,b,c)

    a,b,c = triangle_list

    if(a+b <= c or a == 0 or b == 0 or c == 0):
        print_list.append("not a triangle")

    elif(a==b and b == c):
        print_list.append("equilateral triangle {:.2f}".format(abc(a,b,c)))
        area_list.append(abc(a,b,c))
        allIsNotTriangle = False

    elif(a==b or b == c or c == a and a*a+b*b > c*c):
        print_list.append("isosceles triangle {:.2f}".format(abc(a,b,c)))
        area_list.append(abc(a, b, c))
        allIsNotTriangle = False

    elif((a*a+b*b) < c*c):
        print_list.append("obtuse triangle {:.2f}".format(abc(a,b,c)))
        area_list.append(abc(a, b, c))
        allIsNotTriangle = False

    elif((a*a+b*b) > c*c):
        print_list.append("acute triangle {:.2f}".format(abc(a,b,c)))
        area_list.append(abc(a, b, c))
        allIsNotTriangle = False

    elif((a*a+b*b) == c*c):
        print_list.append("right triangle {:.2f}".format(abc(a,b,c)))
        area_list.append(abc(a, b, c))
        allIsNotTriangle = False

for sentence in print_list:
    print(sentence)
if(allIsNotTriangle == False):
    print("{:.2f}".format(max(area_list)))
    print("{:.2f}".format(min(area_list)))
else:
    print("All inputs are not triangles!")