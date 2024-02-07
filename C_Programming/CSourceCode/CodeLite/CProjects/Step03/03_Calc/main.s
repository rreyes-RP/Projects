	.file	"main.c"
	.text
Ltext0:
	.cfi_sections	.debug_frame
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 4
LC3:
	.ascii "(taxrate is %.3f) The tax on %.2f is %.2f, so the grand total is %.2f.\12\0"
	.align 4
LC4:
	.ascii "(TAXRATE_DEFINED is %.3f) The tax on %.2f is %.2f, so the grand total is %.2f.\12\0"
	.align 4
LC5:
	.ascii "(TAXRATE_CONST is %.3f) The tax on %.2f is %.2f, so the grand total is %.2f.\12\0"
LC7:
	.ascii "%f\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB6:
	.file 1 "C:/BitwiseCourses/COURSES/LearnC/SOURCE-CODE/CProjects/Step03/03_Calc/main.c"
	.loc 1 4 0
	.cfi_startproc
	pushl	%ebp
LCFI0:
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
LCFI1:
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$96, %esp
	.loc 1 4 0
	call	___main
	.loc 1 6 0
	movl	$1717986918, %eax
	movl	$1069966950, %edx
	movl	%eax, 88(%esp)
	movl	%edx, 92(%esp)
	.loc 1 14 0
	movl	$1717986918, %eax
	movl	$1069966950, %edx
	movl	%eax, 80(%esp)
	movl	%edx, 84(%esp)
	.loc 1 15 0
	movl	$0, %eax
	movl	$1080623104, %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	.loc 1 16 0
	movl	$-1717986918, %eax
	movl	$1070176665, %edx
	movl	%eax, 80(%esp)
	movl	%edx, 84(%esp)
	.loc 1 17 0
	fldl	72(%esp)
	fmull	80(%esp)
	fstpl	64(%esp)
	.loc 1 18 0
	fldl	72(%esp)
	faddl	64(%esp)
	fstpl	56(%esp)
	.loc 1 20 0
	movl	56(%esp), %eax
	movl	60(%esp), %edx
	movl	%eax, 28(%esp)
	movl	%edx, 32(%esp)
	movl	64(%esp), %eax
	movl	68(%esp), %edx
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	movl	72(%esp), %eax
	movl	76(%esp), %edx
	movl	%eax, 12(%esp)
	movl	%edx, 16(%esp)
	movl	80(%esp), %eax
	movl	84(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	$LC3, (%esp)
	call	_printf
	.loc 1 22 0
	movl	$0, %eax
	movl	$1080623104, %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	.loc 1 24 0
	fldl	72(%esp)
	fldl	LC2
	fmulp	%st, %st(1)
	fstpl	64(%esp)
	.loc 1 25 0
	fldl	72(%esp)
	faddl	64(%esp)
	fstpl	56(%esp)
	.loc 1 27 0
	movl	56(%esp), %eax
	movl	60(%esp), %edx
	movl	%eax, 28(%esp)
	movl	%edx, 32(%esp)
	movl	64(%esp), %eax
	movl	68(%esp), %edx
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	movl	72(%esp), %eax
	movl	76(%esp), %edx
	movl	%eax, 12(%esp)
	movl	%edx, 16(%esp)
	movl	$-1717986918, %eax
	movl	$1070176665, %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	$LC4, (%esp)
	call	_printf
	.loc 1 30 0
	movl	$0, %eax
	movl	$1080623104, %edx
	movl	%eax, 72(%esp)
	movl	%edx, 76(%esp)
	.loc 1 32 0
	fldl	72(%esp)
	fmull	88(%esp)
	fstpl	64(%esp)
	.loc 1 33 0
	fldl	72(%esp)
	faddl	64(%esp)
	fstpl	56(%esp)
	.loc 1 35 0
	movl	56(%esp), %eax
	movl	60(%esp), %edx
	movl	%eax, 28(%esp)
	movl	%edx, 32(%esp)
	movl	64(%esp), %eax
	movl	68(%esp), %edx
	movl	%eax, 20(%esp)
	movl	%edx, 24(%esp)
	movl	72(%esp), %eax
	movl	76(%esp), %edx
	movl	%eax, 12(%esp)
	movl	%edx, 16(%esp)
	movl	88(%esp), %eax
	movl	92(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	$LC5, (%esp)
	call	_printf
	.loc 1 37 0
	movl	$1413754136, %eax
	movl	$1074340347, %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	$LC7, (%esp)
	call	_printf
	.loc 1 38 0
	movl	$0, %eax
	.loc 1 39 0
	leave
LCFI2:
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE6:
	.section .rdata,"dr"
	.align 8
LC2:
	.long	-1717986918
	.long	1070176665
	.text
Letext0:
	.file 2 "c:/mingw-4.7.1/bin/../lib/gcc/mingw32/4.7.1/../../../../include/stdio.h"
	.section	.debug_info,"dr"
Ldebug_info0:
	.long	0x256
	.word	0x2
	.secrel32	Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.ascii "GNU C 4.7.1\0"
	.byte	0x1
	.ascii "C:/BitwiseCourses/COURSES/LearnC/SOURCE-CODE/CProjects/Step03/03_Calc/main.c\0"
	.long	Ltext0
	.long	Letext0
	.secrel32	Ldebug_line0
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.ascii "unsigned int\0"
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.ascii "short unsigned int\0"
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.ascii "char\0"
	.uleb128 0x3
	.ascii "_iobuf\0"
	.byte	0x20
	.byte	0x2
	.byte	0x81
	.long	0x137
	.uleb128 0x4
	.ascii "_ptr\0"
	.byte	0x2
	.byte	0x83
	.long	0x137
	.byte	0x2
	.byte	0x23
	.uleb128 0
	.uleb128 0x4
	.ascii "_cnt\0"
	.byte	0x2
	.byte	0x84
	.long	0x13d
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x4
	.ascii "_base\0"
	.byte	0x2
	.byte	0x85
	.long	0x137
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x4
	.ascii "_flag\0"
	.byte	0x2
	.byte	0x86
	.long	0x13d
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x4
	.ascii "_file\0"
	.byte	0x2
	.byte	0x87
	.long	0x13d
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0x4
	.ascii "_charbuf\0"
	.byte	0x2
	.byte	0x88
	.long	0x13d
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.uleb128 0x4
	.ascii "_bufsiz\0"
	.byte	0x2
	.byte	0x89
	.long	0x13d
	.byte	0x2
	.byte	0x23
	.uleb128 0x18
	.uleb128 0x4
	.ascii "_tmpfname\0"
	.byte	0x2
	.byte	0x8a
	.long	0x137
	.byte	0x2
	.byte	0x23
	.uleb128 0x1c
	.byte	0
	.uleb128 0x5
	.byte	0x4
	.long	0x98
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.ascii "int\0"
	.uleb128 0x6
	.ascii "FILE\0"
	.byte	0x2
	.byte	0x8b
	.long	0xa0
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.ascii "long long int\0"
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.ascii "long int\0"
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.ascii "short int\0"
	.uleb128 0x2
	.byte	0x8
	.byte	0x4
	.ascii "double\0"
	.uleb128 0x2
	.byte	0xc
	.byte	0x4
	.ascii "long double\0"
	.uleb128 0x7
	.byte	0x1
	.ascii "main\0"
	.byte	0x1
	.byte	0x4
	.byte	0x1
	.long	0x13d
	.long	LFB6
	.long	LFE6
	.secrel32	LLST0
	.byte	0x1
	.long	0x235
	.uleb128 0x8
	.ascii "argc\0"
	.byte	0x1
	.byte	0x4
	.long	0x13d
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x8
	.ascii "argv\0"
	.byte	0x1
	.byte	0x4
	.long	0x235
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x9
	.ascii "TAXRATE_CONST\0"
	.byte	0x1
	.byte	0x6
	.long	0x23b
	.byte	0x3
	.byte	0x74
	.sleb128 88
	.uleb128 0x9
	.ascii "subtotal\0"
	.byte	0x1
	.byte	0x8
	.long	0x17a
	.byte	0x3
	.byte	0x74
	.sleb128 72
	.uleb128 0x9
	.ascii "tax\0"
	.byte	0x1
	.byte	0x9
	.long	0x17a
	.byte	0x3
	.byte	0x74
	.sleb128 64
	.uleb128 0x9
	.ascii "grandtotal\0"
	.byte	0x1
	.byte	0xa
	.long	0x17a
	.byte	0x2
	.byte	0x74
	.sleb128 56
	.uleb128 0x9
	.ascii "taxrate\0"
	.byte	0x1
	.byte	0xb
	.long	0x17a
	.byte	0x3
	.byte	0x74
	.sleb128 80
	.byte	0
	.uleb128 0x5
	.byte	0x4
	.long	0x137
	.uleb128 0xa
	.long	0x17a
	.uleb128 0xb
	.long	0x144
	.long	0x24b
	.uleb128 0xc
	.byte	0
	.uleb128 0xd
	.ascii "_iob\0"
	.byte	0x2
	.byte	0x9a
	.long	0x240
	.byte	0x1
	.byte	0x1
	.byte	0
	.section	.debug_abbrev,"dr"
Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0x8
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xa
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0x6
	.uleb128 0x2116
	.uleb128 0xc
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x21
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3c
	.uleb128 0xc
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_loc,"dr"
Ldebug_loc0:
LLST0:
	.long	LFB6-Ltext0
	.long	LCFI0-Ltext0
	.word	0x2
	.byte	0x74
	.sleb128 4
	.long	LCFI0-Ltext0
	.long	LCFI1-Ltext0
	.word	0x2
	.byte	0x74
	.sleb128 8
	.long	LCFI1-Ltext0
	.long	LCFI2-Ltext0
	.word	0x2
	.byte	0x75
	.sleb128 8
	.long	LCFI2-Ltext0
	.long	LFE6-Ltext0
	.word	0x2
	.byte	0x74
	.sleb128 4
	.long	0
	.long	0
	.section	.debug_aranges,"dr"
	.long	0x1c
	.word	0x2
	.secrel32	Ldebug_info0
	.byte	0x4
	.byte	0
	.word	0
	.word	0
	.long	Ltext0
	.long	Letext0-Ltext0
	.long	0
	.long	0
	.section	.debug_line,"dr"
Ldebug_line0:
	.def	_printf;	.scl	2;	.type	32;	.endef
