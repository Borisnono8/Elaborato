
//

#ifndef NONO_LABPROGRAMMAZIONE_OBSERVER_H
#define NONO_LABPROGRAMMAZIONE_OBSERVER_H

// Classe astratta che rappresenta un osservatore
class Observer {
public:
    // Metodo virtuale puro che deve essere implementato dagli osservatori concreti
    virtual void update(const ShoppingList& list) = 0;
};

#endif //NONO_LABPROGRAMMAZIONE_OBSERVER_H
