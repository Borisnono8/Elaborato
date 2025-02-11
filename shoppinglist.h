
  #pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "Subject.h"
class ListaDellaSpesa: public Subject {
public:
    void aggiungiItem(const Item& item) {
        auto it = std::find_if(items.begin(), items.end(), [&item](const Item& i) {
            return i.name == item.name;
        });

        if (it == items.end()) {
            items.push_back(item);
            notificaOsservatori(); // Notifica gli osservatori dell'aggiornamento
        } else {
            std::cout << "L'oggetto " << item.name << " è già presente nella lista." << std::endl;
        }
    }

    void rimuoviItem(const std::string& nomeItem) {
        std::erase_if(items, [&nomeItem](const Item& item) {
            return item.name == nomeItem;
        });
        notificaOsservatori(); // Notifica gli osservatori dell'aggiornamento
    }

    void impostaItemComeComprato(const std::string& nomeItem) {
        for (auto& item : items) {
            if (item.name == nomeItem) {
                item.comprato = true;
                notificaOsservatori(); // Notifica gli osservatori dell'aggiornamento
                return;
            }
        }
    }

    [[nodiscard]] int getItemsDaComprare() const {
        return std::count_if(items.begin(), items.end(), [](const Item& item) {
            return !item.comprato;
        });
    }

    [[nodiscard]] int getNumeroTotaleItems() const {
        return items.size();
    }

    [[maybe_unused]] Item* cercaItem(const std::string& nomeItem) {
        auto it = std::ranges::find_if(items, [&nomeItem](const Item& item) {
            return item.name == nomeItem;
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
            return item.category == categoria;
        });
        return itemsCategoria;
    }

    void getItems();

private:
    std::vector<Item> items;
};

   
