/**
 * queue
 * 선입선출 리스트 형태, stack과 반대의 개념이다.
 * 가장 먼저 들어온 자료가 가장 나중에 들어온다. 입력 순서대로 출력이 필요한 경우 사용된다
 * 한쪽 끝에 삽입되고 반대쪽 끝에 삭제가 일어나는 자료 구조 형태
 * thread나 process의 관리에 사용
*/

/**
 * enqueue : rear에서 data가 삽입됨
 * dequeue : front에서 data가 삭제됨

 * stack은 삽입과 삭제 모두 top에서 일어나 top 메모리만 할당하면 됐지만
    queue는 rear과 front 두 메모리 할당이 필요하다.
*/