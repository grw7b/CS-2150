; linearSearch.s
;
; Parameter 1 (in rdi) is arr 
; Parameter 2 (in rsi) is size
; Parameter 3 (in rdx) is target
;

	global linearSearch

	section .text

linearSearch:

	; Subroutine body:

	xor	rax, rax	 ; zero out the return register
	xor	r10, r10	 ; zero out index, i
	
searchLoop:	
	cmp	r10, rsi	 		; does i == size?
	je	notInLoop			; if so, we are done with the loop

	cmp edx, [rdi + 4*r10]	; compare a[i] to target
	je	done
	
	inc r10

	jmp searchLoop			; restart loop


notInLoop:	
	mov rax, -1
	ret


done:
	mov rax, r10
	ret



