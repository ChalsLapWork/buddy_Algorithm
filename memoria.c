#include "memoria.h"
#include "system.h"
#include "errorController.h"
#include "SistemaOperativo.h"
#include "queue.h"


extern struct _SO_ OS;

/* memory allocation para darle meoria a los procesos del sistema operativo
 * return: location where is the pid owner of the memory block:size,
 * *memo: pointer to the block memo lent to process until be killed */
byte *malloc_memory(byte size,byte pid){
	//byte *p;
	//byte offset;
	//byte blocksize;
	byte  *memo=0;
	static byte error;
	//p = buscar_ptr_tablas_de_Asignacion(size, &blocksize);//tenemos la dir de la tabla asignada correspondiente al tamaño
	//offset = buscar_espacio_libre_en_Tabla(p);
	//memo = buscar_bloque_de_memoria_enBanco_de_memoria(blocksize, offset);   
    if(!buscar_y_asignar_Proc_memoria_libre(size,memo)){//buscar si hay memoria libre que necesitamos
      if(is_Proc_free_enough(size))//ver si hay suficiente memoria libre atomica
		 desfragmentar_Proc_mem();
	  else{errorCritico("Error 20");}}

return memo;
}//fin de freedfg memory++++++++++++++++++++++++++++++++++

/* Obtener el nodo libre */
struct _Nodo_ *get_Nodo_Libre(void){
#if(PROC_MAX<255)
	byte i;
#else 
	int i;
#endif
byte ret=0;
	for(i=0;i<PROC_MAX;i++){
		if(OS.memo.nodo[i].PID==0){
			OS.memo.nodo[i].addr=0;
			OS.memo.nodo[i].id=0;
			OS.memo.nodo[i].next=0;
			OS.memo.nodo[i].size=0;
			ret=1;break;}}
	 if(!ret)errorCritico("ERROR 45");
return &OS.memo.nodo[i];
}//obtener el nodo libre+++++++++++++++++++++++++++++