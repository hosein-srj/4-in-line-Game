#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdio.h>
#include <string>
int main(void)
{
    int pauses=0,pauses2=0,x1,y1;
    char v[7]={' '};
    v[4]='J';
    int sht=0;
    int k=1;
    k++;
    char z[7][7]={{' ',' ',' ',' ',' ',' ',' '},
                  {' ',' ',' ',' ',' ',' ',' '},
                  {' ',' ',' ',' ',' ',' ',' '},
                  {' ',' ',' ',' ',' ',' ',' '},
                  {' ',' ',' ',' ',' ',' ',' '},
                  {' ',' ',' ',' ',' ',' ',' '},
                  {' ',' ',' ',' ',' ',' ',' '}
                 };
    int a,b;
    sf::Font font;
    if (!font.loadFromFile("CURLZ.TTF"))
        printf("!");
    sf::Text text1,text2,text3;
    text1.setFont(font);
    text2.setFont(font);
    text3.setFont(font);
    sf::Texture image1,image2,texture1;
    if (!image1.loadFromFile("Laugh.png"))
        return -1;
    if (!image2.loadFromFile("poker.png"))
        return -1;
    sf::Texture texture2;
    if (!texture2.loadFromFile("texture2.jpg"))
        return -1;
    if (!texture1.loadFromFile("texture1.jpg"))
        return -1;
    sf::Sprite sprite,sprite1;
    sprite.setTexture(texture2);
    sprite1.setTexture(texture1);
    sf::RenderWindow window(sf::VideoMode(1200, 750), "Reversi");
    sf::SoundBuffer buffer,buffer2;
    if(!buffer.loadFromFile("Left-Right.wav"))
        return -1;
    sf::Sound sound,sound2;
    sound.setBuffer(buffer);
    if(!buffer2.loadFromFile("Down.wav"))
        return -1;
    sound2.setBuffer(buffer2);
    sf::Music music;
    if (!music.openFromFile("khaste.ogg"))
        return -1;
    text3.setCharacterSize(40);
    text3.setColor(sf::Color::Cyan);
    text3.setPosition(700,200);
    sf::Text restart;
    while (window.isOpen())
    {
        while(pauses2==0)
        {
            window.clear();
            sf::Text play,welcome;
            play.setString("PLAY");
            play.setFont(font);
            play.setColor(sf::Color::Red);
            play.setCharacterSize(100);
            play.setPosition(450,300);
            welcome.setString("Welcome To 4 In Line");
            welcome.setFont(font);
            welcome.setColor(sf::Color::Red);
            welcome.setCharacterSize(110);
            welcome.setPosition(130,100);
            sf::Event event3;
            while (window.pollEvent(event3))
            {
                if (event3.type == sf::Event::Closed)
                    window.close();
                if ( event3.type == sf::Event::MouseMoved )
                {
                    x1=event3.mouseMove.x;
                    y1=event3.mouseMove.y;
                }
                if(event3.type==sf::Event::MouseButtonPressed)
                {
                    if(event3.mouseButton.button==sf::Mouse::Left)
                    {

                        if(x1>450&&x1<690&&y1>320&&y1<420)
                            pauses2=1;
                    }
                }
            }
            if(x1>450&&x1<690&&y1>320&&y1<420)
            {
                play.setStyle(sf::Text::Bold | sf::Text::Underlined );
                play.setColor(sf::Color::Green);
            }
            window.draw(sprite1);
            window.draw(play);
            window.draw(welcome);
            window.display();
        }
        while(1)
        {
            a=0;
            int k=7;
            window.clear();
            sf::Event event;
            while (window.pollEvent(event))
            {
                if(event.type==sf::Event::MouseMoved)
                {
                    x1=event.mouseMove.x;
                    y1=event.mouseMove.y;
                }

                if(event.type==sf::Event::MouseButtonPressed)
                {
                    if(event.mouseButton.button==sf::Mouse::Left)
                    {
                        text3.setString(" ");
                        int x2,y2;
                        x2=event.mouseButton.x;
                        y2=event.mouseButton.y;
                        if(x2>830&&x2<1000&&y2>416&&y2<470)
                        {
                            int pp=0;
                            int ppp=0;
                            while(ppp<7)
                            {
                                while(pp<7)
                              {
                                    z[pp][ppp]=' ';
                                    pp++;
                                }
                                pp=0;
                                ppp++;
                            }
                            sht=0;
                            pauses=0;
                        }
                    }
                }
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
                if(pauses==0)
                {

                    if(event.type==sf::Event::KeyPressed)
                    {
                        if(event.key.code==sf::Keyboard::Left)
                        {
                            sound.play();
                            a=0;
                            while(a<8)
                            {
                                if(v[a]=='J')
                                    break;
                                a++;
                            }
                            if(a-1>=0)
                            {
                                v[a]=' ';
                                v[a-1]='J';
                            }
                        }
                        else if(event.key.code==sf::Keyboard::Right)
                        {
                            sound.play();
                            a=0;
                            while(a<8)
                            {
                                if(v[a]=='J')
                                    break;
                                a++;
                            }
                            if(a+1<7)
                            {
                                v[a]=' ';
                                v[a+1]='J';
                            }
                        }
                        if(event.key.code==sf::Keyboard::Down)
                        {
                            sound2.play();
                            a=0;
                            while(a<8)
                            {
                                if(v[a]=='J')
                                    break;
                                a++;
                            }
                            k=7;
                            switch(a)
                            {
                                case 0:
                                    while(k>0)
                                    {
                                        if(z[k-1][0]==' ')
                                        {
                                            if(sht%2==1)
                                                z[k-1][0]='R';
                                            else
                                                z[k-1][0]='B';
                                            sht++;
                                            break;
                                        }
                                        k--;
                                    }
                                    break;
                                case 1:
                                    while(k>0)
                                    {
                                        if(z[k-1][1]==' ')
                                        {
                                            if(sht%2==1)
                                                z[k-1][1]='R';
                                            else
                                                z[k-1][1]='B';
                                            sht++;
                                            break;
                                        }
                                        k--;
                                    }
                                    break;
                                case 2:
                                    while(k>0)
                                    {
                                        if(z[k-1][2]==' ')
                                        {
                                            if(sht%2==1)
                                                z[k-1][2]='R';
                                            else
                                                z[k-1][2]='B';
                                            sht++;
                                            break;
                                        }
                                        k--;
                                    }
                                    break;
                                case 3:
                                    while(k>0)
                                    {
                                        if(z[k-1][3]==' ')
                                        {
                                            if(sht%2==1)
                                                z[k-1][3]='R';
                                            else
                                                z[k-1][3]='B';
                                            sht++;
                                            break;
                                        }
                                        k--;
                                    }
                                    break;
                                case 4:
                                    while(k>0)
                                    {
                                        if(z[k-1][4]==' ')
                                        {
                                            if(sht%2==1)
                                                z[k-1][4]='R';
                                            else
                                                z[k-1][4]='B';
                                            sht++;
                                            break;
                                        }
                                        k--;
                                    }
                                    break;
                                case 5:
                                    while(k>0)
                                    {
                                        if(z[k-1][5]==' ')
                                        {
                                            if(sht%2==1)
                                                z[k-1][5]='R';
                                            else
                                                z[k-1][5]='B';
                                            sht++;
                                            break;
                                        }
                                        k--;
                                    }
                                    break;
                                case 6:
                                    while(k>0)
                                    {
                                        if(z[k-1][6]==' ')
                                        {
                                            if(sht%2==1)
                                                z[k-1][6]='R';
                                            else
                                                z[k-1][6]='B';
                                            sht++;
                                            break;
                                        }
                                        k--;
                                    }
                                    break;
                            }
                            int g=0,h=0;
                            while(g<7)
                            {
                                while(h<7)
                                {
                                    if(g+3<7)
                                    {
                                        if((z[g][h]==z[g+1][h])&&(z[g][h]==z[g+2][h])&&(z[g][h]==z[g+3][h])&&((z[g][h]=='R')||(z[g][h]=='B')))
                                        {
                                            if (z[g][h]=='B')
                                                text3.setString("Laugh Nut Win The Match");
                                            else if (z[g][h]=='R')
                                                text3.setString("Poker Nut Win The Match");
                                            music.play();
                                            pauses=1;
                                        }
                                    }
                                    h++;
                                }
                                h=0;
                                g++;
                            }
                            g=0;
                            h=0;
                            while(g<7)
                            {
                                while(h<7)
                                {
                                    if(h+3<7)
                                    {
                                        if((z[g][h]==z[g][h+1])&&(z[g][h]==z[g][h+2])&&(z[g][h]==z[g][h+3])&&((z[g][h]=='B')||(z[g][h]=='R')))
                                        {
                                            if (z[g][h]=='B')
                                                text3.setString("Laugh Nut Win The Match");
                                            else if (z[g][h]=='R')
                                                text3.setString("Poker Nut Win The Match");
                                            music.play();
                                            pauses=1;
                                        }
                                    }
                                    h++;
                                }
                                h=0;
                                g++;
                            }
                            g=0;
                            h=0;
                            while(g<7)
                            {
                                while(h<7)
                                {
                                    if(g+3<7&&h+3<7)
                                    {
                                        if((z[g][h]==z[g+1][h+1])&&(z[g][h]==z[g+2][h+2])&&(z[g][h]==z[g+3][h+3])&&((z[g][h]=='B')||(z[g][h]=='R')))
                                        {
                                            if (z[g][h]=='B')
                                                text3.setString("Laugh Nut Win The Match");
                                            else if (z[g][h]=='R')
                                                text3.setString("Poker Nut Win The Match");
                                            music.play();
                                            pauses=1;
                                        }
                                    }
                                    h++;
                                }
                                h=0;
                                g++;
                            }
                            g=0;
                            h=0;
                            while(g<7)
                            {
                                while(h<7)
                                {
                                    if((g-3>=0)&&(h+3<7))
                                    {
                                        if((z[g][h]==z[g-1][h+1])&&(z[g][h]==z[g-2][h+2])&&(z[g][h]==z[g-3][h+3])&&((z[g][h]=='R')||(z[g][h]=='B')))
                                        {
                                            if (z[g][h]=='B')
                                                text3.setString("Laugh Nut Win The Match");
                                            else if (z[g][h]=='R')
                                                text3.setString("Poker Nut Win The Match");
                                            music.play();
                                            pauses=1;
                                        }
                                    }
                                    h++;
                                }
                                h=0;
                                g++;
                            }
                        }
                    }
                }
            }
            window.draw(sprite);
            window.draw(text3);
            restart.setString("Restart");
            restart.setFont(font);
            restart.setColor(sf::Color::Red);
            restart.setCharacterSize(60);
            restart.setPosition(830,400);
            if(x1>830&&x1<1000&&y1>416&&y1<470)
            {
                restart.setStyle(sf::Text::Bold | sf::Text::Underlined );
                restart.setColor(sf::Color::Green);
            }
            window.draw(restart);
            if(sht%2==1)
            {
                text1.setString("Poker Turn");
                text1.setCharacterSize(45);
                text1.setColor(sf::Color::Cyan);
                text1.setPosition(800, 94);
                window.draw(text1);
            }
            if(sht%2==0)
            {
                text2.setString("Laugh Turn");
                text2.setCharacterSize(45);
                text2.setColor(sf::Color::Cyan);
                text2.setPosition(800, 94);
                window.draw(text2);
            }
            int m=0,n=0;
            while(m<7)
            {
                while(n<7)
                {
                    if(z[m][n]=='B')
                    {
                        sf::CircleShape shape2(25);
                        a=100+(n)*62.5+4;
                        b=212.5+(m)*62.5+7;
                        shape2.setPosition(a, b);
                        shape2.setTexture(&image1);
                        window.draw(shape2);
                    }
                    if(z[m][n]=='R')
                    {
                        sf::CircleShape shape1(25);
                        a=100+(n)*62.5+4;
                        b=212.5+(m)*62.5+7;
                        shape1.setPosition(a, b);
                        shape1.setTexture(&image2);
                        window.draw(shape1);
                    }
                    n++;
                }
                n=0;
                m++;
            }
            a=0;
            while(a<520)
            {
                if(v[a]=='J')
                {
                    sf::CircleShape shape3(25);
                    shape3.setPosition(104+62.5*a, 157);
                    if(sht%2==0)
                        shape3.setTexture(&image1);
                    if(sht%2==1)
                        shape3.setTexture(&image2);
                    window.draw(shape3);
                }
                a++;
            }
            double i=0;
            while(i<500)
            {
                sf::RectangleShape line1(sf::Vector2f(437.5,2));
                line1.setPosition(100, 212.5+i);
                line1.setFillColor(sf::Color::Yellow);
                window.draw(line1);
                i+=62.5;
            }
            i=0;
            while(i<500)
            {
                sf::RectangleShape line2(sf::Vector2f(439.5,2));
                line2.setPosition(100+i, 212.5);
                line2.setFillColor(sf::Color::Yellow);
                line2.rotate(90);
                window.draw(line2);
                i+=62.5;
            }
            window.display();
            if(pauses==1)
                break;
        }
        sf::Event event2;
        while (window.pollEvent(event2))
        {
            if (event2.type == sf::Event::Closed)
                window.close();
        }
    }
    return 0;
}
