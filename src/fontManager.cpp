#include "fontManager.h"

#include <imgui.h>
#include <iostream>

void FontSingleton::initFonts()
{
    ImGuiIO &io = ImGui::GetIO();

    std::string fontPath = "../assets/fonts/";

    const std::string notoSansPath = fontPath + "NotoSans-Regular.ttf";
    const std::string notoSansBoldPath = fontPath + "NotoSans-Bold.ttf";

    ImVector<ImWchar> customRanges;
    ImFontGlyphRangesBuilder builder;

    builder.AddRanges(io.Fonts->GetGlyphRangesDefault());
    builder.BuildRanges(&customRanges);

    // Primary font
    ImFont *notoSansNormal = io.Fonts->AddFontFromFileTTF(
        notoSansPath.c_str(), 28.0f, nullptr, customRanges.Data);

    // Noto Sans bold font
    ImFont *notoSansBold = io.Fonts->AddFontFromFileTTF(
        notoSansBoldPath.c_str(), 46.0f, nullptr, customRanges.Data);

    fontMap.emplace("notoSansNormal", notoSansNormal);
    fontMap.emplace("notoSansBold", notoSansBold);

    io.Fonts->Build();
}

ImFont *FontSingleton::getFont(const std::string &fontName)
{
    auto it = fontMap.find(fontName);
    if (it != fontMap.end() && it->second != nullptr)
    {
        return it->second;
    }

    std::cerr << "Font not found: " << fontName << std::endl;
    return nullptr;
}