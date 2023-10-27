#include <iostream>
#include <iomanip>
using namespace std;

void  llenarDatos(int ** matriz, int filas, int col);
void  imprimir(int ** matriz, int filas, int col);
int ** dimensionarMatriz(int filas, int col);
void intercambiarFilas(int **matriz, int filas,int col);

int main()
{ int filas, col;

  srand(time(nullptr));
  cout << "Filas: ";
  cin >> filas;
  cout << "Columnas : ";
  cin >> col;

  int **matriz= dimensionarMatriz(filas,col);

  llenarDatos(matriz, filas, col);
  imprimir(matriz, filas, col);
  cout <<"\n\n";
  cout << "Luego de Intercambiar Filas\n\n";
  intercambiarFilas(matriz,filas,col);
  imprimir(matriz, filas, col);
  //--- se libera la memoria
  for(int f=0; f<filas; f++)
    delete []matriz[f];
  delete []matriz;
  matriz= nullptr;

  return 0;
}

void intercambiarFilas(int **matriz, int filas,int col)
{
  int medio = filas/2;
  int aux, filaFinal;

  filaFinal=filas-1;
  for(int f=0; f<medio; f++)
  {
    for(int c=0; c<col; c++)
    {
      aux = matriz[f][c];
      matriz[f][c] = matriz[filaFinal][c];
      matriz[filaFinal][c]=aux;
    }
    filaFinal--;
  }
}



int ** dimensionarMatriz(int filas, int col)
{ int ** matriz = nullptr;
  matriz = new int*[filas];
  for(int f=0; f<filas; f++)
    matriz[f] = new int[col];
  return matriz;
}

void llenarDatos(int ** matriz, int filas, int col)
{
  for(int f=0; f<filas; f++)
    for(int c=0; c<col; c++)
      matriz[f][c] = rand() % 100;
}

void  imprimir(int ** matriz, int filas, int col)
{
  for(int f=0; f<filas; f++)
  {
    for(int c=0; c<col; c++)
      cout << setw(5) << matriz[f][c];
    cout << "\n";
  }
}

