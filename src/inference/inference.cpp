#include "inferenceengine.h"
#include <iostream>

InferenceEngine::InferenceEngine(KnowledgeBase& kb) : kb(kb) {}

bool InferenceEngine::encadeamento_para_tras(const string& hipotese) {
    cout << "Procurando por " << hipotese << endl;

    if (kb.existe_fato(hipotese)) {
        cout << hipotese << " é um fato" << endl;
        return true;
    }

    if (!pilha.empty() && pilha.top() == hipotese) {
        cout << hipotese << " não pode ser provado" << endl;
        return false;
    }

    pilha.push(hipotese);
    vector<string> antecedentes = kb.Antecedentes(hipotese);
    if (antecedentes.empty()) {
        cout << hipotese << " não tem antecedentes" << endl;
        pilha.pop();
        return false;
    }

    cout << "Antecendentes [" << hipotese << "]: { ";
    for (const auto& antecedente : antecedentes) {
        cout << antecedente << " ";
    }
    cout << "}" << endl;

    for (const auto& antecedente : antecedentes) {
        if (!encadeamento_para_tras(antecedente)) {
            cout << antecedente << " não pode ser provado" << endl;
            pilha.pop();
            return false;
        }
    }

    cout << "Todos os antecedentes de " << hipotese << " foram provados" << endl;
    kb.adicionar_fato(hipotese);
    pilha.pop();
    return true;
}

void InferenceEngine::encadeamento_para_frente() {
    bool novo_fato_adicionado;
    do {
        novo_fato_adicionado = false;
        for (const auto& regra : kb.getRegras()) {
            const string& hipotese = regra.first;
            const vector<string>& antecedentes = regra.second;

            if (!kb.existe_fato(hipotese)) {
                bool todos_antecedentes_sao_fatos = true;
                for (const auto& antecedente : antecedentes) {
                    if (!kb.existe_fato(antecedente)) {
                        todos_antecedentes_sao_fatos = false;
                        break;
                    }
                }

                if (todos_antecedentes_sao_fatos) {
                    cout << "Regra satisfeita: " << hipotese << endl;
                    kb.adicionar_fato(hipotese);
                    novo_fato_adicionado = true;
                }
            }
        }
    } while (novo_fato_adicionado);
}

bool InferenceEngine::encadeamento_misto(const string& hipotese) {
    if (encadeamento_para_tras(hipotese)) {
        encadeamento_para_frente();
        return true;
    }
    return false;
}

bool InferenceEngine::inferir(const string& hipotese, int tipo) {
    switch (tipo) {
        case 1:
            return encadeamento_para_tras(hipotese);
        case 2:
            encadeamento_para_frente();
            return kb.existe_fato(hipotese);
        case 3:
            return encadeamento_misto(hipotese);
        default:
            cout << "Tipo de inferência inválido!" << endl;
            return false;
    }
}
