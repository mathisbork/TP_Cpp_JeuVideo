#include "Console.hpp"
#include <iostream>
#include <iomanip>

Console::Console(const std::string& nom, double prixBase, int stock)
    : Produit(nom, prixBase) {
    setStock(stock); // vérification via mutateur
}

double Console::calculerPrixTTC() const {
    return m_prixBase * 1.20; // TVA 20%, même logique que JeuVideo
}

void Console::afficherDetailsProduit() const {
    std::cout << "Console : " << m_nomProduit << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Prix TTC : " << calculerPrixTTC() << std::endl;
    std::cout << "Stock : " << m_stock << " exemplaire(s)" << std::endl;
}

void Console::setStock(int nouveauStock) {
    if (nouveauStock < 0) {
        throw ErreurArgumentInvalide("Le stock de la console ne peut pas etre negatif.");
    }
    m_stock = nouveauStock;
}

int Console::getStock() const {
    return m_stock;
}
