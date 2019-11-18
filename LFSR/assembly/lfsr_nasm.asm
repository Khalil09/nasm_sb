section .text
global lfsr_nasm

lfsr_nasm:
    push dword ebx;
    mov esi, edi ; vec
    mov eax, 0 ;Cont = 0
    mov ebx, 0x1313 ; lfst = start_state = seed
    do:
        mov ecx, ebx ; ecx = lfst
        shr ecx, 1 ; lfsr >> 2
        mov edx, ebx ; edx = lfst
        shr edx, 5; lfst >> 3
        xor ecx, edx ; lfst >> 2 ^ lfsr >> 3
        mov edx, ebx ; edx = lfsr
        shr edx, 7 ; edx = lfst >> 4
        xor ecx, edx; lfst >> 2 ^ lfsr >> 3 ^ lfsr >> 4
        mov edx, ebx ; edx = lfsr
        shr edx, 13 ; edx = lfst >> 13
        xor ecx, edx; lfst >> 2 ^ lfsr >> 3 ^ lfsr >> 4 ^ lfsr >> 13
        and ecx, 1 ;ecx = bit
        shr ebx, 1 ;lfsr >> 1
        shl ecx, 23 ; bit << 15
        or ebx, ecx ; lfsr = (lfsr >> 1) | (bit << 15);
        mov dword [esi + eax], ebx
        inc eax ; cont++
        cmp eax, 16777216; cont != 65536
        jne do ;
    pop dword ebx;
    ret
