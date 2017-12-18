#include "../header/Game.hpp"

Game::Game(const int width, const int height) : width(width) , height(height), m_exit(false)
{
	//grid = std::make_unique<Grid>(new Grid(width, height));
	grid = std::unique_ptr<Grid>(new Grid(width, height));
}

Game::~Game()
{
}

void Game::PlayerUpdate()
{
	grid->Clear();
	std::string n;
	std::getline(std::cin, n);

	if (n == "exit")
	{
		m_exit = true;
	}
	else
	{
		player->SetSelection(atoi(n.c_str())); //VERY UGLY
	}
}

void Game::Update()
{
	for (l_GameObjects::iterator iter = gameobjects.begin(); iter != gameobjects.end(); ++iter)
	{
		(*iter)->NextMove();
		grid->SetCell((*iter)->GetPosition(), (*iter)->symbol);
	}
}

void Game::Render()
{
	grid->PrintGrid();
}

void Game::AddGameObject(const std::string & type)
{
	Vector2 pos = Basic::Random::getInstance().RandomVector2(width - 1, height - 2);

	//basic for now
	if (type == "Enemy")
	{
		gameobjects.push_back(std::make_shared<Enemy>()); //CREATES NEW OBJECT
		gameobjects.back()->SetPosition(pos);
		grid->SetCell(gameobjects.back()->GetPosition(), gameobjects.back()->symbol);
	}
	else if (type == "Player")
	{
		gameobjects.push_back(std::make_shared<Player>()); //CREATES NEW OBJECT
		gameobjects.back()->SetPosition(pos);
		grid->SetCell(gameobjects.back()->GetPosition(), gameobjects.back()->symbol);
		player = std::static_pointer_cast<Player>(gameobjects.back());
	}
}