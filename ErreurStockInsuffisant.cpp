#include "ErreurStockInsuffisant.hpp"

ErreurStockInsuffisant::ErreurStockInsuffisant(const std::string& titre, int demandee, int disponible)
    : std::runtime_error("Erreur : Stock insuffisant pour le produit \"" + titre +
        "\". Demandée : " + std::to_string(demandee) +
        ", Disponible : " + std::to_string(disponible)),
    titreProduit(titre),
    quantiteDemandee(demandee),
    quantiteDisponible(disponible) {
}

std::string ErreurStockInsuffisant::getTitreProduit() const {
    return titreProduit;
}

int ErreurStockInsuffisant::getQuantiteDemandee() const {
    return quantiteDemandee;
}

int ErreurStockInsuffisant::getQuantiteDisponible() const {
    return quantiteDisponible;
}