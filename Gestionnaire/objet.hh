#include <string>
#include <vector>

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
