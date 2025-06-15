#ifndef JEUVIDEO_HPP
#define JEUVIDEO_HPP

#include "Produit.hpp"
#include "ErreurArgumentInvalide.hpp"

#include <string>

class JeuVideo : public Produit {
private:
    std::string m_genre;
    int m_stock;

public:
    JeuVideo(const std::string& titre, const std::string& genre, double prixBase, int stock);

    double calculerPrixTTC() const override;
    void afficherDetailsProduit() const override;
    void setStock(int nouveauStock) override;
    int getStock() const override;
};

#endif