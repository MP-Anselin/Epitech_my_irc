//
// EPITECH PROJECT, 2018
// Tools
// File description:
// Tools
//

#ifndef TOOLS_HPP_
# define TOOLS_HPP_

#include <vector>
#include <string>

class Tools
{
public:
	static std::string str_replace(std::string str, const std::string& from,
			       const std::string& to);
	static std::vector<std::string> explode(const std::string &str,
						const std::string &separator);
};

#endif
