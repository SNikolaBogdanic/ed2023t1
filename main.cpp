#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>
#include "Usuarios.h"
#include "archivos.h"

using namespace std;

Usuario** user_getter(int cantidad_users, Usuario* usuarios[]){
	while(true){
    	string aux = "";
    	int u = 0;
    	bool truthaux = false;
    	cout << "\nIngrese nombre de usuario (O escribe SALIR para apagar la maquina): ";
    	cin>>aux;
    	if (aux == "SALIR") return NULL;
    	for (u = 0; u<cantidad_users;u++){
    		if (aux == usuarios[u]->getNombre()){
    			truthaux = true;
    			break;
			}
		}
		if (truthaux){
			truthaux = false;
			cout << "\nIngrese clave: ";
	    	cin>>aux;
	    	if (usuarios[u]->checkClave(aux)){
	    		cout << "\n";
	    		return &usuarios[u];
			} else {
				cout << "\nClave incorrecta."<< endl;
				continue;
			}
		} else {
			cout << "\nNo se ha encontrado a ese usuario."<< endl;
			continue;
		}
	}
}

int main() {
    cout << "INICIALIZANDO SISTEMA OPERATIVO SLAVNIK 1.0" << endl;
    
    // Almacenamiento de usuarios
    Usuario* usuarios[255];
    
    // Puntero para usuario que este usando el PC en este momento
    Usuario** current_user;
    
    //Almacenamiento de cantidad de usuarios
    int cantidad_users = 17;

    // Inicializando 1 administrador
    usuarios[0] = new Usuario("Admin", "admin0987654321", 1085043761);
	
	// Cuentas de menores
	usuarios[1] = new Usuario("Sebas123", "niyu123920", 12);
    usuarios[2] = new Usuario("Armin900", "12458393", 15);
    usuarios[3] = new Usuario("CarlosMalebran", "execution512", 10);
	usuarios[4] = new Usuario("UsuarioMenor1", "pass123", 17);
	usuarios[5] = new Usuario("UsuarioMenor2", "pass456", 9);
	
	// Cuentas de usuarios normales
	usuarios[6] = new Usuario("Usuario1", "pass789", 22);
	usuarios[7] = new Usuario("Usuario2", "pass101112", 25);
	usuarios[8] = new Usuario("chistocito", "incorrecta", 31);
	usuarios[9] = new Usuario("null", "password", 37);
	usuarios[10] = new Usuario("User_not_found", "pass192021", 42);
	usuarios[11] = new Usuario("Usuario6", "pass222324", 45);
	usuarios[12] = new Usuario("PastelFurry", "pass252627", 50);
	usuarios[13] = new Usuario("Usuario8", "pass282930", 55);
	usuarios[14] = new Usuario("Usuario9", "pass313233", 56);
	usuarios[15] = new Usuario("Usuario10", "pass343536", 65);
	usuarios[16] = new Usuario("PedritoUrrutia", "pass373839", 72);
	
	Carpeta* main = new Carpeta("main",NULL,usuarios[0]);
	
    while(true){
    	current_user = user_getter(cantidad_users, usuarios);
    	if (current_user == NULL){
    		cout << "\nApagando..." << endl;
    		break;
		}
		
		bool close = false;
		while (!close){
			close = main->abrir(*current_user);
		}
	}
    
    delete main;
    
    // Liberacion de memoria al apagarse. En un computador real, esto no se deberia hacer.
    for (int i = 0; i < cantidad_users; ++i) {
        delete usuarios[i];
    }

    return 0;
}
