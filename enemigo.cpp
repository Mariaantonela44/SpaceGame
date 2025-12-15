#include "enemigo.h"
#include <iostream>
#include <conio.h>
#include <conio2.h>
using namespace std;

//posiciones de enemigos 
int enemigo::getPosx() { 
	return posx; 
}
int enemigo::getPosy() {
	return posy;
}

//verificacion si esta vivo 
bool enemigo::estaVivo() { 
	return vivo; 
}


void enemigo::mover() {
	posx = posx + direccion;
	
	//limites de borde 
	if (posx < 2) {
		posx = 2;
		direccion = 1;
		posy=posy+1;
	}
	if (posx > 79) {
		posx = 79;
		direccion = -1; 
		posy=posy+1;
	}
	//limite extremo inferior
	if (posy > 20) posy = 20;
}

void enemigo::borrar() {
	gotoxy(posx, posy);
	cout << ' ';
}

//daño al enemigo 
void enemigo::danio() {
	puntosenemigo=puntosenemigo-1;
	if (puntosenemigo <= 0) {
		borrar();
		vivo = false;
	}
}

//dibujo de letra de enemigo 
void enemigo::dibujar() {
	gotoxy(posx, posy);
	textcolor(color);
	cout << forma;
}
