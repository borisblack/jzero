	.file	"hello.java"
	.text
	.globl	PrintStream__println
	.def	PrintStream__println;	.scl	2;	.type	32;	.endef
	.seh_proc	PrintStream__println
PrintStream__println:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rsi, %rcx
	call	puts
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section	.rdata,"dr"
.Lstr0:
	.ascii "hello, jzero!\0"
	.text
	.globl main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq %rbp
	.seh_pushreg	%rbp
	movq %rsp,%rbp
	.seh_setframe	%rbp, 0
	subq $40,%rsp
	.seh_stackalloc	40
	.seh_endprologue
	call __main
	leaq .Lstr0(%rip),%rsi
	movq -16(%rbp),%rdx
	movq %rcx,%rdi
	call PrintStream__println
.L65:
	movq $0,%rax
	leave
	ret
	.seh_endproc
	.ident	"j0: (Unicon) 0.1.0"
	.def	puts;	.scl	2;	.type	32;	.endef
