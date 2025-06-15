#ifndef BOUTIQUE_HPP
#define BOUTIQUE_HPP

#include <vector>
#include <string>
#include "JeuVideo.hpp"
#include "Console.hpp"

class Boutique {
private:
    std::vector<JeuVideo> m_jeux;
    std::vector<Console> m_consoles;
    static int totalProduitsVendus;

public:
    void ajouterJeu(const JeuVideo& jeu);
    void ajouterConsole(const Console& console);

    void afficherInventaireComplet() const;

    void vendreJeu(const std::string& titreJeu, int quantite);
    void vendreConsole(const std::string& nomConsole, int quantite);

    static void incrementerTotalVentes(int quantite);
    static int getTotalProduitsVendus();
};

#endif