import math

a = int(input())
b = int(input())
c = int(input())

num = b*b-4*a*c

T = math.sqrt(abs(b*b-4*a*c))


if(num>=0):
    x1 = (-b + T) / (2 * a)
    x2 = (-b - T) / (2 * a)
    print("%.1f" % (x1))
    print("%.1f" % (x2))
elif(num<0):
    x11 = (-b ) / (2 * a)
    x21 = (-b ) / (2 * a)
    x12 = (+ T) / (2 * a)
    x22 = (T) / (2 * a)
    print("%.1f+%.1fi" % (x11, x12))
    print("%.1f-%.1fi" % (x21, x22))