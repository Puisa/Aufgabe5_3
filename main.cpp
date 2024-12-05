#include "std_lib_inc.h"

class Eintrag
        {
public:
    string name;
    int punkte;

    // Konstruktor zum Initialisieren eines Eintrags
    Eintrag(string n, int p) : name(n), punkte(p) {}
};

int main()
{
    vector<Eintrag> eintraege;  // Vector, um die Einträge zu speichern
    string name;                // Name der Person
    int punkte;                 // Punktzahl der Person

    cout << "Gib eine Liste von Namen und Punktzahlen ein (z.B. 'Barbara 22').\n";
    cout << "Beende die Eingabe mit 'x'.\n";

    // Eingabe von Name und Punktzahl
    while (true)
    {
        cout << "Name: ";
        cin >> name;

        if (name == "x")
        {
            break;
        }

        cout << "Punkte: ";
        cin >> punkte;

        // Überprüfen, ob der Name schon existiert
        for (const auto& eintrag : eintraege)
        {
            if (eintrag.name == name)
            {
                cerr << "Fehler: Der Name '" << name << "' ist bereits vorhanden!\n";
                return 1;  // Beendet das Programm bei doppeltem Namen
            }
        }
        // Neuen Eintrag an den Vector anhängen
        eintraege.push_back(Eintrag(name, punkte));
    }

    cout << "\nGib einen Namen ein, um die Punktzahl zu erfahren. Beende mit 'x'.\n";

    while (true)
    {
        cout << "Name: ";
        cin >> name;

        if (name == "x")
        {
            cout << "Programm beendet.\n";
            break;
        }

        // Suche nach dem Namen und gebe die Punktzahl zurück
        bool gefunden = false;
        for (const auto& eintrag : eintraege)
        {
            if (eintrag.name == name)
            {
                cout << "Punkte von " << name << ": " << eintrag.punkte << "\n";
                gefunden = true;
                break;
            }
        }

        if (!gefunden)
        {
            cout << "Name nicht gefunden. Versuch es erneut.\n";
        }
    }
    return 0;
}
