#include "Controller_Character.h"
#include "ObjectFinder.h"

using namespace std;

Controller_Character::Controller_Character() {

}

Controller_Character::~Controller_Character() {

}

void Controller_Character::InitController(Render_Models_Animated *models_animated, Mesh_Terrain *terrain) {
	this->render_models_animated = models_animated;
	this->mesh_terrain = terrain;
}

Character* Controller_Character::AddCharacter(const ObjectInfo &objectInfo, ObjectFinder *objectFinder) {
	Character temp;
	temp.Initiate(objectInfo, render_models_animated, mesh_terrain);
	temp.objectFinder = objectFinder;
	list<Character>::iterator tempIter = characters.end();
	characters.insert(tempIter, temp);
	--tempIter;
	if (tempIter->Activate() == CHAR_ACTIV_FAIL) {
		characters.erase(tempIter);
		return nullptr;
	}
	else {
		//tempIter->iter->character = &(*tempIter);
		tempIter->objectFinder->AddObject(&(*tempIter->iter));
		printf("%d animated characters exits\n", characters.size());
		return &*tempIter;
	}
}

void Controller_Character::DeleteCharacter(Character *target) {
	if (characters.empty()) {
		printf("No objects\n");
		return;
	}
	target->objectFinder->RemoveObject(&(*target->iter));
	list<Character>::iterator targetIter = find(characters.begin(), characters.end(), *target);

	characters.erase(targetIter);
	printf("%d animated characters left\n", characters.size());
}

void Controller_Character::UpdateCharacters() {
	list<Character>::iterator iter = characters.begin();
	while (iter != characters.end()) {
		iter->Update();
		++iter;
	}
}