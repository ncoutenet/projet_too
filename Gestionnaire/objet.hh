#include <string>
#include <vector>

class Objet{
public:
  Objet();
  ~Objet();
  void ajouter();
  void supprimer();
  void modifier();

  void export();
private:
  vector<string> _donnes;
};
