#ifndef JEU_VIDEO_HPP
#define JEU_VIDEO_HPP

#include <string>
#include "ErreurArgumentInvalide.hpp"

class JeuVideo {
private:
    std::string m_titre;
    std::string m_genre;
    double m_prix;
    int m_stock;

public:
    // Constructeur
    JeuVideo(const std::string& titre, const std::string& genre, double prix, int stock);

    // Accesseurs
    std::string getTitre() const;
    std::string getGenre() const;
    double getPrix() const;
    int getStock() const;

    // Mutateurs
    void setPrix(double nouveauPrix);
    void setStock(int nouveauStock);

    // Méthode d'affichage
    void afficherInfos() const;
};

#endif