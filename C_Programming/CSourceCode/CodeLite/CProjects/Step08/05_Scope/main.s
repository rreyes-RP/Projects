	.file	"main.c"
	.comm	_b, 200, 5
	.globl	_teststring
	.data
_teststring:
	.ascii "Hello world\0"
	.globl	_num
	.align 4
_num:
	.long	10
	.section .rdata,"dr"
LC0:
	.ascii "In addnumbers() x=%d, y=%d\12\0"
	.text
	.globl	_addnumbers
	.def	_addnumbers;	.scl	2;	.type	32;	.endef
_addnumbers:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	$0, -12(%ebp)
	movl	_x.1813, %eax
	incl	%eax
	movl	%eax, _x.1813
	incl	-12(%ebp)
	movl	_x.1813, %eax
	movl	-12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	leave
	ret
	.section .rdata,"dr"
LC1:
	.ascii "In globalnum, num is %d\12\0"
	.text
	.globl	_globalnum
	.def	_globalnum;	.scl	2;	.type	32;	.endef
_globalnum:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	_num, %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	leave
	ret
	.section .rdata,"dr"
LC2:
	.ascii "In localnum, num is %d\12\0"
	.text
	.globl	_localnum
	.def	_localnum;	.scl	2;	.type	32;	.endef
_localnum:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	$100, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	leave
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC3:
	.ascii "starting...\0"
LC4:
	.ascii "b=%s; i=%d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	$LC3, (%esp)
	call	_puts
	movl	$200, 4(%esp)
	movl	$_b, (%esp)
	call	_readln
	movl	%eax, 28(%esp)
	movl	28(%esp), %eax
	movl	%eax, 8(%esp)
	movl	$_b, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$_teststring, 4(%esp)
	movl	$_b, (%esp)
	call	_findsubstring
	movl	%eax, (%esp)
	call	_printf
	call	_localnum
	call	_globalnum
	call	_addnumbers
	call	_addnumbers
	call	_addnumbers
	movl	$0, %eax
	leave
	ret
.lcomm _x.1813,4,4
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_readln;	.scl	2;	.type	32;	.endef
	.def	_findsubstring;	.scl	2;	.type	32;	.endef
