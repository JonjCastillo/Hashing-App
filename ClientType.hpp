/**
 * @file ClientType.hpp
 * @author Jonathan Castillo, Sean Harris, Nadeem Ameen
 * @brief This is the header file for a ClientType class. this class holds an object 
 * that contains a persons name, an associated ID, and their current balance. It contains the necessary 
 * accessors and mutators as well as a method that prints the object to a string.
 * @version 0.1
 * @date 2022-11-10
 * 
 * 
 */
#ifndef CLIENTTYPE_HPP
#define CLIENTTYPE_HPP


#include <string>
#include <sstream>
using namespace std;


class ClientType {
   private:
      
      int id;
      string name;
      double balance;
      
   public:
      
      ClientType();
      ClientType(int id, string name, double balance);

      //accessors
      int getID() const;
      double getBalance() const;
      string getName() const;

      //mutators
      void setName(string name);
      void setBalance(double balance);
      void setID(int id);
      
      string toString() const;



};


ClientType::ClientType(int id, string name, double balance) {
   this->id = id;
   this->name = name;
   this->balance = balance;
}

ClientType::ClientType() {
   this->id = 0;
   this->name = "";
   this->balance = 0.0;
}

int ClientType::getID() const{
   return id;
}

string ClientType::getName() const{
   return name;
}

double ClientType::getBalance() const{
   return balance;
}

void ClientType::setName(string newName) {
   this->name = newName;
}

void ClientType::setBalance(double balance) {
   this->balance = balance;
}

void ClientType::setID(int id) {
   this->id = id;
}

string ClientType::toString() const {
   ostringstream buffer;

   buffer << "Name: " << this->name << "\n"
          << "ID: " << this->id << "\n"
          << "Balance $: " << this->balance << "\n";
   return buffer.str();

}


#endif

