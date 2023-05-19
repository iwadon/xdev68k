#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <iocslib.h>
#include <doslib.h>


/* ���荞�ݐݒ�̕ۑ��p�o�b�t�@ */
static volatile uint8_t s_mfpBackup[0x18] = {};
static volatile uint32_t s_vector118Backup = 0;
static volatile uint32_t s_uspBackup = 0;

/* MFP ����̑҂����� */
void waitForMfp() {
	/*
		���ƂȂ��Ă͏o�W�����s���ł����AX68000 �S���������A
		sr ���W�X�^�̏��������� MFP ����̊ԂɎ኱�̑҂����Ԃ����Ȃ��ƁA
		X68030 �Ȃǂ̍����� CPU ���Ō듮�삷�鋰�ꂪ����ƌ����Ă��܂����B

		���ۂ� X68030 ���@���Ńe�X�g�ł��Ă��Ȃ����ߐ^�U���s���ŁA
		�듮��� X68000 �s�s�`���̈�������\�����ے�ł��܂��񂪁A
		�O�̂��ߑ҂����Ԃ��m�ۂ���ړI�ŁA���̊֐������s���Ă��܂��B

		���̊֐��́A�������s���� return ���邾���̓���ł��B
	*/
}

/* �����A�����Ԋ��荞�݊J�n */
void initVsyncInterrupt(void *func) {
	register uint32_t reg_a2 asm ("a2") = (uint32_t)func;

	/*
		�ŐV�� gcc ���ł́A�X�[�p�[�o�C�U�[���[�h�̃��[�U�[���[�h�̐؂�ւ��ɁA
		IOCSLIB.L �Ɏ��^����Ă��� B_SUPER() �𗘗p����̂͊댯�ł��B
		�����ł́A�X�[�p�[�o�C�U�[���[�h��ԂɃR���p�C���̍œK����������邱�Ƃ�
		�����邽�߁A�C�����C���A�Z���u���𗘗p���܂��B
	*/
	asm volatile (
		/* MFP �̃��W�X�^�ԍ� */
		"\n"
		"AER		= $003\n"
		"IERA		= $007\n"
		"IERB		= $009\n"
		"ISRA		= $00F\n"
		"ISRB		= $011\n"
		"IMRA		= $013\n"
		"IMRB		= $015\n"
		"\n"

		/* �X�[�p�[�o�C�U�[���[�h�ɓ��� */
		"	suba.l	a1,a1\n"
		"	iocs	__B_SUPER\n"					/* iocscall.inc �� "__B_SUPER: .equ $81" ����`����Ă��� */
		"	move.l	d0,_s_uspBackup\n"				/*�i���Ƃ��ƃX�[�p�[�o�C�U�[���[�h�Ȃ� d0.l=-1�j */

		/* ���荞�� off */
		"	ori.w	#$0700,sr\n"
		"	bsr		_waitForMfp\n"

		/* MFP �̃o�b�N�A�b�v����� */
		"	movea.l	#$e88000,a0\n"					/* a0.l = MFP�A�h���X */
		"	lea.l	_s_mfpBackup,a1\n"				/* a1.l = MFP�ۑ���A�h���X */
		"	move.b	AER(a0),AER(a1)\n"				/*  AER �ۑ� */
		"	move.b	IERB(a0),IERB(a1)\n"			/* IERB �ۑ� */
		"	move.b	IMRB(a0),IMRB(a1)\n"			/* IMRB �ۑ� */
		"	move.l	$118,_s_vector118Backup\n"		/* �ύX�O�� V-disp �x�N�^ */

		/* V-DISP ���荞�ݐݒ� */
		"	move.l	a2,$118\n"						/* V-disp �x�N�^������ */
		"	bclr.b	#4,AER(a0)\n"					/* �A�����ԂƓ����Ɋ��荞�� */
		"	bset.b	#6,IMRB(a0)\n"					/* �}�X�N���͂��� */
		"	bset.b	#6,IERB(a0)\n"					/* ���荞�݋��� */

		/* ���荞�� on */
		"	bsr		_waitForMfp\n"
		"	andi.w	#$f8ff,sr\n"

		/* ���[�U�[���[�h�ɕ��A */
		"	move.l	_s_uspBackup,d0\n"
		"	bmi.b	@F\n"							/* �X�[�p�[�o�C�U�[���[�h������s����Ă�����߂��K�v���� */
		"		movea.l	d0,a1\n"
		"		iocs	__B_SUPER\n"				/* iocscall.inc �� "__B_SUPER: .equ $81" ����`����Ă��� */
		"@@:\n"

	:	/* �o�� */
	:	/* ���� */	"r"		(reg_a2)				/* in     %0 (���́��ێ�) */
	:	/* �j�� */	"memory",						/* �������o���A��v�� */
					"d0", "a0", "a1"
	);
}

/* �����A�����Ԋ��荞�ݒ�~ */
void termVsyncInterrupt() {
	/*
		�O�q�̗��R����A�C�����C���A�Z���u���𗘗p���܂��B
	*/
	asm volatile (
		/* �X�[�p�[�o�C�U�[���[�h�ɓ��� */
		"	suba.l	a1,a1\n"
		"	iocs	__B_SUPER\n"					/* iocscall.inc �� "__B_SUPER: .equ $81" ����`����Ă��� */
		"	move.l	d0,_s_uspBackup\n"				/*�i���Ƃ��ƃX�[�p�[�o�C�U�[���[�h�Ȃ� d0.l=-1�j */

		/* ���荞�� off */
		"	ori.w	#$0700,sr\n"
		"	bsr		_waitForMfp\n"

		/* MFP �̐ݒ�𕜋A */
		"	movea.l	#$e88000,a0\n"					/* a0.l = MFP�A�h���X */
		"	lea.l	_s_mfpBackup,a1\n"				/* a1.l = MFP��ۑ����Ă������A�h���X */

		"	move.b	AER(a1),d0\n"
		"	andi.b	#%%0101_0000,d0\n"
		"	andi.b	#%%1010_1111,AER(a0)\n"
		"	or.b	d0,AER(a0)\n"					/* AER bit4&6 ���A */

		"	move.b	IERB(a1),d0\n"
		"	andi.b	#%%0100_0000,d0\n"
		"	andi.b	#%%1011_1111,IERB(a0)\n"
		"	or.b	d0,IERB(a0)\n"					/* IERB bit6 ���A */

		"	move.b	IMRB(a1),d0\n"
		"	andi.b	#%%0100_0000,d0\n"
		"	andi.b	#%%1011_1111,IMRB(a0)\n"
		"	or.b	d0,IMRB(a0)\n"					/* IMRB bit6 ���A */

		/* V-DISP ���荞�ݕ��A */
		"	move.l	_s_vector118Backup,$118\n"

		/* ���荞�� on */
		"	bsr		_waitForMfp\n"
		"	andi.w	#$f8ff,sr\n"

		/* ���[�U�[���[�h�ɕ��A */
		"	move.l	_s_uspBackup,d0\n"
		"	bmi.b	@F\n"							/* �X�[�p�[�o�C�U�[���[�h������s����Ă�����߂��K�v���� */
		"		movea.l	d0,a1\n"
		"		iocs	__B_SUPER\n"				/* iocscall.inc �� "__B_SUPER: .equ $81" ����`����Ă��� */
		"@@:\n"

	:	/* �o�� */
	:	/* ���� */
	:	/* �j�� */	"memory",						/* �������o���A��v�� */
					"d0", "a0", "a1"
	);
}

