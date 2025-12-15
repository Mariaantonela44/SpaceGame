#ifndef BALAS_H
#define BALAS_H

class balas {
private:
	int posx;
	int posy;
	bool gatilloJugador;
	bool gatilloEnemigo;	
public:
	balas();
	int getPosx();
	int getPosy();
	bool disparoJugador();
	bool disparoEnemigo();
	void movimientoBalaEnemigo();
	void movimientoBalaJugador();
	void activarDisparoJugador(int x, int y);
	void activarDisparoEnemigo(int x, int y);
	void desactivarDisparoJugador();
	void desactivarDisparoEnemigo();
	void borrar();
	void dibujar();
};
#endif
