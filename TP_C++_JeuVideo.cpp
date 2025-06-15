#include <iostream>
#include "ErreurArgumentInvalide.hpp"
#include "ErreurStockInsuffisant.hpp"

int main() {
    std::cout << "=== Test des exceptions personnalisées ===\n" << std::endl;

    //Test 1 : Argument invalide (prix négatif)
    try {
        throw ErreurArgumentInvalide("Le prix d'un produit ne peut pas être négatif.");
    }
    catch (const ErreurArgumentInvalide& e) {
        std::cerr << "[Exception attrapée - Argument invalide] : " << e.what() << std::endl;
    }

    std::cout << "\n-----------------------------------\n" << std::endl;

    //Test 2 :stock insuffisant
    try {
        throw ErreurStockInsuffisant("JustCause3", 7, 3);
    }
    catch (const ErreurStockInsuffisant& e) {
        std::cerr << "[Exception attrapée - Stock insuffisant] : " << e.what() << std::endl;
        std::cerr << "Produit concerné : " << e.getTitreProduit() << std::endl;
        std::cerr << "Demandé : " << e.getQuantiteDemandee() << " | Disponible : " << e.getQuantiteDisponible() << std::endl;
    }
    return 0;
}
