/*
	FE �t�@���N�V�����𗘗p���������������Z�����s���܂��B

	[���]
		���̃T���v���R�[�h�ł́AFE �t�@���N�V�����ƌĂ΂��@�\�𗘗p����
		�����������Z���s����������܂��B

		FE �t�@���N�V�����́AFLOAT2.X FLOAT3.X FLOAT4.X �Ȃǂ̕��������_���Z
		�p�b�P�[�W��g�ݍ��ނ��Ƃŗ��p�\�ɂȂ镂�������_���Z�@�\�ł��B
		FE �t�@���N�V�����́A0xFE ����n�܂� 16 �r�b�g�̖���`���߂����[�U�[
		�v���O�����Ɏ��s�����邱�ƂŁA���������_���Z�p�b�P�[�W���̃R�[�h��
		���򂵁A���Z�����s���܂��B
		�d�g�ݏ�A�傫�ȃI�[�o�[�w�b�h���������܂��񂪁A���s���ɓ��ڂ����
		���� FPU �̃X�y�b�N�ȂǂɈˑ����Ȃ��݊����̍����v���O�������쐬�\
		�ł��B

	[!!!!! ���� !!!!!]
		�{�R�[�h�����s����ɂ́A���O�ɕ��������_���Z�p�b�P�[�W��g�ݍ���ł���
		�K�v������܂��B
*/

#include <stdlib.h>
#include <stdio.h>

static inline float my_fadd(float a, float b) {
	register float reg_d0 asm ("d0") = a;
	register float reg_d1 asm ("d1") = b;
	/*
		�����Ŏ��s����R�[�h�́A�����ɃX�e�[�g����؎����Ȃ��̂ŁA���s������
		�ǂ̂悤�ɓ���ւ��Ă����ʂ͕ω����Ȃ��B���̂悤�ȃR�[�h�̓R���p�C����
		reordering �����邱�ƂŁA���ǂ��R�[�h��������ꍇ������B
		asm �\���� volatile ���w�肵�Ȃ����Ƃ� reordering ��������B
	*/
	asm (
			/*
				__FADD �́A
				d0.l �����Z���Ƃ��Ď󂯎��B
				d1.l �����Z���Ƃ��Ď󂯎��B
				d0/d1 �Ɍ��ʂ�Ԃ��B
			*/
			".dc.w	__FADD\n"		/* fefunc.inc �� "__FADD: .equ $fe5b" ����`����Ă��� */
	:	/* �o�� */	"+r" (reg_d0),	/* in out %0 */
					"+r" (reg_d1)	/* in out %1 */
	:	/* ���� */
	:	/* �j�� */
	);
	return reg_d0;
}

float a = 1.0;
float b = 2.0;
int main(int argc, char *argv[]){
	float c = my_fadd(a, b);
	printf("%f + %f = %f\n", a, b, c);
	return 0;
}

