/*
	C++ �𗘗p�����ł���{�I�ȃT���v���R�[�h�ł��B

	[���]
		�N���X���`���A�R���X�g���N�^�A�f�X�g���N�^�A����у��[�U�[��`
		���\�b�h����A�R���\�[���� printf �ŕ�������o�͂��܂��B

	[!!!!! ���� !!!!!]
		���� xdev68k ��ł� C++ ���p�͐��񂪂ƂĂ������ł��B

		1) C++ �W���w�b�_�̑����� include �Ɏ��s����
			C++ �W���w�b�_�̑����� include �������_�ŃR���p�C���G���[��
			�Ȃ�܂��B���̖�����������ɂ́Aglibc �����̊��� xdev68k
			�ɈڐA����K�v������܂����A������ƂȂ��Ă��܂��B
			���̂��� std::cout �͗��p�ł����A���̃T���v���R�[�h�ł͑��
			��i�Ƃ��� printf �𗘗p���Ă��܂��B

		2) ��O�� RTTI �������Ȃ�
			��O�� RTTI �𗘗p����ƁA���T�|�[�g�� GAS �f�B���N�e�B�u���o��
			����邽�߁A�A�Z���u���Ɏ��s���܂��B��O����� RTTI �𖳌���
			����ɂ́Am68k-elf-g++ �̃R���p�C���I�v�V������
				-fno-rtti -fno-exceptions
			���w�肷��K�v������܂��B�ڂ����� makefile ���Q�Ƃ��Ă��������B

		3) inline �Ɏ��s�������x�����V���{���Փ˂��N����
			inline �w�肳�ꂽ�֐��́A��� inline �����Ƃ͌��炸�A���s�t�@
			�C���̃T�C�Y��������邽�߁A���̂𐶐����������ŕ����̃R�[�h
			���狤�L�����ꍇ������܂��B���̂悤�Ȋ֐��́AGAS �`���̃A�Z��
			�u���\�[�X��ł� .weak �����̃V���{���Ƃ��Đ�������܂��B����
			xdev68k ���痘�p�\�ȃA�Z���u������у����J�� .weak �ɑ�������
			�d�g�݂��Ȃ����߁AGAS->HAS �ϊ��̍ۂɂ��ׂ� .globl �ɒu�������
			���B���ꂪ�����ŁA�����N���ɃV���{���Փ˂���������ꍇ������܂��B
			���̖����������ɂ́Agcc �� always_inline �w��𗘗p���邩�A
			���������֐��̎��̂��w�b�_��ɋL�q���Ȃ��悤�ɃA�v���P�[�V����
			���̎������C������K�v������܂��B

		4) static �C���X�^���X�̃R���X�g���N�^���f�X�g���N�^�͎������s����Ȃ�
			XC �� CLIB �́Astatic �ȃC���X�^���X�̃R���X�g���N�^���f�X�g���N�^
			�̎��s�ɑΉ����Ă��܂���B�A�v���P�[�V�������Ŏ��͂ł��������s
			����K�v������܂��B

		5) C++ �Ή������A�Z���u���ƃ����J�𗘗p����K�v������
			static �R���X�g���N�^/�f�X�g���N�^�𗘗p����ɂ́A�����ɑΉ�
			�����A�Z���u���ƃ����J�ł��� g2as.x �� g2lk.x �𗘗p����K�v��
			����܂��B�ڂ����� makefile ���Q�Ƃ��Ă��������B

		6) 68060 �̓T�|�[�g����Ȃ�
			g2as.x �� g2lk.x �͎c�O�Ȃ��� 68040 �܂ł� CPU �����T�|�[�g����
			���܂���B���̂��� 68060 �� C++ �̓������p�͌���ł͕s�\�ł��B
*/

/*
	XC �̃w�b�_�� c++ ��z�肵�Ă��Ȃ��̂� extern "C" �̓A�v���P�[�V��������
	�s���K�v������܂��B
*/
#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include "cxx_for_xc.h"

#ifdef __cplusplus
}
#endif


/* ��ʓI�ȃN���X�̗� */
class Example {
public:
	void hello() {
		printf("Example: hello c++ world.\n");
	}
	Example() {
		printf("Example: ctor.\n");
	}
	~Example() {
		printf("Example: dtor.\n");
	}
};


/* �X�^�e�B�b�N�R���X�g���N�^�̗� */
class StaticCtorExample {
public:
	StaticCtorExample() {
		printf("StaticCtorExample: ctor.\n");
	}
	~StaticCtorExample() {
		printf("StaticCtorExample: dtor.\n");
	}
};
static StaticCtorExample s_staticCtorExample;


int main(int argc, char *argv[]){
	/*
		�X�^�e�B�b�N�R���X�g���N�^�����s����B
		�X�^�e�B�b�N�f�X�g���N�^�̓X�^�e�B�b�N�R���X�g���N�^�������� atexit
		�֐��Ƃ��ēo�^���Ă����B
		�����ł����ӂ��K�v�ŁAatexit �֐��̓o�^�\���ɂ͏���iXC ���p����
		32 �j������B
	*/
	execute_static_ctors();

	Example example;
	example.hello();
	return 0;
}

