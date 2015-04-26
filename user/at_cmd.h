/*
 * File	: at_cmd.h
 * This file is part of Espressif's AT+ command set program.
 * Copyright (C) 2013 - 2016, Espressif Systems
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of version 3 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __AT_CMD_H
#define __AT_CMD_H

#include "at.h"
#include "at_wifiCmd.h"
#include "at_ipCmd.h"
#include "at_baseCmd.h"
#include "at_svdCmd.h"

extern void at_getCmdEcho(uint8_t id);
extern void at_setCmdEcho(uint8_t id, char * pPara);

#define at_cmdNum   38

at_funcationType at_fun[at_cmdNum]={
  {NULL, 0, NULL, NULL, NULL, at_exeCmdNull},
  {"E", 1, NULL, NULL, at_setupCmdE, NULL},
  {"+RST", 4, NULL, NULL, NULL, at_exeCmdRst},
  {"+GMR", 4, NULL, NULL, NULL, at_exeCmdGmr},
  {"+GSLP", 5, NULL, NULL, at_setupCmdGslp, NULL},
  {"+IPR", 4, NULL, NULL, at_setupCmdIpr, NULL},
#ifdef ali
  {"+UPDATE", 7, NULL, NULL, NULL, at_exeCmdUpdate},
#endif
  {"+CWMODE", 7, at_testCmdCwmode, at_queryCmdCwmode, at_setupCmdCwmode, at_queryCmdCwmode},
  {"+CWJAP", 6, NULL, at_queryCmdCwjap, at_setupCmdCwjap, at_queryCmdCwjap},
  {"+CWLAP", 6, NULL, NULL, at_setupCmdCwlap, at_exeCmdCwlap},
  {"+CWQAP", 6, at_testCmdCwqap, NULL, NULL, at_exeCmdCwqap},
  {"+CWSAP", 6, NULL, at_queryCmdCwsap, at_setupCmdCwsap, at_queryCmdCwsap},
  {"+CWLIF", 6, NULL, NULL, NULL, at_exeCmdCwlif},
  {"+CWDHCP", 7, NULL, at_queryCmdCwdhcp, at_setupCmdCwdhcp, at_queryCmdCwdhcp},
  {"+CIFSR", 6, at_testCmdCifsr, NULL, at_setupCmdCifsr, at_exeCmdCifsr},
  {"+CIPSTAMAC", 10, NULL, at_queryCmdCipstamac, at_setupCmdCipstamac, at_queryCmdCipstamac},
  {"+CIPAPMAC", 9, NULL, at_queryCmdCipapmac, at_setupCmdCipapmac, at_queryCmdCipapmac},
  {"+CIPSTA", 7, NULL, at_queryCmdCipsta, at_setupCmdCipsta, at_queryCmdCipsta},
  {"+CIPAP", 6, NULL, at_queryCmdCipap, at_setupCmdCipap, at_queryCmdCipap},
  {"+CIPSTATUS", 10, at_testCmdCipstatus, NULL, NULL, at_exeCmdCipstatus},
  {"+CIPSTART", 9, at_testCmdCipstart, NULL, at_setupCmdCipstart, NULL},
  {"+CIPCLOSE", 9, at_testCmdCipclose, NULL, at_setupCmdCipclose, at_exeCmdCipclose},
  {"+CIPSEND", 8, at_testCmdCipsend, NULL, at_setupCmdCipsend, at_exeCmdCipsend},
  {"+CIPMUX", 7, NULL, at_queryCmdCipmux, at_setupCmdCipmux, at_queryCmdCipmux},
  {"+CIPSERVER", 10, NULL, NULL,at_setupCmdCipserver, NULL},
  {"+CIPMODE", 8, NULL, at_queryCmdCipmode, at_setupCmdCipmode, at_queryCmdCipmode},
  {"+CIPSTO", 7, NULL, at_queryCmdCipsto, at_setupCmdCipsto, at_queryCmdCipsto},
  {"+CIUPDATE", 9, NULL, NULL, NULL, at_exeCmdCiupdate},
  {"+CIPING", 7, NULL, NULL, NULL, at_exeCmdCiping},
  {"+RSIP", 5,  NULL,  at_getCmdCrsip, at_setCmdCrsip, at_getCmdCrsip},
  {"+ECHO", 5,  NULL,  at_getCmdEcho, at_setCmdEcho, at_getCmdEcho},
  {"+RSGET", 6,  NULL,  at_getCmdCrsget, at_setCmdCrsget, at_getCmdCrsget},
  {"+RSPORT", 7,  NULL,  at_getCmdCrsport, at_setCmdCrsport, at_getCmdCrsport},
  {"+LSM", 4,  NULL,  at_getCmdLsharedmem, at_setCmdLsharedmem, at_getCmdLsharedmem},
  {"+RSSEND", 7,  NULL,  NULL, at_setCmdCrssend, NULL}, 
  {"+REST", 5, NULL, NULL, NULL, at_setupCmdrest},
  {"+CIPAPPUP", 9, NULL, NULL, NULL, at_exeCmdCipappup},
#ifdef ali
  {"+MPINFO", 7, NULL, NULL, at_setupCmdMpinfo, NULL}
#endif
};

void at_cmdProcess(uint8_t *pAtRcvData);
//static int8_t at_getCmdLen(uint8_t *pCmd);

#endif
