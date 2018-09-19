	.cpu cortex-m0
	.text
	.align 2
	.global run_it_down
	
run_it_down:
	push { r5, lr }
	mov r5, r0
loop:
	push {r5}
	bl application
	pop {r5}
	sub r5, #1
	ble done
	b loop
done:
	pop { r5, pc }