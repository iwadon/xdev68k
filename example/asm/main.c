/*
	�C�����C���A�Z���u���R�[�h�𗘗p���A�R���\�[���ɕ������\�����܂��B

	[���]
		�C�����C���A�Z���u���R�[�h�����ʂ�̕��@�ŃR���\�[���ɕ������\��
		���܂��B

		��ڂ̕��@�ł́AC �W���֐��𗘗p���܂��B
		�C�����C���A�Z���u���R�[�h���� C �֐������s����ɂ́A������ push ����
		�̂��Ɋ֐����� _ ��t�������x���� jsr �܂��� bsr ���߂ŌĂяo���K�v��
		����܂��B

		��ڂ̕��@�ł́AX68K �� doscall �𗘗p���܂��B
		doscall �́A0xFF ����n�܂� 16 �r�b�g�̖���`���߂� CPU �Ɏ��s������
		���ƂŁAOS ���񋟂��Ă���t�@���N�V�����E�R�[�����ďo���܂��B

		doscall �𗘗p����ɂ́Adoscall.mac�iSHARP Compiler PRO-68K	ver2.1 ��
		���^����Ă���j���A�A�Z���u���\�[�X�R�[�h�̖`���� include ����K�v��
		����܂��Bx68k_gas2has.pl �Ɉ��� -inc ���w�肷�邱�ƂŁA���� include 
		���s���f�B���N�e�B�u�𐶐����邱�Ƃ��ł��܂��B


		�C�����C���A�Z���u���R�[�h�́A���̂悤�� asm �\���ŋL�q���܂��B

			asm volatile (
				"�A�Z���u���R�[�h"
			:	�o�̓��X�g
			:	���̓��X�g
			:	�j�󃊃X�g
			);

		volatile �́A�R���p�C���̍œK���ɂ�閽�߂̕��בւ���}�~���邽�߂�
		�w��ł��B����́A�K�v�Ȃ���Ώȗ����邱�Ƃ��ł��܂��B
		���o�̓��X�g�ɂ́A�A�Z���u���R�[�h�̈�����߂�l�̎󂯓n�����@���L�q
		���܂��B����� Constranits �ƌĂ΂�܂��B
		�j�󃊃X�g�ɂ́A�A�Z���u���R�[�h���Ŕj�󂳂�郌�W�X�^��񋓂��܂��B
		����� Clobbers �ƌĂ΂�܂��B

		Constranits �� Clobbers �̋L�q���[���ɂ��ẮAgcc �̌����h�L�������g
		�����Q�Ƃ��������B
		https://gcc.gnu.org/onlinedocs/gcc/Using-Assembly-Language-with-C.html#Using-Assembly-Language-with-C
*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	/* C �W���֐��� puts ���g�����R���\�[��������o�� */
	{
		static char s_string[] = "hello world. (by puts())";
		asm volatile (
			"	move.l	%0,-(sp)\n"
			"	jbsr	_puts\n"			/* �O���V���{�����Q�Ƃ��鎞�� _ ��t���� */
			"	addq.l	#4,sp\n"
		:	/* �o�� */
		:	/* ���� */	"irm" (&s_string)	/* ���� %0 */
		:	/* �j�� */	"d0", "d1", "d2", "a0", "a1", "a2"	/* C �֐��� d0-d2/a0-a2 ��j�󂷂� */
		);
	}

	/* doscall ���g�����R���\�[��������o�� */
	{
		static char s_string[] = "hello world. (by doscall)\r\n";
		asm volatile (
			"	move.l	%0,-(sp)\n"
			"	dc.w	__PRINT\n"			/* doscall.inc �� "__PRINT: .equ $ff09" ����`����Ă��� */
			"	addq.l	#4,sp\n"
		:	/* �o�� */
		:	/* ���� */	"irm" (&s_string)	/* ���� %0 */
		:	/* �j�� */	"d0"				/* doscall �� d0 �Ɍ��ʂ�Ԃ����j�󂷂� */
		);
	}

	return 0;
}
