#pragma once
#include"Gato.h"
#include"Raton.h"
#include<vector>

class ClaseControladora {

private:

	Gato* OBJgato;
	Raton* OBJraton;
	//vectores:
	vector<Raton*>ratones;

	//Datos extras:
	int vidas;
	int contador;
	int n;
	int aux;
	//Time:
	time_t tiempo;
	time_t AparicionRatones;

public:
	ClaseControladora() {
		srand(time(NULL));
		n = rand() % 9+7;

		contador = 0;
		tiempo = time(0);
		AparicionRatones  = time(0);
		OBJraton = new Raton(0,5,1,1,7,1);
		OBJgato = new Gato(50, 20, 1, 1, 7, 3);
		for (int i = 0; i < ratones.size(); i++) {
		    AGREGARraton();
		}
	}
	//si ratones llega a ser igual es contador , ratones se eliminan
	~ClaseControladora(){}

	void AGREGARraton() {
		ratones.push_back(new Raton(0, rand() % 39, 1, 1, 7, 1));

	}


	void borrarTODO() {
		Console::SetCursorPosition(0, 0); cout << "                   ";
		OBJgato->borrar();

		for (int i = 0; i < ratones.size(); i++) {
			ratones[i]->borrar();
		}

	}

	void moverTODO() {
		char tecla;

		OBJgato->movimiento(tecla);

		for (int i = 0; i < ratones.size(); i++) {
			ratones[i]->movimiento();
		}

	}

	void dibujarTODO() {
		Console::SetCursorPosition(0, 0); cout << "Ratones Atrapados: " << contador<<"/"<< n;
		OBJgato->dibujar();

		for (int i = 0; i < ratones.size(); i++) {
			ratones[i]->dibujar();
		}

	}

	Gato* getgato() { return OBJgato; }

	//Tiempo:

	void apariciones() { //gracias a esto aparecen mas ratones

		if (difftime(time(0), AparicionRatones) >= 2) {
			AparicionRatones = time(0);
			AGREGARraton();


		}
		

	}
	//terminar el tiempo
	bool timeOut() {
		if (difftime(time(0), tiempo)>=10000)return true;
		else return false;
	}

	//Colision:
	void colision() 
	{
		//Verification
		for (int i = 0; i < ratones.size(); i++) {
			if (OBJgato->getRectangulo().IntersectsWith(ratones[i]->getRectangulo())) {
				ratones[i]->setVisible(false);
				contador++;
				if (contador==n/2)
				{
					
					cout << "gano :)";
					exit(0);
					system("pause");
					//_getch();
					//system("cls");
					Console::Clear();
					
				}
				
			}
		}

		//Elimination
		for (int i = 0; i < ratones.size(); i++) {
			if (ratones[i]->getVisible()==false) {
				ratones.erase(ratones.begin() + i);
			}

		}
	}

	int getCont() { return contador; }
};