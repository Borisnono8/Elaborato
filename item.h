
#pragma once
#include <stdexcept> // Per std::invalid_argument
#include <utility>

class Item {
public:
    std::string name;     // Nome dell'oggetto
    std::string category; // Categoria dell'oggetto
    int quantity;         // Quantità dell'oggetto
    bool comprato;        // Stato dell'oggetto (comprato o no)

    // Costruttore per inizializzare un oggetto Item
    Item(std::string n, std::string c, const int q) : name(std::move(n)), category(std::move(c)), quantity(q), comprato(false) {
        if (q < 0) {
            throw std::invalid_argument("La quantità non può essere negativa");
        }
    }
};

