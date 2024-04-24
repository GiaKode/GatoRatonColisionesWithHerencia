#pragma once
#include"Movimientos.h"

class Gato : public Movimientos {

private:
	int vidas;

public:
	Gato(int x, int y, int dx, int dy, int ancho, int alto) : Movimientos(x, y, dx, dy, ancho, alto) {


	}
	~Gato(){}

	//borrar - mover - dibujar

	void borrar() {

		Console::SetCursorPosition(x, y);     cout << "       ";
		Console::SetCursorPosition(x, y + 1); cout << "       ";
		Console::SetCursorPosition(x, y + 2); cout << "       ";
	}

	void movimiento(char tecla) {
		switch (tecla)
		{
			//Izquierda X
		case 'A':
			if (x >= 1)x -= dx;
			break;
			//Abajo Y
		case 'S':
			if (y >= 0)y += dy;
			break;
			//Derecha X
		case 'D':
			if (x + ancho <= 133)x += dx;
			break;
			//Arriba Y
		case 'W':
			if (y + alto <= 40)y -= dy;
			break;
		}
	}

	void dibujar() {

		Console::SetCursorPosition(x, y);     cout << " /\\_/\\";
		Console::SetCursorPosition(x, y + 1); cout << "( o.o )";
		Console::SetCursorPosition(x, y + 2); cout << " > ^ < ";
	}




};