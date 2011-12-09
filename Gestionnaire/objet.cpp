#include "objet.hh"

Objet::Objet()
{

}

Objet::~Objet()
{

}

void Objet::ajouter()
{
    std::string name, file;

    std::cout<<"Ajout d'un element:"<<std::endl;
    std::cout<<"Veuillez entrer le nom de l'element:";
    std::cin>>name;
    std::cout<<std::endl;

    file = "../Elements/";
    file += name;
    file += ".txt";

    std::ofstream Ajout(file.c_str());
    if (Ajout)
    {
        Ajout << name  <<std::endl;
    }
}

void Objet::supprimer()
{
    std::string name, file;

    std::cout<<"Suppression d'un element:"<<std::endl;
    std::cout<<"Veuillez entrer le nom de l'element:";
    std::cin>>name;
    std::cout<<std::endl;

    file = " rm ../Elements/";
    file += name;
    file += ".txt";

    system(file.c_str());
}

void Objet::modifier()
{
    std::string name, file, file2;

    std::cout<<"Modification d'un element:"<<std::endl;
    std::cout<<"Veuillez entrer le nom de l'element a modifier:";
    std::cin>>name;
    std::cout<<std::endl;

    file = " rm ../Elements/";
    file += name;
    file += ".txt";

    std::cout<<"Veuillez entrer le nom du nouveau element:";
    std::cin>>name;
    std::cout<<std::endl;

    file2 = "../Elements/";
    file2 += name;
    file2 += ".txt";

    system(file.c_str());
    std::ofstream Ajout(file2.c_str());
    if (Ajout)
    {
        Ajout << name  <<std::endl;
    }
}

void Objet::afficher()
{    
    std::string name, file, ligne;

    std::cout<<"Affichage d'un element:"<<std::endl;
    std::cout<<"Veuillez entrer le nom de l'element:";
    std::cin>>name;
    std::cout<<std::endl;

    file = "../Elements/";
    file += name;
    file += ".txt";

    std::ifstream Affiche(file.c_str());
    if(Affiche)
    {
        while(getline(Affiche, ligne))    //Tant qu'on n'est pas a la fin, on lit
        {
            std::cout<<ligne<<std::endl;
        }

    }
    else
    {
        std::cout<<"ERREUR: Impossible d'ouvrir le fichier en lecture."<<std::endl;
    }

}

void Objet::exporter()
{
    std::string name, file, ligne, page;

    std::cout<<"Export d'un element en html:"<<std::endl;
    std::cout<<"Veuillez entrer le nom de l'element:";
    std::cin>>name;
    std::cout<<std::endl;

    file = "../Elements/";
    file += name;
    file += ".txt";

    page = "../Pages/";
    page += name;
    page += ".html";

    std::ifstream Expor(file.c_str());
    if(Expor)
    {
        std::ofstream Ajout(page.c_str());
        if (Ajout)
        {
            Ajout << "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"" <<std::endl;
            Ajout << "    \"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">" <<std::endl;
            Ajout << "<html xmlns=\"http://www.w3.org/1999/xhtml\" xml:lang=\"fr\">" <<std::endl;
            Ajout << "<head>" <<std::endl;
            Ajout << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\" />" <<std::endl;
            Ajout << "<meta name=\"description\" content=\"Objet\" />" <<std::endl;
            Ajout << "<meta name=\"keywords\" content=\"xhtml,internet,too\" />" <<std::endl;
            Ajout << "<meta name=\"author\" content=\"none\" />" <<std::endl;
            Ajout << "<title>Objet</title>" <<std::endl;
            Ajout << "</head>" <<std::endl;
            Ajout << "<body>" <<std::endl;
            while(getline(Expor, ligne))
            {
                Ajout << ligne <<std::endl;
            }
            Ajout << "</body>" <<std::endl;
            Ajout << "</html>" <<std::endl;
        }
    }
    else
    {
        std::cout<<"ERREUR: Impossible d'ouvrir le fichier en lecture."<<std::endl;
    }
}
