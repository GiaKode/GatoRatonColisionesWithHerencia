#pragma once
#include"Movimientos.h"

class Raton : public Movimientos {

public:
	Raton(int x, int y, int dx, int dy, int ancho, int alto) : Movimientos(x, y, dx, dy, ancho, alto){}

	~Raton(){}

	//borrar - mover - dibujar
	void borrar() {

		Console::SetCursorPosition(x, y);     cout << "       ";
	}

	void dibujar() {

		Console::SetCursorPosition(x, y);     cout << "--(_c'>";
	}

	void getborrar() { return borrar(); }







};