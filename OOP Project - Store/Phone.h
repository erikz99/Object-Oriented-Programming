#include <string>
#include "Technology.h"

class Phone : public Technology
{
public:
	Phone(std::string name = "", double price = 0, std::string maker = "", std::string cpu = "", std::string os = ""
		, size_t ram = 0, size_t memory = 0, size_t year = 0, double screen = 0, std::string camera = ""
		, std::string color = "", double weight=0);

	virtual void print() const override final;
	std::string getCamera() const;
	std::string getColor() const;
	double getWeight() const;

private:
	
	std::string p_camera;
	std::string p_color;
	double p_weight;
	
};