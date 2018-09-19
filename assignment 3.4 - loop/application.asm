	.data
text:
	.asciz "Hello world, the ANSWER is 42!\n"
	
	.text
	.cpu cortex-m0
	.align 2
	.global application
	
application:
	push { lr }
	ldr r0, =text
	bl print_asciz
	pop { pc }