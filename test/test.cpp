#include "Map/CellTypeDirector.h"
#include "Map/CellTypeBuilder.h"
#include "Map/CellTypeJSONRepresentationBuilder.h"
#include "Map/Map.h"
#include "PopulationDirector.h"
#include "Engine/Player/Player.h"

#include <iostream>
#include <string>

int main() {
  std::cout << "***Create cell example code***" << std:: endl;

  CellTypeDirector director;

  auto builder = std::make_shared<CellTypeBuilder>();
  director.setBuilder(builder);
  director.makeSteppeCell();
  std::shared_ptr<CellType> steppeCell = builder -> getProduct();
  std::cout << *steppeCell << std::endl;

  auto jsonBuilder = std::make_shared<CellTypeJSONRepresentationBuilder>();
  director.setBuilder(jsonBuilder);
  director.makeWaterCell();
  auto waterCell = jsonBuilder -> getProduct();
  std::cout << waterCell << std::endl;


  std::cout << "***Create population example code***" << std:: endl;
  PopulationDirector d;
  std::shared_ptr<PopulationBuilder> b = std::make_shared<HerbivorePopulationBuilder>();
  d.setBuilder(b);
  std::shared_ptr<Population> p = d.makeBig("elephant");
  std::cout << *p;

  std::cout << "***Mutation example code***" << std::endl;
  p->mutate(Population::MutationType::VELOCITY);
  std::cout << *p;
  p->mutate(Population::MutationType::SIZE);
  std::cout << *p;

  std::cout << "***Generate map example code***" << std::endl;
  Map map(10, 10);
  map.generate();
  for (int kI = 0; kI < 10; ++kI) {
    for (int kJ = 0; kJ < 10; ++kJ) {
      std::cout << map[kI][kJ] -> getType() << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "***Generate player example code***" << std::endl;
  Player player;
  player.SetName("Cat");
  player.generatePopulations();
  auto populations = player.GetPlayerPopulations();
  for (auto &population : populations) {
    std::cout << *population << std::endl;
  }

  return 0;
}
