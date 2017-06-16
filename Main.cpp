#include <string>
#include <vector>
#include <iostream>

#include "Vehiculo.h"
#include "Usuarios.h"
#include "Cliente.h"
#include "Administrador.h"

#include <fstream>
#include <typeinfo>
#include <sstream>

using namespace std;

void listarautos(vector<Vehiculo*>,vector<int>);
void Factura(vector<Vehiculo*> listacarrosT,string usernameT);

int main()
{
	
	vector<Usuarios*> listaUsuarios;
	vector<Vehiculo*> listaVehiculos;
	vector<int> numrentados;

	

	string username, password,membresia,cargo;
	int seguro;
	int resp=9;
	while(resp!=3)
	{
		cout<<endl<<endl<<"Bienvenido\n1.-Agregar Usuarios\n2.-Login\n3.-Salir\ningrese su opcion: ";
			cin>>resp;
			cout<<endl;
			if (resp==1)//opcionagregar
			{

				int option;
				cout << "1.- Cliente" << endl;
				cout << "2.- Admistrador" << endl;
				cout << "Ingrese una opción: " << endl;
				cin >> option;
				cout << endl;
				if (option == 1){
					cout << "Ingrese nombre del usuario: " << endl;
					cin >> username;
					cout << "Ingrese la password: " << endl;
					cin >> password;

					int n;
					cout << "Ingrese el tipo de membresia\n1.-Normal\n2.-Gold\nPlatinum" << endl;
					cin>>n;

					if (n==1)
					{
						membresia="Normal";
					}
					if (n==2)
					{
						membresia="Gold";
					}
					if (n==3)
					{
						membresia="Platinum";
					}


					listaUsuarios.push_back(new Cliente(username, password, membresia));
					cout << "Cliente agregado exitosamente" << endl;

				}//fin de agregar cliente

				if (option==2)
				{
					cout << "Ingrese nombre del usuario: " << endl;
					cin >> username;
					cout << "Ingrese la password: " << endl;
					cin >> password;

					cout << "Ingrese el cargo : " << endl;
					cin >> cargo;

					cout << "Ingrese el numero del seguro: " << endl;
					cin >> seguro;


					listaUsuarios.push_back(new Administrador(username, password, cargo,seguro));
					cout << "El Administrador ha sido agregado exitosamente";

				}// fin de agregar administrador
			}//fin de agregar usuarios

			if (resp==2)//opcion 2
			{
				
				string temppass,tempusu;

				cout<<endl<<"Ingrese Nombre de usuario: ";
				cin>>tempusu;

				cout<<endl<<"contraseña: ";
				cin>>temppass;

				for (int i = 0; i < listaUsuarios.size(); ++i)
				{
					if (listaUsuarios.at(i)->getNombre()==tempusu && listaUsuarios.at(i)->getPass()==temppass)
					{
						if (listaUsuarios.at(i)->getTipoUsuario()=="Cliente")
						{
							cout<<endl<<"-----------BIENVENIDO----------------"<<endl;
						
							vector <Vehiculo*> alquilertemp;
							//alquilertemp = new vector<Vehiculo*>;
							
							double totalrenta=0;
							int numalquiler;
							bool alquilado=false;


							int resprent=9;//respuesta renta
							if (listaVehiculos.size()==0)
							{
								cout<<"Lo sentimos, no hay carros"<<endl;
								resprent=2;
							}
							while(resprent!=2)
							{
								cout<<"Desea alquilar un auto\n1.-SI\n2.-NO";
								cin>>resprent;

								if (resprent==1)
								{

									listarautos(listaVehiculos,numrentados);	
									cout<<"que numero de auto desea alquilar: ";
									cin>>numalquiler;

									for (int i = 0; i < numrentados.size(); ++i)
									{
										if (numalquiler==numrentados.at(i))
										{
											alquilado=true;
										}

									}
									if (alquilado==true)
									{
										cout<<endl<<"este auto ya esta alquilado, perdon :c"<<endl;
									}else
									{
										alquilertemp.push_back(listaVehiculos.at(numalquiler));

									}
								}//fin rentar
								if (resprent==2)
								{

									Factura(alquilertemp,username);
									cout<<"Gracias por su visita, su factura a sido generada"<<endl;

								}

							}//fin alquilar
							



							//fin cliente
						}else if(listaUsuarios.at(i)->getTipoUsuario()=="Administrador")
						{
							cout<<endl<<"BIENVENIDO ADMINISTRADOR"<<endl;
							int respadmi=9;
							while(respadmi!=4)
							{
								cout<<endl<<"Que es lo que desea realizar\n1.-Agregar Vehiculos\n2.-Modificar Vehiculos\n3.-Eliminar Vehiculos\n4.-Salir"<<endl;
								if (respadmi==1)//agrega carro
								{
									
								}//fin agregar carro
							}
							

						}
					}
				}

			}

		}

	return 0;
}

