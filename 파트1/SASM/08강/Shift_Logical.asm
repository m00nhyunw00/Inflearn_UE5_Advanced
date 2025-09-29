%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    
    ; 쉬프트(shift) 연산, 논리(Logical) 연산
    
    mov eax, 0x12345678
    PRINT_HEX 4, eax
    NEWLINE
    shl eax, 8 ; 왼쪽으로 8칸 쉬프트 (8비트가 손실됨)
    PRINT_HEX 4, eax
    NEWLINE
    shr eax, 8 ; 오른쪽으로 8칸 쉬프트 
    PRINT_HEX 4, eax
    NEWLINE
    
    ; 응용 사례 
    ; 곱셈, 나눗셈에 유용
    ; 게임 서버에서 ObjectID를 만들어줄 때 
    
    ; not and or xor
    
    ; 조건A: 잘생겼다
    ; 조건B: 키가 크다
      
    ; not A : 잘생겼다의 반대 -> (0이면 1, 1이면 0)
    ; A and B : 잘생겼고 and 키도 크고 -> 둘다 1이면 1, 아니면 0
    ; A or B : 잘생겼거나 or 키가 크거나 -> 둘중 하나라도 1이면 1, 아니면 0 
    ; A xor B : 잘생기고 작거나 or 못생기고 크거나 -> 둘다 1이거나 둘다 0이면 0, 아니면 1
    
    mov al, 0b10010101
    mov bl, 0b01111100
    
    ; 0b 0001 0100 = 0x14
    and al, bl ; al = al and bl
    PRINT_HEX 1, al
    NEWLINE
    
    ; 0b 11-- 1-11 = 0xeb
    not al
    PRINT_HEX 1, al
    NEWLINE
    
    ; 응용 사례
    ; bitflag

    mov al, 0b10010101
    mov bl, 0b01111100
    
    NEWLINE
    PRINT_HEX 1, al;
    NEWLINE
    xor al, bl
    PRINT_HEX 1, al;
    NEWLINE
    xor al, bl
    PRINT_HEX 1, al;
    NEWLINE
    ; 동일한 값으로 xor 두번하면 자기 자신으로 되돌아오는 특성
    ; 암호학에서 유용하다! - 대칭키 암호화에서 사용 (value xor key)
 
    ; mov al, 0과 같은 효과를 내는데 더 효율적임
    xor al, al
    PRINT_HEX 1, al
    
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
    