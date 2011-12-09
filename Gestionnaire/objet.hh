#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class Objet{
public:
  Objet();
  ~Objet();
  void ajouter();
  void supprimer();
  void modifier();

  void exporter();
private:
  std::vector<std::string> _donnes;
};
