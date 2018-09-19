   .cpu cortex-m0
   .text
   .align 1
   .global add_one_to_int
   
add_one_to_int:
	push {r5, lr}
	mov r5, r0
	ldr r0, [r5]
	add r0, #0
	beq done
	mov r4, r0
	sub r4, 'A'
	blt done
	mov r4, r0
	sub 
	b done
extra:
	bl uart_put_int
done:
	pop {r5, pc}