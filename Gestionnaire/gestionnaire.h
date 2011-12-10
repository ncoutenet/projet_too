#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

class Gestionnaire
{
public:
    Gestionnaire();
    ~Gestionnaire();
    void afficheMenu();
    void ajouter();
    void supprimer();
    void modifier();
    void afficher();
    void exporter();
private:
};

#endif // GESTIONNAIRE_H
