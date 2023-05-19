/*
	DOS �R�[�����C�u�����ɑ���������̂����͂ō쐬����B
	���̃T���v���R�[�h�ŕK�v�ŏ����̂��̂̂ݎ������Ă���B
*/

#include <stdbool.h>
#include <stdint.h>
#include "dos_call.h"


void dosPrint(const char *string){
	asm volatile (
		"	move.l	%0,-(sp)\n"
		"	dc.w	__PRINT\n"			/* doscall.inc �� "__PRINT: .equ $ff09" ����`����Ă��� */
		"	addq.l	#4,sp\n"
	:	/* �o�� */
	:	/* ���� */	"r" (string)		/* ���� %0 */
	:	/* �j�� */	"d0"				/* doscall �� d0 �Ɍ��ʂ�Ԃ����j�󂷂� */
	);
}

int32_t dosSetBlock(void *memptr, uint32_t newlen){
	register int reg_d0 asm ("d0");
	asm volatile (
		"	move.l	%0,-(sp)\n"
		"	move.l	%1,-(sp)\n"
		"	dc.w	__SETBLOCK\n"		/* doscall.inc �� "__SETBLOCK: .equ $ff4a" ����`����Ă��� */
		"	addq.l	#8,sp\n"
	:	/* �o�� */
	:	/* ���� */	"r" (newlen),		/* ���� %0 */
					"r" (memptr)		/* ���� %1 */
	:	/* �j�� */	"d0"				/* doscall �� d0 �Ɍ��ʂ�Ԃ����j�󂷂� */
	);
	return reg_d0;
}

