/**
 * @file HashTable.hpp
 * @author Jonathan Castillo, Sean Harris, Nadeem Ameen
 * @brief This is a modified implementation of the "C++ Hash Table Implementation"
 * by the Youtube account "Coding Jesus" His video covers a hash table that uses
 * an integer and a string as the key-value pair for the list, in our implementation
 * we are using a string and a ClientType class as the key-value pair.
 * @version 0.1
 * @date 2022-11-10
 * 
 * 
 */
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <iostream>
#include <list>
#include <cstring>
#include "ClientType.hpp"

using namespace std;

class HashTable {
   private:
      static const int tableSize = 10;
      list<pair<string, ClientType*>> table[tableSize]; 
      // this creates a list that at each index holds the key and value pair
      // similar to a map

   public:
      bool isEmpty() const;
      unsigned int hash(string key);
      void insertItem(string key, ClientType* value);
      void removeItem(string key);
      ClientType* searchTable(string key);
      void printTable();
};

bool HashTable::isEmpty() const {
   for (int i = 0; i < tableSize; i++) {
      if (table[i].size() == 0) return false;
   }
   return true;
}

unsigned int HashTable::hash(string key) {
   int length = key.length();
   char keyArr[length + 1];
   unsigned int hashValue = 0;
   strcpy(keyArr, key.c_str());
   for (int i=0; i < length; i++) {
      hashValue += keyArr[i];
      hashValue = (hashValue * keyArr[i]) % tableSize;
   }
   return hashValue;

}

void HashTable::insertItem(string key, ClientType* value) {
   int index = hash(key);
   auto& cell = table[index];
   auto itr = begin(cell);
   bool keyExists = false;
   for (; itr != end(cell); itr++) {
      if (itr->first == key) {
         keyExists = true;
         itr->second = value;
         cout << "[WARNING] key exists. Value Replace" << endl;
         break;
      }
   }

   if (!keyExists) {
      cell.emplace_back(key, value);
   }
   return;
}

void HashTable::removeItem(string key) {
   int index = hash(key);
   auto& cell = table[index];
   auto itr = begin(cell);
   bool keyExists = false;
   for (; itr != end(cell); itr++) {
      if (itr->first == key) {
         keyExists = true;
         itr = cell.erase(itr);
         // cout << "[INFO] Item Removed" << endl;
         break;
      }
   }

   if (!keyExists) {
      cout << "[WARNING] Key not found. Pair not removed." << endl;
   }

   return;
}

void HashTable::printTable() {
   for (int i{}; i < tableSize; i++) {
      if (table[i].size() == 0) continue;
      
      auto itr = table[i].begin();
      for (; itr != table[i].end(); itr++) {
         cout << itr->second->toString() << endl;
      }
   }
   return;
}

/**
 * @brief this method searches through the table for the desired item using the inputed key. 
 * it then returns the associated account if it is found on the table. If the item is not found
 * then it returns a null value.
 * 
 * @param key 
 * @return ClientType* 
 */
ClientType* HashTable::searchTable(string key) {

   int index = hash(key);
	auto& cell = table[index];
	auto itr = begin(cell);
	bool keyExists = false;

	for (; itr != end(cell); itr++) {
		if (itr->first == key) {
			keyExists = true;
			return itr->second;
		}
	}

	if (!keyExists)
		return NULL;
   
}

#endif