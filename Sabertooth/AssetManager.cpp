#include "AssetManager.h"

AssetManager* AssetManager::instance = 0;

AssetManager::AssetManager(){
}

AssetManager::~AssetManager()
{
}

AssetManager * AssetManager::Instance()
{
	if ( instance == 0 )
	{
		instance = new AssetManager();
	}
	return instance;
}

unsigned char * AssetManager::LoadImage(char* path)
{
	int width, height;
	unsigned char *image;

	image = SOIL_load_image( path, &width, &height, 0, SOIL_LOAD_RGBA );
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image );
	SOIL_free_image_data( image );

	return nullptr;
}
