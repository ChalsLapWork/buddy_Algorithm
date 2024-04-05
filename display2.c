#include "PE_Types.h"
#include "display2.h"
#include <stdlib.h>
#include <stdio.h>
#include "SistemaOperativo.h"

/*ingresar el valor para procesar el comando */
byte procesar_comando(byte cmd) {
byte ret = 1;
	switch (cmd) {
	case 1:printf("\nCreando Proceso.");
		    CrearProceso();
		    break;
	case 2:printf("\nEliminando Proceso."); break;
	case 3:printf("\nreset memoria de Asignacion de Procesos"); break;
	case 4:printf("\nDisplay Htop de los procesos"); break;
	case 5:printf("\nSalir del Programa");
		   ret = 0;
		   break;
	default:
		printf("\nNo se reconoce el comando.");
		  break;}
return ret;
}//fin de procesar comando++++++++++++++++++++++++++++++++++++++