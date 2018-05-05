#include <iostream>
#include <string>

using namespace std;




int euclides(int x , int y){
  int t;
  x = (x < 0) ? -x:x;
  y = (y < 0) ? -y:y;
  t = (x < y) ? x : y;
  while ( (x % t) || (y % t))
    --t;
  return t;
}



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
