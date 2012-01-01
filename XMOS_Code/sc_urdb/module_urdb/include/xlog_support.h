// Copyright (c) 2011, XMOS Ltd., All rights reserved
// This software is freely distributable under a derivative of the
// University of Illinois/NCSA Open Source License posted in
// LICENSE.txt and at <http://github.xcore.com/>

/*
 * @ModuleName Support functions for message logging
 * @Description: Support functions for message logging
 *
 *
 *
 */
/* These are inline assembly definitions for the xlog client/server.
   Not to be used elsewhere.
 */

#ifndef _xlog_support_h_
#define _xlog_support_h_
#include <xs1.h>

#define _QUOTEME(x) #x
#define QUOTEME(x) _QUOTEME(x)

#define CT_END 1
#define CT_PAUSE 2
#define CT_ACK 3
#define CT_NACK 4

static inline unsigned int _inToken(unsigned int resource_id) {
  unsigned int ret;
  asm ("int %0,res[%1] ":"=r"(ret):"r"(resource_id));
  return ret;
}


static inline unsigned int _inCT(unsigned int resource_id) {
  unsigned int ret;
  asm ("inct %0,res[%1] ":"=r"(ret):"r"(resource_id));
  return ret;
}

static inline unsigned int _inInt(unsigned int resource_id) {
  unsigned int ret;
  asm ("in %0,res[%1] ":"=r"(ret):"r"(resource_id));
  return ret;
}


static inline void _outCT(unsigned int resource_id, unsigned int token) {
  asm ("outct res[%0],%1" ::"r"(resource_id),"r"(token));
  return;
}

static inline void _outDT(unsigned int resource_id, unsigned int token) {
  asm ("outt res[%0],%1" ::"r"(resource_id),"r"(token));
  return;
}


static inline void _outInt(unsigned int resource_id, unsigned int data) {
  asm ("out res[%0],%1" ::"r"(resource_id),"r"(data));
  return;
}


static inline void _setChanEndDest(unsigned int resource_id, unsigned int dest) {
  asm ("setd res[%0],%1" ::"r"(resource_id),"r"(dest));
  return;
}

static inline unsigned int _getChanEnd(void) {
  unsigned int ret;
  asm ("getr %0, 2" :"=r"(ret) :);
  return ret;
}


static inline void _freeChanEnd(unsigned int resource_id) {
  asm ("freer res[%0] "::"r"(resource_id));
  return;
}

#undef _QUOTEME
#undef QUOTEME


#endif //_xlog_support_h_
