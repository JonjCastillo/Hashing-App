/**
 * @file tableMenu.cpp
 * @author Jonathan Castillo, Sean Harris, Nadeem Ameen
 * @brief this is the implementation of the hash table and the client class
 * ith creates a menu for the user to come in and interact with the menu
 * to add, create, view the table, update, and view specific items on the table.
 * the application calls an instance of the Hash table and then does various operations
 * regarding the Bank clients and their information.
 * @version 0.1
 * @date 2022-11-10
 * 
 * 
 */
#include "HashTable.hpp"
#include "ClientType.hpp"
#include <iostream>

using namespace std;

void topLevelMenu() {
   cout << "1.\tadd a record: \n";
   cout << "2.\tedit record: \n";
   cout << "3.\tfind record: \n";
   cout << "4.\tview the records: \n";
   cout << "5.\tremove a record \n";
   cout << "6.\texit \n";
}

int main(int argc, char const *argv[]) {
   int input;
	bool exit = false;
   bool found = false;
   int choice = 1;
   ClientType* tempClient;
   HashTable HT;
   string name;
   int id;
   float balance;
   string consume;
   char isCorrect;

   do {
         cout << "---------Stack Menu--------" << endl;
         topLevelMenu();
         cin  >> input;

         switch (input)
         {
            case 1: // add to front
               // populateStack(stack);

               while (choice == 1) {
                  cin.ignore(255, '\n');
                  cin.clear();
                  cout << "Enter the name for the Account: " << endl;
                  getline(cin, name);
                  // tempClient->setName(name);
                  cout << "Enter ID for "<< name <<": " << endl;
                  cin  >> id;
                  // tempClient->setID(id);
                  cout << "Enter the current balance for " << name << ": " << endl;
                  cin  >> balance;
                  // tempClient->setBalance(balance);

                  HT.insertItem(name, new ClientType(id, name, balance));

                  cout << "Enter 1 to add another record: ";
                  cin  >> choice; 
               }
               break;

            case 2: // edit a record
               // updateAccountStack(stack);
               cout << "--------Update Records-----------" << endl;
               choice = 0;

               do {

                  cin.ignore(255, '\n');
                  cin.clear();
                  cout << "Enter name of Account to Update: " << endl;
                  getline(cin, name);
                  
                  tempClient = HT.searchTable(name);
                  
                  if (tempClient == NULL) {
                     cout << "Account with Matching name not found" << endl;
                  } else {
                     // cin.ignore(256, '\n');
                     cout << "---Current Information---" << endl;
                     cout << tempClient->toString() << endl;
                  
                     cout << "Enter the updated name for the Account: " << endl;
                     getline(cin, name);
                     
                     cout << "Enter the updated balance for " << name << ": " << endl;
                     cin  >> balance;

                     cout << "---Current Information---" << endl;
                     cout << tempClient->toString() << endl;

                     cout << "---Updated Information---" << endl;
                     cout << "Name: "  << name << "\n"
                          << "ID: " << id << "\n"
                          << "Balance: " << balance << endl;
                     cout << "Is this information correct? (y/n): " << endl;
                     if (cin >> isCorrect) {
                        if (isCorrect == 'y' || isCorrect == 'Y') {
                           
                           id = tempClient->getID();
                           HT.removeItem(tempClient->getName());
                           HT.insertItem(name, new ClientType(id, name, balance));
                           cout << "Record Updated." << endl;


                           cout << "Enter 1 to update another record: ";
                           cin  >> choice; 
                           cin.ignore(255, '\n');
                        }
                     } 

                  }

               } while (choice == 1);
               break;

            case 3: // view (find specific)
               // viewAccountStack(stack);
               choice = 0;
               cin.ignore(255, '\n');
               cin.clear();
               cout << "Enter Account Name: " << endl;
               getline(cin, name);

               tempClient = HT.searchTable(name);

               if (tempClient != NULL) {
                  cout << tempClient->toString() << endl;
               } else {
                  cout << "Account not found" << endl;
               }
               

               break;

            case 4: // print (trigger sub-menu)
               // printStack(stack);
               cout <<"Data in the table\n";

               HT.printTable();

               break;
               
            case 5: // delete
               cin.ignore(255, '\n');
               cin.clear();
               cout << "Enter the id for the account you want to remove: \n";
               getline(cin, name);

               HT.removeItem(name);
               
               break;

            case 6: //exit
            default:
               exit = true;
               break;
         }
   } while (!exit);

   return 0;
}
