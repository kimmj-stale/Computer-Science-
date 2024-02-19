weight = float(input('수하물의 무게를 입력해주세요 : '))

a = (weight - 20)*4000
plus = a//1000
minus = a%1000

if weight >= 20:
    print('무게가 20kg이 초과되어 추가비용 %d,%d 원이 추가 발생합니다.' %(plus,minus))
else:
    print('수하물의 무게는' , weight , 'kg 입니다.')