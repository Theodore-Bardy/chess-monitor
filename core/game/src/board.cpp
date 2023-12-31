/**
 * @file      board.cpp
 * @brief     Board sources
 * @copyright Copyright (C) Theodore Bardy. All rights reserved.
 *            Developed by Theodore Bardy.
 *            Reproduction, copy, modification in whole or part is prohibited
 *            without the written permission of the copyright owner.
 */

#include "board.hpp"
#include "king.hpp"
#include "queen.hpp"
#include "bishop.hpp"
#include "knight.hpp"
#include "rook.hpp"
#include "pawn.hpp"

Board::Board()
    : isInitialize(false)
{
    /* Initialize empty board */
    for (int Y = 0; Y < BOARD_SIZE_MAX; Y++)
    {
        for (int X = 0; X < BOARD_SIZE_MAX; X++)
        {
            Square* newSquare = new Square(this, X, Y);
            this->board[X][Y] = newSquare;
        }
    }
}

Board::~Board()
{
    /* Release board */
    for (int Y = 0; Y < BOARD_SIZE_MAX; Y++)
    {
        for (int X = 0; X < BOARD_SIZE_MAX; X++)
        {
            delete board[X][Y];
            board[X][Y] = NULL;
        }
    }

    /* Release piece vectors */
    for (int index = 0; index < white_pieces.size(); index++)
    {
        delete white_pieces[index];
    }
    white_pieces.clear();

    for (int index = 0; index < balck_pieces.size(); index++)
    {
        delete balck_pieces[index];
    }
    balck_pieces.clear();
}

