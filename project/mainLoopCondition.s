	.arch msp430g2553
	.p2align 1, 0

	.text
	.align 2
	.global screen
	.global finish

screen:
	sub #5, r1
	mov.b r12, 0(r1)
	cmp.b #0, 0(r1)
	jz finish
	mov.b #0, 0(r1)
finish:
	mov.b 0(r1), r12
	add.b #5, r1
	pop r0
