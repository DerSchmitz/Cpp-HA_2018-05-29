#include <iostream>
using namespace std;

struct satom
    {
    char *inhalt;
    struct satom *naechstes;
    } ;

class ClQueue 
    {
private:
    struct satom *start;
    struct satom *end;
    int zaehler;
public:
    ClQueue();
    ~ClQueue();
    void push(char *zkette);
    char *pop(void);
    int empty();
    int size();
    } ;
