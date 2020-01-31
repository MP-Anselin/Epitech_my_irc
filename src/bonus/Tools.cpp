//
// EPITECH PROJECT, 2018
// Tool
// File description:
// Tool
//

#include "Tools.hpp"

std::string Tools::str_replace(std::string str, const std::string& from, const std::string& to) {
	size_t start_pos = 0;

	while((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
	return str;
}

std::vector<std::string> Tools::explode(const std::string &str, const std::string &separator)
{
	std::vector< std::string > result;
	size_t pos1 = 0;
	size_t pos2 = 0;

	while (pos2 != str.npos){
		pos2 = str.find(separator, pos1);
		if (pos2 != str.npos)
		{
			if (pos2 > pos1)
				result.push_back(str.substr(pos1, pos2 - pos1));
			pos1 = pos2 + 1;
		}
	}
	result.push_back(str.substr(pos1, str.size() - pos1));
	return result;
}
