#ifndef _AT_SVDCMD_H_
#define _AT_SVDCMD_H_

#include "at.h"
//#include "at_wifiCmd.h"
//#include "at_ipCmd.h"
//#include "at_baseCmd.h"


void at_setupCmdrest(uint8_t id);

void at_getCmdCrsip(uint8_t id);
void at_setCmdCrsip(uint8_t id, char *pPara);
void at_getCmdCrsget(uint8_t id);
void at_setCmdCrsget(uint8_t id, char *pPara);
void at_getCmdCrsport(uint8_t id);
void at_setCmdCrsport(uint8_t id, char *pPara);
void at_setCmdCrssend(uint8_t id, char *pPara);

void at_getCmdLsharedmem(uint8_t id);
void at_setCmdLsharedmem(uint8_t id, char *pPara);
//struct at_sharedMem_t * at_getSharedMemPtr(void);


#endif