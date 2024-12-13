#include <iostream>

template <typename T>
class AlberoBinario {
private:
    T nodi[100];
    bool presenti[100];

public:
    AlberoBinario() {
        for (int i = 0; i < 100; ++i) {
            presenti[i] = false;
        }
    }

    bool alberoVuoto() const {
        return !presenti[0];
    }

    void insRadice(const T& valore) {
        if (presenti[0]) {
            std::cout << "Errore: La radice è già esistente." << std::endl;
            return;
        }
        nodi[0] = valore;
        presenti[0] = true;
    }

    T radice() const {
        if (alberoVuoto()) {
            std::cout << "Errore: L'albero e' vuoto." << std::endl;
            return T();
        }
        return nodi[0];
    }

    bool isFoglia(int indice) const {
        return !presenti[2 * indice + 1] && !presenti[2 * indice + 2];
    }

    void insFiglioSinistro(int indice, const T& valore) {
        int figlio = 2 * indice + 1;
        if (!presenti[indice]) {
            std::cout << "Errore: l'indice del genitore non è valido." << std::endl;
            return;
        }
        if (presenti[figlio]) {
            std::cout << "Errore: il figlio sx è gia' presente." << std::endl;
            return;
        }
        nodi[figlio] = valore;
        presenti[figlio] = true;
    }

    void insFiglioDestro(int indice, const T& valore) {
        int figlio = 2 * indice + 2;
        if (!presenti[indice]) {
            std::cout << "Errore: l'indice del genitore non è valido." << std::endl;
            return;
        }
        if (presenti[figlio]) {
            std::cout << "Errore: il figlio dx è gia' presente." << std::endl;
            return;
        }
        nodi[figlio] = valore;
        presenti[figlio] = true;
    }

    void rimuovi(int indice) {
        if (!presenti[indice]) {
            std::cout << "Errore: l'indice non è valido." << std::endl;
            return;
        }
        if (!isFoglia(indice)) {
            std::cout << "Errore: Il nodo non è una foglia." << std::endl;
            return;
        }
        presenti[indice] = false;
    }

    void stampa() const {
        for (int i = 0; i < 100; ++i) {
            if (presenti[i]) {
                std::cout << "Pos " << i << ", Valore: " << nodi[i]
                          << ", Figliosx: " << (presenti[2 * i + 1] ? std::to_string(nodi[2 * i + 1]) : "Nessuno")
                          << ", Figliodx: " << (presenti[2 * i + 2] ? std::to_string(nodi[2 * i + 2]) : "Nessuno")
                          << std::endl;
            }
        }
    }
};
