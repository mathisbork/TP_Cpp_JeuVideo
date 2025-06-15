#include "ErreurStockInsuffisant.hpp"

ErreurStockInsuffisant::ErreurStockInsuffisant(const std::string& titre, int demandee, int disponible)
    : std::runtime_error("Erreur : Stock insuffisant pour le produit \"" + titre +
        "\". Demandée : " + std::to_string(demandee) +
        ", Disponible : " + std::to_string(disponible)),
    m_titreProduit(titre),
    m_quantiteDemandee(demandee),
    m_quantiteDisponible(disponible) {
}

std::string ErreurStockInsuffisant::getTitreProduit() const {
    return m_titreProduit;
}

int ErreurStockInsuffisant::getQuantiteDemandee() const {
    return m_quantiteDemandee;
}

int ErreurStockInsuffisant::getQuantiteDisponible() const {
    return m_quantiteDisponible;
}