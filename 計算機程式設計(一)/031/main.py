def graycode(n, k):
    if(n == 1):
        return str(k)
    elif(k<(2**(n-1))):
        return "0" + graycode(n-1 ,k)
    elif (k >= (2 ** (n - 1))):
        return "1" + graycode(n - 1, 2 ** (n)-1-k)

input_list = []

while True:
    nandk = input()
    if(nandk == "-1"):
        break
    else:
        n, k = nandk.split(" ")
        input_list.append([int(n), int(k)])

for n,k in input_list:
    print(graycode(n,k))