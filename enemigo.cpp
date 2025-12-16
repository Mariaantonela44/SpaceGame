#include "enemigo.h"
#include <iostream>
#include <conio.h>
#include <conio2.h>
using namespace std;
enemigo::enemigo() {
	posx = 10;
	posy = 10;
	vivo = true;
	puntosenemigo = 3;
	direccion = 1;
	velocidad = 1;
	color = 7;
	forma = '*';
	ataque = false;
}

enemigo::enemigo(int x, int y, char f) {
	posx = x;
	posy = y;
	forma = f;
	vivo = true;
	color = 7;
	direccion = 1;
	puntosenemigo = 3;
	velocidad = 1;
}

enemigo::enemigo(int x, int y, char f, int c) {
	posx = x;
	posy = y;
	forma = f;
	color = c;
	vivo = true;
	direccion = 1;
	puntosenemigo = 3;
	velocidad = 1;
}


EnemigoH::EnemigoH(int x, int y)
	: enemigo(x, y, 'W', 12) {
	puntosenemigo =5; 
}

EnemigoM::EnemigoM(int x, int y)
	: enemigo(x, y, 'M', 10) {
	puntosenemigo = 3;
}

EnemigoW::EnemigoW(int x, int y)
	: enemigo(x, y, 'H', 14) {
	puntosenemigo = 1;
}

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
	//limite inferior
	//if (posy > 20) posy = 20;
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

//tiro aleatorios
bool enemigo::atacar() {
	int prob = rand() % 100;
	if (prob < 10) {
		return  true;
	}
	else { 
		return  false;
	}
}
