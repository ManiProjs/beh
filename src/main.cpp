#include <iostream>
#include "include/termcolor.hpp"
#include <SFML/Graphics.hpp>
#ifdef WITH_WEBP
#include <webp/decode.h>
#endif

#include <fstream>
#include <vector>
#include <stdexcept>
#include <filesystem>
#include <string>

void error(std::string msg) {
    std::cerr << termcolor::red << "beh ! " << msg << termcolor::reset << std::endl;
}

bool hasWebPExtension(const std::string& filename) {
    std::filesystem::path p(filename);
    return p.extension() == ".webp";
}

#ifdef WITH_WEBP
sf::Texture loadWebP(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        error("Failed to open file");
        throw std::runtime_error("Terminating...");
    }

    std::vector<uint8_t> data((std::istreambuf_iterator<char>(file)),
                                std::istreambuf_iterator<char>());

    int width = 0, height = 0;
    uint8_t* decodedData = WebPDecodeRGBA(data.data(), data.size(), &width, &height);
    if (!decodedData) {
        error("Failed to decode WebP image");
        throw std::runtime_error("Terminating...");
    }

    sf::Texture texture;
    texture.create(width, height);
    texture.update(decodedData);

    return texture;
}
#endif

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << termcolor::red << "Usage: beh [FILENAME]" << termcolor::reset << std::endl;
        return 1;
    }

    std::string filename = argv[1];

    sf::Texture texture;

#ifdef WITH_WEBP
if (hasWebPExtension(filename)) {
    texture = loadWebP(filename);
} else {
    if (!texture.loadFromFile(filename)) {
        std::cout << termcolor::red << "Error: Failed to load image: " << filename << termcolor::reset << std::endl;
        return 1;
    }
}
#else
sf::Texture texture;
if (!texture.loadFromFile(filename)) {
    std::cout << termcolor::red << "Error: Failed to load image: " << filename << termcolor::reset << std::endl;
    return 1;
}
#endif

    sf::Sprite sprite(texture);
    sf::RenderWindow window(sf::VideoMode(texture.getSize().x, texture.getSize().y), "beh - image viewer");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
