#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

void findFirstNonRepeating(char stream[], int n)
{
   unordered_map<char, int> charCount;
   list<char> charOrder;

   for (int i = 0; i < n; i++)
   {
      char currentChar = stream[i];

      charCount[currentChar]++;
      charOrder.push_back(currentChar);

      // Remove characters from the front of the list until a non-repeating character is found
      while (!charOrder.empty() && charCount[charOrder.front()] > 1)
      {
         charOrder.pop_front();
      }

      // Print the first non-repeating character or -1
      if (!charOrder.empty())
      {
         cout << charOrder.front() << " ";
      }
      else
      {
         cout << -1 << " ";
      }
   }
}

int main()
{
   int t;
   cin >> t;

   while (t--)
   {
      int n;
      cin >> n;

      char stream[n];
      for (int i = 0; i < n; i++)
      {
         cin >> stream[i];
      }

      findFirstNonRepeating(stream, n);
      cout << endl;
   }

   return 0;
}