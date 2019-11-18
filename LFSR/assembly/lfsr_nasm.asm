global lfsr_nasm
section .text

lfsr_nasm:
    mov eax, 0 ;Cont = 0
    mov bx, 0x1313 ; lfst = start_state = seed
    do:
        mov cx, bx ; cx = lfst
        shr cx, 2 ; lfsr >> 2
        mov dx, bx; dx = lfst
        shr dx, 3; lfst >> 3
        xor cx, dx ; lfst >> 2 ^ lfsr >> 3
        mov dx, bx ; dx = lfsr
        shr dx, 4 ; dx = lfst >> 4
        xor cx, dx; lfst >> 2 ^ lfsr >> 3 ^ lfsr >> 4
        mov dx, bx ; dx = lfsr
        shr dx, 13 ; dx = lfst >> 13
        xor cx, dx; lfst >> 2 ^ lfsr >> 3 ^ lfsr >> 4 ^ lfsr >> 13
        and cx, 1 ;cx = bit
        shr bx, 1 ;lfsr >> 1
        shl cx, 15 ; bit << 15
        or bx, cx ; lfsr = (lfsr >> 1) | (bit << 15);
        ;and bx, 0x003F ;lfsr = lfsr & MASK;
        inc eax ; cont++
        cmp eax, 65536; cont != 65536
        jne do ;
    xor ebx, ebx
    ret
