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
    std::cout << "RobloxDiogenes v1.1\nBy lightbulblighter\n" << std::endl;

    std::string file_path;
    std::cout << "Enter diogenes path to encrypt/decrypt: ";
    std::cin >> file_path;

    // Worker
    std::ifstream diogenes(file_path);
    std::string result_path = current_directory() + "diogenes_output.fnt";
    std::ofstream result(result_path.c_str(), std::ios::binary);
    
    std::string line;
    if (diogenes.is_open() && result.is_open())
    {
        while (getline(in_file, line, '\n'))
        {
            crypt(line);
            result << line << std::endl;
        }
    }
    
    // Exit
    diogenes.close();
    result.close();
    std::cout << "Successfully written new diogenes file to '" << result_path << "'!" << std::endl;
    system("pause");
    
    return 0;
}
