// Hashing With Chaining:
// task: hashing with chaniging (without using stl)
#include <iostream>
#include <list>
using namespace std;

class Hash
{
   int noOfBuckets;
   list<int> *table;

public:
   Hash(int b)
   {
      this->noOfBuckets = b;
      table = new list<int>[noOfBuckets];
   }
   int hashFunction(int x)
   {
      return (x % noOfBuckets);
   }
   void insertItem(int key)
   {
      int index = hashFunction(key);
      table[index].push_back(key);
   }
   void deleteItem(int key)
   {
      int index = hashFunction(key);

      list<int>::iterator i;
      for (i = table[index].begin(); i != table[index].end(); i++)
      {
         if (*i == key)
            break;
      }

      if (i != table[index].end())
         table[index].erase(i);
      // erase take pointer address
   }

   void displayHash()
   {
      cout << "Hash Table:\n";
      for (int i = 0; i < noOfBuckets; i++)
      {
         cout << i;
         for (auto x : table[i])
            cout << " --> " << x;
         cout << endl;
      }
   }
};
int main()
{
   int a[] = {15, 11, 27, 8, 12};
   int n = 5;

   Hash h(7);
   for (int i = 0; i < n; i++)
      h.insertItem(a[i]);

   h.displayHash();
   h.deleteItem(12);
   h.displayHash();

   return 0;
}
