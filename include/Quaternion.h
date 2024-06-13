// Quaternion.h
#ifndef QUATERNION_H
#define QUATERNION_H

#include <cmath>

struct Quaternion {
    float w, x, y, z;
};

inline Quaternion quaternion_add(Quaternion q1, Quaternion q2) {
    Quaternion result;
    result.w = q1.w + q2.w;
    result.x = q1.x + q2.x;
    result.y = q1.y + q2.y;
    result.z = q1.z + q2.z;
    return result;
}

inline Quaternion quaternion_multiply(Quaternion q1, Quaternion q2) {
    Quaternion result;
    result.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
    result.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
    result.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
    result.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
    return result;
}

inline Quaternion quaternion_conjugate(Quaternion q) {
    Quaternion result;
    result.w = q.w;
    result.x = -q.x;
    result.y = -q.y;
    result.z = -q.z;
    return result;
}

inline float quaternion_norm(Quaternion q) {
    return sqrt(q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z);
}

inline Quaternion quaternion_unit(Quaternion q) {
    float norm = quaternion_norm(q);
    Quaternion result;
    result.w = q.w / norm;
    result.x = q.x / norm;
    result.y = q.y / norm;
    result.z = q.z / norm;
    return result;
}

inline float quaternion_dot_product(Quaternion q1, Quaternion q2) {
    return q1.w * q2.w + q1.x * q2.x + q1.y * q2.y + q1.z * q2.z;
}

inline Quaternion quaternion_cross_product(Quaternion q1, Quaternion q2) {
    Quaternion result;
    result.w = 0;
    result.x = q1.y * q2.z - q1.z * q2.y;
    result.y = q1.z * q2.x - q1.x * q2.z;
    result.z = q1.x * q2.y - q1.y * q2.x;
    return result;
}

inline Quaternion quaternion_from_axis_angle(double angle, double x, double y, double z) {
    Quaternion result;
    result.w = cos(angle / 2.0);
    double s = sin(angle / 2.0);
    result.x = x * s;
    result.y = y * s;
    result.z = z * s;
    return result;
}

#endif // QUATERNION_H
