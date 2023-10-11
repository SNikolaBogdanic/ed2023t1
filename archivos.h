#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>
#include "Usuarios.h"
#pragma once

using namespace std;

/*
class Archivo {
	protected:
		
		//Todos los archivos, sean carpetas o software, tienen nombres.
		string nombre;

	    struct NodoU {
	        Usuario* usuario;
	        NodoU* siguiente;
	        bool deleteflag;
	
	        NodoU(Usuario* user) : usuario(user), siguiente(NULL), deleteflag(false) {}
	    };
	    
	    //Sirve para llevar cuenta de los usuarios que crearon o usan los archivos dentro
	    NodoU* usuarios;
		
	public:
		Archivo(string nombre, Usuario* creador) : nombre(nombre), usuarios(NULL) {
	        // Agrega al creador a la lista de usuarios
	        NodoU* nuevoNodo = new NodoU(creador);
	        nuevoNodo->siguiente = usuarios;
	        usuarios = nuevoNodo;
	    }
		
		~Archivo() {
		    NodoU* actual = usuarios;
		    while (actual != NULL) {
		        NodoU* siguiente = actual->siguiente;
		        delete actual;
		        actual = siguiente;
		    }
		}
		
		virtual string getNombre(){
			return this->nombre;
		}
		
		virtual bool checkNombre(string attempt){
			if (attempt == this->nombre) return true;
			return false;
		}
		
		void changeNombre(string nombre){
			this->nombre = nombre;
		}
		
		virtual bool abrir(Usuario* usuario){
			cout<<"Archivo abierto por el usuario "<<usuario->getNombre()<<"."<<endl;
		}
		
		virtual void getPropiedades(){
			cout<<"Esto es un archivo base sin datos salvo su nombre: "<<this->nombre<<"."<<endl;
		}
		
		void agregarUsuario(Usuario* user){
			NodoU* nuevoNodo = new NodoU(user);
			nuevoNodo->siguiente = usuarios;
			usuarios = nuevoNodo;
	 	}
		
		virtual Archivo* ejecutarComando(char comando, Archivo* archivo, string extradata, Usuario* user){
			cout<<"Se ejecuta el comando "<<comando<<"."<<endl;
		}
		
		//Una importante funcion que sirve a modo de eliminador.
		void tagForDeletion(Usuario* user){
			NodoU* actual = usuarios;
	        while (actual != NULL) {
	            if (actual->usuario->checkNombre(user->getNombre())) {
	                actual->deleteflag = true;
	                
	                NodoU* actual2 = usuarios;
			        while (usuarios != NULL) {
			        	if (actual->deleteflag == false) {
			        		cout << "El archivo no se ha eliminado.\nBasta que el resto de usuarios que ocupan esto intente eliminarlo igualmente." << endl;
			        		return;
						}
			        }
			        cout << "Archivo eliminado exitosamente." << endl;
	                delete this;
	                return;
	            }
	            actual = actual->siguiente;
	        }
	        return;
		}
};

*/
class Software {
	protected:
		string nombre;
	    string desarrollador;
	    int edad_rating;
	    int precio;
	    struct NodoU {
	        Usuario* usuario;
	        NodoU* siguiente;
	        bool deleteflag;
	
	        NodoU(Usuario* user) : usuario(user), siguiente(NULL), deleteflag(false) {}
	    };
	    NodoU* usuarios;
	    
	    struct NodoHistorial {
	        Usuario* usuario;
	        NodoHistorial* siguiente;
	
	        NodoHistorial(Usuario* user) : usuario(user), siguiente(NULL) {}
	    };
	
	    NodoHistorial* historialUsuarios;
	
	public:
	    Software(string nombre, Usuario* creador, string desarrollador, int edad_rating, int precio) {
	    	this->nombre = nombre;
	        this->desarrollador = desarrollador;
	        this->edad_rating = edad_rating;
	        this->precio = precio;
	        NodoU* nuevoNodo = new NodoU(creador);
	        nuevoNodo->siguiente = usuarios;
	        usuarios = nuevoNodo;
	        historialUsuarios = NULL;
	    }
	
