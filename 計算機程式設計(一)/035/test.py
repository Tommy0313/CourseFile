a = [1,2,3,4,5]
b = [1,2]

d = [True for c in b if c not in a]

print(d)

if d:
    print("Hello")
