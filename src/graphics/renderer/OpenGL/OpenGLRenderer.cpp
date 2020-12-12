#include "OpenGLRenderer.h"
#include "OpenGLError.h"

#include "tools/File.h"
#include "graphics/context/GLFW/GLFWContext.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include <iostream>



namespace MemoGL {
    // INITIALIZATION
    void OpenGLRenderer::init() {
        initializeWindow();
        initializeGlew();
        initializeShaders();
        initializeTextures();
        initializeVertexBuffers();


        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        ImGui::StyleColorsDark();

        ImGui_ImplGlfw_InitForOpenGL(context->get(), true);
        ImGui_ImplOpenGL3_Init("#version 330");

    }

    void OpenGLRenderer::initializeWindow() {
        // an opengl context is required in order to query client opengl version
        // which is why we create a dummy context and close it after getting the opengl version
        context->init(nullptr);
        openGLVersion = getOpenGLVersion();
        context->close();

        ContextSettings properties;
        properties.window = WindowSettings(1280, 720, "MemoGL");
        properties.profile = APIProfile::core;
        
        openGLVersion->changeSettings(properties);
        context->init(&properties);
    }

    std::unique_ptr<IOpenGLVersion> OpenGLRenderer::getOpenGLVersion() {
        int major;
        int minor;
        glGetIntegerv(GL_MAJOR_VERSION, &major);
        glGetIntegerv(GL_MINOR_VERSION, &minor);

        if (major >= 4 && minor >= 3) {
            return std::make_unique<OpenGL4>();
        }
        else {
            return std::make_unique<OpenGL3>();
        }
    }

    void OpenGLRenderer::initializeGlew() {
        glewExperimental = GL_TRUE;

        if (glewInit() != GLEW_OK) {
            context->close();
            throw std::runtime_error("Failed to initialize GLEW");
        }

        openGLVersion->initErrorCalls();
    }

    void OpenGLRenderer::initializeShaders() {
        glm::mat4 proj = glm::ortho(-2.0f, 2.0f, -1.125f, 1.125f, -1.0f, 1.0f);
        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-1, 0, 0));
        glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0, 1, 0));

        glm::mat4 mvp = proj * view * model;


        shader = std::make_unique<OpenGLShader>("res/shaders/texture2d.vert", "res/shaders/texture2d.frag");
        shader->bind();
        shader->setUniform4f("u_Color", 0.8f, 0.5f, 0.3f, 1.0f);
        shader->setUniformMat4f("u_MVP", mvp);
        shader->setUniform1i("u_Texture_Slot", 0);
    }

    void OpenGLRenderer::initializeTextures() {
        GLCall(glEnable(GL_BLEND));
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
        
        texture = std::make_unique<OpenGLTexture>("res/textures/memoticone_admiration.png");
        texture->bind();
    }

    void OpenGLRenderer::initializeVertexBuffers() {
        float positions[] = {
            -0.5f, -0.5f, 0.0f, 0.0f,
             0.5f, -0.5f, 1.0f, 0.0f,
             0.5f,  0.5f, 1.0f, 1.0f,
            -0.5f,  0.5f, 0.0f, 1.0f
        };

        unsigned int indices[] = {
            0, 1, 2,
            2, 3, 0
        };


        vao = std::make_unique<OpenGLVertexArray>();
        vbo = std::make_shared<OpenGLVertexBuffer>(positions, 4 * 4 * sizeof(float));
        ibo = std::make_unique<OpenGLIndexBuffer>(indices, 6);

        OpenGLVertexLayout layout;
        layout.push<float>(2);
        layout.push<float>(2);
        
        vao->addBuffer(vbo, layout);

        vao->bind();
        ibo->bind();
    }







    // RENDER LOOP
    void OpenGLRenderer::render() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
            ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
            ImGui::Checkbox("Another Window", &show_another_window);

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(context->get(), &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);

        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        GLCall(glClear(GL_COLOR_BUFFER_BIT));


        vao->bind();
        ibo->bind();
        shader->bind();

        GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        context->swapBuffers();
    }




    // CONSTRUCTORS 
    OpenGLRenderer::OpenGLRenderer() {
        std::cout << "Initializing OpenGL renderer..." << std::endl;
        context = std::make_shared<GLFWContext>();
        init();
        std::cout << "OpenGL " << GLCallR(glGetString(GL_VERSION)) << " renderer initialized." << std::endl;
    }

    OpenGLRenderer::~OpenGLRenderer() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
        std::cout << "OpenGL renderer has been released." << std::endl;
    }
}