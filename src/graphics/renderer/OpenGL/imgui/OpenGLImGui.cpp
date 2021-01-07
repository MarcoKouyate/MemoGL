#include "OpenGLImGui.h"

namespace MemoGL {
	OpenGLImGui::OpenGLImGui(const IContext& context, const char* glslVersion, bool darkMode) :
            context(context)
    {
        IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;

        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
        //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows


		if (darkMode) {
			ImGui::StyleColorsDark();
		}
		else {
			ImGui::StyleColorsClassic();
		}

        ImGuiStyle& style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }

		ImGui_ImplGlfw_InitForOpenGL(context.getWindow(), darkMode);
		ImGui_ImplOpenGL3_Init(glslVersion);
	}

	OpenGLImGui::~OpenGLImGui() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
	}

    void OpenGLImGui::begin() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void OpenGLImGui::end() {
        int display_w, display_h;
        glfwGetFramebufferSize(context.getWindow(), &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
    }

}