#include <bits/stdc++.h>
using namespace std;

/*
 ae stands for Abhimanyu's energy
 The array k stores the energy of respective k1, k2, k3,...., k11 enemies
 b stands for the number of times Abhimanyu can recharge himself with power
 a stands for how many times Abhimanyu has boon to skip fighting enemies
 initialae stands for the energy Abhimanyu had initially
*/
bool canCrossTheChakravyuha(int ae, int k[], int b, int a)
{
  int initialk3 = k[2]; // the initial power of k3 enemy
  int initialk7 = k[6]; // the initial power of k7 enemy
  int initialae = ae;
  for (int i = 0; i < 11; i++)
  {
    if (ae < k[i])
    {
      if (a > 0)
      {
        a--; // Abhimanyu has boon to skip fighting enemies a times
        continue;
      }
      return false;
    }
    else
    {
      if (k[i] < ae)
      {
        int behindAttack = 0;
        if (i == 3 || i == 7) // handling the case of behind attack from k3 and k7
        {
          if (i == 3)
          {
            behindAttack = initialk3 / 2;
          }
          if (i == 7)
          {
            behindAttack = initialk7 / 2;
          }
        }
        ae = ae - k[i] - behindAttack;
        if (ae < 0)
        {
          if (a > 0 && b > 0)
          {
            a--;            // skip fighting
            ae = initialae; // recharge himself with energy
            b--;
            continue;
          }
          return false;
        }
        if (ae < k[i + 1] && b > 0 && (i + 1) < 11)
        {
          ae = initialae;
          b--; // Abhimanyu can recharge himself with power b times
        }
        continue;
      }
    }
  }
  if (ae > 0)
    return true;
  return false;
}
int main()
{
  // test case 1
  int ae = 20;
  int k[] = {9, 8, 7, 4, 3, 2, 1, 1, 2, 3, 5};
  int b = 5;
  int a = 3;
  bool testcase = canCrossTheChakravyuha(ae, k, b, a);
  if(testcase)
  cout<<"Abhimanyu can cross the Chakravyuha\n";
  else
  cout<<"Abhimanyu can not cross the Chakravyuha"<<endl;

  // test case 2
  int ae2 = 15;
  int k2ndTest[] = {12, 8, 20, 5, 18, 10, 25, 3, 2, 4, 6};
  int b2 = 2;
  int a2 = 1;
  bool testcase2 = canCrossTheChakravyuha(ae2, k2ndTest, b2, a2);
  if (testcase2)
    cout << "Abhimanyu can cross the Chakravyuha\n";
  else
    cout << "Abhimanyu cannot cross the Chakravyuha" << endl;

  return 0;
}
