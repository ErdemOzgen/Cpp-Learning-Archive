#include <iostream>
#include <new>
#include <typeinfo>
#include <vector>

using namespace std;

/****************************************************************
 * Exceptions
 ****************************************************************/
class RuntimeException {
private:
  string errorMsg;
public:
  RuntimeException(const string& err) { errorMsg = err; }
  string getMessage() const { return errorMsg; }
};

class IndexOutOfBounds : public RuntimeException {
public:
  IndexOutOfBounds(const string& err = "Index out of bounds!")
    : RuntimeException(err) {}
};

/****************************************************************
 * Game Entries
 *
 ****************************************************************/
// Game entry data structure:
class GameEntry {		// Stores the game scores
public:
  GameEntry(const string& n = "", int s = 0); // Constructor
  string getName() const;		      // Get player name
  int getScore() const;			      // Get player score
private:
  string name;			// Player's name
  int score;			// Player's score
};
// Definitions for Game entry
GameEntry::GameEntry(const string& n, int s)
  : name(n), score(s) {}
string GameEntry::getName() const { return name; }
int GameEntry::getScore() const { return score; }

ostream& operator<<(ostream& out, const GameEntry& obj) {
  out << '{' << obj.getName() << ',' << obj.getScore() << '}';
  return out;
}

// Scores data structure
class Scores {
public:
  Scores(int maxEnt = 10);	// Constructor
  ~Scores();			// Destructor
  void add (const GameEntry& e); // add an entry
  GameEntry remove(int i)	 // Remove a single entry
    throw (IndexOutOfBounds);
  // Operators:
  GameEntry& operator[](size_t i) {
    return entries[i];
  };	// Access to game entries
  friend ostream& operator<<(ostream& out, const Scores& obj);
private:
  int maxEntries;		// maximum number of entries
  int numEntries;		// actual number of entries
  vector<GameEntry> entries;		// array of game entries
};
// Definitions for Scores
Scores::Scores(int maxEnt) {
  maxEntries = maxEnt;
  entries = vector<GameEntry>(maxEnt);
  numEntries = 0;
}
Scores::~Scores() {		// Destructor
  // delete [] entries;
}
void Scores::add(const GameEntry& e) { // Add a game entry
  int newScore = e.getScore();	       // Score to add
  if (numEntries == maxEntries){       // The array is full
    if (newScore <= entries[maxEntries-1].getScore())
      return;			// not high enough
  }
  else
    numEntries++;

  int i = numEntries - 2;	// Start with the next to last
  while (i >= 0 && newScore > entries[i].getScore()) {
    entries[i+1] = entries[i];
    i--;
  }
  entries[i+1] = e;
}
GameEntry Scores::remove(int i) throw(IndexOutOfBounds) { // Remove
  try{	  // Exception for outof bounds
    if ( (i < 0) || (i >= numEntries) )
      throw IndexOutOfBounds("Invalid index");
  } catch (IndexOutOfBounds& iob) {
    cout << iob.getMessage() << endl;
    return GameEntry();
  }
  GameEntry e = entries[i];		// Save the removed object
  for (int j = i+1; j < numEntries; j++)
      entries[j-1] = entries[j];	// Shift entries left
  numEntries--;			// one fewer entry
  return e;			// return the removed object
}

ostream& operator<<(ostream& out, const Scores& obj){
  for (int i = 0; i < obj.numEntries; i++) {
    out << obj.entries[i] << ' ';
  }
  return out;
}


int main() {
  GameEntry *e0 = new GameEntry("Zafar", 10);
  GameEntry *e1 = new GameEntry("Zafa", 11);

  // Scores *s = new Scores(5);
  Scores s(5);
  s.add(*e0);
  s.add(*e1);
  s.add(GameEntry("John", 9));
  s.add(GameEntry("Alice", 19));
  s.add(GameEntry("Bob", 15));
  s.add(GameEntry("Connor", 1));
  cout << s << endl;
  s.remove(0);
  s.remove(6);

  delete e0;
  delete e1;
    
  cout << s << endl;
}
