/*
	�t�@�C���T�C�Y�������Ȏ��s�t�@�C�����쐬���܂��B

	[���]
		C/C++ �ō쐬���ꂽ���s�t�@�C���͒ʏ�Amain �֐����珈�����J�n���܂��B
		���s�t�@�C�������ł́Amain �֐��Ăяo���O�ɗl�X�ȏ��������s����
		���܂��B���̏������葱�����̃R�[�h�T�C�Y�͐��L���o�C�g����A���s�t�@
		�C�����̌����ɂȂ��Ă��܂��B

		���s�t�@�C�����������ɂ́Amain �֐��𗘗p�����A���O�ŗp�ӂ���
		�G���g���|�C���g����v���O�������J�n����悤��������K�v������܂��B
		����������p�Ƃ��āAC �W���֐��̑啔�������p�s�\�ɂȂ�̂ŁA������
		��{�I�ȏ��������O�Ŏ�������K�v�������܂��B

		�{�T���v���R�[�h�ł́Aminicrt.s ���G���g���|�C���g�ɐݒ肵�Ă��܂��B
		�ȉ��̏����Ŏ��s����܂��B

			1) minicrt.s ����v���O�����̎��s���J�n����B
			2) minicrt.s ���� asmMain() �֐������s����B
			3) asmMain() �֐��ŃR�}���h���C����������͂���B
			4) �R�}���h���C��������͌��ʂ�^���� main() �֐������s����B
*/

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "dos_call.h"
#include "app.h"


int main(int argc, char *argv[]) {
	/* ������ TTY �o�� */
	for (int i=0; i<argc; i++) {
		dosPrint(argv[i]);
		dosPrint("\r\n");
	}

	return EXIT_SUCCESS;
}

