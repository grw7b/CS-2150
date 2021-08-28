; threexplusone.s
;
; Lab 9: Pre-Lab
; Name: Gizella Wade
; D; grw7b
;
; Parameter 1 (in rdi) is x
;
; optimizations: lea instead of mov/imul and add, shift instead of idiv

	global threexplusone

	section .text


threexplusone:

	; Subroutine body:
	xor	rax, rax	; zero out the return register
	xor	r10, r10	; zero out the counter c
	xor	r11, r11	; zero out the temp 

	

start:
	cmp rdi, 1		; if x = 1, then done
	je done


	lea r11, [rdi]	; stores x into temp 

	shr r11, 1 		; x % 2 == 0
	jc odd


	shr rdi, 1 		; divide x by 2
	inc r10			; increment c, c++
	call start		; recurse back

	ret


odd:
	lea rdi, [4*rdi - rdi + 1]	; x = 3x + 1

	inc r10 					; increment c, c++

	call start					; recurse back 

	ret

done:
	lea rax, [r10]
	ret



