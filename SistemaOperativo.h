#pragma once
#ifndef _SISTEMA_OPERATIVO_H
#define _SISTEMA_OPERATIVO_H_
#include "PE_Types.h"

byte create(unsigned char size);
void CrearProceso(void);
byte is_Proc_free_enough(byte size);
void desfragmentar_Proc_mem(void);
byte buscar_y_asignar_Proc_memoria_libre(byte size,byte *addr);

#endif