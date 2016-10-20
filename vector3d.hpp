#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <ostream>

class vector3d {
public:
    double x, y, z;
    const static vector3d X;
    const static vector3d Y;
    const static vector3d Z;
    const static vector3d ZERO;

    vector3d();
    vector3d(double _x, double _y, double _z);
    vector3d operator+(const vector3d &other) const;
    vector3d operator-(const vector3d &other) const;
    double operator*(const vector3d &other) const;
    vector3d operator^(const vector3d &other) const;
    double length() const;
    void normalize();
    bool operator==(const vector3d &other) const;
    bool operator!=(const vector3d &other) const;
};

std::ostream& operator<<(std::ostream& out, const vector3d &output);
vector3d operator*(double multiplier, const vector3d &vector);
vector3d operator*(const vector3d &vector, double multiplier);
vector3d operator-(const vector3d &vector);

#endif
