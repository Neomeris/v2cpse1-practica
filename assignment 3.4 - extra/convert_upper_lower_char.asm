	.cpu cortex-m0
	.text
	.align 2
	.global convert_upper_lower_char
	
convert_upper_lower_char:
	push { lr }
check_upper:
	mov r4, r0
	sub r4, #'A'
	blt done
	mov r4, r0
	sub r4, #'Z'
	bgt check_lower
	add r0, #('a' - 'A')
	b done
check_lower:
	mov r4, r0
	sub r4, #'a'
	blt done
	mov r4, r0
	sub r4, #'z'
	bgt done
	sub r0, #('a' - 'A')
	b done
done:
	pop { pc }