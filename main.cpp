#include <iostream>
using namespace std;
int main() {
    srand(time(0));
    int i, n, j, t, x, inizio, medio, fine, indice, c, y, d;
    bool scambio;
    cout << "inserisci la dimensione del vettore" << endl;
    cin >> n;
    int v[n];
    for (i = 0; i <= n - 1; i++) {
        v[i] = rand() % 101;
    }
    scambio = true;
    i = 0;
    while (i <= n - 1 && scambio) {
        scambio = false;
        j = 0;
        while (j <= n - 2 - i) {
            if (v[j] > v[j + 1]) {
                t = v[j];
                v[j] = v[j + 1];
                v[j + 1] = t;
                scambio = true;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    for (i = 0; i <= n - 1; i++) {
        cout << v[i] << endl;
    }
    cout << "inserisci un numero presente nel vettore" << endl;
    cin >> x;
    inizio = 0;
    fine = n - 1;
    indice = (int) (-1);
    c = 0;
    while (indice == -1) {
        medio = (int) (inizio + (double) (fine - inizio) / 2);
        if (v[medio] == x) {
            indice = medio;
        } else {
            if (v[medio] > x) {
                fine = medio - 1;
            } else {
                inizio = medio + 1;
            }
        }
        c = c + 1;
    }
    cout << "il valore cercato si trova nella cella " << indice << " e abbiamo impiegato " << c << " passaggi per la ricerca binaria" << endl;
    indice = (int) (-1);
    i = 0;
    d = 0;
    while (i <= n - 1 && indice == -1) {
        d = d + 1;
        if (v[i] == x) {
            indice = i;
        }
        i = i + 1;
    }
    if (indice == -1) {
        cout << "valore non trovato" << endl;
    } else {
        cout << "il valore si trova nella cella " << indice << " e sono stati impiegati " << d << " passaggi per la ricerca sequenziale" << endl;
    }
}