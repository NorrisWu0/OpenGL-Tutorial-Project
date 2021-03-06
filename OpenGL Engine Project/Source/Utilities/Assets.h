#pragma once
#include <map>


class Asset;


class Assets
{
public:
	Assets();
	~Assets();

	const Asset* GetAsset(const char* _id) const;

private:
	std::map<const char*, const Asset*> m_Assets;
};