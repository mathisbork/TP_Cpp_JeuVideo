#ifndef PRODUIT_HPP
#define PRODUIT_HPP

#include <string>
#include <iostream>

class Produit {
protected:
    std::string m_nomProduit;
    double m_prixBase;

    Produit(const std::string& nom, double prix);

public:
    virtual ~Produit();

    std::string getNomProduit() const;
    double getPrixBase() const;

    virtual double calculerPrixTTC() const = 0;
    virtual void afficherDetailsProduit() const = 0;
    virtual void setStock(int nouveauStock) = 0;
    virtual int getStock() const = 0;
};

// Surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream& os, const Produit& produit);

#endif