#include "Main.hpp"
#include "Sprite.hpp"
#include "background.hpp"
#include "Obstacles.hpp"
#include <fstream>

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1280, 720), "Dagan-dagan");
    window.setFramerateLimit(60);
    Background bg("content/backdrop.png");
    Background mn("content/static mountain.png");
    Background floor("content/ground.png");
    mn.sprite.setPosition(Vector2f(0, 100));
    floor.sprite.setPosition(Vector2f(0,444));
    Background cl("content/cloud1.png");

    SpriteAnimate character("content/playerspritesheet.png", IntRect(0,0,128,128), Vector2f(400,380), 0.05, 1664, 128);
    character.sprite.setOrigin(Vector2f(64,64));
    int score = 0, i = 0, hiScore = 0;
    float spawn = 2.5;
    Clock game, scr, jumpClock;
    bool gameOn = true;
    Font font;
    font.loadFromFile("content/Fipps-Regular.otf");
    Text currentScore("Score: 0", font, 20);
    Text highScore("High Score: ", font, 20);
    Text gameOver("Game Over\n", font, 90), finalScore("10", font, 140);
    finalScore.setPosition(640, 420);
    gameOver.setPosition(640, 350);
    gameOver.setOrigin(gameOver.getLocalBounds().width/2.0f, gameOver.getLocalBounds().height/2.0f);
    highScore.setPosition(10,10);
    highScore.setFillColor(Color(0,0,0));

    ifstream readFile;
    readFile.open( "Content/hiscore.txt");
    if(readFile.is_open()){
        while(!readFile.eof()){
            readFile >> hiScore;
        }
    }
    readFile.close();
    highScore.setString("High Score: "+to_string(hiScore));

    currentScore.setFillColor(Color(0,0,0));
    currentScore.setPosition(10,40);
    vector < Obstacle > ob;
    Obstacle t[] = {Obstacle("content/obstacle1.png"), Obstacle("content/obstacle2.png"), Obstacle("content/obstacle3.png")};

    Music back, jump, run, gameover;
    if (!back.openFromFile("content/bg.ogg"))
        return EXIT_FAILURE;
    if (!run.openFromFile("content/run.ogg"))
        return EXIT_FAILURE;
    if (!jump.openFromFile("content/jump.ogg"))
        return EXIT_FAILURE;
    if (!gameover.openFromFile("content/gameover.ogg"))
        return EXIT_FAILURE;
    gameover.setVolume(50);

    run.setLoop(true);
    run.play();
    run.setVolume(50);
    back.setLoop(true);
    back.play();

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if(event.type==Event::KeyPressed && (event.key.code==Keyboard::Up || event.key.code==Keyboard::Space)){
                character.jump();
                jump.play();
                if(!gameOn){
                    score = 0;
                    i = 0;
                    character.increment = 128;
                    gameOn = true;
                    ob.clear();
                }
            }
            // if(event.type==Event::KeyPressed && event.key.code==Keyboard::Down)
            //     character.slide();
        }
        if(jumpClock.getElapsedTime().asSeconds() > 0.8f){
            jump.stop();
            jumpClock.restart();
        }
        if(score > 10)
            spawn = 1.8;
        if(score > 20)
            spawn = 1.0;
        if(score > 30)
            spawn = 0.7;
        if(game.getElapsedTime().asSeconds() > spawn){
            if(gameOn){
                srand(time(NULL));
                int random = (rand() % 3);
                ob.push_back(t[random]);
                score++;
            }
            game.restart();
        }
        currentScore.setString("Score: "+to_string(score));
        character.animate();
        window.clear(Color(240,240,240));
        window.draw(bg.sprite);
        window.draw(mn.sprite);
        window.draw(floor.sprite);
        window.draw(character.sprite);
        for(int k = ob.size()-1; k >= 0; k--){
            ob[k].update();
            if(score > 10)
                ob[k].speed = -11;
            if(score > 20)
                ob[k].speed = -15;
            if(score > 30)
                ob[k].speed = -19;
            window.draw(ob[k].sprite);
            if(ob[k].x < 0)
                ob.erase(ob.begin() + k);
            if(ob[k].isHit(character.sprite)){
                character.increment = 0;
                ob[k].speed = 0;
                gameOn = false;
                spawn = 2.5;
                if(scr.getElapsedTime().asSeconds() > 0.05f && i <= score){
                    finalScore.setString(to_string(i));
                    finalScore.setOrigin(finalScore.getLocalBounds().width/2.0f, finalScore.getLocalBounds().height/2.0f);
                    scr.restart();
                    i++;
                }
            }
        }
        if(!gameOn){
            std::ofstream writeFile( "Content/hiscore.txt");
            if(writeFile.is_open()){
                if( score > hiScore ){
                    hiScore = score;
                }
                writeFile << hiScore;
            }
            cout << hiScore << endl;
            writeFile.close();
            highScore.setString("High Score: "+to_string(hiScore));


            window.draw(gameOver);
            currentScore.setString("");
            window.draw(finalScore);
            // ob.clear();
        }
        window.draw(highScore);
        window.draw(currentScore);
        window.display();
    }
    return EXIT_SUCCESS;
}
