/*
	�C�����C���A�Z���u���R�[�h��ŁA�����t���A�Z���u���𗘗p���܂��B

	[���]
		HAS �̏����t���A�Z���u���𗘗p���A���[�U�[��`�V���{���̒l�ɏ]���A
		�R���\�[���ɕ\�����镶�����ω������܂��B
*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	/*
		�����t���A�Z���u��
	*/
	{
		static const char s_string1[] = "FLAG is 1.\r\n";
		static const char s_string2[] = "FLAG is not 1.\r\n";
		asm volatile (
			"FLAG:=1\n"						/* ���[�U�[��`�V���{�� */
			"	.if	FLAG==1\n"
			"		move.l	%0,-(sp)\n"
			"	.else\n"
			"		move.l	%1,-(sp)\n"
			"	.endif\n"
			"	dc.w	__PRINT\n"			/* doscall.inc �� "__PRINT: .equ $ff09" ����`����Ă��� */
			"	addq.l	#4,sp\n"
		:	/* �o�� */
		:	/* ���� */	"irm" (&s_string1),	/* ���� %0 */
						"irm" (&s_string2)	/* ���� %1 */
		:	/* �j�� */	"d0"				/* doscall �� d0 �Ɍ��ʂ�Ԃ����j�󂷂� */
		);
	}

	return 0;
}
