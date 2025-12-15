#include "juego.h"
#include "jugador.h"
#include "actualizar.h"	
#include <conio.h>	
#include <iostream>
#include <conio2.h>

using namespace std;


juego::juego() {
	nivel = 1;
	puntaje = 0;
	
}

int juego::getNivel() {
	return nivel; 
}
int juego::getPuntaje() {
	return puntaje; 
}

void juego::cargarenemigos() {
	int i = 0;
	
	for (int x = 4; x <= 32; x += 4)
		enemigos[i++] = new EnemigoW(x, 3);
	
	for (int x = 4; x <= 32; x += 4)
		enemigos[i++] = new EnemigoM(x, 5);
	
	for (int x = 4; x <= 32; x += 4)
		enemigos[i++] = new EnemigoH(x, 7);
}

void juego::aumentarPuntaje(int puntos) {
	puntaje = puntaje + puntos;
}

void dibujarBorde() {
	
	int ancho = 80;   
	int alto = 25;  
	
	textcolor(15);
	
	gotoxy(1, 1);
	for (int x = 1; x <= ancho; x++) {
		cout << ".";
	}
	
	for (int y = 2; y < alto; y++) {
		gotoxy(1, y);
		cout << ".";
		gotoxy(ancho, y);
		cout << ".";
	}
	
	gotoxy(1, alto);
	for (int x = 1; x <= ancho; x++) {
		cout << ".";
	}
}


void juego::iniciarjuego() {
	
	jugador jugador1;
	actualizar actualizar1;
	cargarenemigos();
	
	bool juegoActivo = true;
	
	int altoBorde = 25;   
	int anchoBorde = 80;  
	
	actualizar1.limpiar();
	dibujarBorde();
	
	while (juegoActivo) {
		char tecla = 0;
		
		if (_kbhit()) tecla = getch();
		
		jugador1.borrar();
		jugador1.moverjugador(tecla);
		jugador1.dibujar();
		
		for (int i = 0; i < MAX_ENEMIGOS; i++) {
			if (enemigos[i] != nullptr && enemigos[i]->estaVivo()) {
				enemigos[i]->borrar();
				enemigos[i]->mover();
				enemigos[i]->dibujar();
				}
			}
		}
			
			gotoxy(2, altoBorde + 1);
			cout << "Vidas: " << jugador1.Vidas()
				<< "  Puntaje: " << getPuntaje() << "     ";
	}
	


