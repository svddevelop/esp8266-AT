#include "at_svdCmd.h"

#include <stdlib.h>
#include "osapi.h"
#include "c_types.h"
#include "at.h"
#include "at_baseCmd.h"
#include "user_interface.h"
#include "at_version.h"
#include "version.h"
#include "driver/uart_register.h"
//#include "at_cmd.h"

#define _CRLN	"\r\n"

extern void user_esp_platform_load_param(void *param, uint16 len);
extern void user_esp_platform_save_param(void *param, uint16 len);


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
static int8_t ICACHE_FLASH_ATTR
getCmdLen(uint8_t *pCmd)
{
  uint8_t n,i;

  n = 0;
  i = 128;

  while(i--)
  {
    if((*pCmd == '\r') /*|| (*pCmd == '=') || (*pCmd == '?') || ((*pCmd >= '0')&(*pCmd <= '9'))*/)
    {
      return n;
    }
    else
    {
      pCmd++;
      n++;
    }
  }
  return -1;
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ICACHE_FLASH_ATTR
at_getCmdCrsip(uint8_t id){
	
	//uart0_sendStr("rsipa GET\r\n");
	at_uartType tmp;
	
	user_esp_platform_load_param((uint32 *)&tmp, sizeof(at_uartType));
	uart0_tx_buffer(tmp.remoteIP.value, tmp.remoteIP.len);
	//uart0_sendStr(_CRLN);
	at_backOk;
}

void ICACHE_FLASH_ATTR
at_setCmdCrsip(uint8_t id, char *pPara)
{
	uart0_sendStr(_CRLN);
	at_uartType tmp;
	user_esp_platform_load_param((uint32 *)&tmp, sizeof(at_uartType));
	if (tmp.saved != 1){
		tmp.saved = 1;
		tmp.baud = 9600;
		tmp.remoteIP.len = 0;
		tmp.remoteGET.len = 0;
		tmp.remotePort = 80;
	}
	//uart0_sendStr("rsipa SET\r\n");
	uart0_tx_buffer(pPara+1, 15);
	tmp.remoteIP.len = getCmdLen(pPara+1);
	
	/*char temp[32];
	os_sprintf(temp, "s:%d\r\n",
	             /*at_fun[id].at_cmdName,*//* iRemoteServerIpLen);
	uart0_sendStr(temp);*/
	  
	  
	//pPara++;
	if (tmp.remoteIP.len > 15)
		tmp.remoteIP.len = 15;
	//len = 
	//at_dataStrCpy(pPara, sRemoteServerIp, iRemoteServerIpLen);
	uint8_t i = 0;
	while (i < tmp.remoteIP.len)
		tmp.remoteIP.value[i] = pPara[1 + i++];
	
	user_esp_platform_save_param((uint32 *)&tmp, sizeof(at_uartType));
	//at_getCmdCrsip(id);
	at_backOk;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ICACHE_FLASH_ATTR
at_getCmdCrsget(uint8_t id){
	
	at_uartType tmp;
	user_esp_platform_load_param((uint32 *)&tmp, sizeof(at_uartType));
	//uart0_sendStr("rsget GET\r\n");
	uart0_tx_buffer(tmp.remoteGET.value, tmp.remoteGET.len);
	//uart0_sendStr(_CRLN);
	at_backOk;
}

void ICACHE_FLASH_ATTR
at_setCmdCrsget(uint8_t id, char *pPara)
{
	at_uartType tmp;
	user_esp_platform_load_param((uint32 *)&tmp, sizeof(at_uartType));
	if (tmp.saved != 1){
		tmp.saved = 1;
		tmp.baud = 9600;
		tmp.remoteIP.len = 0;
		tmp.remoteGET.len = 0;
		tmp.remotePort = 80;
	}
	//uart0_sendStr("rsget SET\r\n");
	uart0_tx_buffer(pPara+1, 15);
	tmp.remoteGET.len = getCmdLen(pPara+1);
	
	/*char temp[32];
	os_sprintf(temp, "s:%d\r\n",
	             /*at_fun[id].at_cmdName,*//* iRemoteServerIpLen);
	uart0_sendStr(temp);*/
	  
	  
	//pPara++;
	if (tmp.remoteGET.len > 15)
		tmp.remoteGET.len = 15;
	//len = 
	//at_dataStrCpy(pPara, sRemoteServerIp, iRemoteServerIpLen);
	uint8_t i = 0;
	while (i < tmp.remoteGET.len)
		tmp.remoteGET.value[i] = pPara[1 + i++];
	
	user_esp_platform_save_param((uint32 *)&tmp, sizeof(at_uartType));
	//at_getCmdCrsip(id);
	at_backOk;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ICACHE_FLASH_ATTR
at_getCmdCrsport(uint8_t id){
	
	//uart0_sendStr("rsporta GET\r\n");
	at_uartType tmp;
	char text [8];
	
	user_esp_platform_load_param((uint32 *)&tmp, sizeof(at_uartType));
	
	os_sprintf(text, "%d\r\n", tmp.remotePort);
	uart0_sendStr(text);
	at_backOk;
}

void ICACHE_FLASH_ATTR
at_setCmdCrsport(uint8_t id, char *pPara)
{
	uart0_sendStr(_CRLN);
	at_uartType tmp;
	user_esp_platform_load_param((uint32 *)&tmp, sizeof(at_uartType));
	if (tmp.saved != 1){
		tmp.saved = 1;
		tmp.baud = 9600;
		tmp.remoteIP.len = 0;
		tmp.remoteGET.len = 0;
		tmp.remotePort = 80;
	}
	//uart0_sendStr("rsporta SET\r\n");
	uart0_tx_buffer(pPara+1, 12);
	tmp.remotePort = atoi(pPara+1);
	
	/*char temp[32];
	os_sprintf(temp, "s:%d\r\n",
	             /*at_fun[id].at_cmdName,*//* iRemoteServerIpLen);
	uart0_sendStr(temp);*/
		
	user_esp_platform_save_param((uint32 *)&tmp, sizeof(at_uartType));
	//at_getCmdCrsip(id);
	at_backOk;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
volatile uint8_t svdStatus = 1;


void ICACHE_FLASH_ATTR
at_getCmdEcho(uint8_t id){
	
	uart0_sendStr(_CHECKBIT(svdStatus, _SVD_STATUS_ECHO) ? "ON\r\n" : "OFF\r\n");
}

void ICACHE_FLASH_ATTR
at_setCmdEcho(uint8_t id, char *pPara)
{
	pPara++;
	if (pPara[0] == '0')
		svdStatus &= ~(1<<_SVD_STATUS_ECHO);
	else
		svdStatus |= (1<<_SVD_STATUS_ECHO);
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

volatile at_sharedMem_t sharedMem;

void ICACHE_FLASH_ATTR
at_getCmdLsharedmem(uint8_t id){
	// возвращает данные из sharedMem. Данные передаются в винарном формате без разметки.
	
	uint8_t len = 0; char text [4];
	while (len < _SM_BUF_LEN){

		os_sprintf(text, "%02X", sharedMem.buf[ len++ ]);
		uart0_sendStr(text);
	}
	uart0_sendStr(_CRLN);
}

uint8_t hex2nibl(uint8_t c){
	
	if (( c >= 48 )&( c <= 57 ))
		return c - 48;
	else
		return 10 + ((uint8_t) (c - 65));
}


void ICACHE_FLASH_ATTR
at_setCmdLsharedmem(uint8_t id, char *pPara)
{
	//данные приходят в hex-формате без разделителей. старший нибл нечетный(первый)
	char text [40];
	//os_sprintf(text, "id=%d; \r\n", id);uart0_sendStr(text);

	sharedMem.changedByUART = 0;
	char bh, bl; uint8_t i, b,len = 0; pPara++;

	len = getCmdLen(pPara); len = ((len >> 1) << 1);
	if (len > (_SM_BUF_LEN << 1)) len = _SM_BUF_LEN << 1;
	i = 0;
	//os_sprintf(text, "len=%d \r\n", len);uart0_sendStr(text);
	while (i < len){
		
		//os_sprintf(text, " i=%d \r\n", i);uart0_sendStr(text);		
		bh = pPara[i++];
		//os_sprintf(text, " +i=%d %d\r\n", i, bh);text[0] = bh; uart0_sendStr(text);
		bl = pPara[i++];
		//os_sprintf(text, " ++i=%d %d\r\n", i, bl);text[0] = bl; uart0_sendStr(text);
		
		b = (hex2nibl(bh) << 4) + hex2nibl(bl);
		//os_sprintf(text, "*-*  b=%d; %02x\r\n", b, b);uart0_sendStr(text);
		sharedMem.buf[(i/2)-1] = b;
	}
	
	
	
	sharedMem.changedByUART = 1;
	uart0_sendStr("+SM:");
	if (_CHECKBIT(svdStatus, _SVD_STATUS_ECHO))
		at_getCmdLsharedmem(id);
	else {
			
		uart0_tx_buffer(sharedMem.buf, _SM_BUF_LEN);
		uart0_sendStr("\r\n");			
		
	}
		
	//at_backOk;
}

/*struct at_sharedMem_t * ICACHE_FLASH_ATTR
at_getSharedMemPtr(void){
	
	return (struct at_sharedMem_t *)&sharedMem;
}*/

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ICACHE_FLASH_ATTR
at_setCmdCrssend(uint8_t id, char *pPara)
{
	uart0_sendStr("rssend:");
	uart0_sendStr(pPara);
	/*uart0_sendStr(_CRLN);
	//uart0_sendStr("rsget SET\r\n");
	uart0_tx_buffer(pPara+1, 15);
	iRemoteParamLen = getCmdLen(pPara+1);
	
	/*char temp[32];
	os_sprintf(temp, "s:%d\r\n",
	             /*at_fun[id].at_cmdName,*//* iRemoteServerIpLen);
	uart0_sendStr(temp);*//*
	  
	  
	//pPara++;
	if (iRemoteParamLen > 15)
		iRemoteParamLen = 15;
	//len = 
	//at_dataStrCpy(pPara, sRemoteServerIp, iRemoteServerIpLen);
	uint8_t i = 0;
	while (i < iRemoteParamLen)
		sRemoteParam[i] = pPara[1 + i++];
	
	//at_getCmdCrsip(id);*/
	at_backOk;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ICACHE_FLASH_ATTR
at_setupCmdrest(uint8_t id){
	uart0_sendStr("\r\nrestore:\r\nipMode");
	
	char buf[48] = "=1\r\n";
	at_setupCmdCipmode(id, buf);
	
	uart0_sendStr("wifiMode");
	buf[1] = '3';
	at_setupCmdCwmode(id, buf);
	
	buf[1] = '1';
	uart0_sendStr("ipMux");
	at_setupCmdCipmux(id, buf);
	
	uart0_sendStr("ipServer");
	//buf[2] = ','; buf[3] = '8'; buf[4] = '0'; buf[5] = '\r'; buf[6] = '\n';
	os_sprintf(buf, "=1,80\r\n");
	at_setupCmdCipserver(id, buf);
	uart0_sendStr("[REST]\r\n");
	//at_backOk;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
