/**
 * @file      parser.hpp
 * @brief     Parser header
 * @copyright Copyright (C) Theodore Bardy. All rights reserved.
 *            Developed by Theodore Bardy.
 *            Reproduction, copy, modification in whole or part is prohibited
 *            without the written permission of the copyright owner.
 */

#ifndef _PARSER_HPP_
#define _PARSER_HPP_

#include "piece.hpp"
#include <string>
#include <tuple>
#include <vector>

using namespace std;

class Parser
{
private:
    vector<string> gameDescription;

public:
    Parser();
    ~Parser();

    bool loadGame(string filePath, string fileName);
    bool saveGame(string filePath, string fileName);
};

#endif /* _PARSER_HPP_ */
