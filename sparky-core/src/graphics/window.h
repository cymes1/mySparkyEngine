#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

namespace Sparky { namespace Graphics
{
	class Window
	{
		friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	
	private:
		static const int MAX_KEYS = 1024;
		static const int MAX_BUTTONS = 32;
		const string m_name;
		int m_width;
		int m_height;
		GLFWwindow* m_window;
		bool m_isClosed;

		static bool m_keys[MAX_KEYS];
		static bool m_mouseButtons[MAX_BUTTONS];
		static double m_mx, m_my;

	public:
		Window(string name, int width, int height);
		~Window();
		void clear() const;
		void update();
		bool isClosed() const;
		static bool isKeyPressed(unsigned int keycode);
		static bool isMouseButtonPressed(unsigned int buttoncode);

		int width() const;
		int height() const;
		void mousePosition(double& mx, double& my);

	private:
		bool init();
	};
}}

#endif
