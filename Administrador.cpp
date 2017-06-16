#include "Administrador.h"

Administrador::Administrador(string pnombre, string ppass, string pcargo, int pseguro) : Usuarios(pnombre, ppass)
{
	cargo=pcargo;
	seguro=pseguro;
}

string Administrador::getCargo()
{
	return cargo;
}
void Administrador::setCargo(string tcargo)
{
	cargo=tcargo;
}

int Administrador::getSeguro()
{
	return seguro;
}
void Administrador::setSeguro(int tseguro)
{
	seguro=tseguro;
}


string Administrador::getTipoUsuario()
{
	return "Administrador";
}		