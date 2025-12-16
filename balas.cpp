#include "balas.h"
#include <iostream>
#include <conio2.h>
using namespace std;



balas::balas() {
	posx = 0;
	posy = 0;
	gatilloJugador = false;
	gatilloEnemigo = false;
}


int balas::getPosx() {
	return posx;
}

int balas::getPosy() {
	return posy;
}


bool balas::disparoJugador() {
	return gatilloJugador;
}

bool balas::disparoEnemigo() {
	return gatilloEnemigo;
}


void balas::movimientoBalaJugador() {
	if (gatilloJugador) {
		borrar();
		posy--;
		if (posy <= 0) {
			gatilloJugador = false;
		}
	}
}

void balas::movimientoBalaEnemigo() {
	if (gatilloEnemigo) {
		borrar();
		posy++; 
		if (posy >= 24) { 
			gatilloEnemigo = false;
		}
	}
}

void balas::activarDisparoJugador(int x, int y) {
	if (!gatilloJugador) {
		posx = x;
		posy = y - 1;
		gatilloJugador = true;
	}
}

void balas::activarDisparoEnemigo(int x, int y) {
	if (!gatilloEnemigo) {
		posx = x;
		posy = y + 1;
		gatilloEnemigo = true;
	}
}

void balas::dibujar() {
	if (gatilloJugador || gatilloEnemigo) {
		gotoxy(posx, posy);
		cout << "|";
	}
}

void balas::borrar() {
	gotoxy(posx, posy);
	cout << " ";
}

void balas::desactivarDisparoJugador() {
	gatilloJugador = false;
}

void balas::desactivarDisparoEnemigo() {
	gatilloEnemigo = false;
}
