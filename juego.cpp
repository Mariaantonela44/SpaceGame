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
		enemigos[i++] = new EnemigoH(x, 3);
	
	for (int x = 4; x <= 32; x += 4)
		enemigos[i++] = new EnemigoM(x, 5);
	
	for (int x = 4; x <= 32; x += 4)
		enemigos[i++] = new EnemigoW(x, 7);
}

void juego::aumentarPuntaje(int puntos) {
	puntaje = puntaje + puntos;
}
void dibujarBorde() {
	
	int ancho = 80;   
	int alto = 25;  
	
	textcolor(15);
	
	gotoxy(1, 1);
	/*for (int x = 1; x <= ancho; x++) {
		cout << ".";
	}*/
	
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

bool juego::hayEnemigoDebajo(enemigo* actual){
	for (int i = 0; i < MAX_ENEMIGOS; i++) {
		if (enemigos[i] != nullptr && enemigos[i]->estaVivo()) {
			if (enemigos[i]->getPosx() == actual->getPosx()) {
				if (enemigos[i]->getPosy() > actual->getPosy()) {
					return true;
				}
			}
		}
	}
	return false;
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
		
		//PRESIONAR TECLA
		if (_kbhit()){ tecla = getch();
		}else{ 
			tecla=0;
			}
	    //DIBUJO Y MOVIMIENTO DEL JUGADOR
		jugador1.dibujar();
		jugador1.moverjugador(tecla);
		
	     //ATAQUE DEL JUGADOR
		if (tecla == ' ' && !balaJugador.disparoJugador()){
			balaJugador.activarDisparoJugador(jugador1.getPosx(), jugador1.getPosy());
		}
		//BALAS DEL JUGADOR CON TIMER
		if(clock()-relojBalaJugador>=intervaloBalaJugador){
		balaJugador.movimientoBalaJugador();
		relojBalaJugador=clock();}
		

		if (balaJugador.disparoJugador()) {
			balaJugador.dibujar();
		}
		if (balaJugador.disparoJugador()){ 
			balaJugador.dibujar();
		}
		//BALAS JUGADOR
		if (clock() - relojBalaEnemigo >= intervaloBalaEnemigo) {
			balaEnemigo.movimientoBalaEnemigo();
			relojBalaEnemigo = clock();
		}
		
		if (balaEnemigo.disparoEnemigo()) {
			balaEnemigo.dibujar();
		}
		
		//COLISION BALA DEL JUGADOR A ENEMIGO 
		if(balaJugador.disparoJugador()){
			int balaX=balaJugador.getPosx();
			int balaY=balaJugador.getPosx();
			
			for (int i = 0; i < MAX_ENEMIGOS; i++) {
				if (enemigos[i] && enemigos[i]->estaVivo()) {
					int enemigoX=enemigos[i]->getPosx();
					int enemigoY=enemigos[i]->getPosy();
					
					if  (balaY == enemigoY && balaX >= enemigoX && balaX < enemigoX + 3) {
						
						aumentarPuntaje(enemigos[i]->puntosenemigo);
						enemigos[i]->danio();
						
						balaJugador.borrar();
						balaJugador.desactivarDisparoJugador();
						break;
					}
				}
			}
		}
		
		//BALAS ENEMIGAS 
		
		//DISPARO DE ENEMIGOS
		if (clock() - relojEnemigos >= intervaloEnemigos) {
			
			bool cambiarDireccion = false;
			
			// detectar borde
			for (int i = 0; i < MAX_ENEMIGOS; i++) {
				if (enemigos[i] && enemigos[i]->estaVivo()) {
					int x = enemigos[i]->getPosx();
					if (x <= 2 || x >= 79) {
						cambiarDireccion = true;
						break;
					}
				}
			}	
			
		//BAJAR AL COLISIONAR CON BORDES LATERALES 
			if (cambiarDireccion) {
				for (int i = 0; i < MAX_ENEMIGOS; i++) {
					if (enemigos[i] && enemigos[i]->estaVivo()) {
						enemigos[i]->borrar();
						enemigos[i]->direccion *= -1;
						enemigos[i]->posy += 1;
						enemigos[i]->dibujar();
					}
				}
			}
			//MOVIMIENTO DE ENEMIGOS
			for (int i = 0; i < MAX_ENEMIGOS; i++) {
				if (enemigos[i] && enemigos[i]->estaVivo()) {
					
					if (enemigos[i]->getPosy() >= jugador1.getPosy()) {
						juegoActivo = false;
						break;
					}
					
					enemigos[i]->borrar();
					enemigos[i]->mover();
					enemigos[i]->dibujar();
				}
			}
		
			//DISPARO DE ENEMIGO DESDE LA ULTIMA FILA 
			if (!balaEnemigo.disparoEnemigo()) {
				
				for (int i = 0; i < MAX_ENEMIGOS; i++) {
					if (enemigos[i] && enemigos[i]->estaVivo()) {
						
						if (!hayEnemigoDebajo(enemigos[i])) {
							
							if (enemigos[i]->atacar()) {
								balaEnemigo.activarDisparoEnemigo(enemigos[i]->getPosx(),enemigos[i]->getPosy());
								break;
								}
							}
						}
					}
				}
			
			relojEnemigos = clock();
		}								
		// bala enemigo vs jugador
		if (balaEnemigo.disparoEnemigo() && balaEnemigo.getPosx() == jugador1.getPosx() && balaEnemigo.getPosy() == jugador1.getPosy()) {
			jugador1.CantidadVidas();
			balaEnemigo.desactivarDisparoEnemigo();
			if (jugador1.Vidas() <= 0){
				juegoActivo = false;
			}
		}
	
		actualizar1.limpiar();
		
		textcolor(12);
		gotoxy(30, 10);
		cout << "GAME OVER";
		
		textcolor(15);
		gotoxy(25, 12);
		cout << "Puntaje final: " << puntaje;
		
		gotoxy(20, 15);
		cout << "Presione una tecla para salir...";
		getch();
		
	// limpiar memoria
	for (int i = 0; i < MAX_ENEMIGOS; i++)
		delete enemigos[i];
}
	


