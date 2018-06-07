#include <iostream>
using namespace std;
#include <fstream>
#include "queue6.h"
#include "queue";
#include <vector>
#include <list>
#include <algorithm>
#include "string.h";



int main()
{
ifstream datei;
char puffer[101];
char **array;
int zeilen;
int i;

//erschaffe liste für beliebig viele Strings
list<string> stringListe;
// erschaffe Iterator, mit dem wir auf die Listenelemente zugreifen können
list<string>::iterator pos;

// erschaffe Hilfevariablen
string hilfeString;
string sortierterString;

// öffne Datei
datei.open("koeln.txt");
if (!datei)
   {
   cout << "Die Datei existiert nicht!" << endl;
   return 0;
   }



for (;!datei.eof();)
    {
    // spiele  Zeile für Zeile in den Puffer
    datei.getline(puffer,100,'\n');

    // speichere gelesenen Puffer in hilfsvariable Hilfestring hinein
    hilfeString = puffer;

    // drehe Zeichen im String um:  "Zeile 5=6" wird zu "6=5 elieZ"
    reverse(hilfeString.begin(), hilfeString.end());

    // schiebe den soeben gespeicherten String in die Liste
    stringListe.push_back(hilfeString);

    }

// datei fertig gelesen
datei.close();

// sortiere Liste
stringListe.sort();

// drehe Liste um - Zahlensortierung absteigend statt aufsteigend
reverse(stringListe.begin(), stringListe.end());

// iteriere Listenpositionen durch
for (pos=stringListe.begin(); pos!= stringListe.end(); pos++){

    // spiele Pointer aus Liste in neue Stringvariable
    sortierterString = *pos;

    // // drehe Zeichen im String um:  "6=5 elieZ" wird zu "Zeile 5=6"
    reverse(sortierterString.begin(), sortierterString.end());

    try
       {
                                // schneide String nach dem "="-Zeichen ab
        // gebe restlichen String aus
        cout << sortierterString.erase(  ( sortierterString.find("=")  ) ) << endl;

       }
    catch (out_of_range)
       {
       cout << "Out of Range-Fehler" << endl;
       }


}


{
	        /* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
	        int x;
		        cin >> x;
}
}
