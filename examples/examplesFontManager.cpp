#include "fontManager.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <iostream>

int main(int argc, char const *argv[])
{
    if (!glfwInit())
    {
        std::cout << "GLFW init failed" << std::endl;
        return -1;
    }

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    int glfwWidth = 1000;
    int glfwHeigth = 400;
    glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
    GLFWwindow *window = glfwCreateWindow(glfwWidth, glfwHeigth, "imgui-font-manager", NULL, NULL);

    if (!window)
    {
        std::cerr << "GLFW window creation failed" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();

    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoCollapse |
    ImGuiWindowFlags_NoResize |
    ImGuiWindowFlags_NoBackground |
    ImGuiWindowFlags_NoScrollbar |
    ImGuiWindowFlags_NoScrollWithMouse;
    
    /**
     * Start of example
     */

    // Singleton init
    FontSingleton::getInstance().initFonts();

    std::string exampleText = "";
    std::string currentFont = "notoSansNormal";

    while ((!glfwWindowShouldClose(window)))
    {
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::SetNextWindowSize(ImVec2(glfwWidth, glfwHeigth));
        ImGui::SetNextWindowPos(ImVec2(0, 0));

        ImGui::Begin("Font Manager Demo", 0, window_flags);

        // Applying the currently selected font before rendering text
        ImGui::PushFont(FontSingleton::getInstance().getFont(currentFont));
        
        // Display the main example text using the selected font
        ImGui::Text(exampleText.c_str());

        // Remove the font and allow for another to be added again
        ImGui::PopFont();

        // Button for changing font Noto Sans Normal
        if (ImGui::Button("Noto Sans Normal"))
        {
            currentFont = "notoSansNormal";
            exampleText = "The text is now in Noto Sans Normal";
        }
        // Button for changing font to Noto Sans Bold
        if (ImGui::Button("Noto Sans Bold"))
        {
            currentFont = "notoSansBold";
            exampleText = "The text is now in Noto Sans Bold";
        }

        /**
         * End of example
         */

        ImGui::End();

        ImGui::Render();
        int displayW, displayH;
        glfwGetFramebufferSize(window, &displayW, &displayH);
        glViewport(0, 0, displayW, displayH);
        glClearColor(0.1, 0.1, 0.1, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
