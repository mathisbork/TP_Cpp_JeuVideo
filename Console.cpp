#include "Console.hpp"
#include <iostream>

// Constructeur
Console::Console(const std::string& nomConsole, double prix, int stock)
    : m_nomConsole(nomConsole) {
    setPrix(prix);   // Utilisation des mutateurs pour validation
    setStock(stock);
}

// Accesseurs
std::string Console::getNomConsole() const {
    return m_nomConsole;
}

double Console::getPrix() const {
    return m_prix;
}

int Console::getStock() const {
    return m_stock;
}

// Mutateurs
void Console::setPrix(double nouveauPrix) {
    if (nouveauPrix < 0) {
        throw ErreurArgumentInvalide("Le prix de la console ne peut pas être négatif.");
    }
    m_prix = nouveauPrix;
}

void Console::setStock(int nouveauStock) {
    if (nouveauStock < 0) {
        throw ErreurArgumentInvalide("Le stock de la console ne peut pas être négatif.");
    }
    m_stock = nouveauStock;
}

// Méthode d'affichage
void Console::afficherInfos() const {
    std::cout << "Console : " << m_nomConsole << std::endl;
    std::cout << "Prix    : " << m_prix << " €" << std::endl;
    std::cout << "Stock   : " << m_stock << " exemplaire(s)" << std::endl;
}
