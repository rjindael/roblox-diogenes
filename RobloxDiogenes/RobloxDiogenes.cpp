#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include "../cxxopts/include/cxxopts.hpp"

#define WIN32_LEAN_AND_MEAN

std::string crypt(std::string word)
{
    for (unsigned i = 0; i < word.size(); ++i)
    {
        word[i] = 0x55 ^ word[i];
    }

    return word;
}

std::string current_directory()
{
    char buffer[256];
    GetCurrentDirectoryA(256, buffer);
    return std::string(buffer) + '\\';
}

// https://stackoverflow.com/a/19841704
bool file_exists(const char* file_name)
{
    std::ifstream infile(file_name);
    return infile.good();
}

int main(int argc, char* argv[])
{
    std::cout << "RobloxDiogenes" << std::endl << "By lightbulblighter" << std::endl << std::endl;

    cxxopts::Options options("RobloxDiogenes");
    options.add_options()
        ("f,file", "The input diogenes file path, or file name", cxxopts::value<std::string>())
        ("o,output", "The output decrypted / encrypted file path, or file name (default: <working_dir>/diogenes_output.fnt)", cxxopts::value<std::string>()->default_value(current_directory() + "diogenes_output.fnt"));
    
    cxxopts::ParseResult args = options.parse(argc, argv);

    std::string input_file;
    std::string output_file = args["output"].as<std::string>();

    if (args.count("file") == 0)
    {
        std::string file_path;

        std::cout << "Enter diogenes path to encrypt/decrypt: ";
        while (true)
        {
            std::cin >> file_path;
            if (!file_exists(file_path.c_str()))
            {
                std::cout << "The file path you inputted was either invalid, or the file does not exist." << std::endl << std::endl;
                std::cout << "Enter diogenes path to encrypt/decrypt: ";
            }
            else
            {
                break;
            }
        }

        input_file = file_path;
    }
    else
    {
        std::cout << "It seems like a file was inputted through command line arguments, reading from path provided..." << std::endl;
       
        if (!file_exists(args["file"].as<std::string>().c_str()))
        {
            std::cout << "The file path you inputted was either invalid, or the file does not exist." << std::endl;
            system("pause");
            
            return 0;
        }

        input_file = args["file"].as<std::string>();
    }

    // Worker
    std::ifstream diogenes(input_file);
    std::ofstream result(output_file.c_str(), std::ios::binary);

    std::string line;
    if (diogenes.is_open() && result.is_open())
    {
        while (getline(diogenes, line, '\n'))
        {
            result << crypt(line) << std::endl;
        }
    }

    // Exit
    diogenes.close();
    result.close();

    std::cout << "Successfully written new diogenes file to '" << output_file << "'!" << std::endl;
    system("pause");

    return 0;
}