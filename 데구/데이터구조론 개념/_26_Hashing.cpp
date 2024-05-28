/**
 * Hash (해시)
 * 산술적인 연산을 이용하여 키가 있는 위치를 계산하여 바로 찾아가는 계산 검색 방식
*/

/** 해시 연산
 * 검색 방식
- 키 값을 해시 함수를 이용해 위치로 변환시켜주고 그 값을 이용해 해시 테이블에서 바로 탐색

 * 해시 함수
- 키 값을 원소의 위치로 변환시켜주는 함수

 * 해시 테이블
- 해시 함수에 의해 계산된 주소가 저장된 표
*/

/**
 * 해시 함수의 조건
 * 해시 함수는 연산이 쉬워야 한다
- 해시 함수를 이용하여 탐색하는 시간이 기본적인 탐색 시간보다 빨라야 하므로 해시 함수는 간단하면서 빨라야 한다
 * 해시 함수는 충돌이 적어야 한다
- 충돌이 많다는 것은 버킷에 할당받는 키 값이 많다는 뜻이므로 좋은 해시 함수가 될 수 없다
- 특정 버킷에만 몰려 오버플로가 생길 수가 있으므로 충돌이 적어야 한다
*/

/** 해시 함수의 종류
 * 중간 제곱 함수
- 특정 비트 향식의 키 값을 제곱하여 중간의 적당한 값을 채택하여 주소로 사용
 * 제산 함수
- 키 값을 해시 테이블의 크기값으로 나눈 나머지 (Mod)값을 주소로 사용
- 이와 반대로 승산 함수는 두 값을 곱한 값을 주소로 사용
 * 접지 함수
- 키의 비트 수가 해시 테이블 인덱스의 비트 수보다 큰 경우에 주로 사용
 * 경계 접지 함수
- 분할된 각 경계를 기준으로 접으면서 서로 마주보도록 배치하고 더하는 방법
 * 숫자 분석 함수
- 키 값을 이루고 있는 각 자릿수의 분포를 분석하여 해시 주소로 사용
 * 진법 변환 함수
- 키 값이 10진수가 아닌 다른 진수일 때, 10진수로 변환하고 해시 테이블 주소로 필요한 자릿수만큼만 하위자리의 수를 사용하는 방법
 * 비트 추출 함수
- 해시 테이블의 크기가 2 ^ k일 때 키 값을 이진 비트로 놓고 임의의 위치에있는 비트들을 추출하여 주소로 사용하는 방법
*/

/** 해시의 오버플로를 해결하는 방법
 * 선형 개방 주소법
- 해싱 함수로 구한 버킷에 빈 슬롯이 없어서 오버플로가 발생하면, 그 다음 버킷에 빈 슬롯이 있는지 조사
*/