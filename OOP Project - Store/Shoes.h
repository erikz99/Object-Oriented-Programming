#include <string>
#include "Clothes.h"

class Shoes : public Clothes
{
public:
	Shoes(std::string name = "", double price = 0, std::string color = "", size_t size = 0, std::string sole = ""
		, std::string type = "");

	virtual void print() const override final;

	std::string getSole() const;
	std::string getType() const;

private:
	std::string s_sole;
	std::string s_type;
};