#include "Usuarios.h"
#include <string>

#ifndef CLIENTE_H
#define CLIENTE_H

using namespace std;

class Cliente : public Usuarios
{
	private:
		string tipo;


	public:
		Cliente(string, string, string);
		//~Cliente();
		string getTipomembresia();
		void setTipomembresia(string);

		string getTipoUsuario();		

};
#endif