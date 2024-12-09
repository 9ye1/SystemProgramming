	.file	"stack_array.c"
	.comm	_stack, 400, 5
	.globl	_top
	.bss
	.align 4
_top:
	.space 4
	.text
	.globl	_isFull
	.def	_isFull;	.scl	2;	.type	32;	.endef
_isFull:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	_top, %eax
	cmpl	$100, %eax
	jne	L2
	movl	$1, %eax
	jmp	L3
L2:
	movl	$0, %eax
L3:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.globl	_push
	.def	_push;	.scl	2;	.type	32;	.endef
_push:
LFB11:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	_top, %eax
	movl	8(%ebp), %edx
	movl	%edx, _stack(,%eax,4)
	movl	_top, %eax
	addl	$1, %eax
	movl	%eax, _top
	nop
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE11:
	.globl	_isEmpty
	.def	_isEmpty;	.scl	2;	.type	32;	.endef
_isEmpty:
LFB12:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	_top, %eax
	testl	%eax, %eax
	jne	L6
	movl	$1, %eax
	jmp	L7
L6:
	movl	$0, %eax
L7:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE12:
	.globl	_pop
	.def	_pop;	.scl	2;	.type	32;	.endef
_pop:
LFB13:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	_top, %eax
	subl	$1, %eax
	movl	%eax, _top
	nop
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE13:
	.section .rdata,"dr"
LC0:
	.ascii "%d \0"
	.text
	.globl	_display
	.def	_display;	.scl	2;	.type	32;	.endef
_display:
LFB14:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	jmp	L10
L11:
	movl	-12(%ebp), %eax
	movl	_stack(,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	addl	$1, -12(%ebp)
L10:
	movl	_top, %eax
	cmpl	%eax, -12(%ebp)
	jl	L11
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE14:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 4
LC1:
	.ascii " \12 1:push \12 2:pop \12 3:isFull \12 4:isEmpty \12 5:Display \12 6:Exit\0"
LC2:
	.ascii "%d\0"
LC3:
	.ascii "push : \0"
LC4:
	.ascii "push ok\0"
LC5:
	.ascii "stack is empty\0"
LC6:
	.ascii "pop ok :: value = %d\0"
LC7:
	.ascii "yes\0"
LC8:
	.ascii "no\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB15:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
L26:
	movl	$LC1, (%esp)
	call	_puts
	leal	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_scanf
	movl	$10, (%esp)
	call	_putchar
	movl	28(%esp), %eax
	cmpl	$1, %eax
	jne	L13
	movl	$LC3, (%esp)
	call	_printf
	leal	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_scanf
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	_push
	movl	$LC4, (%esp)
	call	_printf
	jmp	L26
L13:
	movl	28(%esp), %eax
	cmpl	$2, %eax
	jne	L15
	movl	_top, %eax
	testl	%eax, %eax
	jne	L16
	movl	$LC5, (%esp)
	call	_printf
	jmp	L26
L16:
	call	_pop
	movl	_top, %eax
	movl	_stack(,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$LC6, (%esp)
	call	_printf
	jmp	L26
L15:
	movl	28(%esp), %eax
	cmpl	$3, %eax
	jne	L18
	call	_isFull
	testb	%al, %al
	je	L19
	movl	$LC7, (%esp)
	call	_printf
	jmp	L26
L19:
	movl	$LC8, (%esp)
	call	_printf
	jmp	L26
L18:
	movl	28(%esp), %eax
	cmpl	$4, %eax
	jne	L21
	call	_isEmpty
	testb	%al, %al
	je	L22
	movl	$LC7, (%esp)
	call	_printf
	jmp	L26
L22:
	movl	$LC8, (%esp)
	call	_printf
	jmp	L26
L21:
	movl	28(%esp), %eax
	cmpl	$5, %eax
	jne	L24
	call	_display
	jmp	L26
L24:
	movl	28(%esp), %eax
	cmpl	$6, %eax
	je	L29
	jmp	L26
L29:
	nop
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE15:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_putchar;	.scl	2;	.type	32;	.endef
