#include <iostream>
#include <string.h>
using namespace std;

const char *nombre_archivo = "Archivo.dat";
const char *archivo_temporal = "temporal.dat";

struct Estudiante {
	
	int codigo;
	char nombre [50];
	char apellido [50];
	char direccion [50];
	int telefono;
	
};

void crear();
void leer();
void actualizar();
void eliminar();

main(){
	int op;
	do{
	system("cls");
	leer();
	cout<<"__________________________________________________________________________________"<<endl;
	cout<<"\n               *** MENU ***\n";
	cout<<" 1. INGRESAR ESTUDIANTE"<<endl;
	cout<<" 2. ACTUALIZAR DATOS DE ESTUDIANTE"<<endl;
	cout<<" 3. ELIMINAR ESTUDIANTE"<<endl;
	cout<<" 0. SALIR"<<endl;
	cin>>op;
	if (op==1){
	crear();
	}
	else if (op==2){
	actualizar();
	}
	else if (op==3){
	eliminar();
	}
	
	
	}while (op!=0);
	
}


void crear (){
	
	char continuar;
	
	FILE* archivo = fopen(nombre_archivo, "ab");
	Estudiante estudiante;
	string nombre, apellido, direccion;
	
	do {
		fflush(stdin);				
		
		cout<<"\n                         *** INGRESAR NUEVO ESTUDIANTE *** \n"<<endl;
		cout<<"INGRESE CODIGO:";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"INGRESE NOMBRES: ";
		getline(cin,nombre);
		strcpy(estudiante.nombre, nombre.c_str());
		cout<<"INGRESE APELLIDOS: ";
		getline(cin, apellido);
		strcpy(estudiante.apellido, apellido.c_str());
		cout<<"INGRESE DIRECCION: ";
		getline(cin,direccion);
		strcpy(estudiante.direccion, direccion.c_str());
		cout<<"INGRESE TELEFONO: ";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite(&estudiante, sizeof(Estudiante),1,archivo);
		
		cout<<"\n DESA AGREGAR OTRO ESTUDIANTE (s/n): ";
		cin>>continuar;
	
	}while (continuar == 's' || continuar == 'S');
	fclose(archivo);
}


void leer(){
	system("cls");
	FILE* archivo= fopen(nombre_archivo, "rb");
	
	if(!archivo){
		
		archivo= fopen(nombre_archivo, "a+w");
	}

	Estudiante estudiante;
	
	int id=0;
	
	fread(&estudiante, sizeof(Estudiante),1,archivo);
	
		cout<<"_______________________________________________________________________"<<endl;
		cout<<"ID"<<" | "<<"CODIGO"<<" | "<<"     NOMBRES      "<<" | "<<"        APELLIDOS    "<<" | "<<"     DIRECCION    "<<" | "<<"  TELEFONO"<<endl;
		do{
		cout<<"_______________________________________________________________________"<<endl;
		cout<<id<<" | "<<estudiante.codigo<<"       | "<<estudiante.nombre<<"      | "<<estudiante.apellido<<"      | "<<estudiante.direccion<<" | "<<estudiante.telefono<<endl;
		fread(&estudiante, sizeof (Estudiante),1,archivo);
		id++;
		
		}while (feof(archivo)==0);
		fclose(archivo);
		cout<<endl;
		
}

void actualizar (){
	
	FILE* archivo= fopen(nombre_archivo, "r+b");
	
	int id;
	Estudiante estudiante;
	
	string nombre, apellido, direccion;
	
	cout<<"INGRESE EL ID DEL ESTUDIANTE QUE DESEA MODIFICAR: ";
	cin>>id;
	
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
	
	fflush(stdin);
	cout<<"\n              *** DATOS A MODIFICAR ***       \n";
	cout<<" INGRESE CODIGO: ";
	cin>>estudiante.codigo;
	cin.ignore();
	cout<<" INGRESE NOMBRES: ";
	getline(cin, nombre);
	strcpy(estudiante.nombre, nombre.c_str());
	cout<<" INGRESE APELLIDOS: ";
	getline(cin,apellido);
	strcpy(estudiante.apellido, apellido.c_str());
	cout<<" INGRESE DIRECCION: ";
	getline(cin, direccion);
	strcpy(estudiante.direccion, direccion.c_str());
	cout<<" INGRESE TELEFONO: ";
	cin>>estudiante.telefono;
	cin.ignore();
	
	fwrite(&estudiante, sizeof(Estudiante),1,archivo);
	fclose(archivo);
	system("cls");
	leer();
	cout<<"_________________________________________________________________________"<<endl;
	cout<<"************* MODIFICACION EXITOSA **************"<<endl;
	system("pause");
	
	
	
}


void eliminar(){

		FILE* archivo_temp=fopen(archivo_temporal,"w+b"); 
		FILE* archivo=fopen(nombre_archivo,"rb"); 	 
	
		int codigo; 
		Estudiante estudiante; 
		
	                      				                
		cout<<"INGRESE CODIGO DEL ESTUDIANTE A ELIMINAR: "<<endl; 
		cin>>codigo; 
	                                                                                
		while(fread(&estudiante,sizeof(Estudiante),1,archivo)){	
			
			if (codigo != estudiante.codigo) {
			fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp); 
			}
			else{
				cout<<"\n                    ****** ARCHIVO ELIMINADO ****** \n";
				system("pause");
			}
			
			}
	                
		fclose(archivo_temp); 
		fclose(archivo); 
	
	remove("Archivo.dat");
	rename("temporal.dat", "Archivo.dat");
	
	}


