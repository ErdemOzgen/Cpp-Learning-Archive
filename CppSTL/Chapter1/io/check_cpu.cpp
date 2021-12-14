#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string fetch_from_cpuinfo(string search_string)
{
  ifstream file;
  const char* filename = "/proc/cpuinfo";

  file.open(filename);
  // Check if file is opened correctly ::
  // WAY I: if(!file.is_open())
  // WAY II: if(file.fail())
  // WAY III: proposed one
  if(!file)
  {
    cout << "Could not open " << filename << ". ERROR!\n";
    exit(1);
  }

  string line;
  string fetched_str;

  // Loop through the end of file ::
  while(!file.eof())
  {
    // Get current line
    getline(file, line);
    // Find string 'search_string'
    size_t pos = line.find(search_string);
    
    if(pos == std::string::npos)
      continue;

    pos = pos + search_string.length();
    fetched_str = line.substr(pos, std::string::npos);

    break;
  }

  // Close the file | free system resources
  file.close();

  if(!file.good()) {
    cout << "Error occured during the close() of file " << filename << endl;
    exit(1);
  }

  return fetched_str;
}


int main()
{
  cout << "CPU Model Name : " << fetch_from_cpuinfo("model name\t:")
        << "\nCPU Frequency  : " << fetch_from_cpuinfo("cpu MHz\t\t:")  << " KHz"
        << "\nCPU Cache      : " << fetch_from_cpuinfo("cache size\t:")
        << "\nCPU Cores      : " << fetch_from_cpuinfo("cpu cores\t:")
        << "\nKnown Bugs     : " << fetch_from_cpuinfo("bugs\t\t:")
        << endl;

  return 0;
}
