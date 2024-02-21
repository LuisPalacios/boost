// #define FMT_HEADER_ONLY // may need this line

#include <filesystem>
#include <fstream>
#include <iostream>

#include <fmt/format.h>
#include <spdlog/spdlog.h>

#include "config.hpp"
#include "my_lib.h"

#include <algorithm>
#include <iostream>
#include <iterator>

//#include <boost/lambda/lambda.hpp>
#include <boost/regex.hpp>


int main(int argc, char **argv)
{
    /**
     * @brief Default
     *
    std::cout << "FMT: " << FMT_VERSION << '\n';
    std::cout << "SPDLOG: " << SPDLOG_VER_MAJOR << "." << SPDLOG_VER_MINOR
              << "." << SPDLOG_VER_PATCH << '\n';

    const auto welcome_message =
        fmt::format("Welcome to {} v{}\n", project_name, project_version);
    spdlog::info(welcome_message);
    */

    /**
     * @brief Test 1
     *

    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::for_each(
        in(std::cin), in(), std::cout << (_1 * 3) << " "
        );
     */

    /**
     * @brief Test 2
     *
     */
    std::string line;
    boost::regex pat ("^Subject: (Re: |Aw: )*(.*)" );

    while (std::cin) {
        std::getline(std::cin, line);
        boost::smatch matches;
        if (boost::regex_match(line,matches,pat))
            std::cout << matches[2] << std::endl;

    }


    return 0;
}
