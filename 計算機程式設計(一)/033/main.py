import math


def distance(new_dict, index_list):
    if(len(index_list) == 1):
        return new_dict
    for i in range(1,len(index_list)):
        new_dict[str(index_list[0][0])+" "+str(index_list[i][0])] = math.sqrt((index_list[0][1]-index_list[i][1])**2 + (index_list[0][2]-index_list[i][2])**2+ (index_list[0][3]-index_list[i][3])**2)

    return distance(new_dict, index_list[1:])

num = int(input())

distance_dict = {}
index_list = []
index_dict = {}


for i in range(num):
    index, x, y, z = list(map(int, input().split()))
    index_list.append([index, x, y, z])
    index_dict[index] = str(x) + " " + str(y) + " " + str(z)

distance_dict = distance(distance_dict,index_list)

first = min(distance_dict,key=distance_dict.get)
distance_dict.pop(first)
print(first + " " + index_dict[int(first.split()[0])] + " " + index_dict[int(first.split()[1])])

first = min(distance_dict,key=distance_dict.get)
distance_dict.pop(first)
print(first + " " + index_dict[int(first.split()[0])] + " " + index_dict[int(first.split()[1])])

first = min(distance_dict,key=distance_dict.get)
distance_dict.pop(first)
print(first + " " + index_dict[int(first.split()[0])] + " " + index_dict[int(first.split()[1])])

