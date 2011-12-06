class Menu{
public:
  Menu();
  ~Menu();
  void affiche();
private:
  int _choix;
};

void Menu::affiche()
{
  do{
    std::cout<<"--------------------------------------------"<<std::endl;
    std::cout<<"-                  MENU                    -"<<std::endl;
    std::cout<<"--------------------------------------------"<<std::endl;
    std::cout<<"-1)Afficher les documents                  -"<<std::endl;
    std::cout<<"-2)Ajouter un document                     -"<<std::endl;
    std::cout<<"-3)Supprimer un document                   -"<<std::endl;
    std::cout<<"-4)Trier la liste des documents            -"<<std::endl;
    std::cout<<"-5)Rechercher un document                  -"<<std::endl;
    std::cout<<"-6)exporter la liste en version html       -"<<std::endl;
    std::cout<<"-0)Quitter                                 -"<<std::endl;
    std::cout<<"--------------------------------------------"<<std::endl;
    std::cout<<"Votre choix : ";
    std::cin>>_choix;
  }while (choix != 0)
}
