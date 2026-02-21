#pragma once
#include <iostream>
#include <map>


class MySettings {
private:
	std::map<std::string, int> int_settings;
	std::map<std::string, std::string> str_settings;

public:
	MySettings() = default;
	~MySettings();


	void add(const std::string& name, int value);
	void add(const std::string& name, const std::string& value);
	void erase_int(const std::string& name);
	void erase_str(const std::string& name);
	int find_int(const std::string& name) const;
	std::string find_str(const std::string& name) const;


	friend std::ostream& operator<<(std::ostream& os, const MySettings& settings);
	friend std::istream& operator>>(std::istream& is, MySettings& settings);

	void save_selected(const std::string& filename, std::initializer_list<std::string> keys) const;

	void load(const std::string& filename);
	void save(const std::string& filename) const;


};