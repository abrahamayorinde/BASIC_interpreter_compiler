//
//  symbol_table.h
//  
//
//  Created by Abraham Ayorinde on 9/7/22.
//

#ifndef symbol_table_h
#define symbol_table_h
#include "symbol_node.h"
using namespace std;
  
const int MAX = 32655;

class SymbolTable {
    SymbolNode* head[MAX];
    
public:
    SymbolTable()
    {
        for (int i = 0; i < MAX; i++)
            head[i] = NULL;
    }
  
    int hashf(string id); // hash function
    bool insert(string id, string scope,
                string Type, int lineno);
  
    int find(string id);
  
    bool deleteRecord(string id);
  
    bool modify(string id, string scope,
                string Type, int lineno);
};

#endif /* symbol_table_h */
