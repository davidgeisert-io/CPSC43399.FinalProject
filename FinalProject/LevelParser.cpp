#include "LevelParser.h"

void LevelParser::Load(const char* fileName, std::vector<GameObject*>* gameObjects, InputDevice* iDevice, GameAssetLibrary* gameAssets, ArtAssetLibrary* artAssets, PhysicsAssetLibrary* pLibrary, b2World* world)
{
    TiXmlDocument doc(fileName);
    if (doc.LoadFile())
	{

        TiXmlHandle hDoc(&doc);
        TiXmlHandle hRoot(0);
        TiXmlElement* pElem;

        pElem = hDoc.FirstChildElement().Element();
        hRoot = TiXmlHandle(pElem);
		
		pElem = hRoot.FirstChild("Resources").Element();
		TiXmlHandle resourceRoot = TiXmlHandle(pElem);
		TiXmlElement* factoryNode= resourceRoot.FirstChild("Factories").FirstChild().Element();
		for(factoryNode; factoryNode; factoryNode=factoryNode->NextSiblingElement())
		{
			const char *name = factoryNode->Attribute("type");
			gameAssets->Insert(name);
		}

		TiXmlElement* animationNode = resourceRoot.FirstChild("Animations").FirstChild().Element();
		for(animationNode; animationNode; animationNode= animationNode->NextSiblingElement())
		{
			const char* type = animationNode->Attribute("type"); 
			TiXmlElement* spriteNode = animationNode->FirstChildElement();
			artAssets->AddContainer(type);
			for(spriteNode; spriteNode; spriteNode = spriteNode->NextSiblingElement())
			{
				const char* key = spriteNode->Attribute("key");
				TiXmlElement* sprite = spriteNode->FirstChildElement();
				for(sprite; sprite; sprite = sprite->NextSiblingElement())
				{
					const char* id = sprite->Attribute("id");
					const char* dir = sprite->Attribute("file");
					float width, height;
					sprite->QueryFloatAttribute("width", &width);
					sprite->QueryFloatAttribute("height", &height);
					artAssets->AddSpriteToContainer(type, key, id, dir, width, height);
				}
			}
			artAssets->PostInitializeContainer(type);
		}

		
		TiXmlElement* physicsNode = resourceRoot.FirstChild("PhysicsDefinitions").FirstChild().Element();
		for(physicsNode; physicsNode; physicsNode = physicsNode->NextSiblingElement())
		{
			const char *name = physicsNode->Attribute("name");
			const char *type = physicsNode->Attribute("type");
			const char *shape = physicsNode->Attribute("shape");
			float density, restitution, angDamp, linDamp, angForce, linForce;
			physicsNode->QueryFloatAttribute("density", &density);
			physicsNode->QueryFloatAttribute("restitution", &restitution);
			physicsNode->QueryFloatAttribute("angDamp", &angDamp);
			physicsNode->QueryFloatAttribute("linDamp", &linDamp);
			physicsNode->QueryFloatAttribute("angForce", &angForce);
			physicsNode->QueryFloatAttribute("linForce", &linForce);
			pLibrary->Add(name, type, shape, density, restitution, angDamp, linDamp, angForce, linForce);
		}

		gameObjects->clear();
		pElem = hRoot.FirstChild("Layout").Element();
		TiXmlHandle gAssetRoot = TiXmlHandle(pElem);
		TiXmlElement* gAssetNode = gAssetRoot.FirstChild("GameAsset").Element();
        for(gAssetNode; gAssetNode; gAssetNode=gAssetNode->NextSiblingElement())
        {
            const char *pName = gAssetNode->Attribute("name");
            float x, y, angle, width, height;

            gAssetNode->QueryFloatAttribute("x", &x);
            gAssetNode->QueryFloatAttribute("y", &y);
            gAssetNode->QueryFloatAttribute("angle", &angle);
			gAssetNode->QueryFloatAttribute("width", &width);
			gAssetNode->QueryFloatAttribute("height", &height);


            GameObject* tmp = gameAssets->Create(pName);
            tmp->Initialize(pName, iDevice, gameObjects, gameAssets, artAssets, pLibrary, world, x, y, angle, width, height);
			tmp->PostInitialize();
            gameObjects->push_back(tmp);
        }
	}
}