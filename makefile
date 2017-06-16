Main:	Main.o Usuarios.o Cliente.o   Administrador.o Vehiculo.o 
	g++ Main.o Usuarios.o Cliente.o   Administrador.o Vehiculo.o  -o Main

Main.o:	Main.cpp Usuarios.h Cliente.h  Administrador.h  Vehiculo.h
	g++ -c Main.cpp

Usuarios.o:	Usuarios.cpp Usuarios.h
	g++ -c Usuarios.cpp

Cliente.o:	Cliente.cpp Cliente.h Usuarios.h
	g++ -c Cliente.cpp

Administrador.o:	Administrador.cpp Administrador.h Usuarios.h
	g++ -c Administrador.cpp

Vehiculo.o: Vehiculo.cpp Vehiculo.h
	g++ -c Vehiculo.cpp


clean:	
	rm -f *.o Main