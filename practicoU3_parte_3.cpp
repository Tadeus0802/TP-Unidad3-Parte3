#include <iostream>
#include <fstream>
#define ESPACIO cout << endl;
#define CLEAR system("cls");

using namespace std;

ofstream crearArchivo;
ifstream leerArchivo;

void PuntoA();
void PuntoB();
void PuntoC();
void PuntoD();

int main()
{
    PuntoA();
    PuntoB();
    PuntoC();
    PuntoD();

    return 0;
}

void PuntoA()
{
    /*
        a. Crea un programa que vaya leyendo las frases que el usuario teclea y las guarde en un fichero de texto llamado “frasesDeBjarme.txt”. Terminará cuando la frase introducida sea &quot;fin&quot; (esa frase no deberá guardarse en el fichero).
    */
    CLEAR
    string frases;

    crearArchivo.open("frasesDeBjarme.txt");

    if (crearArchivo.is_open())
    {
        while (frases != "&quot;fin&quot;")
        {
            crearArchivo << frases;
            crearArchivo << endl;

            cout << "Ingrese alguna frase ";
            getline(cin, frases);
            ESPACIO
        }
    }
    crearArchivo.close();
}

void PuntoB()
{
    // b. Para el ejercicio anterior, Abrir el archivo y mostrar las frases x pantalla, con cada frase en una línea, con Interlineado.
    CLEAR
    string frases;

    leerArchivo.open("frasesDeBjarme.txt", ios::in);
    if (leerArchivo.is_open())
    {
        while (!leerArchivo.eof())
        {
            getline(leerArchivo, frases);

            cout << frases;
            ESPACIO
        }
    }
    else
    {
        cout << "No se pudo abrir el archvio";
        exit(1);
    }
    leerArchivo.close();
}

void PuntoC()
{
    // c. Para el Archivo del ejercicio (a) contar la cantidad de palabras que hay x línea, luego mostrar la cantidad total y el promedio de palabras x línea.
    CLEAR
    string text;
    int aux = 0;
    double cantidadDePalabras = 0, resultado = 0;

    leerArchivo.open("frasesDeBjarme.txt", ios::in);

    if (leerArchivo.is_open())
    {
        while (!leerArchivo.eof())
        {
            leerArchivo >> text;
  
            cantidadDePalabras += text.length();
            aux++;  
            // cout<<text.length()<<" ";
            // ESPACIO
            // cout<<text;
            // ESPACIO   
        }
        resultado = cantidadDePalabras / aux;
        cout<<"La cantidad total de palabras que hay en l linea es de: "<<cantidadDePalabras;
        ESPACIO
        cout<<"El promedio es de: "<<resultado;
    }
    else
    {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
}

void PuntoD()
{
    // d. Para el archivo de “frasesDeBjarme.txt” indicar cuál es la palabra más Larga.
    CLEAR
    string text, aux;
    
    leerArchivo.open("frasesDeBjarme.txt", ios::in);

    if (leerArchivo.is_open())
    {
        while (!leerArchivo.eof())
        {
            leerArchivo >> text;
            if(text.length() > aux.length()){
                aux = text;
            }
        }
        cout<<"La palabra mas larga es: "<<aux;
    }
    else
    {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
}
