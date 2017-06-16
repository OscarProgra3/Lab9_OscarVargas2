#include "Usuarios.h"
#include <string>

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

using namespace std;

class Administrador : public Usuarios
{
	private:
		string cargo;
		int seguro;

	public:
		Administrador(string, string, string, int);
		//~Administrador();
		
		string getCargo();
		void setCargo(string);

		int getSeguro();
		void setSeguro(int);

		string getTipoUsuario();		


};
#endif