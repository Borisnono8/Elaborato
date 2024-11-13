// Created by boris nono il 25/02/2024

#ifndef NONO_LABPROGRAMMAZIONE_ITEM_H
#define NONO_LABPROGRAMMAZIONE_ITEM

// Classe che rappresenta un oggetto nella lista della spesa
class Item {
public:
    std::string name;     // Nome dell'oggetto
    std::string category; // Categoria dell'oggetto
    int quantity;         // Quantità dell'oggetto

    // Costruttore per inizializzare un oggetto Item
    Item(std::string n, std::string c, int q) : name(n), category(c), quantity(q) {}
};
_
#endif //NONO_LABPROGRAMMAZIONE_ITEM_H
