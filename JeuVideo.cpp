#include "JeuVideo.hpp"
#include <iostream>

// Constructeur
JeuVideo::JeuVideo(const std::string& titre, const std::string& genre, double prix, int stock)
    : m_titre(titre), m_genre(genre) {
    setPrix(prix);
    setStock(stock);
}

// Accesseurs
std::string JeuVideo::getTitre() const {
    return m_titre;
}

std::string JeuVideo::getGenre() const {
    return m_genre;
}

double JeuVideo::getPrix() const {
    return m_prix;
}

int JeuVideo::getStock() const {
    return m_stock;
}

// Mutateurs
void JeuVideo::setPrix(double nouveauPrix) {
    if (nouveauPrix < 0) {
        throw ErreurArgumentInvalide("Le prix ne peut pas être négatif.");
    }
    m_prix = nouveauPrix;
}

void JeuVideo::setStock(int nouveauStock) {
    if (nouveauStock < 0) {
        throw ErreurArgumentInvalide("Le stock ne peut pas être négatif.");
    }
    m_stock = nouveauStock;
}

// Affichage
void JeuVideo::afficherInfos() const {
    std::cout << "Titre : " << m_titre << std::endl;
    std::cout << "Genre : " << m_genre << std::endl;
    std::cout << "Prix  : " << m_prix << " €" << std::endl;
    std::cout << "Stock : " << m_stock << " exemplaire(s)" << std::endl;
}