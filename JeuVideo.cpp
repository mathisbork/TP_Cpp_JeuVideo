#include "JeuVideo.hpp"
#include <iostream>

// Constructeur
JeuVideo::JeuVideo(const std::string& titre, const std::string& genre, double prix, int stock)
    : titre(titre), genre(genre) {
    setPrix(prix);
    setStock(stock);
}

// Accesseurs
std::string JeuVideo::getTitre() const {
    return titre;
}

std::string JeuVideo::getGenre() const {
    return genre;
}

double JeuVideo::getPrix() const {
    return prix;
}

int JeuVideo::getStock() const {
    return stock;
}

// Mutateurs
void JeuVideo::setPrix(double nouveauPrix) {
    if (nouveauPrix < 0) {
        throw ErreurArgumentInvalide("Le prix ne peut pas être négatif.");
    }
    prix = nouveauPrix;
}

void JeuVideo::setStock(int nouveauStock) {
    if (nouveauStock < 0) {
        throw ErreurArgumentInvalide("Le stock ne peut pas être négatif.");
    }
    stock = nouveauStock;
}

// Affichage
void JeuVideo::afficherInfos() const {
    std::cout << "Titre : " << titre << std::endl;
    std::cout << "Genre : " << genre << std::endl;
    std::cout << "Prix  : " << prix << " €" << std::endl;
    std::cout << "Stock : " << stock << " exemplaire(s)" << std::endl;
}