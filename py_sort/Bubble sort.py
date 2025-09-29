list = [64, 34, 25, 12, 22, 11, 90]

for i in range(len(list)):
    for j in range(len(list)-1):
        if list[j] > list[j+1]:
            list[j], list[j+1] = list[j+1], list[j]

print("Sorted list is:")
for i in range(len(list)):
    print(list[i])