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
	posxAnterior=0;
	necesitaRedibujar=true;
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
	if (!necesitaRedibujar) return;
	gotoxy(posx, posy);
	cout << "A"; 
	necesitaRedibujar=false;
}
void jugador::moverjugador(char tecla) {
	posxAnterior=posx;
	necesitaRedibujar=false;
	
	if (tecla == 'a' || tecla == 'A') {
		if (posx > 2) posx--;
	}
	else if (tecla == 'd' || tecla == 'D') {
		if (posx < 78) posx++;
	}
		if(posx!=posxAnterior){
			borrar();
			necesitaRedibujar=true;
		}
	
}

void jugador::borrar() {		
	gotoxy(posxAnterior, posy);
	cout << " ";
}	
void jugador::Redibujar(){
	necesitaRedibujar=true;
}
