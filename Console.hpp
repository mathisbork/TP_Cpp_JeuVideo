#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <string>
#include "ErreurArgumentInvalide.hpp"

class Console {
private:
    std::string m_nomConsole;
    double m_prix;
    int m_stock;

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

    // M�thode publique
    void afficherInfos() const;
};

#endif
