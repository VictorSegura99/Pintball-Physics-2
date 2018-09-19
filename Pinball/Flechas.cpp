#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "Flechas.h"
#include "ModuleInput.h"
#include <stdio.h>

Flecha::Flecha()
{
	idle.PushBack({ 11,0,80,70 });

	hit.PushBack({ 11,0,80,70 });
	hit.PushBack({ 11,70,80,70 });
	hit.PushBack({ 11, 140, 80,70 });
	hit.PushBack({ 11, 210, 80,70 });
	hit.PushBack({ 11, 280, 80,70 });
	hit.PushBack({ 11, 350, 80,70 });
	hit.PushBack({ 11, 420, 80,70 });
	hit.speed = 0.25f;
	hit.loop = false;

	rep.PushBack({ 11, 350, 80,70 });
	rep.PushBack({ 11, 280, 80,70 });
	rep.PushBack({ 11, 210, 80,70 });
	rep.PushBack({ 11, 140, 80,70 });
	rep.PushBack({ 11,70,80,70 });
	rep.speed = 0.25f;
	rep.loop = false;
}

Flecha::~Flecha()
{
}

bool Flecha::Start()
{
	texture = App->textures->Load("Assets/Sprites/Nuevo Resorte.png");
	current_animation = &idle;
	position.x = 258;
	position.y = 688;
	return true;
}

bool Flecha::CleanUp()
{
	App->textures->Unload(texture);

	return true;
}

update_status Flecha::Update()
{
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_DOWN)
	{
		hit.Reset();
		if (current_animation != &hit) {
			current_animation = &hit;

		}

	}
	if ((App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_UP)) {
		current_animation = &rep;
		rep.Reset();

	}

	App->render->Blit(texture, position.x, position.y, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}