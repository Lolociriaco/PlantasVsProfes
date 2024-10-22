#include "claseCompraPlantas.h"

CompraPlanta::CompraPlanta() : segundos(0)
{
    sf::Color marron(139, 69, 19);
    sf::Color marronBordes(190, 89, 47);
    sf::Color colorNormal(255, 255, 255, 128); // Opacidad al 50%
    sf::Color colorSeleccionada(255, 255, 255, 255); // Opacidad al 100%

    texTableroCompra.loadFromFile("tableroCompra.jpg");
    texNuezMenu.loadFromFile("nuezMenu.jpg");
    texLanzaguisanteMenu.loadFromFile("guisantevioletaMenu.jpg");
    texGirasolMenu.loadFromFile("girasolMenu.jpg");
    contador.loadFromFile("Samdan.ttf");

    tableroCompra.setTexture(texTableroCompra);
    nuezMenu.setTexture(texNuezMenu);
    lanzaguisanteMenu.setTexture(texLanzaguisanteMenu);
    girasolMenu.setTexture(texGirasolMenu);

    contadorRondas.setFont(contador);

    tableroCompra.setPosition(260, 0);
    nuezMenu.setPosition(622, 11);
    nuezMenu.setScale(1.f, 1.f);
    nuezMenu.setColor(colorNormal);
    lanzaguisanteMenu.setPosition(517, 11);
    lanzaguisanteMenu.setScale(1.f, 1.f);
    lanzaguisanteMenu.setColor(colorNormal);
    girasolMenu.setPosition(412, 11);
    girasolMenu.setScale(1.f, 1.f);
    girasolMenu.setColor(colorSeleccionada);

    contadorRondas.setFillColor(sf::Color(255, 223, 0));
    contadorRondas.setCharacterSize(75);
    contadorRondas.setString("00:00 - ROUND 1");
    contadorRondas.setPosition(750, 35);
    contadorRondas.setOutlineColor(sf::Color::Black);
    contadorRondas.setOutlineThickness(5);

    cuadroContador.setFillColor(marron);
    cuadroContador.setSize(sf::Vector2f(440.f, 137.f));
    cuadroContador.setPosition(735, 8);
    cuadroContador.setOutlineColor(marronBordes);
    cuadroContador.setOutlineThickness(12);
}

void CompraPlanta::draw(sf::RenderWindow& window)
{

    if (tableroCompra.getTexture()) {
        window.draw(tableroCompra);
    }
    if (nuezMenu.getTexture()) {
        window.draw(nuezMenu);
    }
    if (lanzaguisanteMenu.getTexture()) {
        window.draw(lanzaguisanteMenu);
    }
    if (girasolMenu.getTexture()) {
        window.draw(girasolMenu);
    }

    window.draw(cuadroContador);
    window.draw(contadorRondas);
}

void CompraPlanta::setColor(const sf::Color& color) {
    nuezMenu.setColor(color);
    lanzaguisanteMenu.setColor(color);
    girasolMenu.setColor(color);
}

void CompraPlanta::actualizarContador() {
    sf::Time tiempoTranscurrido = reloj.restart(); // Reinicia el reloj y obtiene el tiempo transcurrido
    static float acumulador = 0.0f; // Acumulador de tiempo

    acumulador += tiempoTranscurrido.asSeconds(); // Sumar el tiempo transcurrido al acumulador

    // Si ha pasado un segundo
    if (acumulador >= 1.0f) {
        acumulador -= 1.0f; // Restar 1 segundo del acumulador
        segundos++; // Aumentar el contador de segundos

        // Actualiza el texto del contador
        std::string texto = std::string("00:") + (segundos < 10 ? "0" : "") + std::to_string(segundos) + " - ROUND 1";

        contadorRondas.setString(texto);
    }
}
