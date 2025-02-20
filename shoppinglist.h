#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "Subject.h"
#include "Item.h"

class ListaDellaSpesa : public Subject {
public:
    void aggiungiItem(const Item& item) {
        auto it = std::ranges::find_if(items, [&item](const Item& i) {
            return i.getName() == item.getName(); // Usa il getter per il nome
        });
        if (it == items.end()) {
            items.push_back(item);
            notificaOsservatori(); // Notifica gli osservatori dell'aggiornamento
        } else {
            std::cout << "L'oggetto " << item.getName() << " è già presente nella lista." << std::endl; // Usa il getter per il nome
        }
    }

    void rimuoviItem(const std::string& nomeItem) {
        if (items.empty()) {
            std::cout << "La lista è vuota, non ci sono oggetti da rimuovere." << std::endl;
            return;
        }

        auto it = std::ranges::find_if(items, [&nomeItem](const Item& item) {
            return item.getName() == nomeItem; // Usa il getter per il nome
        });

        if (it != items.end()) {
            items.erase(it);
            notificaOsservatori(); // Notifica gli osservatori dell'aggiornamento
        } else {
            std::cout << "L'oggetto " << nomeItem << " non è presente nella lista." << std::endl;
        }
    }

    void impostaItemComeComprato(const std::string& nomeItem) {
        if (items.empty()) {
            std::cout << "La lista è vuota, non ci sono oggetti da marcare come comprati." << std::endl;
            return;
        }

        auto it = std::ranges::find_if(items, [&nomeItem](const Item& item) {
            return item.getName() == nomeItem; // Usa il getter per il nome
        });

        if (it != items.end()) {
            it->setComprato(true); // Usa il setter per lo stato comprato
            notificaOsservatori(); // Notifica gli osservatori dell'aggiornamento
        } else {
            std::cout << "L'oggetto " << nomeItem << " non è presente nella lista." << std::endl;
        }
    }

    [[nodiscard]] int getItemsDaComprare() const {
        return std::count_if(items.begin(), items.end(), [](const Item& item) {
            return !item.isComprato(); // Usa il getter per lo stato comprato
        });
    }

    [[nodiscard]] int getNumeroTotaleItems() const {
        return items.size();
    }

    [[maybe_unused]] Item* cercaItem(const std::string& nomeItem) {
        auto it = std::ranges::find_if(items, [&nomeItem](const Item& item) {
            return item.getName() == nomeItem; // Usa il getter per il nome
        });
        if (it != items.end()) {
            return &(*it);
        } else {
            return nullptr;
        }
    }

    [[maybe_unused]] [[nodiscard]] std::vector<Item> getItemsPerCategoria(const std::string& categoria) const {
        std::vector<Item> itemsCategoria;
        std::ranges::copy_if(items, std::back_inserter(itemsCategoria), [&categoria](const Item& item) {
            return item.getCategory() == categoria; // Usa il getter per la categoria
        });
        return itemsCategoria;
    }

    void getItems() {
        for (const auto& item : items) {
            std::cout << "Nome: " << item.getName() << ", Categoria: " << item.getCategory()
                      << ", Comprato: " << (item.isComprato() ? "Sì" : "No") << std::endl;
        }
    }

private:
    std::vector<Item> items;
};
