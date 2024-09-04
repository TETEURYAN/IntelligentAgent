#include "explanation.h"
#include <bits/stdc++.h>

using namespace std;

Explanation::Explanation(InferenceEngine& ie) : ie(ie) {}

void Explanation::explicar(const string& hipotese, int tipo) {
    switch (tipo) {
        case 1:
            cout << "Por quê? Tentando provar " << hipotese << endl;
            ie.inferir(hipotese, 1);
            break;
        case 2:
            cout << "Como? Mostrando como " << hipotese << " foi provado." << endl;
            ie.inferir(hipotese, 3);
            break;
        default:
            cout << "Tipo de explanação inválido!" << endl;
            break;
    }
}
