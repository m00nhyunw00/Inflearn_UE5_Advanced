%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    ;write your code here
    
    mov eax, 0x1234
    mov rbx, 0x12345678
    mov cl, 0xff
    
    mov al, 0x00
    
    ; 메모리 -> 레지스터
    mov rax, a ; <- a 안에 있는 값이 아닌 주소값을 가져옴
    mov rax, [a] ; <- a 주소에 있는 값을 가져옴
    mov al, [a] ; <- a 주소에 있는 값 중 딱 a에 넣었던 값만 가져옴 
    
    ; 레지스터 -> 메모리
    ; mov [a], 0x55 ; <- 크기를 정확하게 명시해주지 않으면 실패함
    mov [a], byte 0x55
    mov [a], word 0x6666 ; <- 옆 주소 b까지 침범함
    mov [a], cl ; <- 이 경우에는 크기 명시 필요 없음

    xor rax, rax
    ret
    
    ; 초기화 된 데이터
    ; [변수 이름] [크기] [초기값]
    ; [크기] db(1) dw(2) dd(4) dq(8)  
section .data
    a db 0x11
    b dw 0x2222
    c dd 0x33333333
    d dq 0x4444444444444444

    ; 초기화 되지 않은 데이터
    ; [변수 이름] [크기] [개수]
    ; [크기] resb(1) resw(2) resd(4) resq(8)  
section .bss
    e resb 10
    