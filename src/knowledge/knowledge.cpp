#include "knowledgebase.h"
#include <bits/stdc++.h>

using namespace std;

void KnowledgeBase::adicionar_fato(const string& fato) {
    fatos.insert(fato);
    cout << "Fato '" << fato << "' adicionado com sucesso." << endl;
}

void KnowledgeBase::adicionar_regra(const string& consequente, const vector<string>& antecedentes) {
    regras[consequente] = antecedentes;
    cout << "Regra '" << consequente << "' adicionada com sucesso." << endl;
}

vector<string> KnowledgeBase::Antecedentes(const string& hipotese) {
    if (regras.find(hipotese) != regras.end()) {
        return regras[hipotese];
    }
    return {};
}

bool KnowledgeBase::existe_fato(const string& fato) {
    return fatos.find(fato) != fatos.end();
}

void KnowledgeBase::editor_de_base_de_conhecimento() {
    int escolha;
    string fato, consequente;
    int num_antecedentes;
    vector<string> antecedentes;

    do {
        cout << "Editor de Base de Conhecimento:\n";
        cout << "1. Adicionar fato\n";
        cout << "2. Adicionar regra\n";
        cout << "3. Voltar ao menu principal\n";
        cout << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                cout << "Digite o fato a ser adicionado: ";
                cin >> fato;
                adicionar_fato(fato);
                break;
            case 2:
                cout << "Digite o consequente da regra: ";
                cin >> consequente;
                cout << "Quantos antecedentes? ";
                cin >> num_antecedentes;
                antecedentes.resize(num_antecedentes);
                for (int i = 0; i < num_antecedentes; i++) {
                    cout << "Digite o antecedente " << i + 1 << ": ";
                    cin >> antecedentes[i];
                }
                adicionar_regra(consequente, antecedentes);
                break;
            case 3:
                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    } while (escolha != 3);
}
