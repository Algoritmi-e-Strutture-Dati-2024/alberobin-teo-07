int main() {
    AlberoBinario<int> albero;

    // Creo l'albero con la radice
    albero.insRadice(10);

    // Inserisco i figli
    albero.insFiglioSinistro(0, 5);
    albero.insFiglioDestro(0, 15);
    albero.insFiglioSinistro(1, 3);
    albero.insFiglioDestro(1, 7);

    // Stampo la struttura dell'albero
    albero.stampa();

    // Rimuovo un nodo
    albero.rimuovi(4); // Nodo 7 perchè è foglia

    // Stampo di nuovo la struttura dell'albero
    albero.stampa();

    return 0;
}
