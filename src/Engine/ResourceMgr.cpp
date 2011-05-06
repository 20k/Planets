#include "ResourceMgr.h"

ResourceMgr::ResourceMgr() : m_imageList()
{
}

ResourceMgr::~ResourceMgr()
{
}

sf::Image& ResourceMgr::LoadImageFromFile(std::string path)
{
	if(m_imageList[path]!=NULL)
	{
		return *(m_imageList[path]);
	}
	sf::Image *img = new sf::Image;
	img->LoadFromFile(path);
	m_imageList[path] = img;
	return *img;
}