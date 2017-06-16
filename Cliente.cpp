#include "Cliente.h"

Cliente::Cliente(string pnombre,string ppass, string ptipo) : Usuarios(pnombre, ppass)
{
	tipo=ptipo;
}

string Cliente::getTipomembresia()
{
	return tipo;
}
void Cliente::setTipomembresia(string ttipo)
{
	tipo=ttipo;
}


string Cliente::getTipoUsuario()
{
	return "Cliente";
}		