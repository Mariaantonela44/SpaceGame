#include "juego.h"
#include "enemigo.h"
#include "jugador.h"
#include "balas.h"  
#include "actualizar.h"	
#include <conio.h>	
#include <iostream>
#include <conio2.h>
#include "timer.h"

using namespace std;


juego::juego() {
	nivel = 1;
	puntaje = 0;
	
	
	for (int i = 0; i < MAX_ENEMIGOS; i++)
		enemigos[i] = nullptr;
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

void juego::Timers() {
	
	intervaloEnemigos = CLOCKS_PER_SEC * 1;
	relojEnemigos = clock();
	
	
	intervaloJugador = CLOCKS_PER_SEC / 12;
	relojJugador = clock();
	
	
	intervaloBalaJugador = CLOCKS_PER_SEC / 10;
	relojBalaJugador = clock();
	
	
	intervaloBalaEnemigo = CLOCKS_PER_SEC / 5;
	relojBalaEnemigo = clock();
}

void juego::iniciarjuego() {
	Timers();
	
	jugador jugador1;
	balas balaJugador;
	balas balaEnemigo;
	actualizar actualizar1;
	cargarenemigos();
	
	bool juegoActivo = true;
	
	int altoBorde = 25;   
	int anchoBorde = 80;  
	
	actualizar1.limpiar();
	dibujarBorde();
	
	while (juegoActivo) {
		char tecla = 0;
		
		//si pulso una tecla
		if (_kbhit()) tecla = getch();
		
		jugador1.moverjugador(tecla);
		jugador1.dibujar();
		jugador1.borrar();
		
		if (tecla == ' ' && !balaJugador.disparoJugador()){
			balaJugador.activarDisparoJugador(jugador1.getPosx(), jugador1.getPosy());
		}
	
		if(clock()-relojBalaJugador>=intervaloBalaJugador){
		balaJugador.movimientoBalaJugador();
		relojBalaJugador=clock();}
		
		//bala jugador
		if (balaJugador.disparoJugador()) {
			balaJugador.dibujar();
		}
		if (balaJugador.disparoJugador()){ 
			balaJugador.dibujar();
		}
		
		//bala enemigo
		if (clock() - relojBalaEnemigo >= intervaloBalaEnemigo) {
		balaEnemigo.movimientoBalaEnemigo();
		relojBalaEnemigo = clock();
		}
	
		if (balaEnemigo.disparoEnemigo()) {
			balaEnemigo.dibujar();
		}
		
		
		//Dibujo y movimiento de enemigos 
		if (clock() - relojEnemigos >= intervaloEnemigos) {
			for (int i = 0; i < MAX_ENEMIGOS; i++) {
				if (enemigos[i] != nullptr && enemigos[i]->estaVivo()) {
					enemigos[i]->borrar();
					enemigos[i]->mover();
					enemigos[i]->dibujar();
				
					if (enemigos[i]->atacar()){
						balaEnemigo.activarDisparoEnemigo(enemigos[i]->getPosx(),enemigos[i]->getPosy());
					}
				
					if (balaJugador.disparoJugador() && balaJugador.getPosx() == enemigos[i]->getPosx() &&balaJugador.getPosy() == enemigos[i]->getPosy()) {
						aumentarPuntaje(enemigos[i]->puntosenemigo);
						enemigos[i]->danio();
						balaJugador.desactivarDisparoJugador();
					}
				}
			}
			relojEnemigos=clock();
		}
		
		// bala enemigo vs jugador
		if (balaEnemigo.disparoEnemigo() && balaEnemigo.getPosx() == jugador1.getPosx() && balaEnemigo.getPosy() == jugador1.getPosy()) {
			jugador1.CantidadVidas();
			balaEnemigo.desactivarDisparoEnemigo();
			if (jugador1.Vidas() <= 0){
				juegoActivo = false;
			}
		}
		
		//bala jugador vs enemigo 
		for (int i = 0; i < MAX_ENEMIGOS; i++) {
			if (enemigos[i] && enemigos[i]->estaVivo()) {
				
				if (balaJugador.disparoJugador() &&
					balaJugador.getPosx() == enemigos[i]->getPosx() &&
					balaJugador.getPosy() == enemigos[i]->getPosy()) {
					
					aumentarPuntaje(enemigos[i]->puntosenemigo);
					enemigos[i]->danio();
					balaJugador.desactivarDisparoJugador();
				}
			}
		}
			
			// --- HUD ARREGLADO --- Problemas que no se veia
			gotoxy(2, altoBorde + 1);
			cout << "Vidas: " << jugador1.Vidas()<< "  Puntaje: " << getPuntaje() << "     ";
	}
	
	// limpiar memoria
	for (int i = 0; i < MAX_ENEMIGOS; i++)
		delete enemigos[i];
}
	


