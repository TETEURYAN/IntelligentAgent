#include "knowledge/knowledgebase.h"
#include "inference/inferenceengine.h"
#include "explanation/explanation.h"

using namespace std;

int main() {
    KnowledgeBase kb;
    InferenceEngine ie(kb);
    Explanation exp(ie);

    int modo;
    string sentenca_inicial;

    do {
        cout << "\nMenu Principal:\n";
        cout << "1. Editor de Base de Conhecimento\n";
        cout << "2. Inferência\n";
        cout << "3. Explanação\n";
        cout << "4. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> modo;

        switch (modo) {
            case 1:
                kb.editor_de_base_de_conhecimento();
                break;
            case 2: {
                int tipo_inferencia;
                cout << "Escolha o modo de inferência:\n";
                cout << "1. Encadeamento para trás\n";
                cout << "2. Encadeamento para frente\n";
                cout << "3. Encadeamento misto\n";
                cin >> tipo_inferencia;

                cout << "Digite a sentença inicial a ser provada: ";
                cin >> sentenca_inicial;

                if (ie.inferir(sentenca_inicial, tipo_inferencia)) {
                    cout << sentenca_inicial << " é verdade" << endl;
                } else {
                    cout << sentenca_inicial << " não pode ser provada" << endl;
                }
                break;
            }
            case 3: {
                int tipo_explicacao;
                cout << "Escolha o tipo de explanação:\n";
                cout << "1. Por quê?\n";
                cout << "2. Como?\n";
                cin >> tipo_explicacao;

                cout << "Digite a sentença que deseja explicar: ";
                cin >> sentenca_inicial;

                exp.explicar(sentenca_inicial, tipo_explicacao);
                break;
            }
            case 4:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    } while (modo != 4);

    return 0;
}
