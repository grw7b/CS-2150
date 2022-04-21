; mathlib.s
;
; Lab 8: Pre-Lab
; Name: Gizella Wade
; D; grw7b
;
; Parameter 1 (in rdi) is x
; Parameter 2 (in rsi) is y
;

	global product
	global power

	section .text



product:

	; Subroutine body:
	xor	rax, rax	 ; zero out the return register
	xor	r10, r10	 ; zero out the counter i


_productLoop:	
	cmp	r10, rsi	 	; does i == y?
	je	_productDone 	; if so, we are done with the loop

	add	rax, rdi 		; add rax+=x

	inc	r10		 		; increment our counter i
	jmp _productLoop	; done with this loop iteration, restart loop


_productDone:	
	ret 	; return product





power:
	; Subroutine body:
	xor	rax, rax	 ; zero out the return register

	xor	r11, r11	 ; set r11 to 0 
	mov r11, rsi 	 ; set r11 to y  


_powerRecurse:
	cmp r11, 0	     ; check if y = 0
	je _baseZero

	cmp r11, 1		 ; check if y = 1
	je _baseOne

	
	dec r11 		; y--
	call _powerRecurse	; (x,y-1)

	xor rsi, rsi 	; set y to 0
	add rsi, rax 	; set y to rax

	call product 	; call product to compute power 


	ret

_baseZero:
	mov rax, 1
	ret

_baseOne:
	mov rax, rdi
	ret

