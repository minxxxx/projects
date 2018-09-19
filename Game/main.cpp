#include <zion.h>

void    checkKeys(Zion::Window& win, Zion::Camera& camera);
void    generateBlocks();

Zion::Window    win;
Zion::Shader    shader;
Zion::Shader    shader1;
Zion::Renderer  renderer;
Zion::Camera    camera =  Zion::Camera(glm::vec3(0, 0, 3), 0, -90.0f);

int map[10][10] = {
	{1,0,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,1,0,1,0,1},
	{1,0,1,0,0,1,0,1,0,1},
	{1,0,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,1,0,0,1,1,0,0,1},
	{1,0,1,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1},
};

int     main(int ac, char **av)
{
	win.initWindow("Test",  1280, 760);
	shader.initShader("shaders/basic.vert", "shaders/basic.frag");
	shader1.initShader("shaders/anime.vert", "shaders/basic.frag");

	glm::mat4   proj_mat = glm::perspective(glm::radians(70.0f), (float)1280 / (float)960, 0.1f, 1000.0f);
	shader.setUniformMat4((GLchar *)"proj_matrix", proj_mat);
	shader1.setUniformMat4((GLchar *)"proj_matrix", proj_mat);

	//generateBlocks();

	Zion::Gltf *model = new Zion::Gltf();
	model->loadFromFile(shader1, "models/bomberman/Onile.glb");
	Zion::Material *mat = new Zion::Material();
	mat->texure.loadTextureFromPath("models/bomberman/OnileDiffuseColor.png");
	model->addMaterial(0, *mat);

	Zion::Renderable::startTime = (float)glfwGetTime();
	Zion::Renderable::runTime = Zion::Renderable::startTime;

	while (!win.shouldClose() && !win.isKeyPressed(GLFW_KEY_ESCAPE))
	{
		auto currentTime = (float)glfwGetTime();
		Zion::Renderable::deltaTime = currentTime - Zion::Renderable::runTime;
		Zion::Renderable::runTime = currentTime;
		Zion::Renderable::secondsPassed = currentTime - Zion::Renderable::startTime;

		win.clearWindow(0.0f, 0.0f, 0.0f, 1.0f);
		checkKeys(win, camera);
		shader.setUniformMat4((GLchar *)"view_matrix", camera.getViewMatrix());
		shader1.setUniformMat4((GLchar *)"view_matrix", camera.getViewMatrix());
		model->render(glm::translate(glm::mat4(), glm::vec3(0, 0, -1)));
		//renderer.render();
		win.updateWindow();
	}
	for (GLuint id : Zion::Texture::textureIDs)
		glDeleteTextures(1, &id);
	Zion::Texture::textureIDs.clear();
	delete model;
	delete mat;
	return 0;
}

void    checkKeys(Zion::Window& win, Zion::Camera& camera)
{
	if (win.isKeyPressed(GLFW_KEY_A))
		camera.changeCameraXPos(-2.5f);
	if (win.isKeyPressed(GLFW_KEY_D))
		camera.changeCameraXPos(2.5f);
	if (win.isKeyPressed(GLFW_KEY_W))
		camera.changeCameraZPos(-2.5f);
	if (win.isKeyPressed(GLFW_KEY_S))
		camera.changeCameraZPos(2.5f);
}

void    generateBlocks()
{
	glm::mat4   mat;
	Zion::Gltf  *block = new Zion::Gltf();

	block->loadFromFile(shader, "models/blocks/block2.gltf");

	float  Z = -1;
	for (int z = 0; z < 10; z++)
	{
		float X = 1;
		for (int x = 0; x < 10; x++)
		{
			if (map[z][x] == 1)
				//renderer.addToRender(block, glm::translate(mat, glm::vec3(X, 0, Z)));
			X += 2;
		}
		Z -= 2;
	}
}