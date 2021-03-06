#ifndef _cBasicTextureManager_HG_
#define _cBasicTextureManager_HG_

#include <string>
#include <map>
#include "CTextureFromBMP.h"

#include <Windows.h>
#include <thread>

class cBasicTextureManager
{
public:
	struct sTextureThreadData
	{
		cBasicTextureManager* texture_manager;
		CTextureFromBMP* texture;
	};

	int push_loaded_textures_to_gpu();

	static DWORD load_texture_threaded_function(void* params)
	{
		auto* data = reinterpret_cast<sTextureThreadData*>(params);

		if (!data->texture->load_texture_file(data->texture->getTextureName(), data->texture->getFileNameFullPath(), true))
		{
			data->texture->status = CTextureFromBMP::eTextureStatus::error;
			return -1;
		}

		data->texture->status = CTextureFromBMP::eTextureStatus::ready_to_goto_gpu;

		return 0;
	}

	bool Create2DTextureFromBMPFile_threaded(std::string textureFileName, bool bGenerateMIPMap);

	bool Create2DTextureFromBMPFile( std::string textureFileName, bool bGenerateMIPMap );

	// Picks a random texture from the textures loaded
	std::string PickRandomTexture(void);

	bool CreateCubeTextureFromBMPFiles( std::string cubeMapName, 
		                                std::string posX_fileName, std::string negX_fileName, 
		                                std::string posY_fileName, std::string negY_fileName, 
										std::string posZ_fileName, std::string negZ_fileName, 
										bool bIsSeamless, std::string &errorString );


	// returns 0 on error
	GLuint getTextureIDFromName( std::string textureFileName );

	void SetBasePath(std::string basepath);

private:
	std::string m_basePath;
	std::string m_lastError;
	void m_appendErrorString( std::string nextErrorText );
	void m_appendErrorStringLine( std::string nextErrorTextLine );

	std::map< std::string, CTextureFromBMP* > m_map_TexNameToTexture;


};

#endif
