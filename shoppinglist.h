#include <vector>
#include <string>
#include <algorithm>

class Observer; // Dichiarazione anticipata della classe Observer

// Classe che rappresenta una lista della spesa
class ShoppingList {
private:
    std::vector<Item> items;           // Vettore di oggetti Item
    std::vector<Observer*> observers;  // Vettore di puntatori agli osservatori

public:
    // Metodo per aggiungere un oggetto alla lista
    void addItem(const Item& item) {
        items.push_back(item);
        notifyObservers(); // Notifica gli osservatori dell'aggiornamento
    }

    // Metodo per rimuovere un oggetto dalla lista per nome
    void removeItem(const std::string& itemName) {
        items.erase(std::remove_if(items.begin(), items.end(), & {
            return item.name == = itemName;
        }), items.end());
        notifyObservers(); // Notifica gli osservatori dell'aggiornamento
    }

    // Metodo per ottenere tutti gli oggetti nella lista
    const std::vector<Item>& getItems() const {
        return items;
    }

    // Metodo per aggiungere un osservatore
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    // Metodo per rimuovere un osservatore
    void removeObserver(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    // Metodo per notificare tutti gli osservatori
    void notifyObservers();
};
