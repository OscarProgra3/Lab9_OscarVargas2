#include <string>

#ifndef USUARIO_H
#define USUARIO_H

using namespace std;

class Usuarios
{
	protected:
		string nombre;
		string pass;
		

	public:
		Usuarios(string,string);
	//	~Usuarios();
	
		string getNombre();
		void setNombre(string);

		string getPass();
		void setPass(string);

		virtual string getTipoUsuario();		

};
#endif