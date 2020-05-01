#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>

#define WIN32_LEAN_AND_MEAN

void crypt(std::string& word)
{
    for (unsigned i = 0; i < word.size(); ++i)
    {
        word[i] = 0x55 ^ word[i];
    }
}

std::string current_directory()
{
    char buf[256];
    GetCurrentDirectoryA(256, buf);
    return std::string(buf) + '\\';
}

int main()
{
    // Why am I signing my name off on this, lol
    std::cout << "Roblox Diogenes Fun v1.0\nBy lightbulblighter\n" << std::endl;

    std::string file_path;
    std::cout << "Enter diogenes path to encrypt/decrypt: ";
    std::cin >> file_path;

    // Worker
    std::string line;
    std::ifstream in_file(file_path);
    std::string out_file_path = current_directory() + "diogenes_output.fnt";
    std::ofstream out_file(out_file_path.c_str());

    if (in_file.is_open() && out_file.is_open())
    {
        while (getline(in_file, line, '\n'))
        {
            crypt(line);
            out_file << line << std::endl;
        }
    }

    // Exit
    std::cout << "Successfully written new diogenes file to " << out_file_path << "!" << std::endl;
    system("pause");
    
    return 0;
}