#ifndef INFERENCEENGINE_H
#define INFERENCEENGINE_H

#include "knowledge/knowledgebase.h"
#include <stack>

class InferenceEngine {
private:
    KnowledgeBase& kb;
    stack<string> pilha;

    bool encadeamento_para_tras(const string& hipotese);
    void encadeamento_para_frente();
    bool encadeamento_misto(const string& hipotese);

public:
    InferenceEngine(KnowledgeBase& kb);
    bool inferir(const string& hipotese, int tipo);
};

#endif
