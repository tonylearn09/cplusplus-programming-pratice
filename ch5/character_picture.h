#ifndef GUARd_character_picture_h
#define GUARd_character_picture_h

#include <string>
#include <vector>

std::string::size_type width(const std::vector<std::string>&);

std::vector<std::string> frame(const std::vector<std::string>&);

std::vector<std::string> vcat(const std::vector<std::string>& top, const std::vector<std::string>& bottom);

std::vector<std::string> hcat(const std::vector<std::string>& left, const std::vector<std::string>& right);

#endif
