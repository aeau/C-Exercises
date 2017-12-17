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
	//std::uniform_int_distribution<int> aux(0, width - 1);
	//std::uniform_int_distribution<int> aux_2(0, height - 1);
	//int x = aux(random_generator);
	//int y = aux_2(random_generator);

	Vector2 pos = Basic::Random::getInstance().RandomVector2(width - 1, height - 2);

	//basic for now
	if (type == "Enemy")
	{
		gameobjects.push_back(std::unique_ptr<Enemy>(new Enemy())); //CREATES NEW OBJECT
		gameobjects.back()->SetPosition(pos);
		grid->SetCell(gameobjects.back()->GetPosition(), gameobjects.back()->symbol);
	}
	else if (type == "Player")
	{
		gameobjects.push_back(std::unique_ptr<Player>(new Player())); //CREATES NEW OBJECT
		gameobjects.back()->SetPosition(pos);
		grid->SetCell(gameobjects.back()->GetPosition(), gameobjects.back()->symbol);
	}
}