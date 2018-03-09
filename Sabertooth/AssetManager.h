#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <GL\glew.h>
#include <SOIL.h>

#include <string>

class AssetManager
{

private:
	static AssetManager* instance;

private:
	AssetManager();

public:
	~AssetManager();

	static AssetManager* Instance();

	// TODO: Add different modes
	static unsigned char* LoadImage( char* path );

};

#endif