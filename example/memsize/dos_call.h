#ifndef	DOS_CALL_H
#define	DOS_CALL_H


/* puts �̑�֎��� */
void dosPrint(const char *string);

/* setblock */
int32_t dosSetBlock(void *memptr, uint32_t newlen);


#endif
