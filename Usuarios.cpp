#include "Usuarios.h"

Usuarios::Usuarios(string pnombre,string ppass)
{
	nombre=pnombre;
	pass=ppass;
}
	
	
string Usuarios::getNombre()
{
	return nombre;
}
void Usuarios::setNombre(string tnombre)
{
	nombre=tnombre;
}

string Usuarios::getPass()
{
	return pass;
}
void Usuarios::setPass(string tpass)
{
	pass=tpass;
}

string Usuarios::getTipoUsuario()
{
	return "";
}		
