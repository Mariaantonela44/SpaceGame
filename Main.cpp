#include "juego.h"
#include <iostream>
#include <conio.h>
#include <conio2.h>
#include "actualizar.h"

using namespace std;

void mostrarMenu() {
	actualizar actualizar1;
	actualizar1.limpiar();
	textcolor(14); 
	gotoxy(30, 5); cout << "JUEGO: ";
	gotoxy(30, 7); cout << "a. Iniciar Juego";
	gotoxy(30, 8); cout << "b. Instrucciones";
	gotoxy(30, 9); cout << "c. Salir";
	gotoxy(30, 11); cout << "Seleccione una opcion: ";
}

void Instruccionesjuego() {
	actualizar actualizar1;
	actualizar1.limpiar();
	textcolor(11); 
	gotoxy(5, 5); cout << "INSTRUCCIONES:";
	gotoxy(5, 7); cout << "- Mover jugador: flechas izquierda/derecha";
	gotoxy(5, 8); cout << "- Disparar: tecla ESPACIO";
	gotoxy(5, 9); cout << "- Sobrevive y elimina enemigos";
	gotoxy(5, 11); cout << "Presione cualquier tecla para volver al menu...";
	getch();
}

int main() {
	int eleccion;
	bool salir = false;
	actualizar actualizar1;
	
	while (!salir) {
		mostrarMenu();
		eleccion = getch(); 
		
		switch (eleccion) {
		case 'a': {
			juego J;
			J.iniciarjuego();
			break;
			
		}
		case 'b':
			Instruccionesjuego();
			break;
			
		case 'c':
			salir = true;
			break;
			
		default:
			gotoxy(30, 13);
			textcolor(12); 
			cout << "Opcion invalida. Intente de nuevo.";
			getch();
			break;
		}
	}
	actualizar1.limpiar();
	gotoxy(30, 10);
	textcolor(10); 
	cout << "Gracias por jugar!";
	return 0;
}
