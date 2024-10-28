#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>

class Jugador {
private:
    sf::Text playerNameText;
    std::string playerName;
    sf::Font font;
    sf::Clock inputClock; // Reloj para gestionar el retraso en la entrada de texto
    int lastKey;

public:
    // Constructor: carga la fuente y configura el texto
    Jugador() {
        if (!font.loadFromFile("Samdan.ttf")) {
            throw std::runtime_error("No se pudo cargar la fuente");
        }
        playerNameText.setFont(font);
        playerNameText.setCharacterSize(100);
        playerNameText.setFillColor(sf::Color::Green);
        playerNameText.setPosition(380, 350);
        playerNameText.setOutlineColor(sf::Color::Black);
        playerNameText.setOutlineThickness(10);
        playerNameText.setString("Nombre: ");
    }

    // Método para manejar eventos de entrada de texto
    bool handleEvent(const sf::Event &event) {
        // Limitar entradas repetidas con un retraso de 0.2 segundos


        if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode < 128) { // Solo caracteres ASCII
                if (event.text.unicode == 8 && !playerName.empty()) {
                    if (inputClock.getElapsedTime().asSeconds() < 0.1f) return false;
                    playerName.pop_back();
                } else if (event.text.unicode != 8 && event.text.unicode != 13) {

                    if(event.text.unicode == lastKey){
                        if (inputClock.getElapsedTime().asSeconds() < 0.2f) return false;
                    }

                    if (inputClock.getElapsedTime().asSeconds() < 0.06f) return false;
                    // Agregar el carácter al nombre del jugador
                    playerName += static_cast<char>(event.text.unicode);

                    lastKey = event.text.unicode;
                }
                playerNameText.setString("Nombre: " + playerName);
                inputClock.restart(); // Reiniciar el reloj para evitar repeticiones
            }
        }

        // Detectar la tecla Enter una sola vez
        if (playerName.size() > 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            std::cout << "Nombre ingresado: " << playerName << std::endl;
            // Aquí podrías procesar el nombre o cambiar de pantalla
            return true;
        }
        return false;
    }

    // Método para obtener el texto a dibujar
    sf::Text getDraw() const {
        return playerNameText;
    }

    // Método para obtener el nombre del jugador
    std::string getPlayerName() const {
        return playerName;
    }
};
