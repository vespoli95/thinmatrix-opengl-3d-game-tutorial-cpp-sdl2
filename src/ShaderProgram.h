
#include "Headers.h"
#include "Maths.h"

class ShaderProgram
{
public:
	ShaderProgram(string vertexFile, string fragmentFile);
	void start();
	void stop();
	void cleanUp();
	void bindAttribute(int attribute, string variableName);
	void bindAttributes();
	
	int getShaderProgram() { return programID; }
	//protected:
	int getUniformLocation(string uniformName);
	void loadFloat(int location, float value);
	void loadVector(int location, vector<GLfloat>& vec);
	void loadBoolean(int location, bool value);
	void loadMatrix(int location, GLfloat matrix[16]);
	void getAllUniformLocations();
	void loadTransformationMatrix(GLfloat matrix[16]);

private:
	int loadShader(string fileName, GLenum type);
	string readShaderSource(string fileName);
	
	int programID;
	int vertexShaderID;
	int fragmentShaderID;

	int location_transformationMatrix;
};
