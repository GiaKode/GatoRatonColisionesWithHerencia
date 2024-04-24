#include "pch.h"
#include"Controladora.h"
#include <conio.h>
using namespace System;

ClaseControladora* juego = new ClaseControladora();

char tecla;

int main()
{
	srand(time(NULL));
    Console::CursorVisible = false;
	Console::SetWindowSize(140, 40);
	while (1)
	{
		if (_kbhit())
		{
			tecla = _getch();
			tecla = toupper(tecla);
			juego->getgato()->borrar();
			juego->getgato()->movimiento(tecla);

		}
		//(juego->timeOut());

		juego->borrarTODO();
		juego->colision();
		juego->moverTODO();
		juego->dibujarTODO();
		juego->apariciones();

		_sleep(20);
	}
	
	_getch();
    return 0;
}
