/*
 * Created by Rorie Reyes on 10/3/22.
 */

#include "TextureHolder.h"
#include <assert.h>

TextureHolder* TextureHolder::m_s_Instance = nullptr;

TextureHolder::TextureHolder() {
    assert(m_s_Instance == nullptr);
    m_s_Instance = this;
}

Texture& TextureHolder::GetTexture(string const& filename) {
    //Get reference to m_Textures using m_s_Instance
    auto& m = m_s_Instance->m_Textures;
    // auto is the equivalent of map<string, Texture>

    /*
     * Create an iterator to hold a key-value-pair (kvp)
     * and search for the required kvp
     * using the passed in file name
     */
    auto keyValuePair = m.find(filename);
    // auto is equivalent of map<string, Texture>::iterator

    // Finding a match
    if (keyValuePair != m.end()) {
        // Yes, return texture, the second part of the kvp
        return keyValuePair->second;
    }
    else {
        /*
         * File name not found
         * Create a new key value pair using the filename
         */
        auto& texture = m[filename];
        // Load the texture from file in the usual way
        texture.loadFromFile(filename);

        // Return the texture to the calling code
        return texture;

    }
}
