/*
** EPITECH PROJECT, 2023
** EpiLinter-tokenizer
** File description:
** BoostTokenizer
*/

#ifndef BOOSTTOKENIZER_HPP_
#define BOOSTTOKENIZER_HPP_
#include "Tokenizer.hpp"
#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <boost/wave.hpp>
#include <boost/wave/cpplexer/cpp_lex_token.hpp>
#include <boost/wave/cpplexer/cpp_lex_iterator.hpp>
#include <boost/wave/cpplexer/cpplexer_exceptions.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>

typedef std::string TokenFilter;
typedef std::vector<TokenFilter> FilterSequence;
typedef std::vector<Token> TokenSequence;

class BoostTokenizer
{
public:
    static TokenSequence getTokens(const std::string & fileName,
    int fromLine, int fromColumn, int toLine, int toColumn,
    const FilterSequence & filter);
};

#endif /* !BOOSTTOKENIZER_HPP_ */
