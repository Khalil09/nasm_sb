global _test

lfsr_nasm:

    mov esi, 0 ;Cont = 0
    mov eax, 0x13131 ; start_state = seed
    mov ebx, eax ; lfst = start_state
