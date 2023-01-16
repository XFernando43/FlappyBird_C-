#pragma once
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace std;
class CEntidad {
protected:
	int x;
	int y;
	int dx;
	int dy;
	int idfilas;
	int idcolumnas;
	int altoPersonaje;
	int anchoPersonaje;
	int AltoImangem;
	int AnchoImagen;
public:
	CEntidad() {

	}
	void Draw();
};