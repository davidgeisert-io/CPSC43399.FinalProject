#include "LevelParser.h"


LevelParser::~LevelParser()
{

}

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

		TiXmlElement* spriteNode = resourceRoot.FirstChild("Sprites").FirstChild().Element();
		for(spriteNode; spriteNode; spriteNode= spriteNode->NextSiblingElement())
		{
			const char *name = spriteNode->Attribute("name"); 
			const char *dir = spriteNode->Attribute("file");
			float width, height;
			spriteNode->QueryFloatAttribute("width", &width);
			spriteNode->QueryFloatAttribute("height", &height);
			artAssets->Add(name, dir, width, height);
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
            float x, y, angle;

            gAssetNode->QueryFloatAttribute("x", &x);
            gAssetNode->QueryFloatAttribute("y", &y);
            gAssetNode->QueryFloatAttribute("angle", &angle);

            GameObject* tmp = gameAssets->Create(pName);
            tmp->Initialize(pName, iDevice, gameObjects, gameAssets, artAssets, pLibrary, world, x, y, angle);
			tmp->PostInitialize();
            gameObjects->push_back(tmp);
        }
	}
}