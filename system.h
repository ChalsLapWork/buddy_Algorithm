#pragma once
#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#define PRFREE      'F'//0xF0 //lugar libre de proceso, bloque libre.
#define PRREADY     'R'//0xF1  //proceso listo
#define PRCURR      'C'// 0xF2 //proceso actual
#define PRSUSP      's'//0xF3//PROCESO suspendido
#define PRSLEEP     'S'//0xF4//proceso durmiendo


#define _ERROR_      0xF1 //ERROR en algun systema 


#endif