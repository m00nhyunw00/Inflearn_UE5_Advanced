%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    
    GET_DEC 1, al
    GET_DEC 1, num
    
    ; PRINT_DEC 1, al
    ; NEWLINE
    ; PRINT_DEC 1, num
    
    ; 더하기
    ; add a, b (a = a + b)
    ; a는 레지스터 | 메모리
    ; b는 레지스터 | 메모리 | 상수
    ; 단! a, b 모두 메모리는 x
    
    ; 빼기
    ; sub a, b (a = a- b) 
    ; 이하 동일 
    
    add al, 1 ; 레지스터 + 상수
    PRINT_DEC 1, al ; 1 + 1 = 2
    NEWLINE
    
    ; add al, num ; num을 그대로 쓰면 num의 주소값을 가져오므로 어마어마하게 큰 값을 가져와서 충돌
    add al, [num] ; 레지스터 + 메모리 
    PRINT_DEC 1, al ; 2 + 2 = 4
    NEWLINE
    
    mov bl, 3 ; 레지스터 + 레지스터 
    add al, bl ; 4 + 3 = 7
    PRINT_DEC 1, al
    NEWLINE
    
    add [num], byte 1 ; 메모리 + 상수 
    PRINT_DEC 1, [num] ; 2 + 1 = 3
    NEWLINE
    
    add [num], al ; 메모리 + 레지스터
    PRINT_DEC 1, [num] ; 3 + 7 = 10
    NEWLINE
    
    ; 곱하기 연산
    ; 곱셈 연산은 덧셈만큼 간단하게 이루어져있지는 않음 
    ; mul reg
    ; - mul bl => al * bl
    ; -- 연산 결과를 ax에 저장
    ; -mul bx => ax * bx
    ; -- 연산 결과는 dx(상위 16비트) ax(하위 16비트)에 저장
    ; - mul ebx => eax * ebx
    
    ; ex) 5 * 8 은?
    mov ax, 0
    mov al, 5
    mov bl, 8
    mul bl
    PRINT_DEC 2, ax
    NEWLINE
    
    ; 나누기 연산
    ; div reg
    ; - div bl => ax / bl
    ; -- 연산 결과는 al(몫) ah(나머지)
    
    ; ex) 100 / 3 은?
    mov ax, 100
    mov bl, 3
    div bl
    PRINT_DEC 1, al
    NEWLINE
    mov al, ah ; 그대로 ah를 출력하면 오류가 나므로 al로 출력
    PRINT_DEC 1, al
    NEWLINE 

    xor rax, rax
    ret
    
    ; 초기화 된 데이터
    ; [변수 이름] [크기] [초기값]
    ; [크기] db(1) dw(2) dd(4) dq(8)  
;section .data

    

    ; 초기화 되지 않은 데이터
    ; [변수 이름] [크기] [개수]
    ; [크기] resb(1) resw(2) resd(4) resq(8)  
section .bss
    num resb 1
    