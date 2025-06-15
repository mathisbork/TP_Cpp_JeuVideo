#include "Boutique.hpp"
#include "ErreurArgumentInvalide.hpp"
#include "ErreurStockInsuffisant.hpp"
#include <iostream>

int Boutique::totalProduitsVendus = 0;

void Boutique::ajouterJeu(const JeuVideo& jeu) {
    m_jeux.push_back(jeu);
}

void Boutique::ajouterConsole(const Console& console) {
    m_consoles.push_back(console);
}

void Boutique::afficherInventaireComplet() const {
    std::cout << "=== Inventaire Jeux Video ===" << std::endl;
    for (const auto& jeu : m_jeux) {
        std::cout << jeu << std::endl;
    }

    std::cout << "=== Inventaire Consoles ===" << std::endl;
    for (const auto& console : m_consoles) {
        std::cout << console << std::endl;
    }
}

void Boutique::vendreJeu(const std::string& titreJeu, int quantite) {
    for (auto& jeu : m_jeux) {
        if (jeu.getNomProduit() == titreJeu) {
            if (quantite <= 0) throw ErreurArgumentInvalide("Quantite invalide.");
            if (jeu.getStock() < quantite)
                throw ErreurStockInsuffisant(titreJeu, quantite, jeu.getStock());

            jeu.setStock(jeu.getStock() - quantite);
            incrementerTotalVentes(quantite);
            return;
        }
    }
    std::cout << "Jeu \"" << titreJeu << "\" non trouve." << std::endl;
}

void Boutique::vendreConsole(const std::string& nomConsole, int quantite) {
    for (auto& console : m_consoles) {
        if (console.getNomProduit() == nomConsole) {
            if (quantite <= 0) throw ErreurArgumentInvalide("Quantite invalide.");
            if (console.getStock() < quantite)
                throw ErreurStockInsuffisant(nomConsole, quantite, console.getStock());

            console.setStock(console.getStock() - quantite);
            incrementerTotalVentes(quantite);
            return;
        }
    }
    std::cout << "Console \"" << nomConsole << "\" non trouvee." << std::endl;
}

void Boutique::incrementerTotalVentes(int quantite) {
    totalProduitsVendus += quantite;
}

int Boutique::getTotalProduitsVendus() {
    return totalProduitsVendus;
}