/*
	�t���[�������T�C�Y�����߂�R�}���h���쐬���܂��B

	[���]
		�{�T���v���R�[�h�́Ax68k_bin/ �ȉ��Ɏ��^����Ă��� MEMSIZE.X �R�}���h
		�̃\�[�X�R�[�h�ł��B

		���s�t�@�C���T�C�Y�����������邽�߁Amain �֐��𗘗p���Ă��܂���B
		�ڂ����́A�T���v���R�[�h "mini_exe" ���Q�Ƃ��ĉ������B
*/

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "dos_call.h"
#include "asm_main.h"


void printDec(uint32_t x) {
	#define NUM_DIGITS	(10)
	static const uint32_t s_decDigits[] = {
		1000000000,
		100000000,
		10000000,
		1000000,
		100000,
		10000,
		1000,
		100,
		10,
		1,
	};

	char decAsString[NUM_DIGITS + 1];
	decAsString[0] = '0';
	decAsString[1] = '0';
	decAsString[2] = '0';
	decAsString[3] = '0';
	decAsString[4] = '0';
	decAsString[5] = '0';
	decAsString[6] = '0';
	decAsString[7] = '0';
	decAsString[8] = '0';
	decAsString[9] = '0';
	decAsString[10] = 0;

	int pos = 0;
	while (x != 0) {
		if (x < s_decDigits[pos]) {
			pos++;
			continue;
		}
		x -= s_decDigits[pos];
		decAsString[pos]++;
	}
	for (pos = 0; pos < NUM_DIGITS - 1; pos++) {
		if (decAsString[pos] != '0') break;
	}
	dosPrint(&decAsString[pos]);
}

int asmMain(void *a0, void *a1, void *a2, void *a3, void *a4) {
	/*
		SETBLOCK �́A���̃v���Z�X�ŗ��p���郁�����T�C�Y���w�肷�� doscall 
		�ł���B���� doscall �́A�m�ۉ\�ȏ�̃������T�C�Y���w�肳���ƁA
		�G���[�Ƃ��āA���ۂɊm�ۉ\�ȃ������T�C�Y + 0x81000000 ��Ԃ��B
		����𗘗p���A�t���[�������T�C�Y�����߂邱�Ƃ��\�ł���B

		���� a0 �ɂ́A�v���Z�X�N�����̃������Ǘ��|�C���^�̃A�h���X���i�[
		����Ă���Ba0+16 �́A���̃v���Z�X�ɗ^����ꂽ�������u���b�N��
		�w���|�C���^�ɂȂ�B�ڂ����́AX68000 ���n���h�u�b�N p.92 �ŉ��
		����Ă���B
	*/
	void *memblock = (void *)((intptr_t)a0 + 16);
	uint32_t availableSizeInBytes = 0x7FFFFFFF;
	int32_t ret1 = dosSetBlock(memblock, availableSizeInBytes);
	if (ret1 < 0) {
		availableSizeInBytes = ret1 - 0x81000000;
	}
	printDec(availableSizeInBytes);

	return EXIT_SUCCESS;
}


