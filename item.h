#pragma once
#include <stdexcept> // Per std::invalid_argument
#include <utility>
#include <string> // Per std::string

class Item {
private:
    std::string name;     // Nome dell'oggetto
    std::string category; // Categoria dell'oggetto
    int quantity;         // Quantità dell'oggetto
    bool comprato;        // Stato dell'oggetto (comprato o no)

public:
    // Costruttore per inizializzare un oggetto Item
    Item(std::string n, std::string c, const int q) : name(std::move(n)), category(std::move(c)), quantity(q), comprato(false) {
        if (q < 0) {
            throw std::invalid_argument("La quantità non può essere negativa");
        }
    }

    // Getter per il nome
    [[nodiscard]] std::string getName() const {
        return name;
    }

    // Getter per la categoria
    [[nodiscard]] std::string getCategory() const {
        return category;
    }

    // Getter per la quantità
    [[nodiscard]] int getQuantity() const {
        return quantity;
    }

    // Getter per lo stato comprato
    [[nodiscard]] bool isComprato() const {
        return comprato;
    }

    // Setter per la quantità, mantiene l'invariante
    void setQuantity(int q) {
        if (q < 0) {
            throw std::invalid_argument("La quantità non può essere negativa");
        }
        quantity = q;
    }

    // Metodo per segnare l'oggetto come comprato
    void setComprato(bool state) {
        comprato = state;
    }
};
