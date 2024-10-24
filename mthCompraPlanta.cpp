#include "claseCompraPlantas.h"

CompraPlanta::CompraPlanta()
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
    nuezMenu.setColor(colorSeleccionada);
    lanzaguisanteMenu.setPosition(517, 11);
    lanzaguisanteMenu.setScale(1.f, 1.f);
    lanzaguisanteMenu.setColor(colorSeleccionada);
    girasolMenu.setPosition(412, 11);
    girasolMenu.setScale(1.f, 1.f);
    girasolMenu.setColor(colorSeleccionada);

    contadorRondas.setFillColor(sf::Color(255, 223, 0));
    contadorRondas.setCharacterSize(75);
    contadorRondas.setPosition(750, 35);
    contadorRondas.setOutlineColor(sf::Color::Black);
    contadorRondas.setOutlineThickness(5);

    cuadroContador.setFillColor(marron);
    cuadroContador.setSize(sf::Vector2f(440.f, 137.f));
    cuadroContador.setPosition(735, 8);
    cuadroContador.setOutlineColor(marronBordes);
    cuadroContador.setOutlineThickness(12);

}

void CompraPlanta::update()
{
    sf::Time tiempoTranscurrido = reloj.getElapsedTime(); // Obtener el tiempo transcurrido

    if (tiempoTranscurrido.asSeconds() >= 1.0f)
    {
        segundos++; // Incrementa los segundos
        reloj.restart(); // Restablecer el reloj para volver a contar desde 0

        if (segundos >= 60)
        {
            minutos++;
            segundos = 0; // Reiniciar segundos
        }
    }

        std::string texto = (minutos < 10 ? "0" : "") + std::to_string(minutos) + ":" + (segundos < 10 ? "0" : "") + std::to_string(segundos) + " - ROUND 1";
        contadorRondas.setString(texto);

        //std::cout << "Segundos transcurridos: " << segundos << std::endl;



}

void CompraPlanta::setColor(const sf::Color& color)
{
    sf::Color colorNormal(255, 255, 255, 128); // Opacidad al 50%
    sf::Color colorSeleccionada(255, 255, 255, 255); // Opacidad al 100%


    nuezMenu.setColor(colorNormal);
    lanzaguisanteMenu.setColor(colorNormal);
    girasolMenu.setColor(colorNormal);
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

