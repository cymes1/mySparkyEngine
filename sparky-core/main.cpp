#include <GL/glew.h>
#include <GL/glu.h>
#include <time.h>

#include "src/math/math.h"
#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/graphics/batchrenderer2d.h"
#include "src/graphics/simple2drenderer.h"
#include "src/graphics/renderable2d.h"
#include "src/graphics/sprite.h"
#include "src/graphics/layers/tilelayer.h"
#include "src/graphics/layers/group.h"
#include "src/utils/timer.h"

using namespace Sparky;
using namespace Graphics;
using namespace Math;

int main()
{
	Window window("Sparky", 960, 540);

	//mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader* shader = new Shader("shaders/basic.vert", "shaders/basic.frag");
	shader->setUniform2f("light_pos", vec2(4.0f, 1.5f));

	TileLayer layer(shader);

	/*srand(time(NULL));
	for(float y = -9.0f; y < 9.0f; y += 0.1f)
	{
		for(float x = -16.0f; x < 16.0f; x += 0.1f)
		{
			layer.add(new Sprite(x, y, 0.08f, 0.08f, vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}*/

	Group* group = new Group(mat4::translation(vec3(-15.0f, 5.0f, 0.0f)));
	group->add(new Sprite(0.0f, 0.0f, 6, 3, Math::vec4(1, 1, 1, 1)));
	group->add(new Sprite(0.5f, 0.5f, 5.0f, 2.0f, Math::vec4(1, 0, 1, 1)));
	layer.add(group);

	Timer timer;
	int framesPerSecond = 0;
	double t = 0;
	mat4 mat = mat4::translation(vec3(0.0f, 5.0f, 0.0f));
	shader->setUniformMat4("pr_matrix", mat);

	while(!window.isClosed())
	{
		window.clear();

		double x, y;
		window.mousePosition(x, y);
		shader->setUniform2f("light_pos", vec2((float)(x * 32.0f / 960.0f - 16.0f), (float)(9.0f - y * 18.0f / 540.0f)));

		layer.render();
		window.update();

		++framesPerSecond;
		if(timer.elapsed() - t >= 1)
		{
			++t;
			printf("FPS = %d\n", framesPerSecond);
			framesPerSecond = 0;
		}
	}

	return 0;
}