void listarautos(vector<Vehiculo*> listacarros,vector<int> rentadost)
{
	cout<<endl<<"----------LISTA DE LOS VEHICULOS---------------------";
	for (int i = 0; i < listacarros.size(); ++i)
	{
			cout << endl<<"        Numero del Vehiculo: " << (i) << endl;
			cout << endl<<"Placa: "<< listacarros.at(i)->getPlaca()<<endl;
			cout << endl<<"Marca: "<< listacarros.at(i)->getMarca()<<endl;
			cout << endl<<"Modelo: "<< listacarros.at(i)->getModelo()<<endl;
			cout << endl<<"Anio del vehiculo: "<< listacarros.at(i)->getAnio()<<endl;
			cout << endl<<"Precio: "<< listacarros.at(i)->getPrecio()<<endl;
			for (int i = 0; i < rentadost.size(); ++i)
			{
				if (i==rentadost.at(i))
				{
					cout<<endl<<"ALQUILADO"<<endl;
				}

			}



			//Lavaplatos* templavaplatos=dynamic_cast<Lavaplatos*>(listaousuariosT.at(i));

			
			
			cout <<endl<< "----------------------------------------------" << endl;
	}
}


void Factura(vector<Vehiculo*> listacarrosT,string usernameT)
{
	double acum=0;

	ofstream  salida;
	stringstream stm;
	string fichero;

	stm << "./log_alquileres/" << usernameT<< ".log";
	fichero = stm.str();
	salida.open(fichero.c_str());
	salida << "-----------ALQUILERES---------" << endl;
	salida << "---------------------------" << endl;
	
	cout<<endl<<"----------LISTA DE LOS VEHICULOS ALQUILADOS---------------------";
	for (int i = 0; i < listacarrosT.size(); ++i)
	{
			salida << endl<<"        Numero del Vehiculo: " << (i) << endl;
			salida << endl<<"Placa: "<< listacarrosT.at(i)->getPlaca()<<endl;
			salida << endl<<"Marca: "<< listacarrosT.at(i)->getMarca()<<endl;
			salida << endl<<"Modelo: "<< listacarrosT.at(i)->getModelo()<<endl;
			salida << endl<<"Anio del vehiculo: "<< listacarrosT.at(i)->getAnio()<<endl;
			salida << endl<<"............................Precio: "<< listacarrosT.at(i)->getPrecio()<<endl;
			acum+=listacarrosT.at(i)->getPrecio();
			salida <<endl<< "----------------------------------------------" << endl;
	}

			salida<<endl<<"------------------- TOTAL DE ALQUILERES......."<<acum<<" lps.";
			salida <<endl<< "----------------------------------------------" << endl;

}

/*
void imprimirVenta(Venta* venta)
{
	int contarticulos=0;
	ofstream  salida;
	stringstream stm;
	string fichero;

	string horafinalizacion=hora();
	stm << "./log_ventas/" << horafinalizacion<<"_"<<venta->getNombreusuario()<< ".log";
	fichero = stm.str();
	salida.open(fichero.c_str());
	salida << "-----------GAMEHUB---------" << endl;
	salida << "---------------------------" << endl;
	salida << horafinalizacion << endl;
	salida << "Vendedor: " << venta->getNombreusuario()<< endl;
	salida << "Cliente: " << venta->getNombrecliente() << endl;
	int contador = venta->getTamConsola() + venta->getTamJuegos();

	salida <<endl<< "Cantidad de articulos " << contador  << endl;
	salida <<endl;
	vector <Consolas*> listaconsolasTe = venta -> getListaconsolas();
	vector<Videojuegos*> listavideojuegosTe = venta -> getListavideojuegos();

	salida<< "Articulos: "<<endl<<endl;
	for (int i=0; i < listaconsolasTe.size(); i++)
	{
		salida << listaconsolasTe.at(i)->getModelo() << "    L." << listaconsolasTe.at(i)->getPrecio() << endl;
	}
	for (int i=0; i < listavideojuegosTe.size(); i++)
	{
 		salida << listavideojuegosTe.at(i)->getNombre() << "     L." << listavideojuegosTe.at(i)->getPrecio() << endl;
	}

	salida << "Subtotal: " << venta->getSubtotal() << endl;
	double impuesto = venta->getSubtotal()*0.15;
	salida << "Impuesto: " << impuesto << endl;
	double total = venta->getSubtotal() + impuesto;
	salida << "Total: " << total << endl;
	salida.close();
	salida << "---------------------------" << endl;
	salida << "---------------------------" << endl;
	for (int i = 0; i < listaconsolasTe.size(); ++i)
	{
		listaconsolasTe.erase(listaconsolasTe.begin() + i);
	}
	listaconsolasTe.clear();

	for (int i = 0; i < listavideojuegosTe.size(); ++i)
	{
		listavideojuegosTe.erase(listavideojuegosTe.begin() + i);
	}
	listavideojuegosTe.clear();
}*/