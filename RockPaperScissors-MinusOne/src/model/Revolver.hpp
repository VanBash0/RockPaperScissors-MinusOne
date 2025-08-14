#ifndef REVOLVER
#define REVOLVER

class Revolver {
public:
    bool fire();
    void loadChambers(int n);
private:
    unsigned char chambers = 0;
    int currIndex;
};

#endif // REVOLVER
