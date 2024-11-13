// Classe che rappresenta un utente che osserva una lista della spesa
class User : public Observer {
private:
    std::string name; // Nome dell'utente

public:
    // Costruttore per inizializzare un utente con un nome
    User(std::string n) : name(n) {}

    // Implementazione del metodo update per ricevere aggiornamenti dalla lista
    void update(const ShoppingList& list) override {
        std::cout << "Aggiornamento per " << name << ": " << std::endl;
        for (const auto& item : list.getItems()) {
            std::cout << "- " << item.name << " (" << item.category << "): " << item.quantity << std::endl;
        }
    }
};
