
#include <iostream>
#include <yaml-cpp/yaml.h>
#include <Magick++.h>


int main (int argc, char *argv[])
{
  YAML::Node config = YAML::LoadFile("../config.yaml"); // relative to executable location in build

  if (config["text"])
	{ std::cout << "text: " << config["text"].as<std::string>() << "\n";
  }

	Magick::Image pix_image(Magick::Geometry(100, 100), Magick::Color("white"));;
	pix_image.draw(Magick::DrawableText(0, 50, config["text"].as<std::string>()) );
	pix_image.magick("BMP2");
	pix_image.write("one.bmp");

  return 0;
}
