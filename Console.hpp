#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <string>
#include "ErreurArgumentInvalide.hpp"

class Console {
private:
    std::string nomConsole;
    double prix;
    int stock;

public:
    // Constructeur
    Console(const std::string& nomConsole, double prix, int stock);

    // Accesseurs
    std::string getNomConsole() const;
    double getPrix() const;
    int getStock() const;

    // Mutateurs
    void setPrix(double nouveauPrix);
    void setStock(int nouveauStock);

    // Méthode publique
    void afficherInfos() const;
};

#endif
