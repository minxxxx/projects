#pragma once

#include <zion.h>
#include <glm/gtx/quaternion.hpp>

class   NonStatic
{
private:
	int             _id;
	std::string     _type;
	glm::mat4       _position;
	glm::mat4       _rotation;
	glm::mat4       _scale;
public:
	std::string     modelType;
public:
	NonStatic(int id, std::string type){
		_id = id;
		_type = type;
		_position = glm::mat4();
		_rotation = glm::mat4();
		_scale = glm::mat4();
	}
	NonStatic(const NonStatic & rhs){
		*this = rhs;
	}
	NonStatic&  operator=(const NonStatic & rhs){
		if (this != &rhs){
			_id = rhs._id;
			_type = rhs._type;
			_position = rhs._position;
			_rotation = rhs._rotation;
			_scale = rhs._scale;
		}
		return *this;
	}
	~NonStatic() = default;

	void    translate(glm::vec3 trans){ _position = glm::translate(glm::mat4(), trans); }
	void    translate(glm::mat4 trans){ _position = trans; }
	void    rotate(glm::mat4 rot) { _rotation = rot; }
	void    rotate(float angle, glm::vec3 rot){ _rotation = glm::rotate(glm::mat4(), angle, rot); }
	void    rotate(glm::quat rot) { _rotation = glm::toMat4(rot); }
	void    scale(glm::vec3 scale) { _scale = glm::scale(glm::mat4(), scale); }
	void    scale(glm::mat4 scale) { _scale = scale; }

	glm::mat4   getTransformation() { return _position * _rotation * _scale; }
	int         getId(){ return _id; }
	std::string getType() { return _type; }
	glm::vec3   getPosition() { return glm::vec3(_position[3]); }
};