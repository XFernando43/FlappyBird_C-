#pragma once
#include "Obstaculo.h"
#include <vector>
using namespace std;
class Arr_Obstaculo {
	vector<Obstaculo*>* arreglo;
public:
	Arr_Obstaculo() {
		arreglo = new vector<Obstaculo*>();
	}
	void agregar_tubo(Bitmap^ img, Bitmap^ imgMoneda, Bitmap^ imgTi,int x, int y) {
		arreglo->push_back(new Obstaculo(img, imgMoneda, imgTi, x, y));
	}
	void Dibujar_tubos(Bitmap^ img,Bitmap^ imgMoneda, Bitmap^ imgTi, Graphics^ L) {
		for (size_t i = 0; i < arreglo->size(); i++)
		{
			arreglo->at(i)->Draw(img, imgMoneda, imgTi,L);
		}
	}
	void Mover_tubos() {
		for (size_t i = 0; i < arreglo->size(); i++)
		{
			arreglo->at(i)->Mover();
		}
	}
	void Eliminar_tubos() {
		for (size_t i = 0; i < arreglo->size(); i++)
		{
			if (arreglo->at(i)->getEstado() == true) {
				arreglo->erase(arreglo->begin() + i);
			}
		}
	}

	void Eliminar_Monedas() {
		for (size_t i = 0; i < arreglo->size(); i++)
		{
			if (arreglo->at(i)->getMoneda()->getEstado() == true) {
				delete arreglo->at(i)->getMoneda();
			}
		}
	}

	void detener_tubos() {
		for (size_t i = 0; i < arreglo->size(); i++)
		{
			arreglo->at(i)->setDx(0);
		}
	}

	void detener_tubos_invertidos() {
		for (size_t i = 0; i < arreglo->size(); i++)
		{
			arreglo->at(i)->getTuvo_Invertido()->setDx(0);
		}
	}

	void detener_Monedas() {
		for (size_t i = 0; i < arreglo->size(); i++)
		{
			arreglo->at(i)->getMoneda()->setDx(0);
		}
	}

	int getSize() { return arreglo->size(); }
	Obstaculo* getTubo(int i) { return arreglo->at(i); }
};