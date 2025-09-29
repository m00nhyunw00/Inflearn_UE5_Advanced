%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    
    ; 반복문 (while, for)
    ; 특정 조건을 만족할 때까지 반복해서 실행~
    
    ; ex) Hello World을 10번 출력해야한다면?

    mov ecx, 10 ; 카운팅을 위한 변수
    
LABEL_LOOP:
    PRINT_STRING msg
    NEWLINE
    dec ecx ; sub ecx, 1과 동일한데 조금 더 빠름
    cmp ecx, 0
    jne LABEL_LOOP
    
    
    ; 연습 문제) 1에서 100까지의 합을 구하는 프로그램
    mov eax, 100 ; 최종 목적지
    xor ebx, ebx ; 결과물 / mov ebx, 0 ebx와 같음
   
    ; 1번 풀이 
LABEL_SUM1:
    inc ecx ; add exc, 1과 동일
    add ebx, ecx
    cmp ecx, eax
    jne LABEL_SUM1
    
    PRINT_DEC 4, ebx
    NEWLINE
    
    xor ebx, ebx ; 2번 풀이를 위한 초기화
    
    ; 2번 풀이
LABEL_SUM2:
    add ebx, eax
    dec eax
    cmp eax, 0
    jne LABEL_SUM2
    
    PRINT_DEC 4, ebx
    NEWLINE
    
    
    ; loop [라벨]
    ; - ecx에 반복 횟수 
    ; - loop 할 때마다 ecx 1 감소, 0이면 빠져나감. 아니면 라벨로 이동
    
    mov ecx, 100
    xor ebx, ebx ; 초기화
LABEL_LOOP_SUM:
    add ebx, ecx
    loop LABEL_LOOP_SUM
    
    PRINT_DEC 4, ebx
    NEWLINE
    
    
        
    xor rax, rax
    ret
    
    ; 초기화 된 데이터
    ; [변수 이름] [크기] [초기값]
    ; [크기] db(1) dw(2) dd(4) dq(8)  
;section .data
    msg db 'Hello World', 0x00

    ; 초기화 되지 않은 데이터
    ; [변수 이름] [크기] [개수]
    ; [크기] resb(1) resw(2) resd(4) resq(8)  
section .bss
    num resb 1
    