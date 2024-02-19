#dict_mango = {
#    "name":"건조 망고",
#    "type":"당절임",
#    "ingredient":["망고" , "설탕" , "메타중아황산나트륨" , "치지황색소"],
#     "origin":"필리핀"
#}
#value = dict_mango.get("존재하지 않는 키")
#print("값:" , value)

#if value == None:
#    print("존재하지 않는 키에 접근했습니다.")
#-------------------------------------------------------------------
#numbers = [1 , 2 , 3 , 8 , 4 , 3 , 2 , 1 , 9 , 5 , 4 , 9 , 7 , 2 , 1 , 3 , 5 , 4 , 8 , 9 , 7 , 2 , 3]

#counter = {

#}
#for number in numbers:
#    if (counter.get(number) == None):
#        counter[number] = 1
#    else:
#        counter[number] = counter[number] + 1
#print(counter)
 #-----------------------------------------------
#numbers = [1 , 2 , 3 , 8 , 4 , 3 , 2 , 1 , 9 , 5 , 4 , 9 , 7 , 2 , 1 , 3 , 5 , 4 , 8 , 9 , 7 , 2 , 3]   
#a = int(input("숫자를 입력하세요"))
#num_a = numbers.count(a)

#if num_a == 0:
#    print("찾으시는 수가 목록에 없습니다.")
#else:
#    print(a , "가 " , num_a , "개 만큼 있습니다.")

#----------------------------------------------
#character = {
#    "name":"기사",
#    "level":12,
#    "items":{
#        "sword":"불꽃의 검",
#        "armor":"풀플레이트"
#    },
#    "skill":{
#        "베기",
#        "세게 베기",
#        "아주 세게 베기"
#    }
#}

#for key in character:
#    if type(character[key]) is str:
#        print(key, ":" , character[key])
#    elif type(character[key]) is int:
#        print(key, ":" , character[key])
#    elif type(character[key]) is dict:
#        print(key, ":" , character[key])
#    elif type(character[key]) is list:
#        count = 0
#        for key_list in character[key]:
#            print(key_list)
#            print(key, ":" , list(character[key])[count])
#            count = count + 1
#-----------------------------------------------------------
#def 함수 지정
#def sum(a , b):
#   return a + b
#x = 3
#y = 4
#result = sum(x , y)
#print(result)
#---------------------
#def get_sum(start , end + 1):
#    sum = 0
#    for i in range(start , end):
#        sum = sum + i
#    return sum

#result = get_sum(1 , 100)
#print(result)
#---------------------------------
#def calc(x , y , z):
#    return (x + y)*z
#result = calc(z = 30 , x = 10 , y = 20)
#print(result)
#---------------------------------------
