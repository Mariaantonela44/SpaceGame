#include "jugador.h"
#include <iostream>	
#include <conio.h>
#include <conio2.h>
#include <iostream>
using namespace std;

jugador::jugador() {
	posx = 40;
	posy =22;
	vidas = 3;
}

int jugador::getPosx() {
	return posx;
}	
int jugador::getPosy() {
	return posy;
}	
int jugador::Vidas() {
	return vidas;
}	

void jugador::CantidadVidas() {
	vidas= vidas -1;
}	
void jugador::dibujar() {
	gotoxy(posx, posy);
	cout << "A"; 
}
void jugador::moverjugador(char tecla) {
	
	if (tecla == 'a' || tecla == 'A') {
		if (posx > 2) posx--;
	}
	else if (tecla == 'd' || tecla == 'D') {
		if (posx < 78) posx++;
	}
}

void jugador::borrar() {		
	gotoxy(posx, posy);
	cout << " ";
}	
