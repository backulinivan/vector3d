#include "vector3d.hpp"

#include <cmath>

const vector3d vector3d::X = {1, 0, 0};
const vector3d vector3d::Y = {0, 1, 0};
const vector3d vector3d::Z = {0, 0, 1};
const vector3d vector3d::ZERO = {0, 0, 0};

vector3d::vector3d() {
    x = 0;
    y = 0;
    z = 0;
}

vector3d::vector3d(double _x, double _y, double _z) {
    x = _x;
    y = _y;
    z = _z;
}

bool vector3d::operator==(const vector3d &other) const {
    return (x == other.x) && (y == other.y) && (z == other.z);
}

bool vector3d::operator!=(const vector3d &other) const {
    return (x != other.x) | (y != other.y) | (z != other.z);
}

vector3d vector3d::operator+(const vector3d &other) const {
    return vector3d(x + other.x, y + other.y, z + other.z);
}

vector3d vector3d::operator-(const vector3d &other) const {
    return vector3d(x - other.x, y - other.y, z - other.z);
}

double vector3d::operator*(const vector3d &other) const {
    return x*other.x + y*other.y + z*other.z;
}

vector3d operator*(double multiplier, const vector3d &vector){
    return vector3d(multiplier*vector.x, multiplier*vector.y, multiplier*vector.z);
}

vector3d operator*(const vector3d &vector, double multiplier){
    return multiplier*vector;
}

vector3d operator-(const vector3d &vector){
    return (-1)*vector;
}

double vector3d::length() const {
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

void vector3d::normalize() {
    double length = this->length();
    x = x/length;
    y = y/length;
    z = z/length;
}

std::ostream& operator<<(std::ostream& out, const vector3d &output){
    out << "{" << output.x << ", " << output.y << ", " << output.z << "}";
    return out;
}

vector3d vector3d::operator^(const vector3d &other) const {
    double new_x = y*other.z - z*other.y;
    double new_y = z*other.x - x*other.z;
    double new_z = x*other.y - y*other.x;
    return vector3d(new_x, new_y, new_z);
}