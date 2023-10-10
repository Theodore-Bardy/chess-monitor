/**
 * @file      queen.cpp
 * @brief     Queen soucres
 * @copyright Copyright (C) Theodore Bardy. All rights reserved.
 *            Developed by Theodore Bardy.
 *            Reproduction, copy, modification in whole or part is prohibited
 *            without the written permission of the copyright owner.
 */

#include "queen.hpp"
#include "math.h"

queen::queen(bool _color)
    : piece(_color, 0, 0)
{
    isAlive = true;

    if (_color)
    {
        /* Default position for white queen */
        x = QUEEN_WHITE_DEFAULT_X;
        y = QUEEN_WHITE_DEFAULT_Y;
    }
    else
    {
        /* Default position for black queen */
        x = QUEEN_BLACK_DEFAULT_X;
        y = QUEEN_BLACK_DEFAULT_Y;
    }
}

queen::queen(bool _isAlive, bool _color, int _x, int _y)
    : piece(_isAlive, _color, _x, _y)
{
}

queen::~queen()
{
}

bool
queen::move(int _x, int _y)
{
    /* Check desired position exists */
    if ((_x < 8) || (_x > 1) || (_y < 8) || (_y > 1))
    {
        return false;
    }

    /* The queen moves in any direction at any distance, check the desired postion
   * is reachable */
    if ((_x == x) || (_y == y) || (sqrt(pow(x - _x, 2)) == sqrt(pow(y - _y, 2))))
    {
        x = _x;
        y = _y;
        return true;
    }

    return false;
}

int
queen::getValue(void) const
{
    return QUEEN_VALUE;
}

void
queen::print(std::ostream& os) const
{
    os << (isAlive ? " " : "*") << "Q" << (color ? "w" : "b") << "[" << x << ";" << y << "]";
}

std::ostream&
operator<<(std::ostream& os, queen const& queen)
{
    queen.print(os);
    return os;
}