	    ~Software() {
			NodoU* actual = usuarios;
		    while (actual != NULL) {
		        NodoU* siguiente = actual->siguiente;
		        delete actual;
		        actual = siguiente;
		    }
		    NodoHistorial* actual2 = historialUsuarios;
	        while (actual2 != NULL) {
	            NodoHistorial* siguiente = actual2->siguiente;
	            delete actual2;
	            actual2 = siguiente;
	        }
		}
		
		string getNombre() {
        	return this->nombre;
	    }
	
	    string getDesarrollador() {
	        return this->desarrollador;
	    }
	
	    int getEdadRating() {
	        return this->edad_rating;
	    }
	
	    int getPrecio() {
	        return this->precio;
	    }
	
	    void setNombre(string nombre) {
	        this->nombre = nombre;
	    }
	
	    void setDesarrollador(string desarrollador) {
	        this->desarrollador = desarrollador;
	    }
	
	    void setEdadRating(int edad_rating) {
	        this->edad_rating = edad_rating;
	    }
	
	    void setPrecio(int precio) {
	        this->precio = precio;
	    }
		
		bool checkNombre(string attempt){
			if (attempt == this->nombre) return true;
			return false;
		}
		
		void changeNombre(string nombre){
			this->nombre = nombre;
		}
		
		virtual void abrir(Usuario* usuario){
			cout<<"Archivo abierto por el usuario "<<usuario->getNombre()<<"."<<endl;
			registrarApertura(usuario);
		}
		
		virtual void getPropiedades(){
			cout<<"Esto es un archivo base sin datos salvo su nombre: "<<this->nombre<<"."<<endl;
		}
		
		void agregarUsuario(Usuario* user){
			NodoU* nuevoNodo = new NodoU(user);
			nuevoNodo->siguiente = usuarios;
			usuarios = nuevoNodo;
	 	}
		
		void tagForDeletion(Usuario* user){
			NodoU* actual = usuarios;
	        while (actual != NULL) {
	            if (actual->usuario->checkNombre(user->getNombre())) {
	                actual->deleteflag = true;
	                
	                NodoU* actual2 = usuarios;
			        while (usuarios != NULL) {
			        	if (actual->deleteflag == false) {
			        		cout << "El archivo no se ha eliminado.\nBasta que el resto de usuarios que ocupan esto intente eliminarlo igualmente." << endl;
			        		return;
						}
			        }
			        cout << "Archivo eliminado exitosamente." << endl;
	                delete this;
	                return;
	            }
	            actual = actual->siguiente;
	        }
	        return;
		}
		
		void registrarApertura(Usuario* usuario) {
	        NodoHistorial* nuevoNodo = new NodoHistorial(usuario);
	        nuevoNodo->siguiente = historialUsuarios;
	        historialUsuarios = nuevoNodo;
	    }
	    
	    void printLog(Usuario* usuario){
	    	if (usuario->getEdad() == 1085043761){
	    		NodoU* actual = usuarios;
	    		cout << "Historial de uso de este programa (Ultimos logs primero):" << endl;
		    	while (actual != NULL) {
		            cout << actual->usuario->getNombre() << endl;
		            actual = actual->siguiente;
		        }
			}
		}
		
};

class Juego : public Software {
	private:
	    string generos[14];
	    int genero;
	public:
	    Juego(string nombre, Usuario* creador, string desarrollador, int edad_rating, int precio, int genero)
	        : Software(nombre, creador, desarrollador, edad_rating, precio), genero(genero) {
				generos[0] = "Accion";
				generos[1] = "Aventura";
				generos[2] = "Arcade";
				generos[3] = "Deportes";
				generos[4] = "Estrategia";
				generos[5] = "FPS";
				generos[6] = "Indie";
				generos[7] = "Juego de Mesa";
				generos[8] = "MMO";
				generos[9] = "Musical";
				generos[10] = "RPG";
				generos[11] = "Puzzle";
				generos[12] = "Simulacion";
				generos[13] = "Supervivencia";
			}
	
	    void abrir(Usuario* usuario) {
	    	if (usuario->checkPrivilegio(edad_rating)){
	    		cout << usuario->getNombre() << " ahora esta jugando: " << getNombre() << ". Género: " << genero << "." << endl;
			} else {
				cout << "No tienes permisos para abrir este juego." << endl;
				return;
			}
	        
	    }
	    
