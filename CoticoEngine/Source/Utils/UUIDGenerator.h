#pragma once
#include<string>

#include"UUID/uuid.h"

class UUIDGenerator
{
public:
	static std::string Generate() 
	{
		UUIDv4::UUIDGenerator<std::mt19937_64> uuidGenerator;
		UUIDv4::UUID uuid = uuidGenerator.getUUID();
		return uuid.str();
	};
};