#pragma once
#ifndef BITMAP_STORE_H
#define BITMAP_STORE_H

#include <SFML/Graphics.hpp>
#include <map>

class BitmapStore {
public:
	BitmapStore();
	static sf::Texture& getBitmap(std::string const& filename);
	static void addBitmap(std::string const& filename);

private:
    std::map<std::string, sf::Texture> m_BitmapsMap;
    static BitmapStore* m_s_Instance;
};
#endif