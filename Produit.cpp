#include "Produit.hpp"

Produit::Produit(const std::string& nom, double prix)
    : m_nomProduit(nom), m_prixBase(prix) {
}

Produit::~Produit() {}

std::string Produit::getNomProduit() const {
    return m_nomProduit;
}

double Produit::getPrixBase() const {
    return m_prixBase;
}

// Surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream& os, const Produit& produit) {
    produit.afficherDetailsProduit();
    return os;
}