#raw = input("계좌번호를 입력하세요: ")
#processed = ""

#for c in raw:
#    if c != "-":
#        processed = processed + c
#
#print(processed)
#---------------------------------
#매서드 문자열
#raw = input("계좌번호를 입력하시오: ")
#rep = ""

#rep = raw.replace('-'' ')
#-------------------------------
#range 함수
#a = range(0 , 10 , 1)
#print(a)
#-----------------------------
#for구문을 이용한 range함수
#for i in range(10 , -1 , -1):
#    print(i , ": 안녕하세요!")
#------------------------------
#for문과 range문 활용 2
#for i in range(0 , 10 , 1):
#    k = i + i
#    print(k)
#----------------------------
#passkey = ""
#while passkey != "pythonisfun":
#    passkey = input("암호를 입력하세요: ")
#print("로그인 되었습니다.")
#--------------------------
#password = "1234"
#passkey = ""

#while passkey != password:
#    passkey = input("암호를 입력하세요: ")
#    if passkey == "change":
#        new_passkey = input("새로운 암호를 입력하세요: ")
#    print("암호가 다릅니다. 암호를 변경하려면 'change'를 입력하세요.")

#print("환영합니다!")
#----------------------------
#sum = 0
#start_str = input('시작 숫자를 입력하세요: ')
#s_str = start_str

#while start_str.isnumeric() == False:
#    start_str = input('숫자만 입력 가능합니다. 다시 입력해주세요.: ')
#start_str = int(start_str)

#end_str = input('시작 숫자를 입력하세요: ')

#while end_str.isnumeric() == False:
#    end_str = input('숫자만 입력 가능합니다. 다시 입력해주세요.: ')
#end_str = int(end_str)

#while start_str <= end_str:
#    sum = sum +start_str
#    start_str = start_str + 1

#print(s_str , "부터" , end_str , "까지의 정수의 합은" , sum , "입니다.")
#-----------------------------------------------------------------
#sum = 0
#b = 0

#for i in range(500 , 1001 , 1):
#    if i%2 != 0:
#        b = i
#    sum = b + sum
#    print("500과 1000 사이의 홀수의 합은" , sum , "입니다.")
#-------------------------------------------------------
#import turtle as t

#angle_inp = int(input("원하는 각도를 입력하세요: "))
#length_inp = int(input("원하는 길이를 입력하세요: "))
#fx = Tr.Turtle()

#for n in range(0,angle_inp):
#    if angle_inp == 3:
#        t.right(120)
#elif:
#        t.right(90)

