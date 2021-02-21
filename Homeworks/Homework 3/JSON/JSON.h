#pragma once

class JSON
{
public:
	inline virtual JSON* copy() {
		return new JSON(*this);
	}
	virtual ~JSON() = default;
};