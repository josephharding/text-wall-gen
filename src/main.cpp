
#include <iostream>
#include <yaml-cpp/yaml.h>
#include <Magick++.h>


int main (int argc, char *argv[])
{
  YAML::Node config = YAML::LoadFile("../config.yaml"); // relative to executable location in build
  
	Magick::Image pix_image(Magick::Geometry(300, 100), Magick::Color("transparent"));

  pix_image.strokeColor(Magick::Color("red"));
  pix_image.fontPointsize(20);

  int y = 20; 
  for(unsigned i = 0; i < config["text"].size(); i++)
  {
    std::string myst = config["text"][i].as <std::string> ();
    std::cout << "Found scalar: " << config["text"][i] << std::endl;
	  pix_image.draw(Magick::DrawableText(0, y, config["text"][i].as <std::string> ()) );
    y += 20;
  }
	
	pix_image.magick("png");
	pix_image.write("one.png");

  return 0;
}
