#ifndef KNOWLEDGE_BASE_H
#define KNOWLEDGE_BASE_H

#include <bits/stdc++.h>
#include "../utils/utils.h"

using namespace std;

class KnowledgeBase {
private:
    unordered_set<string> fatos;
    unordered_map<string, vector<string>> regras;

public:
    void adicionar_fato(const string& fato);
    void adicionar_regra(const string& consequente, const vector<string>& antecedentes);
    vector<string> Antecedentes(const string& hipotese);
    bool existe_fato(const string& fato);
    void editor_de_base_de_conhecimento();
    void exibir_fatos();
    void exibir_regras();

    const unordered_map<string, vector<string>>& getRegras() const {
        return regras;
    }
};

#endif
