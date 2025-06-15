#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include "Produit.hpp"
#include "ErreurArgumentInvalide.hpp"
#include <string>

class Console : public Produit {
private:
    int m_stock;

public:
    Console(const std::string& nom, double prixBase, int stock);

    double calculerPrixTTC() const override;
    void afficherDetailsProduit() const override;
    void setStock(int nouveauStock) override;
    int getStock() const override;
};

#endif