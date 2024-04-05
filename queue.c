#include "queue.h"
#include "system.h"
#include "SistemaOperativo.h"
#include "memoria.h"

struct _SO_ OS;


void init_queue(void) {
byte i,j;
	OS.memo.malloc = malloc_memory;
	OS.memo.getNodo=get_Nodo_Libre;
	for(i=0,j=2;i<FMBC_SIZE;i++,j*=2){
	    OS.memo.FMBC[i].addr=0;
	    OS.memo.FMBC[i].id=0; 
	    OS.memo.FMBC[i].next=0;
	    OS.memo.FMBC[i].PID=0;
		OS.memo.nodo[i].status=0;
		OS.memo.FMBC[i].size=j;}
	for(i=0;i<PROC_MAX;i++){
	    OS.memo.nodo[i].addr=0;
		OS.memo.nodo[i].id=0;
		OS.memo.nodo[i].next=0;
		OS.memo.nodo[i].PID=0;
		OS.memo.nodo[i].status=0;
		OS.memo.nodo[i].size=0;}
    OS.memo.FMBC[_255]=OS.memo.getNodo();
	OS.memo.FMBC[_255]->PID=0xFE;//pid virtual para que el sistema vea que esa ocupado el nodo
	OS.memo.FMBC[_255]->id=0;
	OS.memo.nodo[i].status=PRFREE;//Usado para memoria libre
	OS.memo.nodo[i].next=OS.memo.getNodo();
	OS.memo.nodo[i].size=255;
	OS.memo.nodo[i].next->next=0;
	OS.memo.nodo[i].next->PID=0;
	OS.memo.nodo[i].next->size=255;
	estamos configurando el nodo cero cuando esta en el pointer de 
		256 cuando esta en cer otodo
}//fin de init quueeue+++++++++++++++


//nuevo pid ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/* regresa -1 si hay error, regresa el pid que corresponde al nuevo
 * proceso, ese pid es el indice en el block de procesos BCP
 * el proceso 0 no existe es el 0xFF */
unsigned char newpid(void) {
	auto unsigned char i, j = 0;

	for (i = 0; i < PROC_MAX; i++) {
		if (OS.BCP[i].state == 0) { OS.kernel.free(i); }
		if (OS.BCP[i].state == PRFREE) {
			j = TRUE; break;
		}
	}
	if (!j) { return _ERROR_; }
	if (i == 0)i = 0xFF;
	return i;
}//fin de new pid-------------------------------------------------------

void free1(byte pid) {
	byte pid1;
	if (pid == 0xFF)pid1 = 0; else { pid1 = pid; }
	OS.Pstatus[pid1] = PRFREE;
	OS.BCP[pid1].state = PRFREE;
}//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
