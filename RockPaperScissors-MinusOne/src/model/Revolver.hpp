#ifndef REVOLVER
#define REVOLVER

class Revolver {
public:
    bool Fire();
    void LoadChambers(int n);
    void setIfSpins(bool ifSpins) { this->ifSpins = ifSpins; };
private:
    unsigned char chambers;
    int currIndex = 0;
    bool ifSpins;
};

#endif // REVOLVER