	    string getGenero(){
	    	return generos[genero];
		}
	    
	    void setGenero(int genero){
	    	this->genero = genero;
		}
};

class Ofimatica : public Software {
	private:
	    int contadorArchivos;
	
	public:
	    Ofimatica(string nombre, Usuario* creador, string desarrollador, int edad_rating, int precio)
	        : Software(nombre, creador, desarrollador, edad_rating, precio), contadorArchivos(0) {}
	
	    void abrir(Usuario* usuario) {
	        cout << usuario->getNombre() << " está usando el software de ofimática: " << getNombre() << "." << endl;
	        while (true) {
	        	string input;
	        	cout << "Ingrese un comando: ";
	        	cin>>input;
	            if (input == "ayuda")
				{
	                cout << "\nComandos disponibles: " << endl;
	                cout << "ayuda                  Muestra todos los comandos a los que tienes acceso." << endl;
	                cout << "agregar                Agrega un archivo." << endl;
	                cout << "quitar                 Elimina un archivo." << endl;
	                cout << "limpiar                Elimina todos los archivos." << endl;
	                cout << "atras                  Vuelve al menu principal." << endl;
	            }
	            else if (input == "agregar")
				{
	            	addContadorArchivos();
				}
				else if (input == "quitar")
				{
	            	restContadorArchivos();
				}
				else if (input == "limpiar")
				{
	            	restContadorArchivos(getContadorArchivos());
				}
				else if (input == "atras")
				{
	            	return;
				}
				else {
					cout << "Comando no valido. Ingresa 'ayuda' para ver comandos disponibles." << endl;
				}
			}
	    }
	
	    int getContadorArchivos() const {
	        return contadorArchivos;
	    }
	
	    void addContadorArchivos() {
	        contadorArchivos++;
	    }
	    
	    void addContadorArchivos(int cont) {
	        contadorArchivos += cont;
	    }
	    
	    void restContadorArchivos() {
	        contadorArchivos--;
	    }
	    
	    void restContadorArchivos(int cont) {
	        contadorArchivos =- cont;
	    }
	    
	    void setContadorArchivos(int cont) {
	        contadorArchivos = cont;
	    }
};



