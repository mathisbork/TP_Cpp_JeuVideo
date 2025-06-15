#ifndef ERREUR_ARGUMENT_INVALIDE_HPP
#define ERREUR_ARGUMENT_INVALIDE_HPP

#include <stdexcept>
#include <string>

class ErreurArgumentInvalide : public std::invalid_argument {
public:
    explicit ErreurArgumentInvalide(const std::string& message);
};

#endif