#include "debug.h"

#include <algorithm>
#include <boost/regex.hpp>
#include <boost/regex/v5/regex_replace.hpp>
#include <boost/regex/v5/regex_search.hpp>
#include <boost/token_functions.hpp>
#include <boost/tokenizer.hpp>
#include <cstdio>
#include <cstring>
#include <format>
#include <iostream>
#include <vector>

int main()
{

    // Reg expression.
    printf(ANSI_FMT("Test boost regular expression \n", ANSI_BLUE));
    std::vector<boost::regex> exprs;
    exprs.push_back(boost::regex("\\b[0-9]{1,100}\\b"));
    exprs.push_back(boost::regex("[0-9]{1,100}"));

    // test string
    std::string              input{"wda 24232 dwa dawd\n9 dwadsawd \nHello wordl12321321dhwdaadwadad\n"};

    boost::smatch            matched;  // Store  matched result
    std::vector<std::string> str_res;

    // Traversal all regex
    for (auto &expr : exprs)
    {
        while (boost::regex_search(input, matched, expr))
        {
            // Output every matched item
            std::for_each(
                matched.begin(), matched.end(),
                [&](const auto &sub_match)
                {
                    std::cout << std::format(
                                     ANSI_FMT("Regular expression {}, matched: {}", ANSI_BLUE), expr.str(),
                                     sub_match.str()
                                 )
                              << std::endl;
                }
            );

            // delete matched  string
            auto pos = matched.position();
            auto len = matched.length();

            input.erase(pos, len);
        }
    }

    // test for tokens
    printf(ANSI_FMT("Test boost token  library \n", ANSI_BLUE));
    using tokenizer = boost::tokenizer<boost::char_separator<char>>;
    boost::char_separator<char> septor(" ");

    tokenizer                   tokens(input, septor);
    for (const auto &str : tokens)
    {
        std::cout << std::format(ANSI_FMT("Token: {}", ANSI_BLACK), str) << std::endl;
    }

    return 0;
}