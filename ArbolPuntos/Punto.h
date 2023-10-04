#ifndef __PUNTO_H__
#define __PUNTO_H__

struct Punto {
    int x;
    int y;
    
    Punto& operator = (const Punto &p) {
        x = p.x;
        y = p.y;
        return *this;
    }
    
    bool operator == (const Punto &p) const {
        return (x == p.x && y == p.y);
    }
    
    friend std::ostream& operator << (std::ostream &o, const Punto &p) {
        o << "(" << p.x << "," << p.y << ")";
        return o;
    }
};

#endif
