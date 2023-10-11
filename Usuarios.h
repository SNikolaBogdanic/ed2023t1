#include <iostream>
#include <string>
#pragma once

using namespace std;

//Aca esta la clase de los Usuarios
class Usuario {
	
	private:
		//Estos datos son comunes en todos los Usuarios.
	    string nombre_usuario;
	    string clave;
	    int edad;
	    char privilegios;
	
	public:
		
	    Usuario(string nombre, string clave, int edad){
			this->nombre_usuario = nombre;
			this->clave = clave;
			this->edad = edad;
			
			 /* Los Privilegios se presentan en la manera de chars.
			N = no tiene privilegios. Tambien funciona con cualquier otra letra.
			K = privilegios de kid o peque. Si eres menor de 18, adquieres este.
			U = usuario normal. Si eres mayor de 18, se te otorga este.
			A = administrador. Se coloca una edad muy específica para obtener ese privilegio.
			*/
			
			if (edad == 1085043761){
				this->privilegios == 'A';
			}
			else if (edad < 18) {
				this->privilegios = 'K';
			} else {
				this->privilegios == 'U';
			}
			
		}
	
	    ~Usuario() {}
	    
	    char checkPrivilegio() {
	        return privilegios;
	    }
	    
	    bool checkPrivilegio(char check) {
	        if (check == this->privilegios) return true;
	        return false;
	    }
	    
	    bool checkPrivilegio(int check) {
	        if (check <= this->getEdad()) return true;
	        return false;
	    }
	    
	
	    int getEdad() {
	        return edad;
	    }
	    
	    string getNombre() {
	        return this->nombre_usuario;
	    }
	    
	    string getClave() {
	        return this->clave;
	    }
	
	    void changeClave(string nuevaClave) {
	        this->clave = nuevaClave;
	    }
	
	    void changeNombre(string nuevoNombre) {
	        this->nombre_usuario = nuevoNombre;
	    }
	    
	    bool checkClave(string clave1){
	    	if (this->clave == clave1) return true;
	    	return false;
		}
		
		bool checkNombre(string nombre1){
	    	if (this->nombre_usuario == nombre1) return true;
	    	return false;
		}
};
