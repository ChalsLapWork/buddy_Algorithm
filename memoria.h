#pragma once
#ifndef _MEMORIA_H
#include "PE_Types.h"

byte* malloc_memory(byte  size, byte pid);
struct _Nodo_ *get_Nodo_Libre(void);

#endif