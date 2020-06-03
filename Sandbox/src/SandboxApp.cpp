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