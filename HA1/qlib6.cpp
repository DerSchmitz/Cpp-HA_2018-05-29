#include <string.h>
using namespace std;
#include "queue6.h"
#include "string.h"

ClQueue::ClQueue()
{
start=NULL;
end=NULL;
zaehler=0;
}

ClQueue::~ClQueue()
{
struct satom *atom;

while (start!=NULL)
   {
   atom=start;
   delete atom->inhalt;
   start=atom->naechstes;
   delete atom;
   }
}

void ClQueue::push(
char         *zkette)
{


   // cout << "Ich befinde mich in der Push-Methode, ich habe folgende Zeichenkette bekommen: " << hilfesString <<endl ;
  //  cout << "das hintere Ende der Zeichenkette nenne ich " << hilfesString.back()<<endl ;


 //char *hilfeChar = hilfesString.back();
//cout << "das hintere Ende der Zeichenkette nenne ich als Zahl: " << atoi(hilfeChar)<<endl ;




    struct satom *neu;

    neu=new struct satom;
    neu->inhalt=new char[strlen(zkette)+1];


    strcpy(neu->inhalt,zkette);

    //erschaffe neues struct-objekt namens "neu"
                    // setze pointer auf NULL
    neu->naechstes=NULL;

    if (end!=NULL) end->naechstes=neu;

    else start=neu;
    end=neu;
    zaehler++;
}

// pop bedeutet etwas lesen und es anschließend entfernen
char *ClQueue::pop(void)
{
char *wert;
struct satom *atom;

atom=start;
wert=atom->inhalt;
//
start=atom->naechstes;
delete atom;
// wenn aktuelles objekt leer ist,setze ende ebenfalls auf NULL
if (start==NULL) end=NULL;
zaehler--;

return wert;
}

int ClQueue::empty(void)
{
if (start==NULL) return 1;
return 0;
}

int ClQueue::size(void)
{
return zaehler;
}
