#include "HashTable.h"
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    if (argc <= 1)
    {
        cout << "Please supply a file name for the dictionary as input" << endl;
        return 1;
    }
    
    HashTable* hashTable = new HashTable(argv[1]);

        
    cout << "Spell checking...\n";
    
    hashTable->SpellCheck("spelling");
    cout << endl;
    hashTable->SpellCheck("spel");
    cout << endl;
    hashTable->SpellCheck("goiing");
    cout << endl;
    hashTable->SpellCheck("abcdefghijklmnop");
    cout << endl;
   
    cout << endl << "   added tests:" << endl << endl;

    hashTable->SpellCheck("spellling");
    cout << endl;
    hashTable->SpellCheck("speling");
    cout << endl;
    hashTable->SpellCheck("spellina");

    return 0;
}
