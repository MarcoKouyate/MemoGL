#include "OpenGLImGui.h"

namespace MemoGL {
	OpenGLImGui::OpenGLImGui(const IContext& context, const char* glslVersion, bool darkMode) :
            context(context)
    {
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;

		if (darkMode) {
			ImGui::StyleColorsDark();
		}
		else {
			ImGui::StyleColorsClassic();
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
    }

}