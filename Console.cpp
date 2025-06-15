#include "Console.hpp"
#include <iostream>

// Constructeur
Console::Console(const std::string& nomConsole, double prix, int stock)
    : nomConsole(nomConsole) {
    setPrix(prix);   // Utilisation des mutateurs pour validation
    setStock(stock);
}

// Accesseurs
std::string Console::getNomConsole() const {
    return nomConsole;
}

double Console::getPrix() const {
    return prix;
}

int Console::getStock() const {
    return stock;
}

// Mutateurs
void Console::setPrix(double nouveauPrix) {
    if (nouveauPrix < 0) {
        throw ErreurArgumentInvalide("Le prix de la console ne peut pas �tre n�gatif.");
    }
    prix = nouveauPrix;
}

void Console::setStock(int nouveauStock) {
    if (nouveauStock < 0) {
        throw ErreurArgumentInvalide("Le stock de la console ne peut pas �tre n�gatif.");
    }
    stock = nouveauStock;
}

// M�thode d'affichage
void Console::afficherInfos() const {
    std::cout << "Console : " << nomConsole << std::endl;
    std::cout << "Prix    : " << prix << " �" << std::endl;
    std::cout << "Stock   : " << stock << " exemplaire(s)" << std::endl;
}
