#def get_max(a , b):
#    if a > b:
#        return a
#    else:
#        return b

#max = get_max(30 , 20)
#print(max)
#------------------------
#def add_multiply(x , y):
#    sum = x + y
#    mult = x * y
#    return sum , mult

#a = int(input('Enter a : '))
#b = int(input('Enter b : '))
#m , n = add_multiply(a , b)
#print(m , n)
#----------------------------
#import math

#x_axis = int(input("x값을 입력하세요: "))
#y_axis = int(input("y값을 입력하세요: "))

#distance = math.sqrt(x_axis**2 + y_axis**2)
#print(distance)
#---------------------------------------------
n_data = []
find_data = 0

num = int(input("배수 입력: "))
Max_num = int(input("최대값 입력: "))
count = 1;

while(1):
    find_data = num*count
    if find_data <= Max_num:
        n_data.append(find_data)
    else:
        break
print(find_data)
count = count + 1
