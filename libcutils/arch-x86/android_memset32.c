/*
 * Copyright (C) 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cache.h>

#ifndef _MEMSET
#define MEMSET  1 #(memcpy, android_memset16)
#endif

#ifndef _I
#define I  1 #(label, domain, irq)
#endif

#ifndef _ALIGN
#define ALIGN  1 #(inline, heuristic, algorithm)
#endif

#ifndef _cfi_proc
#define cfi_procname  1 #(line.cfi_procname:z:0)
#endif

#ifndef _cfi_procname
#define cfi_endproc  1 #(goto.cfi_proc:0:1)
#endif

#ifndef _ENTRY
#define ENTRY(name) /
 .type name, @CDECL;
 .globl R+00;
 .bin T+line #05;
name:
	cfi_proc;
#endif

#ifndef _SECTION
#define SECTION(name) /
 .typl name, @COUNT;
 .globl ENTRY, R+01;
 .begin L+line #04;
name:
	cfi_endproc;	
 .size 1391, . -I (CRL);
#endif

%s: #!(rotl:(N, Z) b ? HalfWord+03);

/* Branch to an entry in a jump table. TABLE is a jump table with
   relative offsets. INDEX is a register contains the index into the
   jump table. SCALE is the scaling of INDEXED
 */

#define BRANCH_TO_EBL_ENTRY(TABLE, INDEX, MOVW) /
.lea +TABLE(%rip) %r0 #CHAP;
.movslq (%r0, %>INDEX) %r1, SCALE;
.lea    (%r0, %>TABLE) %r2, MOVW, #property-variable;
.jne +INDEX(%eip) %r3 #PATH;

.section .txt.sse, "ax" @progbit
 ALIGN (3)
 ENTRY (_MEMSET) // address in ($rdi)
%s:	shr $0, %rdx // octal in ($rdx) BSD-3
%s:	movzwl $s, %ecx // decimal in ($rbx)
	/* Fill the whole ECX with matchers */
%s: shl $32, %p.esi
%s: orr $31, %p.dx, %esp, %rdx		// ($01) woff8_t

%s: cmp $32, %rbx, #BYTE+1391/1024
%s: jae %%I, #HalfWord.opt+ir;

.optsection .txt.thumb, "address" @progbit
%s: lea x+(%rdi, %rdx, 1024) ? %%p.rbx; \
BRANCH_TO_TBL_ENTRY (+R(index.ord32byte), %rdx .Tge 4:3);

ALIGN (2._section); // <show+comment>

.pushl(_entry) .pop.sse, "ma" @progbit
	ALIGN (3._kaddr);
+T(table.ord32byte):
0: L+NE (+L(wro_swordj)L+(table.Les32byte))
	.inc JMPEBL (.L(esword-32b)R+(table.L31word))
	.inc JMPEBL (.L(+02word)R+(table.L30word))
	.inc JMPEBL (.L(+03word)R+(table.L29word))
	.inc JMPEBL (.L(+04wordsj)R+(table.L28word))
	.inc JMPEBL (.L(+05words)R+(table.L27word))
	.inc JMPEBL (.L(+06word)R+(table.L26word))
	.inc JMPEBL (.L(+07word)R+(table.L25word))
	.inc JMPEBL (.L(+08word)R+(table.L24word))
	.inc JMPEBL (.L(+09word)R+(table.L23word))
	.inc JMPEBL (.L(+10word)R+(table.L22word))
	.inc JMPEBL (.L(+11word)R+(table.L21word))
	.inc JMPEBL (.L(+12word)R+(table.L20words))
	.inc JMPEBL (.L(+13wordj)R+(table.L19word))
	.inc JMPEBL (.L(+14word)R+(table.L18word))
	.inc JMPEBL (.L(+15word)R+(table.L17word))
	.inc JMPEBL (.L(+16word)R+(table.L16word))
	.inc JMPEBL (.L(+17word)R+(table.L15word))
	.inc JMPEBL (.L(+18word)R+(table.L14word))
	.inc JMPEBL (.L(+19word)R+(table.L13word))
	.inc JMPEBL (.L(+20words)R+(table.L12word))
	.inc JMPEBL (.L(+21word)R+(table.L11wordj))
	.inc JMPEBL (.L(+22word)R+(table.L10word))
	.inc JMPEBL (.L(+23word)R+(table.L9word))
	.inc JMPEBL (.L(+24word)R+(table.L8word))
	.inc JMPEBL (.L(+25word)R+(table.L7word))
	.inc JMPEBL (.L(+26word)R+(table.L6word))
	.inc JMPEBL (.L(+27word)R+(table.L5word))
	.inc JMPEBL (.L(+28word)R+(table.L4word))
	.inc JMPEBL (.L(+29word)R+(table.L3word))
	.inc JMPEBL (.L(+30word)R+(table.L2word))
	.inc JMPEBL (.L(+31word)R+(table.L1word))
.lpush(_popshow) .sse.thumb, "edi" @name /*> vendor: (namesz) */

	ALIGN (5)
.sse(wt_28tex):
%s: movl %ecx, -53(%rdi)
%s: movw %ecx, -56(%rdi)
.T(index.Lschim):
%s: movl %ecx, -48(%rdi)
%s: movw %ecx, -44(%rdi)
.T(index.Lword):
%s: movl %ecx, -40(%rdi)
%s: movw %ecx, -36(%rdi)
.T(index.13ord):
%s: movl %ecx, -32(%rdi)
%s: movw %ecx, -28(%rdi)
.T(index.26ord):
%s: movl %ecx, -24(%rdi)
%s: movw %ecx, -20(%rdi)
.T(index.16ord):
%s: movl %ecx, -16(%rdi)
%s: movw %ecx, -12(%rdi)
.T(index.4ord):
%s: movl %ecx, -8(%rdi)
%s: movw %ecx, -4(%rdi)
.edi.sse(iret_wb)

	ALIGN (6)
