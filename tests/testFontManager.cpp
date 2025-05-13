#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "fontManager.h"
#include "doctest.h"

TEST_CASE("FontSingleton loads fonts and retrieves them") {
    ImGui::CreateContext();

    // Prior to init
    CHECK(FontSingleton::getInstance().getFont("notoSansNormal") == nullptr);

    // Init fonts
    FontSingleton::getInstance().initFonts();

    // Normal getFont test
    CHECK(FontSingleton::getInstance().getFont("notoSansNormal") != nullptr);
    CHECK(FontSingleton::getInstance().getFont("notoSansBold") != nullptr);

    // Checks persistency after loading font
    auto* font1 = FontSingleton::getInstance().getFont("notoSansNormal");
    auto* font2 = FontSingleton::getInstance().getFont("notoSansNormal");
    CHECK(font1 == font2);

    // Check for a font that is unavailable
    CHECK(FontSingleton::getInstance().getFont("fakeFont") == nullptr);

    // Sanity test
    // CHECK(FontSingleton::getInstance().getFont("notoSansBold") == nullptr);

    ImGui::DestroyContext();
}