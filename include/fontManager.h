#pragma once
#include <string>
#include <unordered_map>
#include <imgui.h>

class FontSingleton
{
public:
    static FontSingleton &getInstance()
    {
        static FontSingleton instance;
        return instance;
    }

    void initFonts();

    ImFont* getFont(const std::string& fontName);

private:
FontSingleton() = default;
~FontSingleton() = default;

std::unordered_map<std::string, ImFont*> fontMap;

// Delete copy constructor and assignment operator
FontSingleton(const FontSingleton&) = delete;
FontSingleton& operator=(const FontSingleton&) = delete;

};
