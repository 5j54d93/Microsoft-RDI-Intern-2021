#include <iostream> 
using namespace std;

int steps(int floor)
{
  if(floor==1) return 1;
  if(floor==2) return 2;
  return steps(floor-1)+steps(floor-2);
}

int main()
{
  int floor;
  cin >> floor;
  cout << steps(floor);
  
  return 0;
}
