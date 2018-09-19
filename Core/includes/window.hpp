#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

namespace Zion
{
#define MAX_KEYS 1024
#define MAX_BUTTONS 32

	struct Input
	{
	private:
		static bool     _prevKeys[MAX_KEYS];
		static bool     _keys[MAX_KEYS];
		static float    _keyTime[MAX_KEYS];
		static bool     _mouse[MAX_BUTTONS];
		static double   _mouseX;
		static double   _mouseY;
	public:
		static bool     (*mouseCallback2)(int, int, int);
		static bool     (*keyCallback2)(int, int, int, int);
		static bool     (*cursorPositionCallback2)(int, int);
		static bool     isPoll;
	public:
		Input();
		Input(const Input & rhs);
		Input&  operator=(const Input & rhs);
		~Input() = default;

		static void     keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void     mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		static void     cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
		static void     updateKeys();
		static bool     getKeyPressOnce(int key);
		bool            getKeyStatus(int key) const;
		bool            getMouseButtonStatus(int button) const;
		double          getMousePosX() const;
		double          getMousePosY() const;
	};

	class Window
	{
	private:
		const char  *_title;
		int         _height;
		int         _width;
		GLFWwindow  *_window;
		Input       _input;
	private:
		bool        createGlfwWindow();
	public:
		Window() = default;
		Window(GLFWwindow *window, const char *title, int width, int height);
		Window(const char *title, int width, int height);
		Window(const Window & rhs);
		Window&     operator=(const Window & rhs);
		~Window();

		static void getError(char *ref);

		bool        initWindow(const char *title, int width, int height);
		bool        initWindow(GLFWwindow *window, const char *title, int width, int height);
		GLFWwindow& getWindow() const;
		int         getHeight() const;
		int         getWidth() const;
		void        enableVsync();
		void        disableVsync();
		void        updateWindow();
		void        clearWindow(float r, float g, float b, float a);
		bool        shouldClose() const;
		bool        isKeyPressed(int key) const;
		bool        isMouseButtonPressed(int button) const;
		void        getMousePos(double &x, double &y) const;
	};
}