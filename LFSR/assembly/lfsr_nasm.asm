section .text
global lfsr_nasm

lfsr_nasm:
    push ebx;
    push edi
    push esi
    mov esi, [esp+16] ; vec
    mov eax, 0 ;Cont = 0
    mov ebx, 0x1313 ; lfst = start_state = seed
    do:
        mov ecx, ebx ; ecx = lfst
        shr ecx, 1 ; lfsr >> 1
        mov edx, ebx ; edx = lfst
        shr edx, 5; lfst >> 5
        xor ecx, edx ; lfst >> 1 ^ lfsr >> 5
        mov edx, ebx ; edx = lfsr
        shr edx, 7 ; edx = lfst >> 7
        xor ecx, edx; lfst >> 1 ^ lfsr >> 5 ^ lfsr >> 7
        mov edx, ebx ; edx = lfsr
        shr edx, 13 ; edx = lfst >> 13
        xor ecx, edx; lfst >> 1 ^ lfsr >> 5 ^ lfsr >> 7 ^ lfsr >> 13
        and ecx, 1 ;ecx = bit
        shr ebx, 1 ;lfsr >> 1
        shl ecx, 23 ; bit << 23
        or ebx, ecx ; lfsr = (lfsr >> 1) | (bit << 23);
        add esi, 4
        mov dword [esi-4], ebx
        inc eax ; cont++
        cmp eax, 16777216; cont != 16777216
        jne do ;
    pop esi
    pop edi
    pop ebx;
    ret
