#ifndef REVOLVER
#define REVOLVER

class Revolver {
public:
    bool Fire();
    void LoadChambers(int n);
private:
    unsigned char chambers = 0;
    int currIndex = 0;
};

#endif // REVOLVER
