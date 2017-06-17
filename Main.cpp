#include <string>
#include <vector>
#include <iostream>

#include "Vehiculo.h"
#include "Usuarios.h"
#include "Cliente.h"
#include "Administrador.h"

#include <stdio.h>
#include <stdlib.h>

#include <fstream>
#include <typeinfo>
#include <sstream>

using namespace std;

void listarautos(vector<Vehiculo*>,vector<int>);
void Factura(vector<Vehiculo*> listacarrosT,string usernameT);
void imprimirautos(vector<Vehiculo*> listacarrost,vector<int> rentadostt);
void imprimirusuarios(vector<Usuarios*> listaUsuariosT);

int main()
{

	srand(time(NULL));
	
	vector<Usuarios*> listaUsuarios;
	vector<Vehiculo*> listaVehiculos;
	vector<int> numrentados;

	

	string username, password,membresia,cargo;
	int seguro;
	int resp=9;
	while(resp!=5)
	{
		cout<<endl<<endl<<"Bienvenido\n1.-Agregar Usuarios\n2.-Login\n3.-Listar e imprimir vehiculos\n4.-Guardar reporte\n5.-Salir\ningrese su opcion: ";
			cin>>resp;
			cout<<endl;
			if (resp==3)
			{
				listarautos(listaVehiculos,numrentados);
				imprimirautos(listaVehiculos,numrentados);
				cout<<endl<<"IMPRESION REALIZADA CON EXITO"<<endl;
			}
			if (resp==4)
			{
				void imprimirusuarios(vector<Usuarios*> listaUsuariosT);
				
			}
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
								cin>>respadmi;
								if (respadmi==1)//agrega carro
								{
									string placat,marcat,modelot;
									int aniot,r;
									double preciot;
									
								

										for (int i = 0; i < 4; ++i)
										{
											r = rand() % 6 + 1;
											if (r == 1)
											{
												placat+= "A";
											} else if (r == 2)
											{
												placat+=  "B";
											} else if (r == 3)
											{
												placat+=  "C";
											} else if (r == 4)
											{
												placat+=  "D";
											} else if (r == 5)
											{
												placat+= "E";
											} else if (r == 6)
											{
												placat+= "F";
											} else {
												placat+= "H";
											}
										}

										int t;
										string tt;
										placat+="--";
										for (int i = 0; i < 4; ++i)
										{
											t= rand() % 9 + 1;
											tt=t+"";
											placat+=tt;
										}

									cout<<"PLACA: "<<placat;
									cout<<endl<<"ingrese la marca del vehiculo: ";
									cin>>marcat;

									cout<<endl<<"ingrese el modelo del vehiculo: ";
									cin>>modelot;

									cout<<endl<<"ingrese el año del vehiculo: ";
									cin>>aniot;

									cout<<endl<<"ingrese el precio del vehiculo: ";
									cin>>preciot;

									listaVehiculos.push_back(new Vehiculo(placat, marcat, modelot,aniot,preciot));
									cout<<endl<<"VEHICULO AGREGADO CON EXITO"<<endl;

								}//fin agregar carro
								if (respadmi==3)
								{
									int eliminar;
									listarautos(listaVehiculos,numrentados);
									cout<<endl<<"¿QUE NUMERO DE AUTO DESEA ELIMINAR?: ";
									cin>>eliminar;
									listaVehiculos.erase(listaVehiculos.begin()+eliminar);
									cout<<endl<<"VEHICULO ELIMINADO CON EXITO"<<endl;

								}
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


			
			
			cout <<endl<< "----------------------------------------------" << endl;
	}
}

void imprimirusuarios(vector<Usuarios*> listaUsuariosT)
{
	ofstream  salida;
	stringstream stm;
	string fichero;

	stm << "./log_alquileres/Usuarios.log";
	
	cout<<endl<<"----------LISTA DE LOS USUARIOS ---------------------";
	for (int i = 0; i < listaUsuariosT.size(); ++i)
	{
			salida << endl<<"        Numero de Usuario: " << (i) << endl;
			salida << endl<<"Nombre del usuario: "<< listaUsuariosT.at(i)->getNombre()<<endl;
			salida << endl<<"Marca: "<< listaUsuariosT.at(i)->getPass()<<endl;
			
			if (listaUsuariosT.at(i)->getTipoUsuario()=="Cliente")
			{
				salida<<endl<<"tipo Cliente";
			}else
			{
				salida<<endl<<"tipo Administrador";
			}
			
			cout <<endl<< "----------------------------------------------" << endl;
}	


}

void imprimirautos(vector<Vehiculo*> listacarrost,vector<int> rentadostt)
{


	ofstream  salida;
	stringstream stm;
	string fichero;

	stm << "./log_alquileres/Vehiculos.log";
	
	cout<<endl<<"----------LISTA DE LOS VEHICULOS ---------------------";
	for (int i = 0; i < listacarrost.size(); ++i)
	{
			salida << endl<<"        Numero del Vehiculo: " << (i) << endl;
			salida << endl<<"Placa: "<< listacarrost.at(i)->getPlaca()<<endl;
			salida << endl<<"Marca: "<< listacarrost.at(i)->getMarca()<<endl;
			salida << endl<<"Modelo: "<< listacarrost.at(i)->getModelo()<<endl;
			salida << endl<<"Anio del vehiculo: "<< listacarrost.at(i)->getAnio()<<endl;
			salida << endl<<"............................Precio: "<< listacarrost.at(i)->getPrecio()<<endl;
			salida <<endl<< "----------------------------------------------" << endl;
			for (int i = 0; i < rentadostt.size(); ++i)
			{
				if (rentadostt.at(i)==i)
				{
					salida <<endl<< "este vehiculo esta alquilado" << endl;
			
				}
			}
	}

			
			cout <<endl<< "----------------------------------------------" << endl;
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
