#pragma once

#include <nonStatic.hpp>

class   Block : public NonStatic
{
private:
	bool    	_breakable;
	bool 		_collision;
    int     	_id;
	std::string _powerName;
	bool 		_powerup;
	bool 		_endMap;
public:
	Block(int id, std::string type, bool breakable);
	~Block() = default;

    int         getId();
	void        setPosition(float x, float y, float z);
	std::string getPowerName();
	bool 		getEndMap();
	bool        isBreakable();
	void        setPowerName(std::string);
	void        setPowerUp(bool);
	bool        getPowerUp();
	void        setEndMap(bool);

	bool		getCollision();
	void		setCollision(bool collision);
};