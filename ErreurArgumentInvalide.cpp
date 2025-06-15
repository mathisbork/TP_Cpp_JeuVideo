#include "ErreurArgumentInvalide.hpp"

ErreurArgumentInvalide::ErreurArgumentInvalide(const std::string& message)
    : std::invalid_argument("Erreur d'argument invalide : " + message) {}
