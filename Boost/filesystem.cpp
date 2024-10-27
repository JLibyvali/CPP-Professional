#include <static_assert>
#include "debug.h"

#include <boost/filesystem.hpp>
#include <boost/filesystem/file_status.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <cstdio>
#include <ctime>
#include <format>
#include <ios>
#include <iostream>
#include <iterator>
#include <string>

int main()
{

    // test for filesystem
    printf(ANSI_FMT("Test filesystem.\n", ANSI_BLUE));

    boost::filesystem::path ph(".");
    boost::filesystem::path self("./pool");

    auto                    st = boost::filesystem::status(ph);

    std::cout << "Is a  directory: " << std::boolalpha << boost::filesystem::is_directory(st) << std::endl;
    auto last_time = boost::filesystem::last_write_time(self);
    std::cout << std::format(
                     "File name: {}\nFile string: {}\nFile size: {} bytes\nFile last write time: {}\n",
                     self.filename().string(), self.string(), self.size(), std::ctime(&last_time)
                 )
              << std::endl;

    
    // space info
    printf(ANSI_FMT("Create new directory\n", ANSI_BLUE));
    
    boost::filesystem::path dir("./files");
    if (boost::filesystem::create_directory(dir))
    {
        auto space_info = boost::filesystem::space(boost::filesystem::path("."));
        std::cout << std::format(
            "disk Capacity {}\nFree {}\nAvailable {} Bytes\n", space_info.capacity, space_info.free, space_info.available
        );

        boost::filesystem::remove(dir);
    }

    return 0;
}