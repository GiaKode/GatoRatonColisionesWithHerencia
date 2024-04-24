#pragma once
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Drawing;

class Movimientos {

protected:

	int x, y, dx, dy, ancho, alto;
	bool visible;

public:

	Movimientos(int x, int y, int dx, int dy, int ancho, int alto) {
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		this->ancho = ancho;
		this->alto = alto;

	}

	~Movimientos() {}

	void movimiento() {

		/*if (x + dx < 0 || Console::WindowWidth < x + dx + ancho) {


			dx *= -1;


		}
		x += dx;*/

		if (x + ancho < 115) x += rand() % 3 + 1;
		else { x += dx; x = 0; y = rand() % 29; }

		/*if (y + dy < 0 || Console::WindowHeight < y + dy + alto) {


			dy *= -1;


		}
		y += dy;*/


	}

	Rectangle getRectangulo() {
		return Rectangle(x, y, ancho, alto);
	}

	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }
	
	int getx() { return x; }
	int gety() { return y; }
	int getdx() { return dy; }
	int getdy() { return dy; }
	int getancho() { return ancho; }








};