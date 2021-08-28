; binarySearch.s
;
; Lab 9: Post-Lab
; Name: Gizella Wade
; ID: grw7b
;
; Parameter 1 is a pointer to the int array - rdi
; Parameter 2 is the left index in the array - rsi
; Parameter 3 is the right index in the array - rdx
; Parameter 4 is the target - rcx
; 
; optimizations: lea instead of mov, shift instead of idiv, dec and inc instead of sub and add

	global binarySearch

	section .text


	xor r10, r10	; int m, middle value

	xor r11, r11	; int temp, stores temp values

	

binarySearch:

	cmp rsi, rdx 					; checks that left index <= right
	jg invalid						; if not then invalid, jump to invalid


	lea r10, [rsi]					; m = left
	add r10, rdx					; m = left + right
	shr r10, 1						; m = (left + right)/2



	cmp ecx, [rdi + 4*r10] 			; compares the m to target
	je	done						; if they are equal, then done


	cmp ecx, [rdi + 4*r10] 			; if the value of m < target
	jl firstHalf					; search through first half of array
	
	
	cmp ecx, [rdi + 4*r10] 			; if the value of m > target
	jg secondHalf					; search through second half of array

	ret 
	


firstHalf:
	dec r10							; m = m -1
	lea rdx, [r10]					; right index = m
	jmp binarySearch 				; restart loop
	


secondHalf:
	inc r10							; m = m +1
	lea rsi, [r10]					; left index = m
	jmp binarySearch				; restart loop



done:
	lea rax, [r10]					; puts value of m, index of target, into return register
	ret


invalid:
	mov rax, -1						; if input invalid, returns -1
	ret