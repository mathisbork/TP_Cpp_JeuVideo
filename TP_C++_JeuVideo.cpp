#include <iostream>
#include <vector>
#include <memory>

#include "JeuVideo.hpp"
#include "Console.hpp"
#include "ErreurArgumentInvalide.hpp"
#include "ErreurStockInsuffisant.hpp"
#include "Produit.hpp"

int main() {
    std::vector<Produit*> produits;

    try {
        // Creation d'un jeu video
        Produit* jeu = new JeuVideo("Elden Ring", "RPG", 59.99, 10);
        produits.push_back(jeu);

        // Creation d'une console
        Produit* console = new Console("PlayStation 5", 499.99, 5);
        produits.push_back(console);

        // Affichage de tous les produits (via operator<<)
        std::cout << "=== Liste des produits ===" << std::endl;
        for (Produit* p : produits) {
            std::cout << *p << std::endl;
            std::cout << "---------------------------" << std::endl;
        }

        // Test d'une erreur de stock negatif
        std::cout << "\n=== Test erreur de stock ===" << std::endl;
        console->setStock(-3);

    }
    catch (const ErreurArgumentInvalide& e) {
        std::cerr << "[ErreurArgumentInvalide] : " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "[Autre exception] : " << e.what() << std::endl;
    }

    for (Produit* p : produits) {
        delete p;
    }

    return 0;
}