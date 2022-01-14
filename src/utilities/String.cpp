#include "utilities/String.hpp"

namespace re
{
    std::string ReadLine(FILE* filestream)
    {
        if(filestream == NULL)
        {
            printf("Failed to open file\n");
            exit(EXIT_FAILURE);
        }

        std::string line_buffer;
        char ch = fgetc(filestream);
    
        while(ch != '\n' && ch != EOF)
        {
            line_buffer += ch;
            ch = fgetc(filestream);
        }

        return line_buffer;
    }
    std::string FirstToken(std::string in)
    {
        UI32 token_start = in.find_first_not_of( " \t");
        UI32 token_end = in.find_first_of( " \t");

        if(token_start != -1 && token_end != -1)
            return in.substr(token_start, token_end - token_start);
        else if(token_start != -1)
            return in.substr(in.size() - token_start);
        else
            return "";
    }
    std::vector<std::string> SplitString(std::string in, std::string token)
    {   
        SIZE input_size = in.size();
        SIZE token_size = token.size();

        std::string buffer;
        std::vector<std::string> out;

        for(int index = 0; index <= input_size; index++)
        {
            std::string test = in.substr(index, token_size);

            if(test == token || index == input_size)
            {   
                if(buffer.size() != 0)
                {
                    out.push_back(buffer);

                    buffer.clear();
                    
                    index += token_size - 1;
                }
            }
            else
                buffer += in[index];
        }
        
        return out;
    }
}