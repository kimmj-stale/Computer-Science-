#import turtle as t

#angle_inp = int(input("원하는 각도를 입력하세요: "))
#length_inp = int(input("원하는 길이를 입력하세요: "))
#fx = Tr.Turtle()

#for n in range(0,angle_inp):
#    if angle_inp == 3:
#        t.right(120)
#    else:
#        t.right(90)
#-----------------------------------------------
#for i in range(0 , 3 , 1):
#    for k in range(0 , 2, 1):
#        print("즐거운 파이썬  i값: " , i , "k값: " , k)
#---------------------------------------------------
#count = 0

#for i in range(0 , 7 , 1):
#    for k in range(0 , 7 , 1):
#        if i + k == 6:
#            count = count + 1
#        print("둘의 합이 6인 경우의 수는 " , count , "회 입니다!")
#------------------------------------------------------------
#반복문 제어
#total = 0

#for k in range(1 , 100 , 1):
#    if total >= 1000:
#        break
#    else:
#        total = total + k
#        print(total)
#----------------------------
#while True:
#    a = int(input("첫 번째 숫자를 입력하세요: "))
#    b = int(input("두 번째 숫자를 입력하세요: "))
#    if (a or b) != 0:
#        sum = a + b
#        print(sum)
#        continue
#    else:
#        break
#-------------------------------------------
#import turtle

#def turtle_game():
#    window = turtle.Screen()
#    window.title("Turtle 게임")
#    window.bgcolor("white")

#    player = turtle.Turtle()
#    player.shape("turtle")
#    player.color("blue")
#    player.speed(0)

    # 이동 함수
#    def move_up():
#        y = player.ycor()
#        y += 20
#        player.sety(y)

#    def move_down():
#        y = player.ycor()
#        y -= 20
#        player.sety(y)

#    def move_left():
#        x = player.xcor()
#        x -= 20
#        player.setx(x)

#    def move_right():
#        x = player.xcor()
#        x += 20
#        player.setx(x)

#    def move_up_left():
#        x = player.xcor()
#        y = player.ycor()
#        x -= 20
#        y += 20
#        player.goto(x, y)

#    def move_up_right():
#        x = player.xcor()
#        y = player.ycor()
#        x += 20
#        y += 20
#        player.goto(x, y)

#    def move_down_left():
#        x = player.xcor()
#        y = player.ycor()
#        x -= 20
#        y -= 20
#        player.goto(x, y)

#    def move_down_right():
#        x = player.xcor()
#        y = player.ycor()
#        x += 20
#        y -= 20
#        player.goto(x, y)

    # 이벤트 처리
#    window.listen()
#    window.onkeypress(move_up, "w")
#    window.onkeypress(move_down, "s")
#    window.onkeypress(move_left, "a")
#    window.onkeypress(move_right, "d")
#    window.onkeypress(move_up_left, "q")
#    window.onkeypress(move_up_right, "e")
#    window.onkeypress(move_down_left, "z")
#    window.onkeypress(move_down_right, "c")

    # 게임 루프
  #  while True:
 #       window.update()

#turtle_game()
#---------------------------------------------------
#numbers = [ 5, 15 , 6 , 20 , 7 , 25]

#for number in numbers:
#    if number < 10:
#        continue
#    print(number)
#--------------------------------------
#sum = 0

#for i in range(1 , 101 , 1):
#    if i %3 == 0:
#        continue
#    sum  = sum + i
#    print(sum)
#----------------------------