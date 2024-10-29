#include "claseCompraPlantas.h"

CompraPlanta::CompraPlanta()
{
    sf::Color marron(139, 69, 19);
    sf::Color marronBordes(190, 89, 47);
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

    cartaGirasol.setFont(contador);
    cartaLanzaguisante.setFont(contador);
    cartaNuez.setFont(contador);

    tapaUTN.setFont(contador);
    tapaLevels.setFont(contador);

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

    cartaGirasol.setFillColor(sf::Color(255, 223, 0));
    cartaGirasol.setCharacterSize(20);
    cartaGirasol.setPosition(420, 15);
    cartaGirasol.setString("1");
    cartaGirasol.setOutlineColor(sf::Color::Black);
    cartaGirasol.setOutlineThickness(3);

    cartaLanzaguisante.setFillColor(sf::Color(255, 223, 0));
    cartaLanzaguisante.setCharacterSize(20);
    cartaLanzaguisante.setPosition(525, 15);
    cartaLanzaguisante.setString("2");
    cartaLanzaguisante.setOutlineColor(sf::Color::Black);
    cartaLanzaguisante.setOutlineThickness(3);

    cartaNuez.setFillColor(sf::Color(255, 223, 0));
    cartaNuez.setCharacterSize(20);
    cartaNuez.setPosition(630, 15);
    cartaNuez.setString("3");
    cartaNuez.setOutlineColor(sf::Color::Black);
    cartaNuez.setOutlineThickness(3);

    tapaLevels.setFillColor(sf::Color::Black);
    tapaLevels.setCharacterSize(40);
    tapaLevels.setPosition(1504, 1030);
    tapaLevels.setString("Waves 1-5");
    tapaLevels.setOutlineColor(sf::Color::White);
    tapaLevels.setOutlineThickness(3);

    tapaUTN.setFillColor(sf::Color::Black);
    tapaUTN.setCharacterSize(40);
    tapaUTN.setPosition(1510, 0);
    tapaUTN.setString("UTN|FRGP");
    tapaUTN.setOutlineColor(sf::Color::White);
    tapaUTN.setOutlineThickness(3);

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

        std::string texto = (minutos < 10 ? "0" : "") + std::to_string(minutos) + ":" + (segundos < 10 ? "0" : "") + std::to_string(segundos) + " - ";
        contadorRondas.setString(texto);

}


int CompraPlanta::getSegundos(){
    return minutos*60 + segundos;
}


void CompraPlanta::enCero()
{
    std::string texto = "00:00 -";
    contadorRondas.setString(texto);

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
    window.draw(cartaGirasol);
    window.draw(cartaLanzaguisante);
    window.draw(cartaNuez);
    window.draw(tapaLevels);
    window.draw(tapaUTN);
}

void CompraPlanta::reiniciarContador()
{
    minutos=0;
    segundos=0;
}
