
#pragma once

#include <string>
#include "User.h"
#include <iostream>
#include "Observer.h"
#include "Shoppinglist.h" // Assicurati di includere il file di intestazione corretto

class User : public Observer {
private:
    std::string nome; // Nome dell'utente
    ListaDellaSpesa* lista; // Puntatore alla lista della spesa osservata

public:
    // Costruttore per inizializzare un utente con un nome
    explicit User(std::string n) : nome(std::move(n)), lista(nullptr) {}

    // Metodo per abbonarsi a una lista della spesa
    void subscribeToList(ListaDellaSpesa* l) {
        if (lista) {
            unsubscribeFromList(); // Disiscriversi dalla lista precedente, se esiste
        }
        lista = l;
        lista->aggiungiOsservatore(this); // Abbonamento alla nuova lista
    }

    // Metodo per disiscriversi dalla lista della spesa
    void unsubscribeFromList() {
        if (lista) {
            lista->rimuoviOsservatore(this); // Disiscrizione dalla lista
            lista = nullptr;
        }
    }

    // Distruttore virtuale per disiscriversi dalla lista
    ~User() override {
        unsubscribeFromList(); // Disiscrizione dalla lista
    }

    // Metodo per ottenere il nome dell'utente
    [[nodiscard]] virtual std::string getNome() const {
        return nome;
    }

    // Metodo per ottenere la lista della spesa
    [[nodiscard]] virtual ListaDellaSpesa* getLista() const {
        return lista;
    }
};

