#include <iostream>
#include <map>
#include <string>

using namespace std;

class Catalogue {
private:
  string name_;
  map<string, size_t> addr_;
  string tel;
public:
  Catalogue(const string& name, const string& addr_a, const size_t addr_nu, const string& tel_num)
    : name_(name), tel(tel_num) {
      addr_.insert({addr_a, addr_nu});
    }
  ~Catalogue() {}
  void show(ostream& );
};

void Catalogue::show(ostream& out) {
  map<string, size_t>::iterator itr = (this->addr_).begin();
  out << "Name:             " << this-> name_ << endl;
  out << "Address:          " << itr->first << " " << itr->second << endl;
  out << "Telephone number: " << this->tel << endl;
}


int main()
{
  Catalogue cat1("Zinedin Zidan", "New York Avenue", 888, "0123456789");
  cat1.show(cout);
  // map test
  return 0;
}
