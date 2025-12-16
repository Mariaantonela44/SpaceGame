#include "actualizar.h"
#include <iostream>	
#include <conio.h>	

actualizar::actualizar() {
	posx = 0;
	posy = 0;
}
int actualizar::getPosx() {
	return posx;
}
int actualizar::getPosy() {
	return posy;
}
void actualizar::actualizarPosicion(int x, int y) {
	posx = x;
	posy = y;
}
void actualizar::limpiar() {
	system("cls");
}