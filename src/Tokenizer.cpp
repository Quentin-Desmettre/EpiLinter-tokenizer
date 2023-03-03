/*
** EPITECH PROJECT, 2022
** EpiLinter-tokenizer
** File description:
** Tokenizer.cpp
*/

#include "Tokenizer.hpp"
#include "BoostTokenizer.hpp"
#include <fstream>

std::vector<Token> Tokenizer::getEveryTokenInFile(std::string const &file)
{
    return BoostTokenizer::getTokens(file, 1, 0, -1, -1, {});
}

std::string Tokenizer::getTokens(const std::string &file_content)
{
    std::string file_name = "/tmp/epi-tokens-" + generatedUid(3);
    std::ofstream file(file_name.c_str());
    std::string result;

    if (!file)
        return "";
    file << file_content;
    file.flush();
    file.close();

    auto tokens = getEveryTokenInFile(file_name);
    for (const auto &token: tokens)
        result += (token.value_ + "\1" + std::to_string(token.line_) + "\1" + std::to_string(token.column_) + "\1" + token.name_ + "\2");
    remove(file_name.c_str());
    return result;
}

std::string Tokenizer::generatedUid(int depth)
{
    std::string uid = std::to_string(random());

    for (int i = 1; i < depth; i++)
        uid += "-" + std::to_string(random());
    return uid;
}
