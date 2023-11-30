/**
 * @file      parser.cpp
 * @brief     Parser sources
 * @copyright Copyright (C) Theodore Bardy. All rights reserved.
 *            Developed by Theodore Bardy.
 *            Reproduction, copy, modification in whole or part is prohibited
 *            without the written permission of the copyright owner.
 */

#include "parser.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Parser::Parser()
{
}

Parser::~Parser()
{
}

bool
Parser::loadGame(string filePath, string fileName)
{
    ifstream fileToRead;
    string   line;
    int      move;

    /* Open file */
    fileToRead.open(fileName);
    if (!fileToRead.is_open())
    {
        return false;
    }

    /* Read file */
    while (fileToRead)
    {
        /* Search for first move "1. " */
        while (getline(fileToRead, line) && !line.find("1. "));

    }

    return true;
}

bool
Parser::saveGame(string filePath, string fileName)
{
    return true;
}
