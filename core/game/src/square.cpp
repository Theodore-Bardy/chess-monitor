/**
 * @file      square.cpp
 * @brief     Square sources
 * @copyright Copyright (C) Theodore Bardy. All rights reserved.
 *            Developed by Theodore Bardy.
 *            Reproduction, copy, modification in whole or part is prohibited
 *            without the written permission of the copyright owner.
 */

#include "square.hpp"

Square::Square(Board* _board, int _x, int _y)
    : board(_board)
    , x(_x)
    , y(_y)
{
    /* Set square color */
    if (((x + y) % 2) == 0)
    {
        color = true;
    }
    else
    {
        color = false;
    }

    /* No piece in the square by default */
    piece = NULL;
}

Square::~Square()
{
}

void
Square::setPiece(Piece* _piece)
{
    piece = _piece;
}

bool
Square::hasPiece()
{
    if (NULL != piece)
    {
        return true;
    }

    return false;
}

bool
Square::removePiece()
{
    /* Check if a piece is in the square */
    if (NULL == piece)
    {
        return false;
    }

    piece = NULL;
    return true;
}

Piece*
Square::getPiece()
{
    return piece;
}

bool
Square::isAttacked(bool _color)
{
    // TODO
    return true;
}

void
Square::print(std::ostream& os) const
{
    if (piece == NULL)
    {
        os << " . ";
    }
    else
    {
        os << " x ";
    }
}

std::ostream&
operator<<(std::ostream& os, Square const& square)
{
    square.print(os);
    return os;
}
