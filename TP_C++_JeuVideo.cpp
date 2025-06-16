#include <iostream>
#include "Boutique.hpp"
#include "ErreurArgumentInvalide.hpp"
#include "ErreurStockInsuffisant.hpp"

int main() {
    Boutique boutique;

    std::cout << "=== TEST BOUTIQUE ===\n" << std::endl;

    // Test de creation avec arguments invalides
    try {
        JeuVideo jeuInvalide("Bug Game", "FPS", -10.0, -3);
    }
    catch (const ErreurArgumentInvalide& e) {
        std::cerr << "[Exception - creation invalide] : " << e.what() << std::endl;
    }

    try {
        Console consoleInvalide("ConsoleX", -200.0, -5);
    }
    catch (const ErreurArgumentInvalide& e) {
        std::cerr << "[Exception - creation invalide] : " << e.what() << std::endl;
    }

    // Ajout de produits valides
    JeuVideo jeu1("Zelda", "Aventure", 49.99, 5);
    JeuVideo jeu2("Mario Kart", "Course", 59.99, 8);
    Console console1("Switch", 299.99, 3);
    Console console2("Xbox Series X", 499.99, 2);

    boutique.ajouterJeu(jeu1);
    boutique.ajouterJeu(jeu2);
    boutique.ajouterConsole(console1);
    boutique.ajouterConsole(console2);

    // Affichage initial
    std::cout << "\n--- Inventaire initial ---" << std::endl;
    boutique.afficherInventaireComplet();

    // Test des mutateurs invalides
    try {
        jeu1.setStock(-1);
    }
    catch (const ErreurArgumentInvalide& e) {
        std::cerr << "[Exception - setStock] : " << e.what() << std::endl;
    }

    try {
        console1.setStock(-10);
    }
    catch (const ErreurArgumentInvalide& e) {
        std::cerr << "[Exception - setStock] : " << e.what() << std::endl;
    }

    // Ventes valides
    try {
        boutique.vendreJeu("Zelda", 2);
        boutique.vendreConsole("Switch", 1);
    }
    catch (const std::exception& e) {
        std::cerr << "[Exception inattendue] : " << e.what() << std::endl;
    }

    // Ventes invalides
    try {
        boutique.vendreJeu("Mario Kart", 100); // Trop de quantite
    }
    catch (const ErreurStockInsuffisant& e) {
        std::cerr << "[ErreurStockInsuffisant] : " << e.what() << std::endl;
        std::cerr << "Produit : " << e.getTitreProduit()
            << " | Demande : " << e.getQuantiteDemandee() << std::endl;
    }

    try {
        boutique.vendreConsole("PS5", 1); // Produit inexistant
    }
    catch (const std::exception& e) {
        std::cerr << "[Exception - produit introuvable] : " << e.what() << std::endl;
    }

    // Affichage final
    std::cout << "\n--- Inventaire apres ventes ---" << std::endl;
    boutique.afficherInventaireComplet();

    // Affichage total produits vendus
    std::cout << "\nTotal de produits vendus : "
        << Boutique::getTotalProduitsVendus() << std::endl;

    // Accesseurs et mutateurs sur objets
    std::cout << "\n--- Accesseurs / Mutateurs manuels ---" << std::endl;
    std::cout << "Nom console 1 : " << console1.getNomProduit() << std::endl;
    std::cout << "Stock console 1 : " << console1.getStock() << std::endl;

    console1.setStock(10);
    std::cout << "Stock console 1 apres modif : " << console1.getStock() << std::endl;

    return 0;
}