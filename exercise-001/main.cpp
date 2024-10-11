#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

void printVec_int16_t(std::vector<std::int16_t> vec)
{
    fmt::print("[");
    for(std::int16_t num : vec)
    {
        fmt::print("{},",num);
    }
    fmt::print("]\n");
}

void sortVec(std::vector<std::int16_t> &vec)
{
    std::sort(vec.begin(),vec.end());
}

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    std::int16_t count = 20;
    
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));

        app.add_option("-c,--count", count, "Size of array");
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }
    std::vector<std::int16_t> nums(count);

    for(std::int16_t i = 0; i<count;i++)
    {
        nums[i] = rand()%100+1;
    }
    printVec_int16_t(nums);
    auto start = std::chrono::system_clock::now();
    sortVec(nums);
    auto end = std::chrono::system_clock::now();
    auto elapsed =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    printVec_int16_t(nums);

    fmt::print("Sorted in {}ms",elapsed );

    
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    //fmt::print("Hello, {}!\n", app.get_name());

    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}
