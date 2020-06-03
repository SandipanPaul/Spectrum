#include<sppch.h>
#include<Spectrum.h>

class ExampleLayer : public Spectrum::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{

	}

	void OnUpdate() override {
		SP_INFO("ExmapleLayer::Update");

		if (Spectrum::Input::isKeyPressed(SP_KEY_TAB))
			SP_INFO("TAB is pressed");
	}

	void OnEvent(Spectrum::Event& event) override {
		SP_TRACE("{0}", event);
	}
};

class Sandbox : public Spectrum::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Spectrum::ImGuiLayer());
	}
	~Sandbox() {

	}
};

Spectrum::Application* Spectrum::CreateApplication() {
	return new Sandbox;
}