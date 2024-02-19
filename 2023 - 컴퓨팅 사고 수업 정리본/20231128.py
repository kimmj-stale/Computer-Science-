#isalpha() - 원본 문자열이 숫자와 기호를 제외한 알파벳으로만 이루어져 있으면 true반환
#isnumeric() - 원본 문자열이 숫자로만 이루어져 았으면 true를 반환
#isdigit() - 원본 문자열이 숫자로만 이루어져 았으면 false를 반환
#isalnum() - 
#isspace()
#------------------------------------------------------------------
#a = "hello world!"
#b = a.replace('world' , 'korea')
#print(b)
#---------------------------------
#s = '/'
#a = s.join('hello world')
#print(a)
#--------------------------
#a = ' 파 이 썬 '
#b = a.strip() - 문자열 양쪽 공백 삭제
#c = a.lstrip() - 문자열 왼쪽 공백 삭제
#d = a.lstrip() - 문자열 오른쪽 공백 삭제
#print(b)
#print(c)
#print(d)
#-------------------------------------
#a = 'PythoN'
#b = a.upper() - 문자열 전체 대문자화
#c = b.lower() - 문자열 전체 소문자화
#d = b.isupper() - 문자열에 대문자가 존재하면 true 반환
#e = b.islower() - 문자열에 대문자가 존재하면 false 반환
#print(b)
#print(c)
#print(d)
#print(e)
#----------------
#st = 'Python is widely used high-level language and Python was conceived in the late 1980s'
#st = st.lower()
#cnt = st.count('python') - 해당 문자열 개수
#print(cnt)
#-------------------------------------------------------------------------------------------
#st = input("시간을 입력하세요: ")
#t = st.split(':') - 특정 문구를 중심으로 문자열을 분리
#hour = int(t[0])*60*60
#min = int(t[1])*60
#sec = int(t[2])
#total = hour + min + sec
#print(total , '초')
#------------------------------------------------
#a = ['삼성전자' , '카카오' , 'LG에너지솔루션']
#b = a.append('네이버') - 
#print(a)
#---------------------------------------
#people = "연세대학교 미래캠퍼스".split()
#people = "연세대학교 미래캠퍼스".split(" ")
#phone = "010-7730-9649".split("-")
#List1 = list(range(1 , 100 , 2))
#List2 = list(range(100 , 0 , -2))
#print(people)
#print(List1)
#print(List2)
#print(List1[3])# - 리스트에서 n번째 요소를 알고싶을 때
#-----------------------------------------------
#List = [1 , 2 , 3 , 4 , 5]
#List[3] = 14 - 리스트 요소 교체
#List1 = List*3 - 리스트 곱셈이 가능하다
#List2 = List + List - 리스트 덧셈이 가능하다
#List0 = List - List - 리스트 뺄셈이 가능하다
#print(List)
#----------------------------
#item = input("찾을 문자를 입력하세요: ")
#list = ['A' , 'B' , 'C' , 'D']

#if item in list:
#    print("리스트에 존재합니다!")
#else:
#    print("죄송합니다. 해당 문자를 찾을 수 없습니다.")
#----------------------------------------------
#a = [1,2,3,4,5,6,7,8,7,6,5,4,3,2,1]
#a.append() - 추가
#a.extend() - 
#a.insert(i, x)
#a.pop()
#a.clear()
#a.count() - 개수 
#a.sort()# - 내림차순으로 정렬
#a.index(2)
#a.remove() - 제거
#a.reverse() - 
#a.copy()
#print(a)
#---------------------------------
#n1 , n2 , n3 , n4 , n5 = input("Input 5 integers: ").split(",") - 다섯가지 입력값을 입력
#detalist = [int(n1) , int(n2) , int(n3) , int(n4) , int(n5)] - 입력된 값을 리스트화

#total = sum(detalist) - 리스트의 요소 전체 합
#avg = total/5

#print(detalist)
#print("평균:" , avg)
#---------------------------------------------------------------
#딕셔너리 자료형
#dict_b = {
#    "director":["안소니 루소" , "조 루소"],
#    "cast":["아이언맨" , "타노스" , "토르" , "닥터 스트레인지" , "헐크"] - 딕셔너리 자료형 유형
#}
#print(dict_b["director"])
#----------------------------------------------------------------------------------
#dict_mango = {
#    "name":"건조 망고",
#    "type":"당절임",
#    "ingredient":["망고" , "설탕" , "메타중아황산나트륨" , "치지황색소"],
#    "origin":"필리핀"
#}
#dict_mango["price"] = 5000# - 딕셔너리에 새로운 요소 입력
#del dict_mango["origin"]# - 딕셔너리 요소를 제거
#print(dict_mango["ingredient"])
#print(dict_mango["price"])
#-----------------------------------------------------------------
