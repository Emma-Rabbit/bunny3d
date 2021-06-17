#include "Renderer.hpp"
#include "WindowManager.hpp"
#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include "VertexArray.hpp"
#include "ShaderLoader.hpp"
#include "ShaderProgram.hpp"
#include "Texture.hpp"
#include "Timer.hpp"
#include "InputManager.hpp"
#include "State.hpp"
#include "Cube.hpp"
#include "Scene.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <fstream>
#include <math.h>

void GLAPIENTRY MessageCallback( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam )
{
  fprintf( stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
           ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
            type, severity, message );
}

int main(){
    WindowManager* wm = new WindowManager(800,600,"dupa");
    glfwMakeContextCurrent(wm->getWindowHandler());//creates opengl context needed by glewInit
    glewInit();//initializes glew

    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEPTH_TEST);
    glDebugMessageCallback(MessageCallback, 0); // set up debug messeges

    InputManager::Bind(*wm);
 
    Scene scene;
    int n = 0;
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            scene.AddObject(Cube::GetCubeOnPosition(glm::vec3((float)i, float(j), 0.0f)), Cube::GetIndeciesOfNthCube(n));
            n++;
        }
    }
    // scene.AddObject(Cube::GetCubeOnPosition(glm::vec3(0.0f, 1.0f, 0.0f)), Cube::GetIndeciesOfNthCube(0));
    // scene.AddObject(Cube::GetCubeOnPosition(glm::vec3(0.0f, 0.0f, 0.0f)), Cube::GetIndeciesOfNthCube(1));

    glEnable(GL_BLEND); //TODO: learn how to use blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    VertexArray verArray;
    VertexBuffer verBuffer{scene.GetVerticies(), scene.GetVerticiesSize()};

    verBuffer.AddLayout(3, GL_FLOAT, GL_FALSE);
    verBuffer.AddLayout(2, GL_FLOAT, GL_FALSE);
    verArray.AddBuffer(verBuffer);

    IndexBuffer indBuffer{scene.GetIndecies(), scene.GetIndeciesSize()};

    ShaderLoader sl;
    sl.LoadShader(GL_VERTEX_SHADER,"src/shader.vert");
    sl.LoadShader(GL_FRAGMENT_SHADER, "src/shader.frag");

    ShaderProgram sp{sl};
    sp.AttachShader(GL_VERTEX_SHADER, "shader");
    sp.AttachShader(GL_FRAGMENT_SHADER, "shader");
    sp.LinkAndValidate();   
    sp.AddUniform("u_Time");
    sp.AddUniform("u_MVP");
    sp.AddUniform("u_Texture");
    sp.Bind();

    Texture texture("res/textures/cheems.png");
    texture.Bind();

    sp.SetUniform1i("u_Texture", 0);

    Renderer renderer{verArray, indBuffer, sp};

    bool increase;
    float time = 0;
    Timer timer;
    Camera& camera = *State::GetInstance()->GetCamera();
    while(!wm->shouldClose()){
        timer.Start();
        renderer.Clear();

        glm::mat4 mvp = camera.Update();

        sp.SetUniform1f("u_Time", time);
        sp.SetUnifromMatrix4f("u_MVP", mvp);
        time += 0.05f;
        renderer.Draw();

        glfwSwapBuffers(wm->getWindowHandler());
        glfwPollEvents();
        timer.LimitFramerate(60);
    }
    return 0;
}