#include <GL/glew.h>
#include <GL/glu.h>
#include <time.h>

#include "src/math/math.h"
#include "src/graphics/window.h"
#include "src/graphics/buffers/buffer.h"
#include "src/graphics/buffers/indexBuffer.h"
#include "src/graphics/buffers/vertexArray.h"
#include "src/graphics/shader.h"
#include "src/graphics/batchrenderer2d.h"
#include "src/graphics/simple2drenderer.h"
#include "src/graphics/renderable2d.h"
#include "src/graphics/sprite.h"
#include "src/utils/timer.h"

using namespace Sparky;
using namespace Graphics;
using namespace Math;

int main()
{
	Window window("Sparky", 960, 540);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("shaders/basic.vert", "shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);

	std::vector<Renderable2D*> sprites;
	srand(time(NULL));

	Sprite sprite(5, 5, 4, 4, vec4(1, 0, 1, 1));
	Sprite sprite2(7, 1, 2, 3, vec4(0.2f, 0, 1, 1));
	
	BatchRenderer2D renderer;

	for(float y = 0.0f; y < 9.0f; y+= 0.15)
	{
		for(float x = 0.0f; x < 16.0f; x+= 0.15)
		{
			sprites.push_back(new Sprite(x, y, 0.1f, 0.1f, Math::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}

	Timer timer;
	int framesPerSecond = 0;
	double t = 0;
	std::cout << sprites.size() << std::endl;

	while(!window.isClosed())
	{
		window.clear();

		mat4 mat = mat4::translation(vec3(5, 5, 5));
		mat = mat * mat4::rotation(timer.elapsed() * 100, vec3(0, 0, 1));
		mat = mat * mat4::translation(vec3(-5, -5, -5));
		shader.setUniformMat4("ml_matrix", mat);

		double x, y;
		window.mousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
		renderer.begin();
		for(unsigned int i = 0; i < sprites.size(); i++)
		{
			renderer.submit(sprites[i]);
		}
		renderer.end();
		renderer.flush();

		window.update();

		++framesPerSecond;
		if(timer.elapsed() - t >= 1)
		{
			++t;
			printf("FPS = %d\n", framesPerSecond);
			framesPerSecond = 0;
		}
	}

	for(unsigned int i = 0; i < sprites.size(); i++)
	{
		delete sprites[i];
	}

	return 0;
}