void
Board::startUp()
{
    /* Check the startUp function is called once */
    if (!isInitialize)
    {
        Piece* piece = NULL;
        isInitialize = true;

        /* White pieces */
        piece = new King(PIECE_WHITE);
        board[KING_WHITE_DEFAULT_X - 1][KING_WHITE_DEFAULT_Y - 1]->setPiece(piece);
        white_pieces.push_back(piece);
        piece = new Queen(PIECE_WHITE);
        board[QUEEN_WHITE_DEFAULT_X - 1][QUEEN_WHITE_DEFAULT_Y - 1]->setPiece(piece);
        white_pieces.push_back(piece);
        piece = new Bishop(PIECE_WHITE, BISHOP_1_WHITE_DEFAULT_X, BISHOP_1_WHITE_DEFAULT_Y);
        board[BISHOP_1_WHITE_DEFAULT_X - 1][BISHOP_1_WHITE_DEFAULT_Y - 1]->setPiece(piece);
        white_pieces.push_back(piece);
        piece = new Bishop(PIECE_WHITE, BISHOP_2_WHITE_DEFAULT_X, BISHOP_2_WHITE_DEFAULT_Y);
        board[BISHOP_2_WHITE_DEFAULT_X - 1][BISHOP_2_WHITE_DEFAULT_Y - 1]->setPiece(piece);
        white_pieces.push_back(piece);
        piece = new Knight(PIECE_WHITE, KNIGHT_1_WHITE_DEFAULT_X, KNIGHT_1_WHITE_DEFAULT_Y);
        board[KNIGHT_1_WHITE_DEFAULT_X - 1][KNIGHT_1_WHITE_DEFAULT_Y - 1]->setPiece(piece);
        white_pieces.push_back(piece);
        piece = new Knight(PIECE_WHITE, KNIGHT_2_WHITE_DEFAULT_X, KNIGHT_2_WHITE_DEFAULT_Y);
        board[KNIGHT_2_WHITE_DEFAULT_X - 1][KNIGHT_2_WHITE_DEFAULT_Y - 1]->setPiece(piece);
        white_pieces.push_back(piece);
        piece = new Rook(PIECE_WHITE, ROOK_1_WHITE_DEFAULT_X, ROOK_1_WHITE_DEFAULT_Y);
        board[ROOK_1_WHITE_DEFAULT_X - 1][ROOK_1_WHITE_DEFAULT_Y - 1]->setPiece(piece);
        white_pieces.push_back(piece);
        piece = new Rook(PIECE_WHITE, ROOK_2_WHITE_DEFAULT_X, ROOK_2_WHITE_DEFAULT_Y);
        board[ROOK_2_WHITE_DEFAULT_X - 1][ROOK_2_WHITE_DEFAULT_Y - 1]->setPiece(piece);
        white_pieces.push_back(piece);

        /* Black pieces */
        piece = new King(PIECE_BLACK);
        board[KING_BLACK_DEFAULT_X - 1][KING_BLACK_DEFAULT_Y - 1]->setPiece(piece);
        balck_pieces.push_back(piece);
        piece = new Queen(PIECE_BLACK);
        board[QUEEN_BLACK_DEFAULT_X - 1][QUEEN_BLACK_DEFAULT_Y - 1]->setPiece(piece);
        balck_pieces.push_back(piece);
        piece = new Bishop(PIECE_BLACK, BISHOP_1_BLACK_DEFAULT_X, BISHOP_1_BLACK_DEFAULT_Y);
        board[BISHOP_1_BLACK_DEFAULT_X - 1][BISHOP_1_BLACK_DEFAULT_Y - 1]->setPiece(piece);
        balck_pieces.push_back(piece);
        piece = new Bishop(PIECE_BLACK, BISHOP_2_BLACK_DEFAULT_X, BISHOP_2_BLACK_DEFAULT_Y);
        board[BISHOP_2_BLACK_DEFAULT_X - 1][BISHOP_2_BLACK_DEFAULT_Y - 1]->setPiece(piece);
        balck_pieces.push_back(piece);
        piece = new Knight(PIECE_BLACK, KNIGHT_1_BLACK_DEFAULT_X, KNIGHT_1_BLACK_DEFAULT_Y);
        board[KNIGHT_1_BLACK_DEFAULT_X - 1][KNIGHT_1_BLACK_DEFAULT_Y - 1]->setPiece(piece);
        balck_pieces.push_back(piece);
        piece = new Knight(PIECE_BLACK, KNIGHT_2_BLACK_DEFAULT_X, KNIGHT_2_BLACK_DEFAULT_Y);
        board[KNIGHT_2_BLACK_DEFAULT_X - 1][KNIGHT_2_BLACK_DEFAULT_Y - 1]->setPiece(piece);
        balck_pieces.push_back(piece);
        piece = new Rook(PIECE_BLACK, ROOK_1_BLACK_DEFAULT_X, ROOK_1_BLACK_DEFAULT_Y);
        board[ROOK_1_BLACK_DEFAULT_X - 1][ROOK_1_BLACK_DEFAULT_Y - 1]->setPiece(piece);
        balck_pieces.push_back(piece);
        piece = new Rook(PIECE_BLACK, ROOK_2_BLACK_DEFAULT_X, ROOK_2_BLACK_DEFAULT_Y);
        board[ROOK_2_BLACK_DEFAULT_X - 1][ROOK_2_BLACK_DEFAULT_Y - 1]->setPiece(piece);
        balck_pieces.push_back(piece);

        /* Pawns */
        for (int index = 0; index < BOARD_SIZE_MAX; index++)
        {
            /* White pawns */
            piece = new Pawn(PIECE_WHITE, index);
            board[index][PAWN_WHITE_DEFAULT_Y - 1]->setPiece(piece);
            white_pieces.push_back(piece);

            /* Black pawns */
            piece = new Pawn(PIECE_BLACK, index);
            board[index][PAWN_BLACK_DEFAULT_Y - 1]->setPiece(piece);
            balck_pieces.push_back(piece);
        }
    }
}

Square*
Board::getSquare(int _x, int _y)
{
    /* Check if the desired position is in the square */
    if ((_x < 0) || (_x >= BOARD_SIZE_MAX) || (_y < 0) || (_y >= BOARD_SIZE_MAX))
    {
        return NULL;
    }
    else
    {
        return this->board[_x][_y];
    }
}

void
Board::print(std::ostream& os) const
{
    for (int Y = 1; Y <= BOARD_SIZE_MAX; Y++)
    {
        os << (BOARD_SIZE_MAX - Y) << "| ";
        for (int X = 1; X <= BOARD_SIZE_MAX; X++)
        {
            os << *board[BOARD_SIZE_MAX - X][BOARD_SIZE_MAX - Y];
        }
        os << "\n";
    }

    os << "___________________________\n";
    os << "  | a  b  c  d  e  f  g  h \n";
}

std::ostream&
operator<<(std::ostream& os, Board const& board)
{
    board.print(os);
    return os;
}
