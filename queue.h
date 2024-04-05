#pragma once
#ifndef _QUEUE_H
#define _QUEUE_H

#include "PE_Types.h"

#define PROC_MAX 20
#define PROC_NAME_SIZE 5
#define MEMO_PROC_SIZE 100
#define FMBC_SIZE 8//pointer free memory block control
#define _255 7//lugar de pointer que apunta a bloques de memoria de 255

//buffer de Processos 
struct _UCProc {//Unidad de control de Processors
	unsigned char (*proc)(unsigned char* m);//Tabla de Procesos, pointer to proceso actual que se guarda
	char name[PROC_NAME_SIZE];//nombre del proceso
	unsigned char size;//cantidad de memoria asinada a este proceso
	//ver si memoAddr se usa o no se usa para quitarlo
	//unsigned char *memoAddr;//direccion de la Tabla de memoria de PIDs asignada a este proceso
	unsigned char* memoPrAddr;//direccon del Bloque de memoria que usara el proceso
	unsigned char recurso;//[REC_X_PROC];//recursoS asignadoS
	//unsigned char pid;//id del proceso
	struct File* file;//archivos abiertos asignados al recurso
	unsigned char state;//RUNNING,WAITING,READY,
	//unsigned char HijosPID[NUM_SON_X_PROC];
	unsigned char PadrePID;
	unsigned char priority;//prioridad del proceso, 0 es alta prioridad  
};//processors control

struct _Nodo_ {
  byte id;//1xxx xxxx [libre|busy]id del nodo, para identificar nodo
  byte *addr;//direccion del bloque de memoria libro o ocupado por un proceso
  byte PID;//pid propertario del bloque de memoria
  struct _Nodo_ *next;
  byte size;//tamaño del bloque de memoria
  byte status;//libre,ready,0,
};


//https://opendsa-server.cs.vt.edu/embed
struct _Memoria {
	//unsigned char memo10[MEMO_SIZE10];//memoria en bloques de 10
	//unsigned char memo20[MEMO_SIZE20];
	//unsigned char memo30[MEMO_SIZE30];
	//unsigned char memo60[MEMO_SIZE60];
	unsigned char memo[MEMO_PROC_SIZE];	//memoria de los programas
	struct _Nodo_ *FMBC[FMBC_SIZE]; //pointer free memory block control
	struct _Nodo_ nodo[PROC_MAX];//nodo de control de memoria de procesos, libre u ocupada
	struct _Nodo_ *(* getNodo)(void);

	unsigned char* (*malloc)(unsigned char size, unsigned char pid);
	void (*free)(unsigned char* ptr);
	//unsigned char tablaSize10[T_MEM_SIZE10];//tablas para encontrar
	//unsigned char tablaSize20[T_MEM_SIZE20];//que pid tiene asignada
	//unsigned char tablaSize30[T_MEM_SIZE30];//que bloque de memoria
	//unsigned char tablaSize60[T_MEM_SIZE60];//
	//unsigned char* FPBpSize[MEMO_FPBP_SIZE];//Free Process Block pointer size, guarda los pointer de cada size
	//struct _MemNodo mn[MEMO_NODO_MAX];

	unsigned short int freeSpace;//memoria libre de Procesos
	unsigned short int usedSpace;//mem usada de procesos

	unsigned char tablaPid[PROC_MAX];//numero de pid del process
	unsigned char* tablaAdd[PROC_MAX];//tabla de inicio de direccion de memo asignada al pid
};



struct _KERNEL {
//struct _FIFO_1byte_ Ready;
	byte pid_debug;
	byte pid_debug2;
	void (*kill)(byte     pid);
	void (*suspend)(byte  pid);
	void (*resume)(byte   pid);
	void (*free)(byte pid);
	byte(*run)(byte pid);
	void (*insertRecurso)(byte recurso, byte pid);//lista de recursos de cada proceso
	void (*removeRecurso)(byte pid);
	void (*cleanRecursos)(byte pid);
	//	byte (*buscarRecurso)(byte recurso,byte pid,byte *index);
	void (*addPID)(byte pid);//agregar pid hijo a un pid padre
	byte(*nextPID)(void);//busca el siguiente PID a ejecut
	struct SYSTEM_CALL {
		byte(*seekFile)(const char*, byte pid, byte* m);
		struct FILE* (*getFileDescriptor)(void);
		void (*createFile)(const char*, byte pid, byte* r, byte* m, byte s);
		byte(*nextSYSCALL)(void);
		void (*createSYSCALL)(byte(*process)(byte* m), char* name, byte size);//debug REvisar si se usa
	}SYSCALL;
	struct _FIFOs_ {
		byte(*getNextPID)(void);
		//struct _FIFO_1byte_ SCIsReady;//System CAll Interfaz fifo of ready processes

	}fifos;
};// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




struct _SO_ {
  struct _UCProc BCP[PROC_MAX];//Bloque de control de Processors
  struct _KERNEL kernel;
  struct _Memoria memo;
  byte Pstatus[PROC_MAX];//estatus de los procesos



};//fin de sistema operativo



unsigned char newpid(void);
void free1(byte pid);
void init_queue(void);

#endif // !_QUEUE_H
