
def getTriangle(a, b, c):
    triangle_list = sorted([a,b,c])

    return triangle_list

a = int(input())
b = int(input())
c = int(input())


triangle_list = getTriangle(a,b,c)

a,b,c = triangle_list

if(a+b <= c or a == 0 or b == 0 or c == 0):
    print("not a triangle")

elif(a==b and b == c):
    print("equilateral triangle")

elif(a==b or b == c or c == a and a*a+b*b > c*c):
    print("isosceles triangle")

elif((a*a+b*b) < c*c):
    print("obtuse triangle")

elif((a*a+b*b) > c*c):
    print("acute triangle")

elif((a*a+b*b) == c*c):
    print("right triangle")

