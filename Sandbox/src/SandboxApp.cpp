#include<sppch.h>
#include<Spectrum.h>


class Sandbox : public Spectrum::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

Spectrum::Application* Spectrum::CreateApplication() {
	return new Sandbox;
}