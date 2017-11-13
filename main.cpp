
// Tarea # 3
// Curso Introducción a la programación
// Grupo 1
// Permutaciones sin repetición

#include <iostream>
#include <cstring>

#define permswap(a,b,t)  ((t)=(a), (a)=(b), (b)=(t)) // macro para swap

//using namespace std;
using std::cout;
using std::cin;
using std::flush;
using std:: endl;

void encabezado ();
void eliminaDups (char* ptr);
void permutaciones(char *palabra, int posInicio, int posFinal);
unsigned long int factorial(int lenString);



int main(){

	encabezado ();
	char userArray[256];
	int continuar = 1;  // controla el ciclo de repeticiones general
	while(continuar ==1){
		int contPalabra = 1;
		while (contPalabra < 4) {
			cout << "Escriba una palabra: " << flush;
			cin >> userArray;
			while (strlen(userArray) < 2 || strlen(userArray) > 6){
				cout << "Error: cantidad de letras incorrecta" << endl;
				cout <<	"Escriba una palabra de 2 a 6 letras: " << flush;
				cin >> userArray;
			}
			eliminaDups (userArray);
			cout << "La palabra cuenta con " << strlen(userArray) <<  " letras únicas." << endl;
			cout << "A continuación vera las permutaciones sin repetición: " << endl;
			permutaciones(userArray, 0, strlen(userArray)-1);
			cout << "Se han generado " <<factorial(strlen(userArray)) << " permutaciones." << endl;
			cout << endl;
			contPalabra++;
		}
		cout << "Desea generar más palabras? 1-Si , 2-No" << endl;
		cout <<	"Escriba el número de su decisión: " <<  flush;
		cin >> continuar;
	}
	cout << "El programa ha finalizado...." << endl;
	return 0;
}

/// Elimina letras duplicadas
void eliminaDups (char* ptr)
{
	int final = 1;
	int arrayLen = strlen(ptr);
	int actual;
	int i;

	actual = 1;

	for(final=1; final<arrayLen; final++)
	{
		for(i=0; i<final; i++)
		{
			if(ptr[final] == ptr[i])
				break;
		}

		if(i == final)
		{
			ptr[actual] = ptr[i];
			actual++;
		}
	}
	ptr[actual] = 0;
}


/// genera las permutaciones recursivas usando el macro de swap
void permutaciones(char *palabra, int posInicio, int posFinal){
	int i, temp;

	if (posInicio==posFinal){
		for (i=0; i<=posFinal; i++)
			cout << palabra[i];
		cout << endl;

	}
	else {
		for (i=posInicio; i<=posFinal; i++){
			permswap(palabra[posInicio],palabra[i],temp);
			permutaciones(palabra,posInicio+1,posFinal);
			permswap(palabra[posInicio],palabra[i],temp);

		}

	}
}




// calcula el factorial
unsigned long int factorial(int lenString){
	if(lenString <= 1){
		return 1;
	} else {
		return lenString*factorial(lenString-1);
	}
}

// imprime instrucciones del programa
void encabezado (){
	cout << "Bienvenido al generador de palabras de Finca la Loca!!" << endl;
	cout << "*************************************************************" << endl;
	cout << "El programa le pedirá tres palabras de 2 a 6 letras cada una." << endl;
	cout << "Luego generará nuevas palabras sin repetición." << endl;
	cout << "Puede generar nuevas series de palabras las veces que guste." << endl;
	cout << "El programa va a Iniciar......." << endl;
	cout << endl;
}
