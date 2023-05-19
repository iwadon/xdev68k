/*
	main �֐��̈��� argc argv �ɑ���������̂����͂ō쐬����B
*/

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "dos_call.h"
#include "asm_main.h"
#include "app.h"


#define NUM_MAX_ARGS					(256)
#define MAX_COMMAND_LINE_SIZE_IN_BYTES	(0x100)


/* �����̃R�s�[���쐬����o�b�t�@ */
static char s_cmdLineCopy[MAX_COMMAND_LINE_SIZE_IN_BYTES];
static char *(s_argv[NUM_MAX_ARGS]);

int asmMain(void *a0, void *a1, void *a2, void *a3, void *a4) {
	int argc = 0;

	/*
		���̃v���Z�X�ŗ��p�\�ȃ��������g������B
		doscall �� SETBLOCK �Ƀ������m�ۃG���[���Ӑ}�I�ɋN�������A
		�G���[�R�[�h����A�m�ۉ\�ȍő�T�C�Y���擾���A���g���C����B
	*/
	{
		void *memblock = (void *)((intptr_t)a0 + 16);
		int32_t ret1 = dosSetBlock(memblock, 0x7FFFFFFF);
		if (ret1 < 0) {
			uint32_t availableSizeInBytes = ret1 - 0x81000000;
			int32_t ret2 = dosSetBlock(memblock, 0x100000);
			if (ret2 < 0) {
				return EXIT_FAILURE;
			}
		}
	}

	/*
		�R�}���h���C����������擾�B
		�擪 1 �o�C�g�͕����񒷂������B
	*/
	const char *cmdLine = (const char *)((intptr_t)a2 + 1);

	/*
		argv[0] �ɂ͎��s���̃R�}���h��������B
		���s�t�@�C���̃t�@�C�����́A�v���Z�X�Ǘ��|�C���^ + 0x00c4 �̈ʒu�ɂ���B
	*/
	s_argv[argc] = (char *)((intptr_t)a0 + 0x00c4);
	argc++;

	/* �X�e�[�g */
	typedef enum {
		State_Separator = 0,
		State_Arg
	} State;
	State state = State_Separator;

	/* �����̃R�s�[���쐬���Ȃ��� argc �� argv ���쐬���� */
	for (int i = 0; i < sizeof(s_cmdLineCopy); i++) {
		char byte = cmdLine[i];

		/* 1 �����R�s�[ */
		s_cmdLineCopy[i] = byte;

		/* �R�}���h���C���I�_���������琳��I�� */
		if (byte == '\0') {
			break;
		}

		/* �Z�p���[�^�Ȃ當����I�_�ɒu�� */
		if (byte <= ' ') {
			byte = '\0';
			s_cmdLineCopy[i] = '\0';
		}

		/* ���݂̃X�e�[�g�ŕ��� */
		switch (state) {
			case State_Separator: {
				/* �Z�p���[�^�̍Œ��ɗL���ȕ������o�������� arg �̊J�n�ʒu�Ƃ݂Ȃ��B*/
				if (byte != '\0') {
					/* arg �ő吔���z����Ȃ�ُ�I�� */
					if (argc >= NUM_MAX_ARGS) {
						return EXIT_FAILURE;
					}

					/* argv �o�^ */
					s_argv[argc] = &s_cmdLineCopy[i];
					argc++;

					/* �X�e�[�g�ύX */
					state = State_Arg;
				}
			} break;

			case State_Arg: {
				/* �����̍Œ��ɃZ�p���[�^���o��������X�e�[�g�̕ύX */
				if (byte == '\0') {
					state = State_Separator;
				}
			} break;
		}
	}

	/* ������I�_���m���ɐ��� */
	s_cmdLineCopy[sizeof(s_cmdLineCopy) - 1] = '\0';

	/* �A�v���P�[�V�����{�̂����s */
	uint16_t ret = 0;
	ret = main(argc, s_argv);
	return ret;
}


