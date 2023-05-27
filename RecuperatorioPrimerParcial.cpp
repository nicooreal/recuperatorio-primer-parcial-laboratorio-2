using namespace std;
#include <iostream>
#include "EstudiantesArchivo.h"
#include "RecuperatorioPrimerParcial.h"
#include "ClaseParticular.h"
#include "ClasesParticularesArchivo.h"



void RecuperatorioPrimerParcial::cursosConMayorAyuda()
{

	/*1 - Crear un método llamado
		cursosConMayorAyuda que muestre el IDCurso con la mayor cantidad de horas acumuladas en las clases particulares
		(en caso de haber más de uno, mostrar todos los que cumplan dicha condición).
		(25 - Puntos)
		*/
 
	ClasesParticularesArchivo clasePartArch;
	int largoDelArchivo = clasePartArch.getCantidad();
	int vecCursos[10] = {};
	int maximasHoras = 0 ;
	for (int i = 0; i < largoDelArchivo; i++) {

		vecCursos[clasePartArch.leer(i).getIdCurso() -1]+= clasePartArch.leer(i).getDuracion();


	}

	for (int x = 0; x < 10; x++) {

		if (vecCursos[x] > maximasHoras) maximasHoras = vecCursos[x];


	}


	for (int j = 0; j < 10; j++) if (vecCursos[j] == maximasHoras) { cout << "los cursos con mas horas son: " << j + 1 << endl; }



}

void  RecuperatorioPrimerParcial::alumnosConPocaAyuda(){
/*
	2 - Crear un método llamado alumnosConPocaAyuda que 
		muestre el legajo y nombre de los alumnos que nunca tuvieron una clase particular con una duración mayor a 1 hora.
		(25 - Puntos)
ClasesParticularesArchivo clasePartArch;
	EstudiantesArchivo estArch;

	for (int i = 0; i < estArch.getCantidad(); i++) {

	float horasDelAlumno = 0;


		for (int j = 0; j < clasePartArch.getCantidad(); j++) {

			if (estArch.leer(i).getLegajo() == clasePartArch.leer(j).getLegajoAlumno()) {

				horasDelAlumno += clasePartArch.leer(j).getDuracion()  / 60;
			}
		}

		if (horasDelAlumno < 1) { cout << "nombre: " << estArch.leer(i).getNombres() << endl << estArch.leer(i).getLegajo() << endl; }

		este es el que hice en el parcial
	}


}

*/
	EstudiantesArchivo estudianteArch;
	ClasesParticularesArchivo clasePartArch;
	int largoDelArchivoClases = clasePartArch.getCantidad();
	int largoDelArchivoEstudiantes = estudianteArch.getCantidad();

	int t = 0;
	cout << largoDelArchivoEstudiantes;

	for (int i = 0; i < largoDelArchivoEstudiantes; i++) {

		
			
		for (int j = 0; j < largoDelArchivoClases; j++) {

			if (estudianteArch.leer(i).getLegajo() == clasePartArch.leer(j).getLegajoAlumno()) {

				if (clasePartArch.leer(j).getDuracion() >= 60) { cout << "se paso" << t << endl;t++ ; break; }

			}


				if ( largoDelArchivoClases == j-1) { cout << "legajo y nombre: " << estudianteArch.leer(i).getLegajo() << endl << estudianteArch.leer(i).getNombres() << endl; }


		}


	}
    




}


void RecuperatorioPrimerParcial::mostrarEstadisticas() {


	for (int i = 0; i < 10; i++) {

		float recaudac;
		FILE* pFile = fopen("estadisticas.dat", "rb");
		if (pFile == NULL)
		{
			exit(80);
		}
		fseek(pFile, i * sizeof(float), SEEK_SET);
		fread(&recaudac, sizeof(float), 1, pFile);
		
		cout << "curso: " << i+1<< endl;
		cout << recaudac << endl;



		
		fclose(pFile);
	}
}




void RecuperatorioPrimerParcial::generarEstadisticasAyuda()
{

/*3 - Crear un método llamado generarEstadisticasAyuda que guarde en un archivo estadisticas.dat para cada curso el promedio de recaudación(monto).
Crear otro método mostrarEstadisticas que lea el archivo de estadisticas.dat y lo muestre por pantalla.
(25 - Puntos)
*/

	float recaudacion;
	int vecCursoRecaudacion[10] = {};
	ClasesParticularesArchivo clasePartArch;
	int largoDelArchivoClases = clasePartArch.getCantidad();
	

	for (int i = 0; i < largoDelArchivoClases; i++) {

		vecCursoRecaudacion[clasePartArch.leer(i).getIdCurso() - 1] += clasePartArch.leer(i).getMonto();

	}

	
	for (int j = 0; j < 10; j++) {

		recaudacion = vecCursoRecaudacion[j];
		
		FILE* pFile = fopen("estadisticas.dat", "ab");
		if (pFile == NULL)
		{
			exit(90);
		}
			fwrite(&recaudacion, sizeof(float), 1, pFile);
			fclose(pFile);

	}






	}









void RecuperatorioPrimerParcial::nuncaRecibioAyuda()
{

	/*

	ClasesParticularesArchivo clasePartArch;
	EstudiantesArchivo estArch;
	int legajo;



	cout << "ingrese legajo" << endl;

		cin >> legajo;

		for (int i = 0; i < estArch.getCantidad(); i++) {
	int flag = 0;



		for (int j = 0; j < clasePartArch.getCantidad(); j++) {


			if (estArch.leer(i).getLegajo() == clasePartArch.leer(j).getLegajoAlumno()) {


				if (legajo == clasePartArch.leer(j).getLegajoProfesor()) { flag = 1; }

			}






		}


		if (flag == 0) { cout << "legajo de alumno: " << estArch.leer(i).getLegajo() << endl; }


		hecho en el parcial

	}
	4 - Crear un método llamado nuncaRecibioAyuda que reciba el legajo del profesor y muestre todos los legajos de los alumnos a
		los que él no les haya dado nunca clases particulares.
		(25 - Puntos)
		*/



	ClasesParticularesArchivo clasePartArch;
	EstudiantesArchivo estArch;

	int largoDelArchivoEstudiantes = estArch.getCantidad();
	int largoDelArchivoClases = clasePartArch.getCantidad();
	int legajoProfe;
	
	for (int x = 0; x < 10; x++) {
	cout <<"legajos de ejemplo: "<<	clasePartArch.leer(x).getLegajoProfesor() << endl;
	
	
	
	}
	cin >> legajoProfe;
	for (int i = 0; i < largoDelArchivoEstudiantes; i++) 
	
	{
		
		int flag = 1;



		for (int j = 0; j < largoDelArchivoClases; j++) {
		
			if (estArch.leer(i).getLegajo() == clasePartArch.leer(j).getLegajoAlumno() && clasePartArch.leer(j).getLegajoProfesor() == legajoProfe) { flag = 0; }






		}
		
		if (flag == 1) cout << estArch.leer(i).getLegajo() << endl;
	}
}