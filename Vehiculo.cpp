#include "Vehiculo.h"

Vehiculo::Vehiculo(string pplaca,string pmarca,string pmodelo,int panio,double pprecio)
{
	placa=pplaca;
	marca=pmarca;
	modelo=pmodelo;
	anio=panio;
	precio=pprecio;
}
		
string Vehiculo::getPlaca()
{
	return placa;
}
void Vehiculo::setPlaca(string tplaca)
{
	placa=tplaca;
}

string Vehiculo::getMarca()
{
	return marca;
}
void Vehiculo::setMarca(string tmarca)
{
	marca=tmarca;
}

string Vehiculo::getModelo()
{
	return modelo;
}
void Vehiculo::setModelo(string tmodelo)
{
	modelo=tmodelo;
}

int Vehiculo::getAnio()
{
	return anio;
}
void Vehiculo::setAnio(int tanio)
{
	anio=tanio;
}

double Vehiculo::getPrecio()
{
	return precio;
}
void Vehiculo::setPrecio(double tprecio)
{
	precio=tprecio;
}