	.file	"mystring.c"
	.text
	.globl	_readln
	.def	_readln;	.scl	2;	.type	32;	.endef
_readln:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$0, -12(%ebp)
	movl	$1, -16(%ebp)
	jmp	L2
L5:
	call	_getchar
	movb	%al, -17(%ebp)
	cmpb	$10, -17(%ebp)
	je	L3
	cmpb	$-1, -17(%ebp)
	jne	L4
L3:
	movl	$0, -16(%ebp)
	jmp	L2
L4:
	movl	12(%ebp), %eax
	decl	%eax
	cmpl	-12(%ebp), %eax
	jle	L2
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movb	-17(%ebp), %al
	movb	%al, (%edx)
	incl	-12(%ebp)
L2:
	cmpl	$0, -16(%ebp)
	jne	L5
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movb	$0, (%eax)
	movl	-12(%ebp), %eax
	leave
	ret
	.def	_getchar;	.scl	2;	.type	32;	.endef
