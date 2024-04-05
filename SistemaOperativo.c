#include "SistemaOperativo.h"
#include "queue.h"
#include "PE_Types.h"
#include "system.h"
#include "stdio.h"
#include "errorController.h"



extern struct _SO_ OS;


/*crear un proceso consiste en
meter el proceso en la memoria de 
procesos y en el BCP*/
void CrearProceso(void) {
int i=0;
	printf("\nCreando Proceso:");
	printf("\nIngrese la memoria:");
	scanf_s("%i",&i);
	create(i);



}//fin de crear proceso+++++++++++++++++

byte create(unsigned char size) {
	auto unsigned char pid, *memoBlock, pid0;
	pid = newpid();
	if (pid == 0){errorCritico("Error 30"); }
	if (pid == 0xFF)pid0 = 0; else { pid0 = pid; }
	if (size == 0)errorCritico("Error 32");//Debug Trap for code in construcction
	if (pid == _ERROR_) return _ERROR_;//Debug mandar error por serial
	//OS.BCP[pid0].priority = prioridad;
	//OS.BCP[pid0].proc = process;
	//for (i = 0; i < NAME_SIZE; i++) {
	//	if (*(name + i) < 0x30) break;
	//  else { OS.BCP[pid0].name[i] = *(name + i); }}
	//if (i < NAME_SIZE) OS.BCP[pid0].name[i] = 0;//ultimo caracter es cero
	memoBlock = OS.memo.malloc(size, pid);
	OS.BCP[pid0].recurso = 0;//recursos del PID
	//for (i = 0; i < NUM_SON_X_PROC; i++)OS.BCP[pid0].HijosPID[i] = 0;//hijos del PID
	//OS.BCP[pid].memoAddr=pAddr;
	OS.BCP[pid0].memoPrAddr = memoBlock;
	//OS.BCP[pid0].PadrePID = PadrePID;
	OS.kernel.addPID(pid);//agregar pid a la lista de 
	OS.kernel.resume(pid);
	return (1);
}//fin create procedure-------------------------------------------

/*buscar y asignar procesos memoria libre */
byte buscar_y_asignar_Proc_memoria_libre(byte size,byte *addr){


  
}//fin de buscar y asignar proceso de memoria libre


byte is_Proc_free_enough(byte size){

}

void desfragmentar_Proc_mem(void){
}