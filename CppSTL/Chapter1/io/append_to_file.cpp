#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define FAIL 1
#define SUCCESS 0
#define FILENAME "/home/diman91/Documents/Cpp-STL-Examples/Firewall.txt"

bool cat_file(const char* filename)
{
  char ch;

  ifstream in_file;
  in_file.open(filename);

  if(!in_file.is_open()) {
    cout << "File was not opened! ERROR! Aborting...\n";
    return FAIL;
  }

  do {
    in_file.get(ch);

    if(!in_file.eof() && ( in_file.fail() || in_file.bad() )) {
      cout << "ERROR! Aborting ...";
      in_file.close();
      return FAIL;
    }

    if(!in_file.eof())
      cout << ch;
  } while(!in_file.eof());

  in_file.clear();    // needed for eof and fail

  in_file.close();

  if(!in_file.good()){
    cout << "ERROR! ... in closing file ... Aborting ...";
    return FAIL;
  }

  return SUCCESS;
}


// Function to write contents to a file
bool write_file(const char* filename, const char* content)
{
  ofstream out_file;
  out_file.open(filename, ios::out | ios::app);

  if(!out_file.is_open()) {
    cout << "File was not opened! ERROR! Aborting...\n";
    return FAIL;
  }

  out_file << content << endl;

  out_file.close();

  if(!out_file.good()){
      cout << "ERROR! Aborting ...";
      return FAIL;
  }

  return SUCCESS;
}


int main()
{
  vector<const char*> commands = {"iptables -A INPUT -p tcp -s 192.168.16.0/16 --dport 24 -j ACCEPT",
                                  "iptables -A INPUT -p tcp -s 192.168.17.0/16 --dport 24 -j ACCEPT",
                                  "iptables -A INPUT -p tcp -s 192.168.16.0/16 --dport 21 -j ACCEPT",
                                  "iptables -A INPUT -p tcp -s 192.168.17.0/16 --dport 21 -j ACCEPT",
                                  "iptables -A INPUT -j DROP"
                                };
  vector<const char*>::iterator itr = commands.begin();
  while(itr != commands.end()) {
    //cout << *itr << endl;
    write_file(FILENAME, *itr);
    itr++;
  }

  cat_file(FILENAME);

  return 0;
}
