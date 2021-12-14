#include <iostream>
#include <vector>
#include <algorithm>  // for_each

using namespace std;

auto test = []( const vector<int>& vec ) {
  for(auto val : vec)
    cout << val << " ";
  cout << endl;
};

auto AVG = [](const vector<int>& vec) {
  int sum_=0;
  for_each( vec.begin(), vec.end(),
            [&sum_](int elem) { sum_+=elem; }
          );
  cout << "AVG = " << sum_/vec.size() << endl;
};

int main()
{
  vector<int> nums{};
  for(size_t i=100; i>=50; i-=10)   nums.push_back( i );
  test(nums);

  AVG(nums);

  return 0;
}
