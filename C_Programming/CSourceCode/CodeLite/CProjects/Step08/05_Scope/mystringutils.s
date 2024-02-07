	.file	"mystringutils.c"
	.text
	.def	_searchstring;	.scl	3;	.type	32;	.endef
_searchstring:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	$-1, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_strstr
	movl	%eax, -16(%ebp)
	cmpl	$0, -16(%ebp)
	je	L2
	movl	-16(%ebp), %edx
	movl	12(%ebp), %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, -12(%ebp)
L2:
	movl	-12(%ebp), %eax
	leave
	ret
	.section .rdata,"dr"
	.align 4
LC0:
	.ascii "'%s' found in '%s' at index #%d\12\0"
LC1:
	.ascii "'%s' not found in '%s'\12\0"
	.text
	.globl	_findsubstring
	.def	_findsubstring;	.scl	2;	.type	32;	.endef
_findsubstring:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$56, %esp
	movl	$200, (%esp)
	call	_malloc
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movb	$0, (%eax)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_searchstring
	movl	%eax, -16(%ebp)
	cmpl	$0, -16(%ebp)
	js	L5
	movl	-16(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_sprintf
	jmp	L6
L5:
	movl	12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_sprintf
L6:
	movl	-12(%ebp), %eax
	leave
	ret
	.def	_strstr;	.scl	2;	.type	32;	.endef
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_sprintf;	.scl	2;	.type	32;	.endef
