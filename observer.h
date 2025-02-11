
#ifndef NONO_LABPROGRAMMAZIONE_OBSERVER_H
#define NONO_LABPROGRAMMAZIONE_OBSERVER_H

// Classe astratta che rappresenta un osservatore
class Observer {
public:
    virtual ~Observer() = default; // Distruttore virtuale

    // Metodo virtuale puro che deve essere implementato dagli osservatori concreti
    virtual void update() = 0;

    // Metodo aggiuntivo per aggiornare l'osservatore
    virtual void aggiorna() {
        // Implementazione del metodo aggiorna
    }
};

#endif //NONO_LABPROGRAMMAZIONE_OBSERVER_H
