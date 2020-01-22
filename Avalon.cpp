#include "Avalon.h"

Avalon::Avalon(std::string name)
	: Scene(name)
{
}

void Avalon::InitScene(float windowWidth, float windowHeight)
{
	
	m_sceneReg = new entt::registry;
	ECS::AttachRegister(m_sceneReg);
	float aspectRatio = windowWidth / windowHeight;
	{
		auto entity = ECS::CreateEntity();
		EntityIdentifier::MainCamera(entity);

		ECS::AttachComponent<Camera>(entity);
		vec4 temp = ECS::GetComponent<Camera>(entity).GetOrthoSize();
		ECS::GetComponent<Camera>(entity).SetWindowSize(vec2(float(windowWidth), float(windowHeight)));
		ECS::GetComponent<Camera>(entity).Orthographic(aspectRatio, temp.x, temp.y, temp.z, temp.w, -100.f, 100.f);
		unsigned int bitHolder = EntityIdentifier::CameraBit();
		ECS::SetUpIdentifier(entity, bitHolder, "Main Camera");
		ECS::SetIsMainCamera(entity, true);
	}

	auto entityBack = ECS::CreateEntity();
	//Add components
	ECS::AttachComponent<Sprite>(entityBack);
	ECS::AttachComponent<Transform>(entityBack);

	//Sets up components
	std::string BackGround = "TestMap.png"; //400, 200
	ECS::GetComponent<Sprite>(entityBack).LoadSprite(BackGround, 380, 200);
	ECS::GetComponent<Transform>(entityBack).SetPosition(vec3(0.f, 0.f, 13.f));

	//Setup up the Identifier
	unsigned int bitHolder = 0x0;
	ECS::SetUpIdentifier(entityBack, bitHolder, "Temp Entity");

}
