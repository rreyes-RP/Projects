/*
 * Created by Rorie Reyes on 10/23/22.
 */

#include "TextureHolder.h"
#include <assert.h>

//using namespace sf;
//using namespace std;

TextureHolder* TextureHolder::m_s_Instance = nullptr;

TextureHolder::TextureHolder() {
    assert(m_s_Instance == nullptr);
    m_s_Instance = this;
}

Texture& TextureHolder::GetTexture(string const& filename) {
    auto& m = m_s_Instance-> m_Textures; // Get a reference to m_Textures using m_s_Instance
    // Auto is the equivalent of map<string, Texture>

    /*
     * Create an iterator to hold a key-value-pair (kvp)
     * and search for the required kvp
     * using the passed in file name
     */
    auto keyValuePair = m.find(filename); //auto is equivalent of map<string, Texture>::iterator

    /*
     * Finding a match
     */
    if (keyValuePair != m.end()) {
        return keyValuePair-> second; // Yes, return the texture, the second part of the kvp
    }

    /*
     * File name not found
     * Create a new key value pair using the filename
     */
    else {
        auto& texture = m[filename];

        texture.loadFromFile(filename); // Load the texture from file in the usual way

        return texture; // Return the texture to the calling code
    }
}
