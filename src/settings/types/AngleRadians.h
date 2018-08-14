//Copyright (c) 2018 Ultimaker B.V.
//CuraEngine is released under the terms of the AGPLv3 or higher.

#ifndef ANGLERADIANS_H
#define ANGLERADIANS_H

#define TAU (2.0*M_PI)

namespace cura
{

/*
 * Represents an angle in radians.
 *
 * This is a facade. It behaves like a double, but this is using clock
 * arithmetic which guarantees that the value is always between 0 and 2 * pi.
 */
struct AngleRadians
{
    /*
     * Translate the double value in degrees to an AngleRadians instance.
     */
    AngleRadians(double value) : value(std::fmod(std::fmod(value * M_PI / 180, TAU) + TAU, TAU)) {};

    /*
     * Casts the AngleRadians instance to a double.
     */
    operator double() const
    {
        return value;
    }

    /*
     * Some operators implementing the clock arithmetic.
     */
    AngleRadians operator +(const AngleRadians& other) const
    {
        return std::fmod(std::fmod(value + other.value, TAU) + TAU, TAU);
    }
    AngleRadians& operator +=(const AngleRadians& other)
    {
        value = std::fmod(std::fmod(value + other.value, TAU) + TAU, TAU);
        return *this;
    }
    AngleRadians operator -(const AngleRadians& other) const
    {
        return std::fmod(std::fmod(value - other.value, TAU) + TAU, TAU);
    }
    AngleRadians& operator -=(const AngleRadians& other)
    {
        value = std::fmod(std::fmod(value - other.value, TAU) + TAU, TAU);
        return *this;
    }

    /*
     * The actual angle, as a double.
     *
     * This value should always be between 0 and 2 * pi.
     */
    double value = 0;
};

}

#endif //ANGLERADIANS_H