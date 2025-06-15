#include "JeuVideo.hpp"
#include <iostream>
#include <iomanip>

JeuVideo::JeuVideo(const std::string& titre, const std::string& genre, double prixBase, int stock)
    : Produit(titre, prixBase), m_genre(genre) {
    setStock(stock); // validation ici
}

double JeuVideo::calculerPrixTTC() const {
    return m_prixBase * 1.20; // TVA de 20%
}

void JeuVideo::afficherDetailsProduit() const {
    std::cout << "Titre : " << m_nomProduit << std::endl;
    std::cout << "Genre : " << m_genre << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Prix TTC : " << calculerPrixTTC() << std::endl;
    std::cout << "Stock : " << m_stock << " exemplaire(s)" << std::endl;
}

void JeuVideo::setStock(int nouveauStock) {
    if (nouveauStock < 0) {
        throw ErreurArgumentInvalide("Le stock du jeu ne peut pas etre negatif.");
    }
    m_stock = nouveauStock;
}

int JeuVideo::getStock() const {
    return m_stock;
}