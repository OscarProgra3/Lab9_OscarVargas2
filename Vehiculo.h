#include <string>

#ifndef VEHICULO_H
#define VEHICULO_H

using namespace std;

class Vehiculo
{
	private:
		string placa;
		string marca;
		string modelo;
		int anio;
		double precio;

	public:
		Vehiculo(string,string,string,int,double);
		
		string getPlaca();
		void setPlaca(string);

		string getMarca();
		void setMarca(string);

		string getModelo();
		void setModelo(string);

		int getAnio();
		void setAnio(int);

		double getPrecio();
		void setPrecio(double);
		//~Vehiculo();
	


};
#endif