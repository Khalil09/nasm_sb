; Grupo 7
;
; Implementação do gerador de números aleatórios com LFSR em NASM
;
; Felipe da Costa Malaquias 13/0044440
;
; Comando para gerar objeto: nasm -f elf 7-01-lfsr-nasm.asm
; 
; Comando para compilação: gcc -m32 7-01-lfsr-nasm.o -o lfsr asm_io.o
;
; (necessário gerar objeto do asm_io: nasm -f elf -d ELF_TYPE asm_io.asm)


%include "asm_io.inc"
%define NN 256 ; numero de classes

SECTION .data
	output1 db "classe ", 0
	output2 db " tem ", 0
	output3 db " elementos", 0
	seed	dq 32790	; seed inicial

SECTION .bss
	class resd NN ; vetor com a frequencia de cada classe

SECTION .text
global main
main:

	mov ebx, seed
	mov edx, 0
	do:
		; operacoes da equacao escolhida
		mov ecx, ebx
		mov eax, ebx
		shr ecx, 2
		xor eax, ecx
		shr ecx, 1
		xor eax, ecx
		shr ecx, 2
		xor eax, ecx
		shr ecx, 3
		xor eax, ecx
		shr ecx, 5
		xor eax, ecx
		shr ecx, 7
		xor eax, ecx
		and eax, 1

		shl eax, 15
		shr ebx, 1
		or eax, ebx
		mov ebx, eax

		and eax, 0x00FFFFFF

		; Calculando a classe em que o numero pertence
		and eax, 0x0FFF

		; incrementa um nesse classe no vetor de frequencias
		add dword [class + eax*4], 1

		inc edx
		cmp edx, 40960
	jne do

	; imprime as frequencias
	mov ecx, 0
	results:
		mov eax, output1
		call print_string

		mov eax, ecx
		call print_int

		mov eax, output2
		call print_string

		mov eax, [class + ecx*4]
		call print_int

		mov eax, output3
		call print_string

		call print_nl
		inc ecx
		cmp ecx, NN
	jne results


	; fim do programa

	mov ebx, 0
	mov eax, 1
	int 0x80