#include "BitmapStore.h"
#include <assert.h>

using namespace sf;
using namespace std;

BitmapStore* BitmapStore::m_s_Instance = nullptr;

BitmapStore::BitmapStore() {
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

void BitmapStore::addBitmap(std::string const& filename) {
	auto& bitmapsMap = m_s_Instance->m_BitmapsMap; // Get a reference to m_Textures using m_S_Instance

	/*
	 * Create an iterator to hold a key-value-pair (kvp) and search for the required kvp using the passed in file name
	 */
	auto keyValuePair = bitmapsMap.find(filename);

	/*
	 * No match found so save the texture in the map
	 */
	if (keyValuePair == bitmapsMap.end()) {
		auto& texture = bitmapsMap[filename]; // Create a new key value pair using the filename

		texture.loadFromFile(filename); // Load the texture from file in the usual way
	}

}

Texture& BitmapStore::getBitmap(string const& filename) {
	auto& m = m_s_Instance->m_BitmapsMap; // Get a reference to m_Textures using m_S_Instance

	/*
	 * Create an iterator to hold a key-value-pair (kvp) and search for the required kvp using the passed in file name
	 */
	auto keyValuePair = m.find(filename);

	/*
	 * Did we find a match?
	 */
	if (keyValuePair != m.end()) {
		return keyValuePair->second;
	}
	else {
#ifdef debuggingOnConsole 		
		cout <<
			"BitmapStore::getBitmap()Texture not found Crrrashh!"
			<< endl;
#endif
		return keyValuePair->second;
	}
}