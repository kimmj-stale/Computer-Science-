#weight = float(input('수화물의 무게를 입력해 주세요: '))

#a = (weight - 20)
#b = a*4000

#if weight > 20:
#    print('무게가', a , '만큼 초과되어', b , '원 만큼 초과 지불되어야 합니다.')
#else:
#    print('수하물에 대한 추가 금액은 없습니다.')

#print('감사합니다.')

#grade = int(input('사과의 품질을 입력하세요 (좋음:3 중간:2  나쁨:1):'))
#price = int(input('사과 가격을 입력하세요: '))

#if grade == 3:
#    print(grade*10*price)

#if grade == 2:
#    print(grade*5*price)

#if grade == 1:
#    print('구매하실 수 없습니다.')

#appleQuality = input('사과 상태를 입력하세요: ')
#strappleQuality = input('사과 상태를 입력하세요: ') -----> 변수형을 잘 판별하기 위해 앞에 자료형 정보를 붙여놓으면 편하다.
#정수형 = nApple     실수형 = fApple
#함수에서의 자료형 = m_nApple    외부에서의 자료형 = g_nApple

#score = int(input('성적을 입력하세요: '))

#if score >= 90:
#    print('A')
#elif score >= 80:
#    print('B')
#elif score >= 70:
#    print('C')
#elif score >= 60:
#    print('D')
#else:
#    print('F')
#print('학점입니다.')
#----------------
#a = int(input('숫자를 입력하세요: '))

#if a > 0:
#    print('입력된 정수는 양수입니다.')
#elif a == 0:
#    print('입력된 정수는 0입니다.')
#else:
#    print('입력된 정수는 음수입니다.')
#---------------
#nwork_time = int(input('근무 시간을 입력하세요: '))
#nwage = int(input('2023년도 기준 최저 임금을 입력하세요: '))

#if nwork_time <= 40:
#    ntotalpay = nwork_time*nwage , '원'
#else:
#    ntotalpay = 40*nwage + (nwork_time - 40)*(nwage*1.5)

#a = ntotalpay//1000
#b = ntotalpay%1000
#if ntotalpay >= 10000:
    

#if b > 0:
#    print("총 %d,%d원 수령 가능합니다." %(a, b))
#else:
#    print("총 %d,000원 수령 가능합니다." %(a))

#반복문 ----------
#i = 0
#while i < 10:
#    i = i + 1
#    print('hello')

#-----------------
#i = 1
#sum = 0
#limit = int(input('어디까지 더할 것인지 구하시오: '))

#while i <= limit:
#    sum = sum + i
#    i = i + 1

#print('1부터' , limit , '까지 정수의 합은' , sum , '이다')
