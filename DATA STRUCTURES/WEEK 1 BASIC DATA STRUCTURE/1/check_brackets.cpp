#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}
    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    int value = 0;
    getline(std::cin, text);
    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            Bracket *a = new Bracket(next, position+1);
            opening_brackets_stack.push(*a);
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
			if(opening_brackets_stack.empty())
			{
				value = position+1;
				std::cout << position+1 << std::endl;
				break;
			}

            else if(opening_brackets_stack.top().Matchc(next))
            {
            	opening_brackets_stack.pop();
			}
			else if(!opening_brackets_stack.top().Matchc(next))
			{
				value = position+1;
				std::cout << position+1 << std::endl;
				break;
			}
			
        }
    }
    
	if(!opening_brackets_stack.empty() && value == 0)
	{
		std::cout << opening_brackets_stack.top().position << std::endl;
	}
	else if(opening_brackets_stack.empty() && value == 0)
	{
		std::cout << "Success" << std::endl;
	}	


//		std::cout << position << std::endl;
    // Printing answer, write your code here

    return 0;
}
