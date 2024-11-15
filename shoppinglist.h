#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

class Osservatore; // Dichiarazione anticipata della classe Osservatore

// Classe che rappresenta un articolo nella lista della spesa
class Item {
public:
    std::string nome;
    int quantita;
    bool comprato;

    Item(const std::string& nome, int quantita) : nome(nome), quantita(quantita), comprato(false) {
        if (quantita < 0) {
            throw std::invalid_argument("La quantità non può essere negativa");
        }
    }
};

// Classe che rappresenta una lista della spesa
class ListaDellaSpesa {
protected:
    std::vector<Item> items;           // Vettore di oggetti Item
    std::vector<Osservatore*> osservatori;    // Vettore di puntatori agli osservatori

public:
    // Metodo per aggiungere un articolo alla lista
    void aggiungiItem(const Item& item) {
        items.push_back(item);
        notificaOsservatori(); // Notifica gli osservatori dell'aggiornamento
    }

    // Metodo per rimuovere un articolo dalla lista per nome
    void rimuoviItem(const std::string& nomeItem) {
        items.erase(std::remove_if(items.begin(), items.end(), & {
            return item.nome == nomeItem;
        }), items.end());
        notificaOsservatori(); // Notifica gli osservatori dell'aggiornamento
    }

    // Metodo per impostare un articolo come comprato
    void impostaItemComeComprato(const std::string& nomeItem) {
        for (auto& item : items) {
            if (item.nome == nomeItem) {
                item.comprato = true;
                notificaOsservatori(); // Notifica gli osservatori dell'aggiornamento
                return;
            }
        }
    }

    // Metodo per ottenere il numero di articoli ancora da comprare
    int getItemsDaComprare() const {
        return std::count_if(items.begin(), items.end(),  {
            return !item.comprato;
        });
    }

    // Metodo per ottenere il numero totale di articoli nella lista
    int getNumeroTotaleItems() const {
        return items.size();
    }

    // Metodo per aggiungere un osservatore
    void aggiungiOsservatore(Osservatore* osservatore) {
        osservatori.push_back(osservatore);
    }

    // Metodo per rimuovere un osservatore
    void rimuoviOsservatore(Osservatore* osservatore) {
        osservatori.erase(std::remove(osservatori.begin(), osservatori.end(), osservatore), osservatori.end());
    }

    // Metodo per notificare tutti gli osservatori
    void notificaOsservatori() {
        for (auto* osservatore : osservatori) {
            osservatore->aggiorna();
        }
    }
};
