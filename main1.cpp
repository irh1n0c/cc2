#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <thread>
#include "personaje.h"
#include "menu.h"
#include "Seleccion.h"
#include "Seleccion2.h"
#include "GameFont.h"

using namespace sf;

void loadTextures(Texture& background, Texture& backgroundmenu, Texture& instructionss, Texture& select) {
    if (!background.loadFromFile("Images/escenario.jpg") ||
        !backgroundmenu.loadFromFile("Images/chain_fondo.jpg") ||
        !instructionss.loadFromFile("Images/instrucciones.png") ||
        !select.loadFromFile("Images/selection.jpg")) {
        throw std::runtime_error("Error loading textures");
    }
}


void f() {
	std::this_thread::sleep_for(std::chrono::seconds(1));
}


int main()
{

	// Create the main window   con 1920.1080
	RenderWindow window(VideoMode(1366, 768), "Street 5ter", Style::Close | Style::Resize);
	//GameFont gamefont;  
	Menu menu(window.getSize().x, window.getSize().y);
	Selection selection(window.getSize().x, window.getSize().y);
	Selection2 selection2(window.getSize().x, window.getSize().y);

	Texture background;
	Texture backgroundmenu;
	Texture instructionss;
	Texture select;
	/*
	if (!background.loadFromFile("Images/escenario.jpg"))
		return EXIT_FAILURE;

	if (!backgroundmenu.loadFromFile("Images/chain_fondo.jpg"))
		return EXIT_FAILURE;

	if (!instructionss.loadFromFile("Images/Instruccioness.jpg"))
		return EXIT_FAILURE;

	if (!select.loadFromFile("Images/selection.jpg"))
		return EXIT_FAILURE;
	*/

	try {
		std::thread textureThread(loadTextures, std::ref(background), std::ref(backgroundmenu), std::ref(instructionss), std::ref(select));
		textureThread.join();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	Sprite backgroundd(background);
	Sprite backgrounddmenu(backgroundmenu);
	Sprite instructions(instructionss);
	Sprite selectt(select);

	// Escalar el sprite para que coincida con las dimensiones de la ventana
	float scaleX = static_cast<float>(window.getSize().x) / backgroundd.getLocalBounds().width;
	float scaleY = static_cast<float>(window.getSize().y) / backgroundd.getLocalBounds().height;
	backgrounddmenu.setScale(scaleX, scaleY);
	selectt.setScale(scaleX, scaleY);
	backgroundd.setScale(scaleX, scaleY);
	//instructions.setScale(scaleX,scaleY);

	// Create a graphical text to display

	Font font;
	if (!font.loadFromFile("Fonts/Burger Free.ttf"))
		return EXIT_FAILURE;

	std::string personajeone;
	std::string personajedos;

	float deltaTime = 0.0f;
	Clock clock;
	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		Event event;
		while (window.pollEvent(event)) {

			if (Keyboard::isKeyPressed(Keyboard::Up)) {
				menu.MoveUp();
			}

			if (Keyboard::isKeyPressed(Keyboard::Down)) {
				menu.MoveDown();
			}

			if (Keyboard::isKeyPressed(Keyboard::Return)) {
				if (menu.GetPressedItem() == 0) {
					while (window.isOpen()) {
						Event event1;
						while (window.pollEvent(event1)) {
							if (event1.type == Event::Closed)
								window.close();

							if (Keyboard::isKeyPressed(Keyboard::W)) {
								selection.MoveUp();
							}

							if (Keyboard::isKeyPressed(Keyboard::S)) {
								selection.MoveDown();
							}

							if (Keyboard::isKeyPressed(Keyboard::Up)) {
								selection2.MoveUp();
							}

							if (Keyboard::isKeyPressed(Keyboard::Down)) {
								selection2.MoveDown();
							}

							if (Keyboard::isKeyPressed(Keyboard::Q)) {
								if (selection.GetPressedItem() == 0) {
									personajeone = "Ken";
								}

								if (selection.GetPressedItem() == 1) {
									personajeone = "Gun-devil";
								}
								if (selection.GetPressedItem() == 2) {
									personajeone = "Zena";
								}


								if (selection.GetPressedItem() == 3) {
									personajeone = "Power";
								}



							}

							if (Keyboard::isKeyPressed(Keyboard::Return)) {
								if (selection2.GetPressedItem() == 0) {
									personajedos = "Ken";
								}

								if (selection2.GetPressedItem() == 1) {
									personajedos = "Gun-devil";
								}
								if (selection2.GetPressedItem() == 2) {
									personajedos = "Zena";
								}


								if (selection2.GetPressedItem() == 3) {
									personajedos = "Power";
								}


							}

							if (Keyboard::isKeyPressed(Keyboard::Space) && (personajeone != "") && (personajedos != "")) {

								Personaje p1(personajeone, 1);
								Personaje p2(personajedos, 2);

								int turn = 0;
								//Names

								Text heroe1;
								heroe1.setFont(font);
								heroe1.setCharacterSize(100);
								heroe1.setString(p1.getName());
								//heroe1.setOrigin(-90,-110);
								heroe1.setOrigin(-50, -80); //15,50


								Text heroe2;
								heroe2.setFont(font);
								heroe2.setCharacterSize(100);
								heroe2.setString(p2.getName());
								//heroe2.setOrigin(-1150,-110);
								heroe2.setOrigin(-850, -80);//850,40

								//Health
								Text heroe1health;
								heroe1health.setFont(font);
								heroe1health.setCharacterSize(50);//25
								heroe1health.setString(std::to_string(p1.getHealth()));
								heroe1health.setOrigin(-315, -250);

								Text heroe2health;
								heroe2health.setFont(font);
								//heroe1health.setColor(sf::Color::Red);
								heroe2health.setCharacterSize(50);//25
								heroe2health.setString(std::to_string(p2.getHealth()));
								heroe2health.setOrigin(-980, -250);
								//heroe2health.setOrigin(-1380,-390);

								std::string life1 = std::to_string(p1.getHealth());
								std::string life2 = std::to_string(p2.getHealth());

								//Health
								Text lifee1;
								lifee1.setFont(font);
								lifee1.setCharacterSize(0);//25
								lifee1.setString(life1);
								lifee1.setOrigin(-500, -250);

								Text lifee2;
								lifee2.setFont(font);
								lifee2.setCharacterSize(0);
								lifee2.setString(life2);
								lifee2.setOrigin(-1150, -250);

								while (window.isOpen()) {

									int cont = 0;

									if (p1.getHealth() <= 0 || p2.getHealth() <= 0) {

										for (int i = 0; i < 3000; i++) {
											Event closeevent;
											while (window.pollEvent(closeevent)) {
												if (closeevent.type == Event::Closed) {
													window.close();
												}
											}


											window.clear();
											p1.p1.Draw(window);
											p2.p1.Draw(window);
											if (p1.getHealth() <= 0) {
												Text personajeWin;
												personajeWin.setFont(font);
												personajeWin.setCharacterSize(130);
												personajeWin.setString(p2.getName() + " won the game");
												personajeWin.setOrigin(-90, -110);
												window.draw(personajeWin);
											}

											if (p2.getHealth() <= 0) {
												Text personajeWin;
												personajeWin.setFont(font);
												personajeWin.setCharacterSize(130);
												personajeWin.setString(p1.getName() + " won the game");
												personajeWin.setOrigin(-90, -110);
												window.draw(personajeWin);
											}

											window.display();

										}
										break;
									}

									deltaTime = clock.restart().asSeconds();

									Event gameevent;


									while (window.pollEvent(gameevent)) {
										if (gameevent.type == Event::Closed) {
											window.close();
										}
									}


									if (Keyboard::isKeyPressed(Keyboard::V) && (turn == 0)) {
										p1.heal();
										std::thread sleep(f);
										sleep.join();
										turn = 1;
									}

									if (Keyboard::isKeyPressed(Keyboard::P) && (turn == 1)) {
										p2.heal();
										std::thread sleep(f);
										sleep.join();
										turn = 0;
									}


									p1.p1.Update(deltaTime);
									if (Keyboard::isKeyPressed(Keyboard::C) && (turn == 0)) {
										std::thread sleep(f);
										sleep.join();
										p1.attack(p2);
										turn = 1;
									}


									p2.p1.Update(deltaTime);
									if (Keyboard::isKeyPressed(Keyboard::O) && (turn == 1)) {
										std::thread sleep(f);
										sleep.join();
										p2.attack(p1);
										turn = 0;
									}



									window.clear();

									window.draw(backgroundd);

									window.draw(heroe1);
									window.draw(heroe2);

									window.draw(heroe1health);
									window.draw(heroe2health);

									window.draw(lifee1);
									window.draw(lifee2);

									heroe1health.setString(std::to_string(p1.getHealth()));
									heroe2health.setString(std::to_string(p2.getHealth()));


									p1.p1.Draw(window);
									p2.p1.Draw(window);


									window.display();


								}
							}
						}

						window.clear();
						window.draw(selectt);
						selection.draw(window);
						selection2.draw(window);
						window.display();

						if (Keyboard::isKeyPressed(Keyboard::Escape)) {
							break;
						}


					}

				}
				if (menu.GetPressedItem() == 1) {
					while (window.isOpen()) {

						Event gameevent;


						while (window.pollEvent(gameevent)) {
							if (gameevent.type == Event::Closed) {
								window.close();
							}
						}

						if (Keyboard::isKeyPressed(Keyboard::Escape)) {
							break;
						}

						window.clear();
						window.draw(instructions);
						window.display();
					}

				}
				if (menu.GetPressedItem() == 2) {
					window.close();
				}
			}

			// Close window: exit
			if (event.type == Event::Closed)
				window.close();
		}




		// Clear screen
		window.clear();
		// Draw the string

		window.draw(backgrounddmenu);

		menu.draw(window);


		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;
}