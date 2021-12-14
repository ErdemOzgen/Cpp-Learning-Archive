#include <iostream>
#include <utility>
#include <string>
#include <map>

using namespace std;    // not the best in bigger projects | avoid it


class Demonstration {
public:
    enum TYPE {
        starters = 1,
        subs = 2,
        coach = 3,
    };
    typedef map<TYPE, map<int, string>> squadMap; 

    // push a player in the team's squad
    // TYPE::starters or TYPE::subs
    void push(const Demonstration::TYPE &tp, const string &player_name, int position) {
        squad[tp].insert(pair<int, string>(position, player_name));
    }
    // Print team | Starters & Subtitutes
    void print() {
        map<int, string>::iterator coachItr = squad[coach].begin();
        cout << "Coach : \t" << coachItr->second << "\n\n";
        cout << "STARTERS : \n";
        map<int, string>::iterator startersItr = squad[starters].begin();
        map<int, string>::iterator subsItr = squad[subs].begin();
        while(startersItr != squad[starters].end())
        {
            cout << "\t\t" << startersItr->second << endl;
            startersItr++;
        }
        cout << "\nSubtitutes : \n";
        while(subsItr != squad[subs].end())
        {
            cout << "\t\t" << subsItr->second << endl;
            subsItr++;
        }
    }
private:
    squadMap squad;
};


int main()
{
    Demonstration diman;

    diman.push(Demonstration::TYPE(3), "Pedro Martins", 1);

    diman.push(Demonstration::TYPE(1), "Jose Sa", 1);
    diman.push(Demonstration::TYPE(1), "Omar Elabdelaoui", 2);
    diman.push(Demonstration::TYPE(1), "Tsimikas", 3);
    diman.push(Demonstration::TYPE(1), "Meriah", 4);
    diman.push(Demonstration::TYPE(1), "Semedo", 5);
    diman.push(Demonstration::TYPE(1), "Bouhalakis", 6);
    diman.push(Demonstration::TYPE(1), "Guilherme", 7);
    diman.push(Demonstration::TYPE(1), "Valbuena", 8);
    diman.push(Demonstration::TYPE(1), "Fortounis", 9);
    diman.push(Demonstration::TYPE(1), "Podence", 10);
    diman.push(Demonstration::TYPE(1), "El Arabi", 11);

    diman.push(Demonstration::TYPE(2), "Masouras", 1);
    diman.push(Demonstration::TYPE(2), "Bobby Allain", 2);
    diman.push(Demonstration::TYPE(2), "Lazar Randjelovic", 3);
    diman.push(Demonstration::TYPE(2), "Maximiliano Lovera", 4);

    diman.print();

    return 0;
}