#ifndef EXPLANATION_H
#define EXPLANATION_H

#include "../inference/inferenceengine.h"
#include <string>

using namespace std;

class Explanation {
private:
    InferenceEngine& ie; 

public:
    Explanation(InferenceEngine& ie);
    void explicar(const string& hipotese, int tipo);
};

#endif
