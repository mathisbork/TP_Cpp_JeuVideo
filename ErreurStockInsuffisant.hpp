#ifndef ERREUR_STOCK_INSUFFISANT_HPP
#define ERREUR_STOCK_INSUFFISANT_HPP

#include <stdexcept>
#include <string>

class ErreurStockInsuffisant : public std::runtime_error {
private:
    std::string m_titreProduit;
    int m_quantiteDemandee;
    int m_quantiteDisponible;

public:
    ErreurStockInsuffisant(const std::string& titre, int demandee, int disponible);

    std::string getTitreProduit() const;
    int getQuantiteDemandee() const;
    int getQuantiteDisponible() const;
};

#endif