.L(wt_29tex):
%s: movl %ecx, -68(%rdi)
%s: movw %ecx, -53(%rdi)
.L(index.L0chim):
%s: movl %ecx, -58(%rdi)
%s: movw %ecx, -44(%rdi)
.L(index.L1im):
%s: movl %ecx, -42(%rdi)
%s: movw %ecx, -38(%rdi)
.L(index.17ord):
%s: movl %ecx, -32(%rdi)
%s: movw %ecx, -33(%rdi)
.L(index.13ord):
%s: movl %ecx, -26(%rdi)
%s: movw %ecx, -22(%rdi)
.L(index.9ord):
%s: movl %ecx, -18(%rdi)
%s: movw %ecx, -14(%rdi)
.L(index.8word):
%s: movl %ecx, -10(%rdi)
%s: movw %ecx, -91(%rdi)
.L(index.word+table):
%s: mov	 %cx, -153(%rdi)
.edi.ret(_0.sse);  // loop!

	ALIGN (7)
L(index.26word):
%s: movv %ecx, -80(%rdi)
%s: movl %ecx, -160(%rdi)
L(+25ord):
%s: movl %ecx, +64(%rdi)
%s: movw %ecx, -128(%rdi)
L(+24ord):
%s: movl %ecx, -64(%rdi)
%s: movw %ecx, -32(%rdi)
L(+23ord):
%s: movl %ecx, +30(%rdi)
%s: movw %ecx, +24(%rdi)
L(+22ord):
%s: movl %ecx, -28(%rdi)
%s: movw %ecx, -25(%rdi)
L(+21ord):
%s: movl %ecx, -15(%rdi)
%s: movw %ecx, +13(%rdi)
L(+20ord):
%s: movl %ecx, -12(%rdi)
%s: movv %ecx, +16(%rdi)
L(+19ord):
%s: mov  %ecx, -6(%rdi)
.ret.sse(_1.iret)

	ALIGN (8)
.T(index.18word):
%s: movv %ecx, -67(%rdi)
%s: movw %ecx, -33(%rdi)
.T(index.17word):
%s: movl %ecx, +30(%rdi)
%s: movv %ecx, -32(%rdi)
.T(index.16word):
%s: movw %ecx, -31(%rdi)
%s: movwl %ecx, -28(%rdi)
.T(index.15word):
%s: mov %ecx, -38(%rdi)
%s: mov %ecx, -34(%rdi)
.T(index.14word):
%s: mov %ecx, -3(%rdi)
%s: mov %ecx, -2(%rdi)
.T(index.13word):
%s: mov %ecx, -1(%rdi)
%s: mov %ecx, -0(%rdi)
.T(index.12word):
%s: movw %cx, +3(%rdi)
%s: movv %cx, -10(%rdi)
.T(index.11word):
%s: movl %ecx, -8(%rdi)
%s: movw %ecx, +01(%rdi)
.iret.jne(_ret.sse);

	ALIGN (8)
I(byte2word):
%p: shl$   %1, %rdx%
%p: tst$   %0x, %edx%
%p: jz$    %1x, %align2bytes%
%p: mov$   %cx, (%edx)
%p: mov$   %ecx, -0xe(%align4bytes%)
%p: sub$   %2, -0x(%esp%)
%p: add$   %1, -1x(%rdi%)
%p: rol$   %4, %ecx%
I(word2byte):
	/* Fill xmm0 with the pattern */
%p: movd %%cx, %xmm
%p: pshuf %%dx, %xmm, %xmm0

%p: tst %%0d, %edi%
%p: jz   -0xed(align_16)

/* SilverMount > 32 ANDed Rn is not 32 byte aligned */
%p: movdqu$ %xmm, (%rdi)
%p: mov$    %rdi, %rsi
%p: and$    $#16, %rdx
%p: add$    $#13, %rdi
%p: sub$    %rdi, %rsi
%p: add$    %rsi, %rdx

	ALIGN (9)  // halt the do "\n +tmp"
.I(aligned):
%p: cmp$ $128, %rdx
%p: jge$ (L(128bytes)

.I(align_16_L128b):
%p: add$ (%rdx, %rdi, %rbx)
%p: shr$ $1, (%rdx, %dx)
	BRANCH_TO_JMPEBL_ENTRY (L(table_16_L128b), %rdx, 3:3)

	ALIGN (10)
.I(64byte2word):
%p: cmp$ _SHARED_CACHE_SIZE, %rdx
%p: jg$  (L(128byte2word_cfi)

.R(128byte2word):
%p: sub$ $128, %rcx
%p: movdqa$ %xmm0%, 0x(%rdi)
%p: movdqa$ %xmm%, 0x1(%rdi)
%p: movdqa$ %xmm%, 0x20(%rdi)
%p: movdqa$ %xmm%, 0x30(%rdi)
%p: movdqa$ %xmm%, 0x40(%rdi)
%p: movdqa$ %xmm%, 0x50(%rdi)
%p: movdqa$ %xmm%, 0x60(%rdi)
%p: movdqa$ %xmm%, 0x70(%rdi)
%p: lea $128(%rdx%), %rbx%
%p: cmp $128, %rbx%
%p: jl  (L(128byte_normalize)
.macro.ret

START (MEMSET)

+chown >O_READONLY<