/*

class Carpeta : public Archivo {
	private:
	    struct NodoC {
	        Carpeta* carpeta;
	        NodoC* siguiente;
	
	        NodoC(Carpeta* carp) : carpeta(carp), siguiente(NULL) {};
	    };
	    
	    struct NodoS {
	        Software* software;
	        NodoS* siguiente;
	
	        NodoS(Software* soft) : software(soft), siguiente(NULL) {};
	    };
	
	    NodoC* primer_fichero;
	    NodoS* primer_software;
	    Carpeta* carpeta_padre;
	
	public:
	    // Constructor
	    Carpeta(string nombre, Usuario* creador, Carpeta* padre) : Archivo(nombre, creador) {
	        this->carpeta_padre = padre;
	        this->primer_fichero = NULL;
	        this->primer_software = NULL;
	    }
	
	    // Destructor
	    ~Carpeta() {
	        while (primer_fichero != NULL) {
	            NodoC* siguiente = primer_fichero->siguiente;
	            delete primer_fichero;
	            primer_fichero = siguiente;
	        }
	        
	        while (primer_software != NULL) {
	            NodoS* siguiente = primer_software->siguiente;
	            delete primer_software;
	            primer_software = siguiente;
	        }
	    }
	    
	    /*
	    Archivo* ejecutarComando(char comando, Archivo* archivo, string data, Usuario* user){
	    	/*Los comandos son los siguientes:
	    	C = obtener la carpeta o archivo padre.
	    	A = agregar archivo
	    	E = enumerar archivos
	    	B = buscar archivo
	    	D = destruir archivo
	    	switch(comando){
	    		case 'A':
	    			agregarArchivo(archivo);
	    			break;
	    		case 'B':
	    			return buscarArchivoPorNombre(data);
	    		case 'C':
	    			return obtenerCarpetaPadre();
	    		case 'D':
	    			borrarArchivo(data, user);
	    			break;
	    		case 'E':
	    			listarArchivos();
	    			break;
	    		default:
	    			cout<<"\nERROR"<<endl;
	    			break;
			}
			return NULL;
		}
	    
	    Carpeta* obtenerCarpetaPadre() {
	        return carpeta_padre;
	    }
	    
	    void agregarCarpeta(Carpeta* arch) {
	        NodoC* nuevoNodo = new NodoC(arch);
	        nuevoNodo->siguiente = primer_fichero;
	        primer_fichero = nuevoNodo;
	    }
	
	    void listarArchivos() {
	    	if (primer_fichero == NULL){
	    		cout << "\nEsta carpeta no tiene archivos" << endl;
	    		return;
			}
	        Nodo* actual = primer_archivo;
	        cout << "\nMostrando archivos disponibles:" << endl;
	        while (actual != NULL) {
	            cout << actual->archivo->getNombre() << endl;
	            actual = actual->siguiente;
	        }
	    }
	    
	    Carpeta* buscarCarpetaPorNombre(string nombre) {
	        NodoC* auxN = buscarNodoArchivoPorNombre(nombre);
	        if (auxN == NULL) return NULL;
	        return auxN->carpeta;
	    }
	    
	    NodoC* buscarNodoCarpetaPorNombre(string nombre) {
	        NodoC* actual = primer_archivo;
	        while (actual != NULL) {
	        	if (actual->archivo == NULL) {
	            	actual = actual->siguiente;
	            	continue;
	            }
	            if (actual->carpeta->checkNombre(nombre)) {
	                return actual;
	            }
	            actual = actual->siguiente;
	        }
	        return NULL;
	    }
	    
	    void getPropiedades() {
	    	cout<<"Propiedades"<<"\nNombre: "<<nombre<<"\nTipo: Carpeta\nContiene los siguientes archivos:"<<endl;
	    	listarArchivos();
	    }
	    
	    void borrarArchivo(string nombreArchivo, Usuario* usuario){
	    	Nodo* nodo_archivo_found = buscarNodoArchivoPorNombre(nombreArchivo);
	        if (nodo_archivo_found != NULL) {
	        	Nodo* nodoaux;
	        	nodoaux = nodo_archivo_found->siguiente;
	            nodo_archivo_found->archivo->tagForDeletion(usuario);
	            if (nodo_archivo_found->archivo == NULL){
	            	delete nodo_archivo_found;
	            	Nodo* current = primer_archivo;
	            	while (current->siguiente != NULL) {
			            current = current->siguiente;
			        }
			        current->siguiente = nodoaux;
				} else {
					cout << "\nArchivo no encontrado." << endl;
				}
	        }
		}
	    
	    bool abrir(Usuario* usuario) {
	    	
	    	//Obteniendo nombres de las carpetas anteriores
	    	string commandline = "";
			Archivo* carpeta_aux = this;
			while (carpeta_aux != NULL) {
			    commandline = "/" + carpeta_aux->getNombre() + commandline;
			    carpeta_aux = carpeta_aux->ejecutarComando('C',NULL,"",NULL);
			}
			
			commandline = usuario->getNombre() + commandline + ": ";
	    	
	    	bool auxBool = true; //Solucion parche de ingreso de texto. NO TOCAR.
	    	
	    	//ejecucion de comandos
	        while (true) {
	        	string input;
	        	cout << commandline;
	        	if (auxBool){
	        		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        		auxBool = false;
				}
	        	getline(cin, input);

			    istringstream iss(input);
			    vector<string> partes;
				
			    do {
			        string parte;
			        iss >> parte;
			        partes.push_back(parte);
			    } while (iss);
				
	            if (partes[0] == "ayuda")
				{
	                cout << "\nComandos disponibles: " << endl;
	                cout << "ayuda                  Muestra todos los comandos a los que tienes acceso." << endl;
	                cout << "revisar                Muestra todos los archivos a los que tienes acceso desde tu carpeta actual." << endl;
	                cout << "revisar [nombre]       Muestra los detalles del archivo que hayas especificado en [nombre], si existe." << endl;
	                cout << "abrir [nombre]         Abre una carpeta o ejecuta un programa. Escribe el nombre del archivo a abrir en [nombre]." << endl;
	                cout << "atras                  Vuelve a la carpeta anterior." << endl;
	                cout << "agrecarpeta            Agrega una nueva carpeta." << endl;
	                cout << "borrar [nombre]        Elimina o trata de eliminar el archivo indicado." << endl;
	                cout << "logout                 Cierra la sesion del usuario actual y vuelve a la pantalla de inicio de sesion." << endl;
	                cout << "Para poder apagar el sistema por completo, debes de ingresar el comando 'logout' y luego ingresar 'SALIR'." << endl;
	            }
	            else if (partes[0] == "revisar")
				{
				    if (partes.size() > 2) {
				        string nombreArchivo = partes[1];
				        Archivo* archivo_found = ejecutarComando('B',NULL,nombreArchivo,NULL);
				        if (archivo_found != NULL) {
				            archivo_found->getPropiedades();
				            continue;
				        } else {
				        	auxBool = true;
				            cout << "\nArchivo no encontrado." << endl;
				            continue;
				        }
				    } else {
				        this->listarArchivos();
				        cout << "" << endl;
				        continue;
				    }
				}
	            else if (partes[0] == "abrir")
				{
					cout << partes.size() << endl;
	            	if (partes.size() > 2) {
	            		cout << "1" << endl;
				        string nombreArchivo = partes[1];
				        cout << partes[1] << endl;
				        Archivo* archivo_found = ejecutarComando('B',NULL,nombreArchivo,NULL);
				        cout << "3" << endl;
				        if (archivo_found != NULL) {
				        	cout << "4" << endl;
				            bool full_close = archivo_found->abrir(usuario);
				            cout << "5" << endl;
				            if (full_close) return true;
				        } else {
				            cout << "\nArchivo no encontrado." << endl;
				        }
				        continue;
				    } else {
				        cout << "\nComando Incompleto. Debes de escribir el nombre del archivo que vas a abrir junto al comando." << endl;
				        continue;
				    }
	            }
	            else if (partes[0] == "atras")
				{
	            	return false;
				}
				else if (partes[0] == "logout")
				{
	            	return true;
				}
				else if (partes[0] == "borrar")
				{
	            	if (partes.size() > 2) {
	            		
				        string nombreArchivo = partes[1];
				        
				        Nodo* nodo_archivo_found;
				        while (nodo_archivo_found != NULL) {
				        	if (nodo_archivo_found->archivo == NULL) {
				            	nodo_archivo_found = nodo_archivo_found->siguiente;
				            	continue;
				            	cout << "niggas" << endl;
				            }
				            if (nodo_archivo_found->archivo->checkNombre(nombreArchivo)) {
				            	cout << "niggum" << endl;
				                break;
				            }
				            nodo_archivo_found = nodo_archivo_found->siguiente;
				        }
				        cout << "niggaasd" << endl;
				        if (nodo_archivo_found != NULL) {
				        	
				        	Nodo* nodoaux;
				        	nodoaux = nodo_archivo_found->siguiente;
				        	
				            nodo_archivo_found->archivo->tagForDeletion(usuario);
				            cout << "nous." << endl;
				            if (nodo_archivo_found->archivo == NULL){
				            	cout << "NIGGER" << endl;
				            	delete nodo_archivo_found;
				            	cout << "nigga" << endl;
				            	Nodo* current = primer_archivo;
				            	cout << "flyid" << endl;
				            	while (current->siguiente != NULL) {
				            		cout << "hail" << endl;
						            current = current->siguiente;
						            cout << "hiler" << endl;
						        }
						        current->siguiente = nodoaux;
						        cout << "moscovit" << endl;
							}
							cout << "verysus" << endl;
				        } else {
				            cout << "\nArchivo no encontrado." << endl;
				        }
				        continue;
				    } else {
				        cout << "\nComando Incompleto. Debes de escribir el nombre del archivo a eliminar junto al comando." << endl;
				        continue;
				    }
				}
				else if (partes[0] == "agrecarpeta")
				{
					cout << "\nDale un nombre: ";
					cin>>input;
					this->agregarArchivo(new Carpeta(input,this,usuario));
					cout << "\nCarpeta creada"<<endl;
					auxBool = true;
					continue;
				}
	            else {
	                cout << "\nComando no reconocido. Escribe el comando 'ayuda' para obtener una lista de comandos validos." << endl;
	                continue;
	            }
        	}
        	
    	}
};

*/
