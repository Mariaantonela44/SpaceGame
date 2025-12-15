#ifndef ENEMIGO_H
#define ENEMIGO_H

class enemigo {
private:
	bool vivo;
	
protected:
	int velocidad;
	char forma;
	int color;
	

public:
	int direccion;
	bool ataque;
	int posx;
	int posy;
	int puntosenemigo;
	enemigo();
	int getPosx();
	int getPosy();
	void borrar();
	void mover();
	void dibujar();
	void danio();
	bool atacar();
	bool estaVivo();
};




#endif
