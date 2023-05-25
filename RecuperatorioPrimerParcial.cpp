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
 


	ClaseParticular clasepart;
	ClasesParticularesArchivo clasePartArch;
	int vecCurso[10] = {};
	int maxi = 0;

	for (int i = 0; i < clasePartArch.getCantidad(); i++) {

		vecCurso[clasePartArch.leer(i).getIdCurso() - 1] += (clasePartArch.leer(i).getDuracion());


		
	}

	




	vecCurso[0] = maxi;

	for (int j = 0; j < 10; j++) {


		if (vecCurso[j] >= maxi) {

			maxi = vecCurso[j];

		}


	}



	for (int y = 0; y < 10; y++) {

		if (maxi == vecCurso[y]) { cout << " los cursos son:  " << clasePartArch.leer(y).getIdCurso() + 1 << endl; }
		// me tenia que dar 10 :(

	}

}

void  RecuperatorioPrimerParcial::alumnosConPocaAyuda(){
/*
	2 - Crear un método llamado alumnosConPocaAyuda que 
		muestre el legajo y nombre de los alumnos que nunca tuvieron una clase particular con una duración mayor a 1 hora.
		(25 - Puntos)


*/

	ClasesParticularesArchivo clasePartArch;
	EstudiantesArchivo estArch;

	for (int i = 0; i < estArch.getCantidad(); i++) {
		
	float horasDelAlumno = 0;
		

		for (int j = 0; j < clasePartArch.getCantidad(); j++) {

			if (estArch.leer(i).getLegajo() == clasePartArch.leer(j).getLegajoAlumno()) {

				horasDelAlumno += clasePartArch.leer(j).getDuracion()  / 60;
			}
		}

		if (horasDelAlumno < 1) { cout << "nombre: " << estArch.leer(i).getNombres() << endl << estArch.leer(i).getLegajo() << endl; }


	}


}

void RecuperatorioPrimerParcial::generarEstadisticaAyuda()
{

/*3 - Crear un método llamado generarEstadisticasAyuda que guarde en un archivo estadisticas.dat para cada curso el promedio de recaudación(monto).
Crear otro método mostrarEstadisticas que lea el archivo de estadisticas.dat y lo muestre por pantalla.
(25 - Puntos)
*/









}

void RecuperatorioPrimerParcial::nuncaRecibioAyuda()
{

	/*4 - Crear un método llamado nuncaRecibioAyuda que reciba el legajo del profesor y muestre todos los legajos de los alumnos a
		los que él no les haya dado nunca clases particulares.
		(25 - Puntos)
		*/

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




	}



}