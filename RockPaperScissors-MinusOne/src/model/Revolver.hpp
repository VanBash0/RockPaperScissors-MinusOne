#ifndef REVOLVER
#define REVOLVER

class Revolver {
public:
    bool fire();
    void loadChambers(int n);
private:
    bool chambers[6];
    int currIndex;
};

#endif // REVOLVER
