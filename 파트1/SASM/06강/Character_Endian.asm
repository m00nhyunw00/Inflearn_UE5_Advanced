%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    
    PRINT_STRING msg

    xor rax, rax
    ret
    
    ; 초기화 된 데이터
    ; [변수 이름] [크기] [초기값]
    ; [크기] db(1) dw(2) dd(4) dq(8)  
section .data

    msg db 'Hello World', 0x00s
    ; == 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x0}
    ; 문자열의 끝에 NULL을 붙여 문자열의 종료 지점을 명시
    
    a db 0x11, 0x11, 0x11, 0x11  
    
    b dd 0x12345678

    ; 초기화 되지 않은 데이터
    ; [변수 이름] [크기] [개수]
    ; [크기] resb(1) resw(2) resd(4) resq(8)  
section .bss
    e resb 10
    